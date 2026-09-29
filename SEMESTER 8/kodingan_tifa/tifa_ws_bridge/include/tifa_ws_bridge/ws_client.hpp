#pragma once

#include <functional>
#include <set>
#include <mutex>
#include <thread>
#include <string>
#include <atomic>

#include <ixwebsocket/IXWebSocket.h>

namespace tifa_ws_bridge
{

// 🔹 Balikin state FALLBACK
enum class ConnectionState
{
  DISCONNECTED,
  CONNECTING,
  CONNECTED,
  FALLBACK     // artinya: lagi pakai backup_uri
};

class WsClient
{
public:
  using MessageCallback = std::function<void(const std::string &)>;
  using StatusCallback  = std::function<void(ConnectionState)>;

  WsClient();
  ~WsClient();

  void configure(
    const std::string & primary_uri,
    const std::string & backup_uri,
    const std::string & robot_id,
    double reconnect_interval_sec);

  void setMessageCallback(MessageCallback cb);
  void setStatusCallback(StatusCallback cb);

  void start();
  void stop();

  void send(const std::string & msg);

  ConnectionState getState() const;

private:
  void notifyStatus(ConnectionState s);

  // 🔹 fungsi bantu untuk reconnect / fallback
  void scheduleReconnect(bool from_error);

  std::string primary_uri_;
  std::string backup_uri_;
  std::string robot_id_;
  double reconnect_interval_sec_{3.0};

  MessageCallback message_cb_;
  StatusCallback status_cb_;

  ix::WebSocket ws_;
  std::atomic<ConnectionState> state_{ConnectionState::DISCONNECTED};

  // 🔹 flag: lagi pakai backup atau bukan
  std::atomic_bool use_backup_{false};
  std::atomic_bool reconnecting_{false};
};

}  // namespace tifa_ws_bridge
