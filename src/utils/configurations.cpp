#include "configurations.hpp"

using namespace boost::property_tree;

void Config::print() const {
    std::string monitor_server = "";
    if (monitoring.enabled) {
        monitor_server = monitoring.server_ip + ":" + std::to_string(monitoring.port);
    }
    std::cout << "Worker Name        : " << worker_name << "\n"
              << "Wallet Address     : " << wallet << "\n"
              << "Algorithm          : " << algo << "\n"
              << "Node Server IP     : " << node.server_ip << ":" << node.port << "\n"
              << "Monitoring Enabled : " << (monitoring.enabled ? "Yes" : "No") << "\n"
              << "Monitoring Server  : " << monitor_server << "\n"
              << "Logging Enabled    : " << (logging_enabled ? "Yes" : "No") << "\n"
              << "Threads count      : " << threads << "\n";
}

Config readConfig(const std::string& filename) {
    ptree config_tree;

    try {
        read_json(filename, config_tree);
    } catch (const json_parser_error& e) {
        throw std::runtime_error("Error reading config.json: " + std::string(e.what()));
    }

    Config config;
    config.worker_name = config_tree.get<std::string>("worker_name");
    config.wallet = config_tree.get<std::string>("wallet");
    config.algo = config_tree.get<std::string>("algo");
    config.threads = config_tree.get<int>("threads");

    config.node.server_ip = config_tree.get<std::string>("node.server_ip");
    config.node.port = config_tree.get<int>("node.port");

    config.monitoring.enabled = config_tree.get<bool>("monitoring.enabled");
    config.monitoring.server_ip = config_tree.get<std::string>("monitoring.server_ip");
    config.monitoring.port = config_tree.get<int>("monitoring.port");

    config.logging_enabled = config_tree.get<bool>("features.logging");

    if (config.threads == 0) {
        printcf(YELLOW, "Threads auto-calibrated.\n");
        try {
            config.threads = std::thread::hardware_concurrency();
        } catch (const std::exception& e) {
            config.threads = 1;
        }
    }

    return config;
}