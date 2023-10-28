#include <iostream>
#include<cstdio>

// https://acm.timus.ru/problem.aspx?space=1&num=1249
// 365690IY


int main() {

    int n, m, value, sum;
    scanf("%d %d", &n, &m);
    bool ok = true;
    if (n != 0) {

        bool current_line[3001];
        for (int i = 0; i < m; ++i) {
            scanf("%d", &value);
            current_line[i] = value;
        }

        bool previous_line[3001];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &value);
                previous_line[j] = current_line[j];
                current_line[j] = value;
                if (j == 0) {
                    continue;
                }
                sum = previous_line[j] + previous_line[j - 1] + current_line[j] + current_line[j-1];
                if (sum == 3) {
                    ok = false;
                    goto label;
                }
            }
        }
    }

    label:
    if (ok) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
}
