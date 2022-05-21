//
// Created by ludwinr on 21/05/22.
//

#include "QueuePixels.h"
#include <iostream>
using namespace std;

QueuePixels::QueuePixels() {
    NodoPixel NodoInicial = NodoPixel();
    head = NodoInicial;
    tail = NodoInicial;
}

void QueuePixels::push(NodoPixel nuevoNodoPixel) {
    head.setNext(nuevoNodoPixel);
    tail = nuevoNodoPixel;
}

NodoPixel QueuePixels::front() {
    return this->head;
}

NodoPixel QueuePixels::pop() {
    NodoPixel tempHead = head;
    if(head.getNext()== nullptr){head = NodoPixel(); return head;}
    head = *head.getNext();
    return tempHead;
}

bool QueuePixels::empty(){
    if(head.getNext()== nullptr){
        return true;
    }
    return false;
}

NodoPixel::NodoPixel() { // Nodos contenidos en la cola de Pixeles
    nextNode = nullptr;
}

void NodoPixel::setNext(NodoPixel nuevoNodoPixel) {
    *nextNode = nuevoNodoPixel;
}

NodoPixel* NodoPixel::getNext() {
    return nextNode;
}
