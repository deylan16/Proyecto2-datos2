//
// Created by deylan on 25/04/22.
//

#ifndef CODIGO_NODO_H
#define CODIGO_NODO_H


#include <string>
template <class T>

class Nodo {
public:
    Nodo *next= nullptr;
    Nodo *prev= nullptr;
    int indice;

    T dato;

    Nodo(T dato_entrante,Nodo *next_entrante, Nodo *prev_entrante,int indice_entrante);

};


#endif //CODIGO_NODO_H
