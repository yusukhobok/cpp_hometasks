cmake_minimum_required(VERSION 3.10)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(allocator VERSION ${PROJECT_VERSION})

add_executable(allocator_cli src/main.cpp)
target_compile_options(allocator_cli PRIVATE -Wall -Wextra -pedantic)

set_target_properties(allocator_cli PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        ENABLE_EXPORTS 1
)

target_include_directories(allocator_cli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS allocator_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)