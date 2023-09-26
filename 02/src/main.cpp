#include <iostream>
#include <string>
#include <vector>
#include <optional>

#include "ip_filter.h"
#include "ip_address.h"


int main() {
    try {
        std::vector<std::vector<std::string>> source = read_source();
        std::vector<IpAddress> ip_pool = parse(source);
        auto sort = [](std::vector<IpAddress> &ip_pool) {
            std::sort(ip_pool.begin(), ip_pool.end());
        };
        sort(ip_pool);
        print_ip_pool(ip_pool);
        print_ip_pool(filter(ip_pool, 1));
        print_ip_pool(filter(ip_pool, 46, 70));
        print_ip_pool(filter(ip_pool, 46, 46, 46, 46, false));
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
