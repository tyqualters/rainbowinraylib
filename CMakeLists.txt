cmake_minimum_required(VERSION 3.28)
project(rainbowraylib)

set(CMAKE_C_STANDARD 11)

add_executable(rainbowraylib main.c
        raygui.h)

find_package(raylib REQUIRED)
target_link_libraries(rainbowraylib PRIVATE raylib -lm)