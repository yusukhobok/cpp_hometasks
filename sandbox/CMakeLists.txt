cmake_minimum_required(VERSION 3.26)
project(sandbox)

set(CMAKE_CXX_STANDARD 14)

add_executable(sandbox
        main.cpp
        example.cpp)
target_compile_options(sandbox PRIVATE -Wall -Wextra -pedantic -Werror)

set_target_properties(sandbox PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)