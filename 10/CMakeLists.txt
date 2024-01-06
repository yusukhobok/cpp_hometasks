cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(network_bulk VERSION ${PROJECT_VERSION})

find_package(Boost COMPONENTS system REQUIRED)

add_executable(network_bulk_cli
        src/main.cpp
        src/command_processor.hpp
        src/command_parser.hpp
        src/command_printer.hpp
        src/command_analyzer.hpp
        src/model.hpp
        src/async_server.cpp
)
target_compile_options(network_bulk_cli PRIVATE -Wall -Wextra -pedantic)

set_target_properties(network_bulk_cli PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(network_bulk_cli PUBLIC Boost::system)



install(TARGETS network_bulk_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()
