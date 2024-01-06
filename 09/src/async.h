#ifndef HOMETASK_09_MULTITHREADING_BULK_ASYNC_H
#define HOMETASK_09_MULTITHREADING_BULK_ASYNC_H

#include <memory>
#include <map>

#include "multithreading_bulk.h"

class Async {
private:
    std::map<void*, std::shared_ptr<Bulk>> func_to_object;
public:
    void *connect(std::size_t block_size);

    void receive(void *handle, const char *data);

    void disconnect(void *handle);
};


#endif //HOMETASK_09_MULTITHREADING_BULK_ASYNC_H
