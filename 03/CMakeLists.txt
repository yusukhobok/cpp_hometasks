cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(allocator VERSION ${PROJECT_VERSION})

add_library(allocator_lib INTERFACE src/custom_allocator.hpp)

add_library(list_lib INTERFACE src/custom_container.hpp)

add_executable(allocator_cli src/main.cpp)
target_link_libraries(allocator_cli PUBLIC list_lib allocator_lib)
target_compile_options(allocator_cli PRIVATE -Wall -Wextra -pedantic -Werror)

set_target_properties(allocator_cli allocator_lib list_lib PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)