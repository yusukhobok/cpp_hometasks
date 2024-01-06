#ifndef HOMETASK_09_MULTITHREADING_BULK_COMMAND_PROCESSOR_H
#define HOMETASK_09_MULTITHREADING_BULK_COMMAND_PROCESSOR_H

#include <iostream>
#include <sstream>

#include "command_parser.hpp"
#include "command_printer.hpp"
#include "command_analyzer.hpp"
#include "model.hpp"
#include "command_processor.hpp"


class CommandProcessor {
private:
    CommandParser command_parser;
    ConsoleCommandPrinter console_command_printer;
    FileCommandPrinter first_file_command_printer;
    FileCommandPrinter second_file_command_printer;
    CommandAnalyzer command_analyzer;
    QueueData console_queue_data;
    QueueData file_queue_data;
    bool is_input_finished;
    std::thread console_thread;
    std::thread first_file_thread;
    std::thread second_file_thread;

public:
    explicit CommandProcessor(int size) :
            first_file_command_printer(1),
            second_file_command_printer(2),
            command_analyzer(size),
            is_input_finished(false),
            console_thread(&ConsoleCommandPrinter::print, &console_command_printer, std::ref(console_queue_data),
                           std::ref(is_input_finished)),
            first_file_thread(&FileCommandPrinter::print, &first_file_command_printer, std::ref(file_queue_data),
                              std::ref(is_input_finished)),
            second_file_thread(&FileCommandPrinter::print, &second_file_command_printer, std::ref(file_queue_data),
                               std::ref(is_input_finished)) {};

    ~CommandProcessor() {
        auto command_block = command_analyzer.get_command_block();
        command_parser.push_command_block(command_block, file_queue_data, console_queue_data);
        is_input_finished = true;
        file_queue_data.condition_variable.notify_all();
        console_queue_data.condition_variable.notify_all();
        console_thread.join();
        first_file_thread.join();
        second_file_thread.join();
    }

    void receive_input(const std::string &str) {
        std::istringstream in(str);
        command_parser.parse(in, command_analyzer, file_queue_data, console_queue_data);
    };
};

#endif //HOMETASK_09_MULTITHREADING_BULK_COMMAND_PROCESSOR_H
