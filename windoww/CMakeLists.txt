cmake_minimum_required(VERSION 3.23)
project(windoww)

set(CMAKE_CXX_STANDARD 11)
link_libraries(SDL2 SDL2_image SDL2_ttf)
add_executable(windoww main.cpp)
