#include <iostream>
#include <vector>
#include<cstdio>
#include <chrono>

// https://acm.timus.ru/problem.aspx?space=1&num=1249
// 365690IY

using vb = std::vector<bool>;

using milli = std::chrono::milliseconds;


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    int n, m, value, sum;
    std::cin >> n >> m;
    bool ok = true;
    if (n != 0) {

        vb current_line = vb(m, 0);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &value);
            current_line[i] = value;
        }

        vb previous_line;
        for (int i = 1; i < n; ++i) {
            previous_line = current_line;
            for (int j = 0; j < m; ++j) {
                scanf("%d", &value);
                current_line[j] = value;
                if (j == 0) {
                    continue;
                }
                sum = previous_line[j] + previous_line[j - 1] + current_line[j] + current_line[j - 1];
                if (sum == 3) {
                    ok = false;
                }
            }
        }
    }

    if (ok) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }


    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "\ntook "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";
}
