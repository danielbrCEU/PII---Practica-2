cmake_minimum_required(VERSION 3.20)
project(ConvexHull LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Intentar primero SFML instalado en el sistema; si no, descargarlo
find_package(SFML 3 COMPONENTS Graphics Window System QUIET)

if(NOT SFML_FOUND)
    message(STATUS "SFML no encontrado en el sistema, descargandolo con FetchContent...")
    include(FetchContent)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
    )
    set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(SFML)
endif()

add_executable(practica_2
    src/main.cpp
    src/ventana.cpp
    src/Geometria.cpp
    src/algoritmos/MergeSort.cpp
    src/algoritmos/Graham.cpp
)

target_link_libraries(practica_2 PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

# Configuracion especifica por plataforma
if(WIN32)
    # En Windows, copiar las DLLs de SFML al directorio del ejecutable
    if(TARGET SFML::Graphics AND BUILD_SHARED_LIBS)
        add_custom_command(TARGET practica_2 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:SFML::Graphics>
                $<TARGET_FILE:SFML::Window>
                $<TARGET_FILE:SFML::System>
                $<TARGET_FILE_DIR:practica_2>
        )
    endif()
    # Evitar consola en Windows para apps graficas (opcional)
    # set_target_properties(practica_2 PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
