//
// Created by deylan on 24/05/22.
//

#ifndef CODIGO_LINKEDLISTPIXELS_H
#define CODIGO_LINKEDLISTPIXELS_H

#include "QueuePixels.h"
class LinkedListPixels {
public:
    LinkedListPixels();
    NodoPixel* getHeatNodo();
    void insertNodo(NodoPixel *nuevoNodoPixel);

    NodoPixel *head;
    NodoPixel *tail;
};


#endif //CODIGO_LINKEDLISTPIXELS_H
