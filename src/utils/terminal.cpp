#include "terminal.hpp"
#include "configurations.hpp"

int initialConfigurations() {
    printcf(WHITE, LOGO);
    printcf(CYAN, "Welcome to BlockFruit\n\n");

    printcf(CYAN, "Reading configurations.....\n\n");
    try {
        Config config = readConfig("config.json");
        config.print();
    } catch (const std::exception& e) {
        printcf(RED, "Error: ", e.what());
        return 1;
    }
    return 0;
}