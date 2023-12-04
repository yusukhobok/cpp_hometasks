#ifndef HOMETASK_02_IP_FILTER_H
#define HOMETASK_02_IP_FILTER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>

#include "ip_address.h"


std::vector<std::string> split(const std::string &str, char d);

std::vector<std::vector<std::string>> read_source();

IpAddress parse_ip_address(const std::vector<std::string> &line);

std::vector<IpAddress> parse(const std::vector<std::vector<std::string>> &source);

void print_ip_pool(std::vector<IpAddress> const &ip_pool);

bool check(int number, std::optional<int> filter);

std::vector<IpAddress> filter(
        const std::vector<IpAddress> &ip_pool,
        std::optional<int> first=std::nullopt,
        std::optional<int> second=std::nullopt,
        std::optional<int> third=std::nullopt,
        std::optional<int> forth=std::nullopt,
        bool is_and_condition=true
);


#endif //HOMETASK_02_IP_FILTER_H
