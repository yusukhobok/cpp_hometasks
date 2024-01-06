#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "multithreading_bulk.h"


std::string BasePrinter::get_command_string(std::vector<std::string> commands) {
    std::ostringstream commands_to_print;
    commands_to_print << "bulk: ";
    for (const auto &command: commands) {
        if (&command != &commands[0]) {
            commands_to_print << ", ";
        }
        commands_to_print << command;
    }
    return commands_to_print.str();
}

void ConsolePrinter::print(std::queue<CommandBlock>& command_queue, std::mutex& mut) {
    while (!command_queue.empty()) {
        std::lock_guard<std::mutex> guard{mut};
        if (command_queue.empty()) {
            continue;
        }
        std::vector<std::string> commands = command_queue.front().commands;
        command_queue.pop();

        if (commands.empty()) {
            return;
        }

        std::cout << get_command_string(commands) << std::endl;
    }
}

void FilePrinter::print(std::queue<CommandBlock>& command_queue, std::mutex& mut) {
    while (!command_queue.empty()) {
        std::lock_guard<std::mutex> guard{mut};
        if (command_queue.empty()) {
            continue;
        }
        auto commands = command_queue.front().commands;
        auto timestamp = command_queue.front().timestamp;
        command_queue.pop();

        if (commands.empty()) {
            return;
        }
        std::string filename = "bulk" + std::to_string(timestamp) + ".log";
        std::ofstream f;
        f.open(filename);
        f << get_command_string(commands);
        f.close();
    }
}


Bulk::Bulk(size_t block_size): block_size(block_size) {}


void Bulk::process(const std::string& command, std::time_t timestamp) {
    if (command == "{") {
        if (open_bracket_count == 0) {
            print_current_commands();
        }
        ++open_bracket_count;
    } else if (command == "}") {
        if (open_bracket_count > 0) {
            ++close_bracket_count;
            if (open_bracket_count == close_bracket_count) {
                print_current_commands();
                open_bracket_count = 0;
                close_bracket_count = 0;
            }
        }
    } else {
        add_command(command, timestamp);
        if (current_block.commands.size() == block_size && open_bracket_count == 0) {
            print_current_commands();
        }
    }
}

void Bulk::add_command(const std::string& command, std::time_t timestamp) {
    if (current_block.commands.empty()) {
        current_block.timestamp = timestamp;
    }
    current_block.commands.push_back(command);
}


void Bulk::print_current_commands() {
    if (current_block.commands.empty()) {
        return;
    }
    std::ostringstream commands_to_print;
    commands_to_print << "bulk: ";
    for (const auto &command: current_block.commands) {
        if (&command != &current_block.commands[0]) {
            commands_to_print << ", ";
        }
        commands_to_print << command;
    }
    print_current_commands_to_console(commands_to_print.str());
    print_current_commands_to_file(commands_to_print.str(), current_block.timestamp);
    current_block.commands.clear();
}


void Bulk::print_current_commands_to_console(const std::string& commands_to_print) {
    std::cout << commands_to_print << std::endl;
}


void Bulk::print_current_commands_to_file(const std::string& commands_to_print, std::time_t timestamp) {
    std::string filename = "bulk" + std::to_string(timestamp) + ".log";
    std::ofstream f;
    f.open(filename);
    f << commands_to_print;
    f.close();
}


size_t Bulk::get_command_size() const {
    return current_block.commands.size();
}