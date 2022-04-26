//
// Created by deylan on 25/04/22.
//

#include "Nodo.h"
template <typename T>
Nodo<T>::Nodo(T dato_entrante, Nodo *next_entrante, Nodo *prev_entrante,int indice_entrante) {
    this->indice = indice_entrante;
    this->dato = dato_entrante;
    this->next = next_entrante;
    this->prev = prev_entrante;
    this->indice = indice_entrante;

}


