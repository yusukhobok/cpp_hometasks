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


include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main gmock_main)


add_executable(allocator_test tests/allocator_tests.cpp)
target_link_libraries(allocator_test allocator_lib list_lib gtest gtest_main)
add_test(allocator_test allocator_test)


install(TARGETS allocator_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()