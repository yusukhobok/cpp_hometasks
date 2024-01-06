#ifndef MULTITHREADING_BULK_COMMAND_PARSER_HPP
#define MULTITHREADING_BULK_COMMAND_PARSER_HPP

#include <iostream>
#include <chrono>
#include <thread>

#include "model.hpp"
#include "command_analyzer.hpp"

class CommandParser {
public:
    CommandParser() = default;

    void parse(std::istringstream& in, CommandAnalyzer& command_analyzer, QueueData& file_queue_data, QueueData& console_queue_data) {
        std::cin.rdbuf(in.rdbuf());
        for (std::string command; std::getline(in, command);) {
            if (command.empty()) {
                continue;
            }
            auto now = std::chrono::system_clock::now();
            std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
            command_analyzer.process(command, timestamp);
            if (command_analyzer.is_ready_to_print()) {
                auto command_block = command_analyzer.get_command_block();
                push_command_block(command_block, file_queue_data, console_queue_data);
                command_analyzer.clear_current_commands();
            }
        }
    }

    void push_command_block(CommandBlock& command_block, QueueData& file_queue_data, QueueData& console_queue_data) {
        file_queue_data.queue.push(command_block);
        file_queue_data.condition_variable.notify_all();
        console_queue_data.queue.push(command_block);
        console_queue_data.condition_variable.notify_all();
    }
};

#endif //MULTITHREADING_BULK_COMMAND_PARSER_HPP
