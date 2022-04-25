cmake_minimum_required(VERSION 3.20)
project(Codigo)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS system window graphics)


add_executable(Codigo main.cpp Interfaz/Ventana.h Interfaz/Ventana.cpp Interfaz/Componentes.h Interfaz/Componentes.cpp)
target_link_libraries(Codigo sfml-system sfml-window sfml-graphics -static)