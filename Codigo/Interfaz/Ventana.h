//
// Created by deyla on 25/4/2022.
//

#ifndef CODIGO_VENTANA_H
#define CODIGO_VENTANA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Componentes.h"
#include "../lista doblemente enlazada/Lista_Doble.h"
#include "../lista doblemente enlazada/Matriz.h"
#include "Datos_juego.h"

class Ventana {
public:



    sf::RenderWindow *ptrwindow ;
    sf::Event event;
    bool escribiendo = false;
    std::string entrada = "";
    int contador_botones = 8;
    int contador_original = 8;
    int multplicador_de_trazo = 2;
    std::string modo_activo = "Ninguno";
    Matriz *RGB_pixeles_imagen = new Matriz();
    Lista_Doble<sf::RectangleShape> *lienzo = new Lista_Doble<sf::RectangleShape>();

    Componentes *componentes = new Componentes();
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");



    Ventana( sf::RenderWindow *window);
    void ventana_principal();
    void cambiar_color_pixel_lienzo(int x,int y,int r,int g,int b);
    void cambiar_color_seleccionado(int r,int g,int b);
    void picker(int x, int y);

};


#endif //CODIGO_VENTANA_H
