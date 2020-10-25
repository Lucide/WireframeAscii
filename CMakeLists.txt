cmake_minimum_required(VERSION 3.17)

project(WireframeAscii
        VERSION 1
        DESCRIPTION "a tiny ascii 3d engine"
        LANGUAGES C)

add_executable(core 73.c)
target_link_libraries(core
        PRIVATE m)
set_target_properties(core
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "urb")
add_executable(launcher launcher.c)
add_dependencies(launcher core)