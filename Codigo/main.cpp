#include <iostream>
#include "Interfaz/Ventana.h"
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(1100,1000),"Memoria");
    sf::RenderWindow *ptrwindow;
    ptrwindow = &window;

    Ventana *ventana = new Ventana(ptrwindow);
    ventana->ventana_principal();
    return 0;
}
//
/*
 g++ -c main.cpp
g++ -c Interfaz/Componentes.cpp
g++ Componentes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
g++ -c Interfaz/Ventana.cpp
g++ Ventana.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system


g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
  */

/*
g++ -c Interfaz/Componentes.cpp
g++ Componentes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

g++ -c Interfaz/Ventana.cpp
g++ Ventana.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system


./sfml-app
  */