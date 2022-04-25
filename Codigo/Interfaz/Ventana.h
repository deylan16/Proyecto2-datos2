//
// Created by deyla on 25/4/2022.
//

#ifndef CODIGO_VENTANA_H
#define CODIGO_VENTANA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Componentes.h"

class Ventana {
public:



    sf::RenderWindow *ptrwindow ;
    sf::Event event;
    bool escribiendo = false;
    std::string entrada = "";
    int contador_botones = 9;

    Componentes *componentes = new Componentes();



    Ventana( sf::RenderWindow *window);
    void ventana_principal();

};


#endif //CODIGO_VENTANA_H
