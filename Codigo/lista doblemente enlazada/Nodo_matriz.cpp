//
// Created by deylan on 25/04/22.
//

#include "Nodo_matriz.h"

Nodo_matriz::Nodo_matriz(Lista_pixeles*dato_entrante, Nodo_matriz *next_entrante, Nodo_matriz *prev_entrante,
                            int indice_entrante){
        this->indice = indice_entrante;
        this->dato = dato_entrante;
        this->next = next_entrante;
        this->prev = prev_entrante;


}
