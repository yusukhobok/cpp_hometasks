cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(editor VERSION ${PROJECT_VERSION})

#add_library(bulk STATIC src/bulk.cpp)
#target_include_directories(bulk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_compile_options(bulk PRIVATE -Wall -Wextra -pedantic -Werror)

add_executable(editor_cli src/main.cpp src/editor.cpp)
#target_link_libraries(bulk_cli PUBLIC bulk)
target_compile_options(editor_cli PRIVATE -Wall -Wextra -pedantic -Werror)

set_target_properties(editor_cli PROPERTIES
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


add_executable(editor_test tests/editor_tests.cpp src/editor.cpp)
target_link_libraries(editor_test gtest gtest_main)
add_test(editor_test editor_test)


install(TARGETS editor_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()