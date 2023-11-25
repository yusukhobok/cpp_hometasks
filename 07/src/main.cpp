#include <iostream>
#include <string>
#include <chrono>
#include "bulk.h"

int main(int argc, char* argv[]) {
    size_t block_size = argc > 1 ? atoi(argv[1]) : 3;
    Bulk bulk{block_size};

    std::string command;
    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
    while (getline(std::cin, command)) {
        bulk.process(command, timestamp);
        ++timestamp;
    }
}