//
// Created by ludwinr on 21/05/22.
//

#include "PaintFill.h"
#include "../lista doblemente enlazada/Nodo_pixel.h"

PaintFill::PaintFill() {
}


void PaintFill::pintarArea(ColorPixel *colorPixels, sf::Vector2f coordsMouse) {
    int coordMouseX = coordsMouse.x; int coordsMouseY = coordsMouse.y;
    Nodo_pixel *pixel = colorPixels->getRGB_pixeles_imagen()->busqueda_indice(coordsMouseY)->busqueda_indice(coordMouseX);
    nodoPixelInicial = colaDePixeles.front();
    nodoPixelInicial->R = pixel->R;
    nodoPixelInicial->G = pixel->G;
    nodoPixelInicial->B = pixel->B;
    nodoPixelInicial->coordX = coordMouseX; nodoPixelInicial->coordY = coordsMouseY;
    NodoPixel* pixelActual = crearNodoPixelVisitado(coordMouseX,coordsMouseY);
    listaDeEstadosPixeles.insertNodo(pixelActual);

    while (!colaDePixeles.empty()){
        pixelActual = colaDePixeles.pop();
        for(int i = 0; i < cantidadPixelesAdyacentes; i++){
            int coord_X_PixelAdyacente = incrementoEnCoordX_nodoAdyacente[i] + pixelActual->coordX;
            int coord_Y_PixelAdyacente = incrementoEnCoordY_nodoAdyacente[i] + pixelActual->coordY;
            verificarCoincidenciaColorPixel(colorPixels,coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
        }
    }
}
NodoPixel* PaintFill::crearNodoPixelVisitado(int coordMouseX, int coordMouseY) {
    NodoPixel *pixelVisitado;
    pixelVisitado->coordX = coordMouseX; pixelVisitado->coordY = coordMouseY;
    pixelVisitado->visitado = true;
    return pixelVisitado;
}

void PaintFill::verificarCoincidenciaColorPixel(ColorPixel *colorPixels, int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
    NodoPixel *pixelAcomprobarSiFuePintado = listaDeEstadosPixeles.getHeatNodo();
    int coordX_pixelAverificar, coordY_pixelAverificar;

    while(!pixelAcomprobarSiFuePintado==NULL){

        coordX_pixelAverificar = pixelAcomprobarSiFuePintado->coordX;
        coordY_pixelAverificar = pixelAcomprobarSiFuePintado->coordY;
        if(coordX_pixelAverificar == coord_X_PixelAdyacente && coordY_pixelAverificar == coord_Y_PixelAdyacente){
            return;
        }
        pixelAcomprobarSiFuePintado = pixelAcomprobarSiFuePintado->nextNodo;
    }
    pintarPixelDeIgualColor(colorPixels,coord_X_PixelAdyacente, coord_Y_PixelAdyacente);
}

void PaintFill::pintarPixelDeIgualColor(ColorPixel *colorPixels, int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
    Nodo_pixel *pixel = colorPixels->getRGB_pixeles_imagen()->busqueda_indice(coord_Y_PixelAdyacente)->busqueda_indice(coord_Y_PixelAdyacente);
    if(pixel != NULL){
        if(pixel->R == nodoPixelInicial->R && pixel->G == nodoPixelInicial->G && pixel->B == nodoPixelInicial->B){
            int R = colorPixels->getDatosJuego()->getColor_R(),  G = colorPixels->getDatosJuego()->getColor_G();
            int B = colorPixels->getDatosJuego()->getColor_B();

            colorPixels->set_color_pixel_lienzo(coord_X_PixelAdyacente,coord_Y_PixelAdyacente,R,G,B);

            NodoPixel *nodoVisitado = crearNodoPixelVisitado(coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
            colaDePixeles.push(nodoVisitado);
            listaDeEstadosPixeles.insertNodo(nodoVisitado);
        }
    }
}


