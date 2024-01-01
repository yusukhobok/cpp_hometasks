#ifndef HOMETASK_09_MULTITHREADING_BULK_H
#define HOMETASK_09_MULTITHREADING_BULK_H

#include <string>
#include <vector>
#include <chrono>

class Bulk {
    size_t block_size;
    int open_bracket_count = 0;
    int close_bracket_count = 0;
    std::vector<std::string> current_commands{};
    std::time_t current_timestamp = 0;

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
