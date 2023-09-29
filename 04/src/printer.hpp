#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>
#include <list>
#include <tuple>
#include <type_traits>
#include <vector>


void print_ip(const std::string &ip) {
    std::cout << ip << std::endl;
}

template<typename T>
std::enable_if_t<std::is_integral_v<T>, void>
print_ip(const T &ip) {
    const auto byte_number = reinterpret_cast<const std::byte *>(&ip);
    for (auto i = static_cast<int>(sizeof(ip) - 1); i >= 0; --i) {
        std::cout << static_cast<int>(byte_number[i]);
        if (i != 0) {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

template<typename T>
std::enable_if_t<
        std::is_same_v<T, std::vector<typename T::value_type>> || std::is_same_v<T, std::list<typename T::value_type>>
>
print_ip(const T &ip) {
    for (const auto &element : ip) {
        std::cout << element;
        if (ip.back() != element) {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

#endif //PRINTER_HPP
