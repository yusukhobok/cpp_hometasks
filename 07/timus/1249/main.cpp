#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
//#include<cstdio>

// https://acm.timus.ru/problem.aspx?space=1&num=1249
// 365690IY

using vb = std::vector<bool>;

vb read_line(int m) {
    vb current_line = vb(m, 0);
    for (int i = 0; i < m; ++i) {
        int value;
//        scanf("%d", &value);
        std::cin >> value;
        current_line[i] = value;
    }
    return current_line;
}

bool check(int m, const vb& previous_line, const vb& current_line) {
    int sum;
    for (int i = 0; i < m - 1; ++i) {
        sum = previous_line[i] + previous_line[i+1] + current_line[i] + current_line[i+1];
        if (sum == 3) {
            return false;
        }
    }
    return true;
}


int main() {
    int n, m;
    std::cin >> n >> m;
    bool should_continue = true;
    bool ok = true;

    if (n == 0) {
        should_continue = false;
    }

    vb current_line = read_line(m);
    vb previous_line;
    for (int i = 1; i < n; ++i) {
        previous_line = std::move(current_line);
        current_line = read_line(m);
        if (!should_continue) {
            continue;
        }
        if (!check(m, previous_line, current_line)) {
            should_continue = false;
            ok = false;
        }
    }

    if (ok) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
}
