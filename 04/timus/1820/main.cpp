#include <iostream>

// https://acm.timus.ru/problem.aspx?space=1&num=1820

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << 2 * (n / k) + (n % k != 0) + ((n % k > k / 2.0) || (n < k));
}
