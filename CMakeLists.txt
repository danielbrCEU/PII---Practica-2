cmake_minimum_required(VERSION 3.20)
project(ConvexHull LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(practica_2
    src/main.cpp
    src/algoritmos/MergeSort.cpp
    src/algoritmos/Graham.cpp
)

target_link_libraries(practica_2 PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
