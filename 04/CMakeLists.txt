cmake_minimum_required(VERSION 3.10)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(printer VERSION ${PROJECT_VERSION})

add_executable(printer_cli src/main.cpp)
target_compile_options(printer_cli PRIVATE -Wall -Wextra -pedantic -Werror)

set_target_properties(printer_cli PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        ENABLE_EXPORTS 1
)

target_include_directories(printer_cli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main gmock_main)

add_executable(printer_test tests/printer_tests.cpp)
target_link_libraries(printer_test printer_cli gtest gtest_main)
add_test(printer_test printer_test)

install(TARGETS printer_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()