#include <iostream>
#include "Interfaz/Ventana.h"

#include "lista doblemente enlazada/Lista_Doble.h"
#include "lista doblemente enlazada/Matriz.h"
#include "lista doblemente enlazada/Lista_pixeles.h"
#include "BMP/Bmp.h"

#include <SFML/Graphics.hpp>

void carro()
{
    Lista_Doble<std::string> *hola = new Lista_Doble<std::string>();
    hola->appe("tole");
    hola->appe("edfg");
    hola->appe("agua");
    hola->print();
    /*std::cout<<hola->busqueda_indice(3)<<std::endl;
    Lista_doble<std::string> *hola2 = new Lista_doble<std::string>();
    hola2->append("3");
    hola2->append("2");
    hola2->append("3");
    hola2->print();
    hola->append("arriiba");
    hola->print();*/

    Lista_pixeles *saa = new Lista_pixeles();
    saa->append(43,89,100);
    saa->append(30,93,170);
    saa->append(56,60,255);
    saa->print();
    Lista_pixeles *saa2 = new Lista_pixeles();
    saa2->append(23,89,100);
    saa2->append(70,93,170);
    saa2->append(96,60,255);
    saa2->print();
    int hi = saa->busqueda_indice(1)->R;
    std::cout<<hi<<std::endl;


    Matriz *tome = new Matriz();
    tome->append(saa);
    tome->append(saa2);

    tome->print();
    std::cout<<tome->busqueda_indice(0)->busqueda_indice(1)->R<<std::endl;


}

int main() {
    sf::RenderWindow window(sf::VideoMode(1100,1000),"Memoria");
    sf::RenderWindow *ptrwindow;
    ptrwindow = &window;

    Ventana *ventana = new Ventana(ptrwindow);
    ventana->ventana_principal();
    //carro();


    
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
