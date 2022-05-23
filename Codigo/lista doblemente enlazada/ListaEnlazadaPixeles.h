//
// Created by ludwinr on 22/05/22.
//

#ifndef CODIGO_LISTAENLAZADAPIXELES_H
#define CODIGO_LISTAENLAZADAPIXELES_H

#include "QueuePixels.h"

class LinkedListPixels{
public:
    LinkedListPixels();
    NodoPixel* getHeatNodo();
    void insertNodo(NodoPixel *nuevoNodoPixel);

private:
    NodoPixel *head;
    NodoPixel *tail;
};



#endif //CODIGO_LISTAENLAZADAPIXELES_H
