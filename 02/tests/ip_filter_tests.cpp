#include <gtest/gtest.h>
#include "src/ip_address.h"
#include "src/ip_filter.h"

TEST(
        MyTest,
        given
) {
    auto ip1 = IpAddress{.first=1, .second=10, .third=1, .forth=1};
    auto ip2 = IpAddress{.first=1, .second=2, .third=1, .forth=1};

    ASSERT_TRUE(ip2 < ip1);
}


TEST(
        MyTest,
        given2
) {
    auto ip1 = IpAddress{.first=1, .second=10, .third=1, .forth=1};
    auto ip2 = IpAddress{.first=1, .second=2, .third=1, .forth=1};
    std::vector<IpAddress> ip_pool{ip1, ip2};
    print_ip_pool(ip_pool);

    ASSERT_EQ(ip_pool.size(), 2);
}