#ifndef HOMETASK_09_MULTITHREADING_BULK_H
#define HOMETASK_09_MULTITHREADING_BULK_H

#include <string>
#include <vector>
#include <chrono>

struct CommandBlock {
    std::vector<std::string> commands{};
    std::time_t timestamp = 0;
};

class Bulk {
    size_t block_size;
    int open_bracket_count = 0;
    int close_bracket_count = 0;
    CommandBlock current_block;

    void add_command(const std::string& command, std::time_t timestamp);
    void print_current_commands();
    static void print_current_commands_to_console(const std::string&  commands_to_print);
    static void print_current_commands_to_file(const std::string&  commands_to_print, std::time_t timestamp);

public:
    explicit Bulk(size_t block_size);
    void process(const std::string& command, std::time_t timestamp);
    size_t get_command_size() const;
};

#endif //HOMETASK_09_MULTITHREADING_BULK_H
