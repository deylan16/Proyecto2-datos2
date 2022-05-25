//
// Created by deylan on 24/05/22.
//

#include "QueuePixels.h"
#include <iostream>
using namespace std;

QueuePixels::QueuePixels() {
}

void QueuePixels::push(NodoPixel *nuevoNodoPixel) {
    if(head == NULL){
        tail = nuevoNodoPixel;
        head = nuevoNodoPixel;
    }else{
        tail->nextNodo = nuevoNodoPixel;
        tail = nuevoNodoPixel;
    }
}

NodoPixel* QueuePixels::front() {
    return this->head;
}

void QueuePixels::pop() {
    if (head == NULL){
        return;
    }
    if(head == tail){tail =head->nextNodo;}
    head = head->nextNodo;
}

bool QueuePixels::empty(){
    if(head == NULL){
        return true;
    }
    return false;
}

void QueuePixels::clear() {
    NodoPixel *NodoInicial = new NodoPixel();
    NodoInicial->nextNodo = NULL;
    head = NodoInicial;
    tail = NodoInicial;

}