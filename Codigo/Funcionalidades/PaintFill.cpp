//
// Created by ludwinr on 21/05/22.
//

#include "PaintFill.h"

PaintFill::PaintFill() {
}


void PaintFill::pintarArea(ColorPixel *colorPixel, sf::Vector2f coordsMouse) {
    int coordMouseX = coordsMouse.x; int coordsMouseY = coordsMouse.y;
    nodoPixelInicial = colaDePixeles.front();
    nodoPixelInicial->R = colorPixel->getDatosJuego()->getColor_R();
    nodoPixelInicial->G = colorPixel->getDatosJuego()->getColor_G();
    nodoPixelInicial->B = colorPixel->getDatosJuego()->getColor_B();
    nodoPixelInicial->coordX = coordMouseX; nodoPixelInicial->coordY = coordsMouseY;
    NodoPixel* pixelActual = crearNodoPixelVisitado(coordMouseX,coordsMouseY);
    listaDeEstadosPixeles.insertNodo(pixelActual);

    while (!colaDePixeles.empty()){
        pixelActual = colaDePixeles.pop();
        for(int i = 0; i < cantidadPixelesAdyacentes; i++){
            int coord_X_PixelAdyacente = incrementoEnCoordX_nodoAdyacente[i] + pixelActual->coordX;
            int coord_Y_PixelAdyacente = incrementoEnCoordY_nodoAdyacente[i] + pixelActual->coordY;
        }
    }
}

void PaintFill::verificarCoincidenciaColorPixel(ColorPixel *colorPixel, int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
    NodoPixel *pixelAcomprobarSiFuePintado = listaDeEstadosPixeles.getHeatNodo();
    int coordX_pixelAverificar = pixelAcomprobarSiFuePintado->coordX;
    int coordY_pixelAverificar = pixelAcomprobarSiFuePintado->coordY;
    while(!pixelAcomprobarSiFuePintado==NULL){
        if(coordX_pixelAverificar == coord_X_PixelAdyacente && coordY_pixelAverificar == coord_Y_PixelAdyacente){
            return;
        }
        pixelAcomprobarSiFuePintado = pixelAcomprobarSiFuePintado->nextNodo;
    }
}

NodoPixel* PaintFill::crearNodoPixelVisitado(int coordMouseX, int coordMouseY) {
    NodoPixel *pixelVisitado;
    pixelVisitado->coordX = coordMouseX; pixelVisitado->coordY = coordMouseY;
    pixelVisitado->visitado = true;
    return pixelVisitado;
}
