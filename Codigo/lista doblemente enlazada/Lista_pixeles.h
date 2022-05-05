//
// Created by deylan on 26/04/22.
//

#ifndef CODIGO_LISTA_PIXELES_H
#define CODIGO_LISTA_PIXELES_H


#include "Nodo_pixel.h"

class Lista_pixeles {
public:
    Nodo_pixel *Inicio = nullptr;
    Nodo_pixel *Final = nullptr;
    int largo = 0;

    void append(int R,int G,int B,sf::RectangleShape rectangulo_entrante);

    void print();
    Nodo_pixel * busqueda_indice(int indice_busqueda);
};


#endif //CODIGO_LISTA_PIXELES_H
