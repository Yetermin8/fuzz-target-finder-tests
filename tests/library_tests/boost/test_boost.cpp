// 10 Relevant Functions
#include <boost/asio.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <iostream>
#include <sstream>

void testBoostLibrary() {
    char buffer[100]; // Declaring buffer here so it is accessible to all code below

    // boost::filesystem::ifstream::read, getline, readsome
    boost::filesystem::ifstream ifs("test.txt");
    if (ifs.is_open()) {
        ifs.read(buffer, 100);
        ifs.getline(buffer, 100);
        ifs.readsome(buffer, 100);
    }

    // boost::asio::read, async_read, read_until, async_read_until
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket socket(io_context);
    boost::asio::streambuf buf;
    boost::asio::read(socket, boost::asio::buffer(buffer, 100));
    boost::asio::async_read(socket, boost::asio::buffer(buffer, 100), [](const boost::system::error_code&, std::size_t){});
    boost::asio::read_until(socket, buf, "\n");
    boost::asio::async_read_until(socket, buf, "\n", [](const boost::system::error_code&, std::size_t){});

    // boost::asio::buffer, socket::receive
    boost::asio::mutable_buffers_1 mutable_buffer = boost::asio::buffer(buffer, 100);
    socket.receive(mutable_buffer);

    // boost::archive::text_iarchive::operator>>, binary_iarchive::operator>>, xml_iarchive::operator>>
    std::istringstream iss("text archive data");
    boost::archive::text_iarchive tia(iss);
    int data;
    tia >> data;

    std::istringstream iss_bin("binary archive data");
    boost::archive::binary_iarchive bia(iss_bin);
    bia >> data;

    std::istringstream iss_xml("xml archive data");
    boost::archive::xml_iarchive xia(iss_xml);
    xia >> BOOST_SERIALIZATION_NVP(data);
}

int main() {
    testBoostLibrary();
    return 0;
}
