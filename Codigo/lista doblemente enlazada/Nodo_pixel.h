//
// Created by deylan on 26/04/22.
//

#ifndef CODIGO_NODO_PIXEL_H
#define CODIGO_NODO_PIXEL_H


#include <SFML/Graphics/RectangleShape.hpp>

class Nodo_pixel {
public:

    Nodo_pixel(int R_entrante, int G_entrante, int B_entrante, Nodo_pixel *next_entrante, Nodo_pixel *prev_entrante,int indice_entrante,sf::RectangleShape rectangulo_entrante);
    Nodo_pixel *next= nullptr;
    Nodo_pixel *prev= nullptr;
    int indice;

    int R = NULL;
    int G;
    int B;
    sf::RectangleShape rectangulo ;


};


#endif //CODIGO_NODO_PIXEL_H
