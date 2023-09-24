#include <iostream>
#include <string>

// https://acm.timus.ru/problem.aspx?space=1&num=2100

bool endsWith(std::string const &str, std::string const &suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.rfind(suffix) == str.size() - suffix.size();
}

int main() {
    int n;
    std::cin >> n;

    std::string name;
    int count = n + 2;
    std::string suffix = "+one";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> name;
        if (endsWith(name, suffix)) {
            count += 1;
        }
    }
    if (count == 13) {
        count += 1;
    }
    std::cout << count * 100;
}
