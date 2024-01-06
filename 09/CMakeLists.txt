cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(multithreading_bulk VERSION ${PROJECT_VERSION})

add_library(multithreading_bulk STATIC src/multithreading_bulk.cpp)
target_include_directories(multithreading_bulk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_compile_options(multithreading_bulk PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(multithreading_bulk PRIVATE -Wall -Wextra -pedantic)

add_executable(multithreading_bulk_cli src/main.cpp src/async.cpp)
target_link_libraries(multithreading_bulk_cli PUBLIC multithreading_bulk)
#target_compile_options(multithreading_bulk_cli PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(multithreading_bulk_cli PRIVATE -Wall -Wextra -pedantic)

set_target_properties(multithreading_bulk_cli multithreading_bulk PROPERTIES
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


add_executable(multithreading_bulk_test tests/multithreading_bulk_tests.cpp)
target_link_libraries(multithreading_bulk_test multithreading_bulk gtest gtest_main)
add_test(multithreading_bulk_test multithreading_bulk_test)


install(TARGETS multithreading_bulk_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()