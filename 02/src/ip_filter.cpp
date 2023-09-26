#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>

#include "ip_address.hpp"


std::vector<std::string> split(const std::string &str, char d) {
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}


std::vector<std::vector<std::string>> read_source() {
    std::vector<std::vector<std::string>> source;
//    source.push_back({"113", "162", "145", "156"});
//    source.push_back({"1", "2", "3", "4"});
    for(std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> v = split(line, '\t');
        source.push_back(split(v.at(0), '.'));
    }
    return source;
}

IpAddress parse_ip_address(const std::vector<std::string> &line) {
    return IpAddress{
            .first=std::stoi(line[0]),
            .second=std::stoi(line[1]),
            .third=std::stoi(line[2]),
            .forth=std::stoi(line[3])
    };
}

std::vector<IpAddress> parse(const std::vector<std::vector<std::string>> &source) {
    std::vector<IpAddress> ip_pool;
    ip_pool.reserve(source.size());
    for (const auto &line: source) {
        ip_pool.push_back(parse_ip_address(line));
    }
    return ip_pool;
}

void print_ip_pool(std::vector<IpAddress> const &ip_pool) {
    for (const auto &ip: ip_pool) {
        std::cout << ip;
    }
}

void sort(std::vector<IpAddress> &ip_pool) {
    std::sort(ip_pool.begin(), ip_pool.end());
}

bool check(int number, std::optional<int> filter) {
    if (! filter.has_value()) {
        return true;
    }
    return filter.value() == number;
}

std::vector<IpAddress> filter(
        const std::vector<IpAddress> &ip_pool,
        std::optional<int> first=std::nullopt,
        std::optional<int> second=std::nullopt,
        std::optional<int> third=std::nullopt,
        std::optional<int> forth=std::nullopt,
        bool is_and_condition=true
) {
    std::vector<IpAddress> filtered_ip_pool;
    bool condition;
    for (const auto &ip: ip_pool) {
        if (is_and_condition) {
            condition = check(ip.first, first) && check(ip.second, second) && check(ip.third, third) && check(ip.forth, forth);
        } else {
            condition = check(ip.first, first) || check(ip.second, second) || check(ip.third, third) || check(ip.forth, forth);
        }
        if (condition) {
            filtered_ip_pool.push_back(ip);
        }
    }
    return filtered_ip_pool;
}

int main(int argc, char const *argv[]) {
    try {
        std::vector<std::vector<std::string>> source = read_source();
        std::vector<IpAddress> ip_pool = parse(source);
        sort(ip_pool);
        print_ip_pool(ip_pool);
        auto filtered_ip_pool = filter(ip_pool, 1);
        print_ip_pool(filtered_ip_pool);
        filtered_ip_pool = filter(ip_pool, 46, 70);
        print_ip_pool(filtered_ip_pool);
        filtered_ip_pool = filter(ip_pool, 46, 46, 46, 46, false);
        print_ip_pool(filtered_ip_pool);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
