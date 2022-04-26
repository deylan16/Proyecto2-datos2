cmake_minimum_required(VERSION 3.20)
project(Codigo)

set(CMAKE_CXX_STANDARD 14)
set(SFML_INCLUDE_DIR "/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/SFML-2.5.1/lib")
set(SFML_DIR "/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()


add_executable(Codigo main.cpp Interfaz/Ventana.h Interfaz/Ventana.cpp Interfaz/Componentes.h Interfaz/Componentes.cpp "lista doblemente enlazada/Lista_doble.cpp" "lista doblemente enlazada/Lista_doble.h" "lista doblemente enlazada/Nodo.cpp" "lista doblemente enlazada/Nodo.h" "lista doblemente enlazada/Matriz.cpp" "lista doblemente enlazada/Matriz.h" "lista doblemente enlazada/Nodo_matriz.cpp" "lista doblemente enlazada/Nodo_matriz.h" "lista doblemente enlazada/Lista_pixeles.cpp" "lista doblemente enlazada/Lista_pixeles.h" "lista doblemente enlazada/Nodo_pixel.cpp" "lista doblemente enlazada/Nodo_pixel.h")
target_link_libraries (Codigo sfml-graphics sfml-window sfml-system)