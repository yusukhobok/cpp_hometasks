#include <map>
#include <memory>

#include "async.h"

namespace async {
    std::map<handle_t, std::shared_ptr<CommandProcessor>> func_to_parser;

    handle_t connect(std::size_t bulk) {
        auto command_parser_ptr = std::make_shared<CommandProcessor>(bulk);
        func_to_parser.emplace(std::make_pair(command_parser_ptr.get(), command_parser_ptr));
        return command_parser_ptr.get();
    }

    void receive(handle_t handle, const char *data, std::size_t size) {
        std::string in = data;
        auto ptr = func_to_parser.find(handle);
        if (ptr != func_to_parser.end()) {
            ptr->second->receive_input(in);
        }
    }

    void disconnect(handle_t handle) {
        auto ptr = func_to_parser.find(handle);
        if (ptr != func_to_parser.end()) {
            func_to_parser.erase(ptr);
        }
    }
}
