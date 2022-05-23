//
// Created by ludwinr on 21/05/22.
//

#include "QueuePixels.h"
#include <iostream>
using namespace std;

QueuePixels::QueuePixels() {
    NodoPixel *NodoInicial;
    NodoInicial->nextNodo = NULL;
    head = NodoInicial;
    tail = NodoInicial;
}

void QueuePixels::push(NodoPixel *nuevoNodoPixel) {
    tail->nextNodo = nuevoNodoPixel;
    tail = nuevoNodoPixel;
}

NodoPixel* QueuePixels::front() {
    return this->head;
}

NodoPixel* QueuePixels::pop() {
    NodoPixel *tempHead = head;
    if (head == NULL){
        return NULL;
    }
    head = head->nextNodo;
    return tempHead;
}

bool QueuePixels::empty(){
    if(head == NULL){
        return true;
    }
    return false;
}

