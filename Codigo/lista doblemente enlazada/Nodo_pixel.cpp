//
// Created by deylan on 26/04/22.
//

#include "Nodo_pixel.h"

Nodo_pixel::Nodo_pixel(int R_entrante,int G_entrante,int B_entrante, Nodo_pixel *next_entrante, Nodo_pixel *prev_entrante, int indice_entrante,sf::RectangleShape rectangulo_entrante) {
    this->indice = indice_entrante;
    this->R = R_entrante;
    this->G = G_entrante;
    this->B = B_entrante;
    this->rectangulo = rectangulo_entrante;
    this->next = next_entrante;
    this->prev = prev_entrante;
    this->indice = indice_entrante;
}
