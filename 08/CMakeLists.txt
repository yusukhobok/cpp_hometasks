cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(bayan VERSION ${PROJECT_VERSION})

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS program_options filesystem regex system REQUIRED)
set(Boost_USE_STATIC_LIBS ON)
include_directories(${Boost_INCLUDE_DIR})

add_library(bayan STATIC src/bayan.cpp)
target_include_directories(bayan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(bayan PRIVATE -Wall -Wextra -pedantic -Werror)

add_executable(bayan_cli src/main.cpp)
target_link_libraries(bayan_cli PUBLIC bayan ${Boost_LIBRARIES} Threads::Threads)
target_compile_options(bayan_cli PRIVATE -Wall -Wextra -pedantic -Werror)

set_target_properties(bayan_cli bayan PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        COMPILE_DEFINITIONS BOOST_ALL_DYN_LINK
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


add_executable(bayan_test tests/bayan_tests.cpp)
target_link_libraries(bayan_test bayan ${Boost_LIBRARIES} gtest gtest_main)
set_target_properties(bayan_test PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        COMPILE_DEFINITIONS BOOST_ALL_DYN_LINK
)
add_test(bayan_test bayan_test)


install(TARGETS bayan_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()