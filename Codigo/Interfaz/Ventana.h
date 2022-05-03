//
// Created by deyla on 25/4/2022.
//

#ifndef CODIGO_VENTANA_H
#define CODIGO_VENTANA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Componentes.h"
#include "../lista doblemente enlazada/Lista_Doble.h"

class Ventana {
public:



    sf::RenderWindow *ptrwindow ;
    sf::Event event;
    bool escribiendo = false;
    std::string entrada = "";
    int contador_botones = 8;
    int contador_original = 8;
    Lista_Doble<sf::RectangleShape> *hola2 = new Lista_Doble<sf::RectangleShape>();

    Componentes *componentes = new Componentes();



    Ventana( sf::RenderWindow *window);
    void ventana_principal();

};


#endif //CODIGO_VENTANA_H
