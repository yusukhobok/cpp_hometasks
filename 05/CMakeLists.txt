cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(editor VERSION ${PROJECT_VERSION})

add_executable(editor_cli
        src/main.cpp
        src/feature.cpp
        src/circle.cpp
        src/rectangle.cpp
        src/model.cpp
        src/view.cpp
        src/controller.cpp
)
target_compile_options(editor_cli PRIVATE -Wall -Wextra -pedantic -Werror)

set_target_properties(editor_cli PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)


install(TARGETS editor_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()