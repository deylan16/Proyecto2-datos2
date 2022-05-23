//
// Created by ludwinr on 21/05/22.
//

#include "PaintFill.h"
#include "../lista doblemente enlazada/Nodo_pixel.h"

PaintFill::PaintFill() {
}


void PaintFill::pintarArea(ColorPixel *colorPixels, sf::Vector2f coordsMouse) {
    int coordMouseX = coordsMouse.x; int coordMouseY = coordsMouse.y;
    Nodo_pixel *pixel = colorPixels->getRGB_pixeles_imagen()->busqueda_indice(coordMouseY)->busqueda_indice(coordMouseX);
    nodoPixelInicial = colaDePixeles.front();
    nodoPixelInicial->R = pixel->R;
    nodoPixelInicial->G = pixel->G;
    nodoPixelInicial->B = pixel->B;
    nodoPixelInicial->coordX = coordMouseX; nodoPixelInicial->coordY = coordMouseY;
    NodoPixel* pixelActual = crearNodoPixelVisitado(coordMouseX,coordMouseY);
    listaDeEstadosPixeles.insertNodo(pixelActual);

    while (!colaDePixeles.empty()){
        pixelActual = colaDePixeles.pop();
        for(int i = 0; i < cantidadPixelesAdyacentes; i++){
            int coord_X_PixelAdyacente = incrementoEnCoordX_nodoAdyacente[i] + pixelActual->coordX;
            int coord_Y_PixelAdyacente = incrementoEnCoordY_nodoAdyacente[i] + pixelActual->coordY;

            cout<<"coordenadada X del pixel inicial: "<< pixelActual->coordX<<" coordenada X del pixel adyacente: "<<coord_X_PixelAdyacente<<endl;
            cout<<"coordenadada Y del pixel inicial: "<< pixelActual->coordY<<" coordenada Y del pixel adyacente: "<<coord_Y_PixelAdyacente<<endl;
            verificarCoincidenciaColorPixel(colorPixels,coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
        }
        cout<<colaDePixeles.empty()<<endl;
    }
}
NodoPixel* PaintFill::crearNodoPixelVisitado(int coordMouseX, int coordMouseY) {
    NodoPixel *pixelVisitado = new NodoPixel();
    pixelVisitado->coordX = coordMouseX; pixelVisitado->coordY = coordMouseY;
    pixelVisitado->visitado = true;
    pixelVisitado->nextNodo = NULL;
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
        cout<<"R del pixel seleccionado: "<<nodoPixelInicial->R<<". R del pixel adyacente: "<< pixel->R<<endl;
        cout<<"G del pixel seleccionado: "<<nodoPixelInicial->G<<". G del pixel adyacente: "<< pixel->G<<endl;
        cout<<"B del pixel seleccionado: "<<nodoPixelInicial->B<<". B del pixel adyacente: "<< pixel->B<<endl;
        cout<<"\n";

        if(pixel->R == nodoPixelInicial->R && pixel->G == nodoPixelInicial->G && pixel->B == nodoPixelInicial->B){
            int R = colorPixels->getDatosJuego()->getColor_R(),  G = colorPixels->getDatosJuego()->getColor_G();
            int B = colorPixels->getDatosJuego()->getColor_B();

            colorPixels->set_color_pixel_lienzo(coord_X_PixelAdyacente,coord_Y_PixelAdyacente,R,G,B);

            NodoPixel *nodoVisitado = crearNodoPixelVisitado(coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
            listaDeEstadosPixeles.insertNodo(nodoVisitado);

            NodoPixel *pixelDeMismoColor = new NodoPixel();
            pixelDeMismoColor->nextNodo = NULL;
            pixelDeMismoColor->coordX = coord_X_PixelAdyacente;
            pixelDeMismoColor->coordY = coord_Y_PixelAdyacente;

            colaDePixeles.push(pixelDeMismoColor);
            cout<<"si entra la porqueria"<<endl;
        }
    }
}


