cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

add_library(ip_filter STATIC src/ip_filter.cpp src/ip_address.cpp)
target_include_directories(ip_filter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(ip_filter PRIVATE -Wall -Wextra -pedantic -Werror)

add_executable(ip_filter_cli src/main.cpp)
target_link_libraries(ip_filter_cli PUBLIC ip_filter)
target_compile_options(ip_filter_cli PRIVATE -Wall -Wextra -pedantic -Werror)

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set_target_properties(ip_filter_cli ip_filter PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)


include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main gmock_main)


add_executable(ip_filter_test tests/ip_filter_tests.cpp)
target_link_libraries(ip_filter_test ip_filter gtest gtest_main)
add_test(ip_filter_test ip_filter_test)