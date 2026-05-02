cmake_minimum_required(VERSION 3.26)
project(hello C CXX)

find_package(SDL3 REQUIRED)

add_executable(engine)

target_sources(engine
PRIVATE
    src/engine.c
)

target_link_libraries(engine SDL3::SDL3)

target_compile_options(engine PRIVATE
    $<$<CONFIG:Release>:-O3 -march=native>
)
