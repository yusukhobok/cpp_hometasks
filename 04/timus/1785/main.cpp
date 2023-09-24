#include <iostream>

// https://acm.timus.ru/problem.aspx?space=1&num=1785

int main() {
    int n;
    std::cin >> n;
    if (n <= 4) {
        std::cout << "few";
    } else if (n <= 9) {
        std::cout << "several";
    } else if (n <= 19) {
        std::cout << "pack";
    } else if (n <= 49) {
        std::cout << "lots";
    } else if (n <= 99) {
        std::cout << "horde";
    } else if (n <= 249) {
        std::cout << "throng";
    } else if (n <= 499) {
        std::cout << "swarm";
    } else if (n <= 999) {
        std::cout << "zounds";
    } else {
        std::cout << "legion";
    }
}
