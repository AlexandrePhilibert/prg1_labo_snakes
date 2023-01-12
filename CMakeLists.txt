cmake_minimum_required(VERSION 3.23)
project(prg1_labo_snakes)

set(CMAKE_CXX_STANDARD 20)

add_executable(prg1_labo_snakes main.cpp terrain.h terrain.cpp fenetre.h  fenetre.cpp saisie.h saisie.cpp annexe.cpp serpent.cpp serpent.h coordonnee.cpp coordonnee.h pomme.h pomme.cpp)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
    set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIR})
    target_link_libraries(prg1_labo_snakes ${SDL2_LIBRARY})
else()
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    target_link_libraries(prg1_labo_snakes ${SDL2_LIBRARIES})
endif()


