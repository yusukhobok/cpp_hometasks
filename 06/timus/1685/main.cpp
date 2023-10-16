#include <iostream>
#include <string>

// https://acm.timus.ru/problem.aspx?space=1&num=1685

std::string process(std::string text) {
    if (text.empty()) {
        return "";
    }
    size_t first_len = (text.size() - 1) / 2;
    size_t second_len = text.size() - first_len - 1;
    std::string first_part = text.substr(1, first_len);
    std::string second_part = text.substr(1 + first_len, second_len);
    return process(first_part) + std::string(1, text[0]) + process(second_part);
}


int main() {
    std::string text;
    std::getline(std::cin, text);
    std::cout << process(text) << std::endl;
}
