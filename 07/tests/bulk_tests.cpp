#include <gtest/gtest.h>
#include <chrono>
#include "src/bulk.h"

TEST(
        BulkTest,
        given_one_command__when_process_then_one_command_left
) {
    Bulk bulk(3);
    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

    bulk.process("cmd1", timestamp);

    ASSERT_EQ(bulk.get_command_size(), 1);
}


TEST(
        BulkTest,
        given_four_commands__when_process_then_one_command_left
) {
    Bulk bulk(3);
    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

    bulk.process("cmd1", timestamp);
    bulk.process("cmd2", timestamp);
    bulk.process("cmd3", timestamp);
    bulk.process("cmd4", timestamp);

    ASSERT_EQ(bulk.get_command_size(), 1);
}


TEST(
        BulkTest,
        given_two_commands_after_open_bracket__when_process_then_one_command_left
) {
    Bulk bulk(3);
    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

    bulk.process("cmd1", timestamp);
    bulk.process("cmd2", timestamp);
    bulk.process("{", timestamp);
    bulk.process("cmd3", timestamp);
    bulk.process("cmd4", timestamp);

    ASSERT_EQ(bulk.get_command_size(), 2);
}
