#include <memory>
#include <map>
#include <chrono>

#include "async.h"


void* Async::connect(std::size_t block_size) {
    auto bulk_pointer = std::make_shared<Bulk>(block_size);
    func_to_object.emplace(std::make_pair(bulk_pointer.get(), bulk_pointer));
    return bulk_pointer.get();
}


void Async::receive(void* handle, const char *data) {
    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
    std::string command = data;
    auto bulk_pointer = func_to_object.find(handle);
    if (bulk_pointer != func_to_object.end()) {
        bulk_pointer->second->process(command, timestamp);
    }
}


void Async::disconnect(void* handle) {
    auto bulk_pointer = func_to_object.find(handle);
    if (bulk_pointer != func_to_object.end()) {
        func_to_object.erase(bulk_pointer);
    }
}


