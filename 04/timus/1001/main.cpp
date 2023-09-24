#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

// https://acm.timus.ru/problem.aspx?space=1&num=1001

int main() {
    std::vector<long long> data;
    long long val;
    while (std::cin >> val) {
        data.push_back(val);
    }

    std::reverse(data.begin(), data.end());

    for (const long long& num : data) {
        std::cout << std::fixed << std::setprecision(4) << std::sqrt(num) << std::endl;
    }
}
