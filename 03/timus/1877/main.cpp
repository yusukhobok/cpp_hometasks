#include <iostream>

// https://acm.timus.ru/problem.aspx?space=1&num=1877

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a % 2 == 0 or b % 2 != 0) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}