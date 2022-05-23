//
// Created by ludwinr on 21/05/22.
//

#ifndef CODIGO_PAINTFILL_H
#define CODIGO_PAINTFILL_H
#include "ColorPixels.h"
#include "../lista doblemente enlazada/QueuePixels.h"
#include "../lista doblemente enlazada/ListaEnlazadaPixeles.h"

class PaintFill{

public:
    PaintFill();
    void pintarArea(ColorPixel *colorPixel, sf::Vector2f coordsMouse);

private:
    NodoPixel *nodoPixelInicial;
    NodoPixel *nodoPixelVisitado;
    QueuePixels colaDePixeles;
    LinkedListPixels listaDeEstadosPixeles;
    int cantidadPixelesAdyacentes = 4;
    NodoPixel* crearNodoPixelVisitado(int coordMouseX, int coordMouseY);
    void verificarCoincidenciaColorPixel(ColorPixel *colorPixels, int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente);
    void pintarPixelDeIgualColor(ColorPixel *colorPixels, int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente);

    // incremento o decremento para obtener posibles nodos adyacentes en el eje horizontal
    int incrementoEnCoordX_nodoAdyacente[4] = {0,0,1,-1};

    // incremento o decremento para obtener posibles nodos adyacentes en el eje vertical
    int incrementoEnCoordY_nodoAdyacente[4] = {1,-1,0,0};
};

#endif //CODIGO_PAINTFILL_H
