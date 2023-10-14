#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// https://acm.timus.ru/problem.aspx?space=1&num=2033
// 365690IY

struct Device {
    std::string name;
    int cost;
    size_t count;
};


void get_data(std::map<std::string, Device> &name_to_device) {
    std::string friend_name;
    std::string device_name;
    int cost;
    while (std::cin >> friend_name) {
        std::cin >> device_name;
        std::cin >> cost;
        if (name_to_device.find(device_name) == name_to_device.end()) {
            name_to_device.insert({device_name, Device{device_name, cost, 1}});
        } else {
            Device &current_device = name_to_device[device_name];
            ++current_device.count;
            if (current_device.cost > cost) {
                current_device.cost = cost;
            }
        }
    }
}

void print_data(const std::map<std::string, Device> &name_to_device) {
    std::cout << std::endl;
    for (const auto &el: name_to_device) {
        std::cout << el.first << "(" << el.second.cost << "," << el.second.count << ") ";
    }
    std::cout << std::endl;
}

std::string get_most_frequent_device(const std::map<std::string, Device> &name_to_device) {
    auto min_field_iterator = std::max_element(
            name_to_device.begin(),
            name_to_device.end(),
            [](const auto &lhs, const auto &rhs) {
                if (lhs.second.count != rhs.second.count) {
                    return lhs.second.count < rhs.second.count;
                }
                return lhs.second.cost > rhs.second.cost;
            }
    );
    auto maxFieldValue1 = min_field_iterator->second.name;
    return maxFieldValue1;
}

int main() {
    std::map<std::string, Device> name_to_device;
    get_data(name_to_device);
    auto most_frequent_device = get_most_frequent_device(name_to_device);
    std::cout << most_frequent_device;
}
