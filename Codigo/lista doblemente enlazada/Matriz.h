//
// Created by deylan on 25/04/22.
//

#ifndef CODIGO_MATRIZ_H
#define CODIGO_MATRIZ_H


#include "Nodo_matriz.h"
#include <iostream>

class Matriz {
public:
    Nodo_matriz *Inicio = nullptr;
    Nodo_matriz *Final = nullptr;
    int largo = 0;

    void append(Lista_pixeles *dato);

    void print();
    Lista_pixeles *busqueda_indice(int indice_busqueda);
};


#endif //CODIGO_MATRIZ_H
