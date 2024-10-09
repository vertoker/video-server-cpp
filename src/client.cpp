
// self
#include "client.hpp"

// packages
#include <fmt/core.h>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

videoserver::client::client(const std::string& ip, const unsigned short& port) {
    fmt::print("Start client");
    
    boost::asio::io_service service;
    boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string(ip.c_str()), port);
    boost::asio::ip::tcp::socket sock(service);
    sock.connect(ep);
}
