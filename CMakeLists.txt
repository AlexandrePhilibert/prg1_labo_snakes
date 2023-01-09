cmake_minimum_required(VERSION 3.23)
project(prg1_labo_snakes)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(prg1_labo_snakes main.cpp fenetre.h fenetre.cpp)

target_link_libraries(prg1_labo_snakes ${SDL2_LIBRARIES})
