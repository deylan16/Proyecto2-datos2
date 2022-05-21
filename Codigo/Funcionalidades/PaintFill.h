//
// Created by ludwinr on 21/05/22.
//

#ifndef CODIGO_PAINTFILL_H
#define CODIGO_PAINTFILL_H
#include "ColorPixels.h"
#include "../lista doblemente enlazada/QueuePixels.h"

class PaintFill{

public:
    PaintFill();
    void pintarArea(ColorPixel *colorPixel, sf::Vector2f coordsMouse);

private:
    NodoPixel nodoPixelInicial;
    QueuePixels colaDePixeles;

    // incremento o decremento para obtener posibles nodos adyacentes en el eje horizontal
    int incrementoEnXnodoAdyacente[4] = {0,0,1,-1};

    // incremento o decremento para obtener posibles nodos adyacentes en el eje vertical
    int incrementoEnYnodoAdyacente[4] = {1,-1,0,0};
};

#endif //CODIGO_PAINTFILL_H
