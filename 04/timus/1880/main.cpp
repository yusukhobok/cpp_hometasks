// https://acm.timus.ru/problem.aspx?space=1&num=1880

#include <iostream>
#include <unordered_map>

void fill_map(std::unordered_map<int, int>& map) {
    int n, value;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        if (map.find(value) != map.end()) {
            map[value] += 1;
        }
        else {
            map[value] = 1;
        }
    }
}

int main() {
    std::unordered_map<int, int> map;

    for (int i = 0; i < 3; ++i) {
        fill_map(map);
    }

    int sum = 0;
    for (const auto& [key, value] : map) {
        if (value == 3) {
            ++sum;
        }
    }
    std::cout << sum;

    return 0;
}

