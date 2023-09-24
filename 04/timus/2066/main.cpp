#include <iostream>

// https://acm.timus.ru/problem.aspx?space=1&num=2066

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::min(a - b - c, a - b * c) << std::endl;
}
