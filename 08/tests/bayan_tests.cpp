#include <gtest/gtest.h>
#include "src/bayan.h"

TEST(
        BayanTest,
        given_1__when_2__then_3
) {
    Example e(1, 2);

    ASSERT_EQ(e.x, 1);
}
