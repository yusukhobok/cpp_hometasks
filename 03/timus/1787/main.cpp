    #include <iostream>
    #include <vector>

    // https://acm.timus.ru/problem.aspx?space=1&num=1787

    int main() {
        int k, n;
        std::vector<int> a;

        std::cin >> k >> n;
        a.reserve(n);
        for (size_t i = 0; i < n; ++i) {
            int el;
            std::cin >> el;
            a.push_back(el);
        }

        int left_current = 0;
        for (const int& el : a) {
            left_current += el - k;
            if (left_current < 0) {
                left_current = 0;
            }
        }
        std::cout << left_current;
    }