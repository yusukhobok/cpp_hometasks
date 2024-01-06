#ifndef MULTITHREADING_BULK_MODEL_H
#define MULTITHREADING_BULK_MODEL_H

#include <vector>
#include <string>
#include <chrono>
#include <queue>
#include <condition_variable>
#include <mutex>

struct CommandBlock {
    std::vector<std::string> commands;
    std::time_t time_stamp;
};

struct QueueData {
    std::queue<CommandBlock> queue;
    std::condition_variable condition_variable;
    std::mutex mutex;
};

#endif //MULTITHREADING_BULK_MODEL_H
