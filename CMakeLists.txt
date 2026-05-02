cmake_minimum_required(VERSION 3.26)
project(hello C CXX)

find_package(SDL3 REQUIRED)

add_executable(engine)

target_sources(engine
PRIVATE
    src/engine.c
	src/fastmath.c
)

target_include_directories(engine
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(engine PRIVATE SDL3::SDL3)

target_compile_options(engine PRIVATE
    $<$<CONFIG:Release>:-O3 -march=native>
)
