//
// Created by ludwinr on 21/05/22.
//

#ifndef CODIGO_QUEUEPIXELS_H
#define CODIGO_QUEUEPIXELS_H

class NodoPixel {
public:
    NodoPixel();
    void setNext(NodoPixel nuevoNodoPixel);
    NodoPixel* getNext();
    int R;
    int G;
    int B;
    bool visitado;
    int coordX;
    int coordY;

private:
    NodoPixel *nextNode;
};

class QueuePixels{
public:
    QueuePixels();
    NodoPixel pop();
    NodoPixel front();
    void push(NodoPixel nuevoNodoPixel);
    bool empty();

private:
    NodoPixel head;
    NodoPixel tail;
};
#endif //CODIGO_QUEUEPIXELS_H
