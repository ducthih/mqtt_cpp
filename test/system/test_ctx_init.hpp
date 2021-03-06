// Copyright Takatoshi Kondo 2017
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#if !defined(MQTT_TEST_CTX_INIT_HPP)
#define MQTT_TEST_CTX_INIT_HPP

#if defined(MQTT_USE_TLS)

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include "test_settings.hpp"

static inline boost::asio::ssl::context test_ctx_init() {
    boost::asio::ssl::context ctx(boost::asio::ssl::context::tlsv12);
    ctx.set_options(
        boost::asio::ssl::context::default_workarounds |
        boost::asio::ssl::context::single_dh_use);
    std::string path = boost::unit_test::framework::master_test_suite().argv[0];
    std::size_t pos = path.find_last_of("/\\");
    std::string base = (pos == std::string::npos) ? "" : path.substr(0, pos + 1);
    ctx.use_certificate_chain_file(base + "server.crt.pem");
    ctx.use_private_key_file(base + "server.key.pem", boost::asio::ssl::context::pem);
    return ctx;
}


#endif // defined(MQTT_USE_TLS)

#endif // MQTT_TEST_CTX_INIT_HPP
