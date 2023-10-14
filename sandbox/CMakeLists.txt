cmake_minimum_required(VERSION 3.20)
project(sandbox)

#set(CMAKE_CXX_STANDARD 14)

find_package(fmt)

add_executable(sandbox
        main.cpp)
#target_compile_options(sandbox PRIVATE -Wall -Wextra -pedantic -Werror)

#set_target_properties(sandbox PROPERTIES
#        CXX_STANDARD 20
#        CXX_STANDARD_REQUIRED ON
#)

target_link_libraries(sandbox fmt::fmt)