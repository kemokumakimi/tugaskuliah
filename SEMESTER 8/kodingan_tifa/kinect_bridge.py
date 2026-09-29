import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import socket
import numpy as np
import struct

class KinectBridge(Node):
    def __init__(self):
        super().__init__('kinect_bridge')
        self.publisher_ = self.create_publisher(Image, 'camera/image/raw', 10)
        self.bridge = CvBridge()
        
        # Konfigurasi Socket (Port 8000 sesuai permintaan Pi)
        self.host = '0.0.0.0'
        self.port = 8000
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_socket.bind((self.host, self.port))
        self.server_socket.listen(1)
        
        self.get_logger().info(f'Server Penerima Aktif di Port {self.port}. Menunggu Raspberry Pi...')
        
        # Timer untuk mengecek koneksi
        self.create_timer(0.1, self.receive_image)

    def receive_image(self):
        try:
            self.server_socket.settimeout(0.1)
            conn, addr = self.server_socket.accept()
            self.get_logger().info(f'Terhubung dengan Raspberry Pi: {addr}')
            
            data = b""
            payload_size = struct.calcsize("Q")
            
            while rclpy.ok():
                while len(data) < payload_size:
                    packet = conn.recv(4096)
                    if not packet: break
                    data += packet
                
                packed_msg_size = data[:payload_size]
                data = data[payload_size:]
                msg_size = struct.unpack("Q", packed_msg_size)[0]
                
                while len(data) < msg_size:
                    data += conn.recv(4096)
                
                frame_data = data[:msg_size]
                data = data[msg_size:]
                
                # Decode gambar
                nparr = np.frombuffer(frame_data, np.uint8)
                frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
                
                if frame is not None:
                    # Publish ke ROS 2
                    ros_image = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
                    self.publisher_.publish(ros_image)
                    
        except socket.timeout:
            pass
        except Exception as e:
            self.get_logger().error(f'Error: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = KinectBridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
