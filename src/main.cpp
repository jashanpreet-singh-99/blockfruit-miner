#include <iostream>
#include "terminal.hpp"

void onExit() {
    printcf(YELLOW, "\n\nExiting Miner...\n");
}

void sigterm(int signum) {
    printcf(YELLOW, "\n\nTerminate signal (", signum, ") received.\n");
    exit(0);
}

void sigint(int signum) {
    printcf(YELLOW, "\n\nInterrupt signal (", signum, ") received.\n");
    exit(0);
}

int main() {
    std::atexit(onExit);
    signal(SIGTERM, sigterm);
    signal(SIGINT, sigint);

    if (initialConfigurations() > 0) { return 1; }

    return 0;
}