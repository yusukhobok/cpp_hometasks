#include <gtest/gtest.h>
#include "../src/printer.h"

TEST(
        PrinterTests,
        given_int8_t_value__when_print_ip__then_function_called
) {
    print_ip( int8_t{-1} );
}

TEST(
        PrinterTests,
        given_int_16t_value__when_print_ip__then_function_called
) {
    print_ip( int16_t{0} );
}

TEST(
        PrinterTests,
        given_int32_t_value__when_print_ip__then_function_called
) {
    print_ip( int32_t{2130706433} );
}

TEST(
        PrinterTests,
        given_int64_t_value__when_print_ip__then_function_called
) {
    print_ip( int64_t{8875824491850138409} );
}

TEST(
        PrinterTests,
        given_string_value__when_print_ip__then_function_called
) {
    print_ip( std::string{"Hello, World!"} );
}

TEST(
        PrinterTests,
        given_vector_value__when_print_ip__then_function_called
) {
    print_ip( std::vector<int>{100, 200, 300, 400} );
}

TEST(
        PrinterTests,
        given_list_value__when_print_ip__then_function_called
) {
    print_ip( std::list<short>{400, 300, 200, 100} );
}
