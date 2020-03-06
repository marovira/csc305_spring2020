cmake_minimum_required(VERSION 3.12)
project(gl_tester)

include(FetchContent)
FetchContent_Declare(
    atlas
    GIT_REPOSITORY https://github.com/marovira/atlas.git)
FetchContent_Populate(atlas)
add_subdirectory(${atlas_SOURCE_DIR} ${atlas_BINARY_DIR})

add_executable(gl_tester "${PROJECT_SOURCE_DIR}/main.cpp")
target_link_libraries(gl_tester PUBLIC atlas::atlas)
