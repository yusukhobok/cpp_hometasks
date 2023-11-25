#include <gtest/gtest.h>
#include "src/bulk.h"

TEST(
        IpFilterTest,
        given_two_ip_addresses__when_compare__then_correct_result_returned
) {
    Bulk bulk(1, 2);

    ASSERT_EQ(bulk.x, 1);
}
