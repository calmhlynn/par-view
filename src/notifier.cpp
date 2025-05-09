#include "notifier.hpp"
#include <boost/asio.hpp>
#include <iostream>
#include <sstream>

Notifier::Notifier(const Config &cfg) : cfg_(cfg) {}

void Notifier::send(const std::string &msg) {
    try {
        boost::asio::io_context io;
        auto endpoints = boost::asio::ip::tcp::resolver(io).resolve(
            cfg_.notifyHost, std::to_string(cfg_.notifyPort));
        boost::asio::ip::tcp::socket sock(io);
        boost::asio::connect(sock, endpoints);

        std::ostringstream req;
        req << "POST " << cfg_.notifyPath << " HTTP/1.1\r\n"
            << "Host: " << cfg_.notifyHost << "\r\n"
            << "Content-Type: application/json\r\n"
            << "Content-Length: " << msg.size() << "\r\n"
            << "Connection: close\r\n\r\n"
            << msg;

        boost::asio::write(sock, boost::asio::buffer(req.str()));
    } catch (std::exception &e) {
        std::cerr << "Notify error: " << e.what() << std::endl;
    }
}
