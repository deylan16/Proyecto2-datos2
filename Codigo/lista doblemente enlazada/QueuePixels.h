//
// Created by ludwinr on 21/05/22.
//

#ifndef CODIGO_QUEUEPIXELS_H
#define CODIGO_QUEUEPIXELS_H

struct NodoPixel{
    NodoPixel *nextNodo;
    int R,G,B;
    bool visitado;
    int coordX, coordY;
};

class QueuePixels{
public:
    QueuePixels();
    NodoPixel* pop();
    NodoPixel* front();
    void push(NodoPixel *nuevoNodoPixel);
    bool empty();

private:
    NodoPixel *head;
    NodoPixel *tail;
};
#endif //CODIGO_QUEUEPIXELS_H
