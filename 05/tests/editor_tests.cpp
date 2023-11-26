#include <gtest/gtest.h>
#include <chrono>
#include "../src/editor.h"

TEST(
        EditorTest,
        give_1__when_2__then_3
) {
    Editor editor(1, 2);

    ASSERT_EQ(editor.x, 1);
}
