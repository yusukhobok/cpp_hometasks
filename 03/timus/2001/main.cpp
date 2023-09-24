#include <iostream>

// https://acm.timus.ru/problem.aspx?space=1&num=2001

int main() {
    int a1, b1, a2, b2, a3, b3;
    std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    std::cout << a1 - a3 << " " << b1 - b2;
}