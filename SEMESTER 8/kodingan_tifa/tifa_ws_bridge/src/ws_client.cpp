#include "tifa_ws_bridge/ws_client.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

using namespace std::chrono_literals;

namespace tifa_ws_bridge
{

WsClient::WsClient()
{
}

WsClient::~WsClient()
{
  stop();
}

void WsClient::configure(
  const std::string & primary_uri,
  const std::string & backup_uri,
  const std::string & robot_id,
  double reconnect_interval_sec)
{
  primary_uri_ = primary_uri;
  backup_uri_ = backup_uri;
  robot_id_ = robot_id;
  reconnect_interval_sec_ = reconnect_interval_sec;
}

void WsClient::setMessageCallback(MessageCallback cb)
{
  message_cb_ = std::move(cb);
}

void WsClient::setStatusCallback(StatusCallback cb)
{
  status_cb_ = std::move(cb);
}

void WsClient::start()
{
  if (primary_uri_.empty()) {
    std::cerr << "[WsClient] primary_uri is empty, not starting WS\n";
    return;
  }

  use_backup_ = false;
  reconnecting_ = false;

  // Set URL awal ke primary
  ws_.setUrl(primary_uri_);

  // Callback dari ixwebsocket
  ws_.setOnMessageCallback(
    [this](const ix::WebSocketMessagePtr & msg)
    {
      switch (msg->type) {
        case ix::WebSocketMessageType::Open:
        {
          if (use_backup_) {
            std::cout << "[WsClient] Connected to BACKUP: " << backup_uri_ << std::endl;
            notifyStatus(ConnectionState::FALLBACK);
          } else {
            std::cout << "[WsClient] Connected to PRIMARY: " << primary_uri_ << std::endl;
            notifyStatus(ConnectionState::CONNECTED);
          }

          // Kirim SI (Session Identify)
          std::string si = std::string("{\"code\":\"SI\",\"data\":{\"type\":\"ROBOT\",\"robot_id\":\"")
            + robot_id_ + "\"}}";
          send(si);
          std::cout << "[WsClient] Sent SI: " << si << std::endl;
          break;
        }

        case ix::WebSocketMessageType::Message:
          if (message_cb_) {
            message_cb_(msg->str);
          }
          break;

        case ix::WebSocketMessageType::Close:
          std::cout << "[WsClient] Connection closed. Reason: "
                    << msg->closeInfo.reason << std::endl;
          notifyStatus(ConnectionState::DISCONNECTED);
          scheduleReconnect(true);
          break;

        case ix::WebSocketMessageType::Error:
          std::cout << "[WsClient] Error: " << msg->errorInfo.reason << std::endl;
          notifyStatus(ConnectionState::DISCONNECTED);
          scheduleReconnect(true);
          break;

        default:
          break;
      }
    });

  notifyStatus(ConnectionState::CONNECTING);
  ws_.start();
}

void WsClient::stop()
{
  ws_.stop();
  notifyStatus(ConnectionState::DISCONNECTED);
}

void WsClient::send(const std::string & msg)
{
  auto s = state_.load();
  if (s != ConnectionState::CONNECTED && s != ConnectionState::FALLBACK) {
    std::cerr << "[WsClient] Not connected, cannot send\n";
    return;
  }
  ws_.sendText(msg);
}

ConnectionState WsClient::getState() const
{
  return state_.load();
}

void WsClient::notifyStatus(ConnectionState s)
{
  state_.store(s);
  if (status_cb_) {
    status_cb_(s);
  }
}

// 🔹 Fallback / reconnect logic utama
void WsClient::scheduleReconnect(bool from_error)
{
  if (reconnecting_.exchange(true)) {
    // sudah ada thread reconnect yang jalan
    return;
  }

  std::thread([this]() {
    std::this_thread::sleep_for(
      std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::duration<double>(reconnect_interval_sec_)));

    // Tentukan target berikutnya:
    // - Kalau sekarang pakai primary & ada backup → pindah ke backup (FALLBACK)
    // - Kalau sekarang pakai backup → balik ke primary
    bool next_use_backup = use_backup_.load();

    if (!next_use_backup && !backup_uri_.empty()) {
      // dari primary → ke backup
      next_use_backup = true;
      std::cout << "[WsClient] Fallback: trying BACKUP WS: " << backup_uri_ << std::endl;
      ws_.setUrl(backup_uri_);
      notifyStatus(ConnectionState::FALLBACK);   // status: lagi di mode fallback (connecting backup)
    } else {
      // dari backup atau tidak ada backup → coba primary lagi
      next_use_backup = false;
      std::cout << "[WsClient] Reconnect: trying PRIMARY WS: " << primary_uri_ << std::endl;
      ws_.setUrl(primary_uri_);
      notifyStatus(ConnectionState::CONNECTING);
    }

    use_backup_.store(next_use_backup);
    ws_.start();   // ixwebsocket akan connect ke URL baru

    reconnecting_.store(false);
  }).detach();
}

}  // namespace tifa_ws_bridge
