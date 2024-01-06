#ifndef HOMETASK_10_COMMAND_ANALYZER_H
#define HOMETASK_10_COMMAND_ANALYZER_H

#include <string>
#include <vector>
#include <chrono>

#include "model.hpp"

class CommandAnalyzer {
private:
    size_t block_size;
    int open_bracket_count = 0;
    int close_bracket_count = 0;
    std::vector<std::string> current_commands{};
    std::time_t current_timestamp = 0;
    bool ready_to_print = false;

    void add_command(const std::string& command, std::time_t timestamp) {
        if (current_commands.empty()) {
            current_timestamp = timestamp;
        }
        current_commands.push_back(command);
    };

public:
    explicit CommandAnalyzer(size_t block_size): block_size(block_size) {};

    void process(const std::string& command, std::time_t timestamp) {
        ready_to_print = false;
        if (command == "{") {
            if (open_bracket_count == 0) {
                ready_to_print = true;
            }
            ++open_bracket_count;
        } else if (command == "}") {
            if (open_bracket_count > 0) {
                ++close_bracket_count;
                if (open_bracket_count == close_bracket_count) {
                    ready_to_print = true;
                    open_bracket_count = 0;
                    close_bracket_count = 0;
                }
            }
        } else {
            add_command(command, timestamp);
            if (current_commands.size() == block_size && open_bracket_count == 0) {
                ready_to_print = true;
            }
        }
    };

    [[nodiscard]] CommandBlock get_command_block() {
        return CommandBlock{
            .commands=current_commands,
            .time_stamp=current_timestamp
        };
    }

    void clear_current_commands() {
        current_commands.clear();
    }

    bool is_ready_to_print() {
        return ready_to_print;
    }
};

#endif //HOMETASK_10_COMMAND_ANALYZER_H
