#include <iostream>
#include <string>
#include <regex>

// https://acm.timus.ru/problem.aspx?space=1&num=1612

std::string read_message() {
    std::string message;
    std::string line;
    while (std::getline(std::cin, line))
    {
        message += line + "\n";
    }
    return message;
}

int find_word_count(const std::string& message, const std::string& word) {
    std::string regex_pattern = "\\b" + word + "\\b";
    std::regex word_regex(regex_pattern);

    std::sregex_iterator it(message.begin(), message.end(), word_regex);
    std::sregex_iterator end;
    int count = 0;
    while (it != end) {
        std::smatch match = *it;
        ++it;
        ++count;
    }

    return count;
}

int main() {
    auto message = read_message();
    int trolleybus_count = find_word_count(message, "trolleybus");
    int tram_count = find_word_count(message, "tram");
    if (trolleybus_count > tram_count) {
        std::cout << "Trolleybus driver";
    }
    else if (tram_count > trolleybus_count) {
        std::cout << "Tram driver";
    }
    else {
        std::cout << "Bus driver";
    }
}
