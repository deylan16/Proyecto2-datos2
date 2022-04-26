//
// Created by deylan on 25/04/22.
//

#ifndef CODIGO_LISTA_DOBLE_H
#define CODIGO_LISTA_DOBLE_H


#include "Nodo.h"

#include <iostream>
template <class T>
class Lista_doble {
public:
    Nodo<T> *Inicio = nullptr;
    Nodo<T> *Final = nullptr;
    int largo = 0;

    void append(T dato);

    void print();
    std::string busqueda_indice(int indice_busqueda);

};


#endif //CODIGO_LISTA_DOBLE_H
