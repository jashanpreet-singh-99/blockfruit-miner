#pragma once

#include <thread>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>

#include "terminal.hpp"

struct NodeConfig {
    std::string server_ip;
    unsigned int port;
};

struct MonitoringConfig {
    bool enabled;
    std::string server_ip;
    unsigned int port;
};

struct Config {
    std::string worker_name;
    std::string wallet;
    std::string algo;
    unsigned int threads;
    NodeConfig node;
    MonitoringConfig monitoring;
    bool logging_enabled;

    void print() const; 
};

Config readConfig(const std::string& filename);
