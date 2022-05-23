//
// Created by ludwinr on 22/05/22.
//

#include "ListaEnlazadaPixeles.h"
#include <iostream>

LinkedListPixels::LinkedListPixels() {
    head = NULL;
    tail = NULL;
}

void LinkedListPixels::insertNodo(NodoPixel *nuevoNodoPixel) {
    if(head == NULL){
        head = nuevoNodoPixel;
        tail = nuevoNodoPixel;
    }else{
        nuevoNodoPixel->nextNodo = head;
        head = nuevoNodoPixel;
    }
}

NodoPixel* LinkedListPixels::getHeatNodo() {
    return head;
}

