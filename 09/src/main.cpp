#include <iostream>
#include <string>
#include <chrono>

#include "multithreading_bulk.h"
#include "async.h"

int main(int argc, char* argv[]) {
    std::size_t block_size = 3;
    auto async = Async();
    auto first_bulk = async.connect(block_size);
    auto second_bulk = async.connect(block_size);
    async.receive(first_bulk, "cmd1\ncmd2\ncmd3\ncmd4\ncmd5");
    async.receive(second_bulk, "1");
    async.disconnect(first_bulk);
    async.disconnect(second_bulk);

//    size_t block_size = argc > 1 ? atoi(argv[1]) : 3;
//    Bulk bulk{block_size};
//
//    std::string command;
//    auto now = std::chrono::system_clock::now();
//    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
//    while (getline(std::cin, command)) {
//        bulk.process(command, timestamp);
//        ++timestamp;
//    }
}