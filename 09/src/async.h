#ifndef HOMETASK_09_MULTITHREADING_BULK_ASYNC_H
#define HOMETASK_09_MULTITHREADING_BULK_ASYNC_H

#include <cstddef>
#include "command_processor.hpp"

namespace async {

    using handle_t = void *;

    handle_t connect(std::size_t bulk);
    void receive(handle_t handle, const char *data, std::size_t size);
    void disconnect(handle_t handle);

}

#endif //HOMETASK_09_MULTITHREADING_BULK_ASYNC_H
