#ifndef PRINTER_HPP
#define PRINTER_HPP

/*!
	@file printer.h
	@brief Набор функций для печати условного IP-адреса
*/


#include <list>
#include <type_traits>
#include <vector>
#include <iostream>


/*!
	@brief Тривиальная реализация функции print_ip
	@param ip Ссылка на строковое представление ip-адреса.
*/
void print_ip(const std::string &ip) {
    std::cout << ip << std::endl;
}


/*!
	@brief Реализация функции print_ip, принимающая целочисленный ip-адрес
	@param ip Ссылка на целочисленное представление ip-адреса.
*/
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


/*!
	@brief Реализация функции print_ip, принимающая целочисленный ip-адрес
	@param ip Ссылка на представление ip-адреса в виде контейнера.
*/
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

//void print_ip(const std::string &ip);
//
//template<typename T>
//std::enable_if_t<std::is_integral_v<T>, void>
//print_ip(const T &ip);
//
//template<typename T>
//std::enable_if_t<
//        std::is_same_v<T, std::vector<typename T::value_type>> || std::is_same_v<T, std::list<typename T::value_type>>
//>
//print_ip(const T &ip);


#endif //PRINTER_HPP
