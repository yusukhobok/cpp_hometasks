#include <gtest/gtest.h>
#include "../src/printer.hpp"

TEST(
        PrinterTests,
        given_int8_t_value__when_print_ip__then_function_called
) {
    print_ip( int8_t{-1} );
}
