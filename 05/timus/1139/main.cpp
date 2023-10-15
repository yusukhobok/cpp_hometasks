#include <iostream>

// https://acm.timus.ru/problem.aspx?space=1&num=1139

int find_divisor(int n, int m) {
    while (n != m) {
        if (n > m) {
            n -= m;
        } else {
            m -= n;
        }
    }
    return n;
}

int find(int n, int m) {
    if (n == m) {
        return n;
    }
    return m + n - find_divisor(n, m);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << find(n-1, m-1);
}
