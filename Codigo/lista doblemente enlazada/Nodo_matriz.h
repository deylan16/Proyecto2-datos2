//
// Created by deylan on 25/04/22.
//

#ifndef CODIGO_NODO_MATRIZ_H
#define CODIGO_NODO_MATRIZ_H


#include "Lista_doble.h"
#include "Lista_pixeles.h"

class Nodo_matriz {
public:
    Nodo_matriz *next= nullptr;
    Nodo_matriz *prev= nullptr;
    int indice;

    Lista_pixeles *dato = nullptr ;

    Nodo_matriz(Lista_pixeles *dato_entrante,Nodo_matriz *next_entrante, Nodo_matriz *prev_entrante,int indice_entrante);
};




#endif //CODIGO_NODO_MATRIZ_H
