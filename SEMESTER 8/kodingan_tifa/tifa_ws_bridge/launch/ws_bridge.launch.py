from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import ThisLaunchFileDir
from launch_ros.substitutions import FindPackageShare
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.substitutions import LaunchConfiguration
from launch.actions import ExecuteProcess

import os


def generate_launch_description():
    pkg_share = FindPackageShare('tifa_ws_bridge').find('tifa_ws_bridge')
    default_params = os.path.join(pkg_share, 'config', 'ws_bridge_params.yaml')

    ws_uri_arg = DeclareLaunchArgument(
        'ws_uri_primary',
        default_value='ws://localhost:3001',
        description='Primary WebSocket URI'
    )

    robot_id_arg = DeclareLaunchArgument(
        'robot_id',
        default_value='TFRB1',
        description='Robot ID'
    )
    
    network_mode = DeclareLaunchArgument(
        'network_mode',
        default_value='auto',   # offline | online | auto
        description='Network mode'
    )


    node = Node(
        package='tifa_ws_bridge',
        executable='ws_bridge_node',
        name='tifa_ws_bridge',
        output='screen',
        parameters=[
            default_params,
            {
                'ws_uri_primary': LaunchConfiguration('ws_uri_primary'),
                'robot_id': LaunchConfiguration('robot_id'),
                'network_mode': LaunchConfiguration('network_mode'),
                'enable_local_ws': True,
                'local_ws_port': 8765
            }
        ]
    )

    adb_kill = ExecuteProcess(
        cmd=['pkill', 'adb'],
        output='screen'
    )


    adb_wait = ExecuteProcess(
        cmd=['adb', 'wait-for-device'],
        output='screen'
    )

    
    adb_reverse = ExecuteProcess(
        cmd=['adb', 'reverse', 'tcp:8765', 'tcp:8765'],
        output='screen'
    )

    delayed_adb_reverse = TimerAction(
        period=5.0,
        actions=[adb_reverse]
    )

    delayed_cloud = TimerAction(
        period=5.0,
        actions=[node]
    )

    node_upload_sensor = Node(
        package='tifa_ws_bridge',
        executable='cloud_upload',
        name='cloud_upload',
        output='screen',
    )

    return LaunchDescription([
        ws_uri_arg,
        robot_id_arg,
        adb_kill,
        adb_wait,
        delayed_adb_reverse,
        delayed_cloud,
        network_mode,
        node_upload_sensor,
    ])
