cmake_minimum_required(VERSION 3.20)
project(ConvexHull LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        3.0.0
)
FetchContent_MakeAvailable(SFML)

add_executable(practica_2
    src/main.cpp
)

target_link_libraries(practica_2 PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
