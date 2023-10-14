#include <iostream>
#include <fmt/format.h>

int main() {
    std::cout << fmt::format("Hello, {}!", "world") << std::endl;
}