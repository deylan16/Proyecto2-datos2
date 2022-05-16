cmake_minimum_required(VERSION 3.20)
project(Codigo)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)



add_executable(Codigo main.cpp Interfaz/Ventana.h Interfaz/Ventana.cpp Interfaz/Componentes.h Interfaz/Componentes.cpp  BMP/Bmp.cpp BMP/Bmp.h "lista doblemente enlazada/Nodo.cpp" "lista doblemente enlazada/Nodo.h" "lista doblemente enlazada/Matriz.cpp" "lista doblemente enlazada/Matriz.h" "lista doblemente enlazada/Nodo_matriz.cpp" "lista doblemente enlazada/Nodo_matriz.h" "lista doblemente enlazada/Lista_pixeles.cpp" "lista doblemente enlazada/Lista_pixeles.h" "lista doblemente enlazada/Nodo_pixel.cpp" "lista doblemente enlazada/Nodo_pixel.h" "lista doblemente enlazada/Lista_Doble.cpp" "lista doblemente enlazada/Lista_Doble.h" Interfaz/Datos_juego.cpp Interfaz/Datos_juego.h Funcionalidades/Facade_funciones.cpp Funcionalidades/Facade_funciones.h Funcionalidades/Giros.cpp Funcionalidades/Giros.h Funcionalidades/Filtros.cpp Funcionalidades/Filtros.h BMP/Image.cpp BMP/Image.h)
target_link_libraries(Codigo -lpthread)
target_link_libraries (Codigo sfml-graphics sfml-window sfml-system)