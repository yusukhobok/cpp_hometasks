#ifndef HOMETASK_10_COMMAND_PRINTER_H
#define HOMETASK_10_COMMAND_PRINTER_H

#include <iostream>
#include <fstream>
#include "model.hpp"

class ICommandPrinter {
public:
    virtual ~ICommandPrinter() {};

    virtual void print(QueueData& queue_controller, bool& input_finished) = 0;

    std::string get_commands_to_print(const std::vector<std::string>& commands) {
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
};


class ConsoleCommandPrinter : public ICommandPrinter {
public:
    ConsoleCommandPrinter() = default;

    void print(QueueData& queue_controller, bool& input_finished) override {
        std::unique_lock<std::mutex> guard{queue_controller.mutex};
        queue_controller.condition_variable.wait(guard, [&queue_controller, &input_finished] {
            return (!queue_controller.queue.empty() || input_finished);
        });
        while (!queue_controller.queue.empty()) {
            if (queue_controller.queue.empty()) {
                continue;
            }
            std::vector<std::string> commands = queue_controller.queue.front().commands;
            queue_controller.queue.pop();
            std::string commands_to_print = get_commands_to_print(commands);
            std::cout << commands_to_print << std::endl;
        }
        guard.unlock();
        if (input_finished) {
            return;
        }
        print(queue_controller, input_finished);
    }
};


class FileCommandPrinter : public ICommandPrinter {
private:
    int postfix;
public:
    FileCommandPrinter(int postfix): postfix(postfix) {};

    void print(QueueData& queue_controller, bool& input_finished) override {
        std::unique_lock<std::mutex> guard{queue_controller.mutex};
        queue_controller.condition_variable.wait(guard, [&queue_controller, &input_finished] {
            return (!queue_controller.queue.empty() || input_finished);
        });
        while (!queue_controller.queue.empty()) {
            if (queue_controller.queue.empty()) {
                continue;
            }
            std::vector<std::string> commands = queue_controller.queue.front().commands;
            std::time_t time_stamp = queue_controller.queue.front().time_stamp;
            queue_controller.queue.pop();
            std::string commands_to_print = get_commands_to_print(commands);
            std::string filename = "bulk" + std::to_string(time_stamp) + "_" + std::to_string(postfix) + ".log";
            std::ofstream f;
            f.open(filename);
            f << commands_to_print;
            f.close();
        }
        guard.unlock();
        if (input_finished) {
            return;
        }
        print(queue_controller, input_finished);
    }
};

#endif //HOMETASK_10_COMMAND_PRINTER_H
