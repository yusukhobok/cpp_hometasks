#include <gtest/gtest.h>
#include "src/ip_address.h"
#include "src/ip_filter.h"

TEST(
        IpFilterTest,
        given_two_ip_addresses__when_compare__then_correct_result_returned
) {
    auto ip1 = IpAddress{.first=1, .second=10, .third=1, .forth=1};
    auto ip2 = IpAddress{.first=1, .second=2, .third=1, .forth=1};

    ASSERT_TRUE(ip1 < ip2);
}


TEST(
        IpFilterTest,
        given_null_filter__when_check__then_true_returned
) {
    ASSERT_EQ(check(10, std::nullopt), true);
}


TEST(
        IpFilterTest,
        given_same_elements__when_check__then_true_returned
) {
    ASSERT_EQ(check(10, 10), true);
}


TEST(
        IpFilterTest,
        given_different_elements__when_check__then_false_returned
) {
    ASSERT_EQ(check(10, 5), false);
}


TEST(
        IpFilterTest,
        given_ip_pool__when_filter__then_correct_ip_addresses_remained
) {
    auto ip1 = IpAddress{.first=1, .second=10, .third=1, .forth=1};
    auto ip2 = IpAddress{.first=5, .second=2, .third=1, .forth=1};
    auto ip3 = IpAddress{.first=1, .second=2, .third=1, .forth=10};
    std::vector<IpAddress> ip_pool {ip1, ip2, ip3};

    auto filtered = filter(ip_pool, 1);

    ASSERT_EQ(filtered.size(), 2);
}
