//
// Created by deylan on 24/05/22.
//

#include "PaintFill.h"
PaintFill::PaintFill() {
}

void PaintFill::pintarArea( sf::Vector2f coordsMouse) {
    colaDePixeles.clear();

    int coordMouseX = coordsMouse.x; int coordMouseY = coordsMouse.y;
    Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(coordMouseY)->busqueda_indice(coordMouseX);
    nodoPixelInicial = colaDePixeles.front();
    pixel->rectangulo.setFillColor(sf::Color(datos->getColor_R(),datos->getColor_G(),datos->getColor_B(),255));
    ptrwindow->draw(pixel->rectangulo);
    ptrwindow->display();
    nodoPixelInicial->R = pixel->R;
    nodoPixelInicial->G = pixel->G;
    nodoPixelInicial->B = pixel->B;
    nodoPixelInicial->coordX = coordMouseX; nodoPixelInicial->coordY = coordMouseY;
    NodoPixel* pixelActual = crearNodoPixelVisitado(coordMouseX,coordMouseY);
    listaDeEstadosPixeles.insertNodo(pixelActual);

    while (!colaDePixeles.empty()){
        pixelActual = colaDePixeles.front();
        colaDePixeles.pop();
        for(int i = 0; i < cantidadPixelesAdyacentes; i++){
            int coord_X_PixelAdyacente = incrementoEnCoordX_nodoAdyacente[i] + pixelActual->coordX;
            int coord_Y_PixelAdyacente = incrementoEnCoordY_nodoAdyacente[i] + pixelActual->coordY;

            // se comprueba que el pixel adyacente este dentro de la matriz
            if(0<=coord_X_PixelAdyacente && coord_X_PixelAdyacente<datos->RGB_pixeles_imagen->busqueda_indice(0)->largo && coord_Y_PixelAdyacente<datos->RGB_pixeles_imagen->largo && coord_Y_PixelAdyacente>= 0 )
                verificarCoincidenciaColorPixel(coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
        }
    }
    liberarMemoriaDeListaEstados();
}
NodoPixel* PaintFill::crearNodoPixelVisitado(int coordMouseX, int coordMouseY) {
    NodoPixel *pixelVisitado = new NodoPixel();
    pixelVisitado->coordX = coordMouseX; pixelVisitado->coordY = coordMouseY;
    pixelVisitado->visitado = true;
    pixelVisitado->nextNodo = NULL;
    return pixelVisitado;
}

void PaintFill::verificarCoincidenciaColorPixel( int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
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
    pintarPixelDeIgualColor(coord_X_PixelAdyacente, coord_Y_PixelAdyacente);
}

void PaintFill::pintarPixelDeIgualColor( int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
    Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);

    if(pixel != NULL){
        if(pixel->R == nodoPixelInicial->R && pixel->G == nodoPixelInicial->G && pixel->B == nodoPixelInicial->B){

            int R = datos->getColor_R(), G = datos->getColor_G(),  B = datos->getColor_B();

            Nodo_pixel *pixel_cambio = datos->RGB_pixeles_imagen->busqueda_indice(
                    coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);
            pixel_cambio->R = R;
            pixel_cambio->G  = G;
            pixel_cambio->B = B;
            pixel_cambio->rectangulo.setFillColor(sf::Color(R,G,B,255));
            ptrwindow->draw(pixel_cambio->rectangulo);
            ptrwindow->display();

            NodoPixel *nodoVisitado = crearNodoPixelVisitado(coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
            listaDeEstadosPixeles.insertNodo(nodoVisitado);

            NodoPixel *pixelDeMismoColor = new NodoPixel();
            pixelDeMismoColor->nextNodo = NULL;
            pixelDeMismoColor->coordX = coord_X_PixelAdyacente;
            pixelDeMismoColor->coordY = coord_Y_PixelAdyacente;

            colaDePixeles.push(pixelDeMismoColor);
        }

        /*else{
            Nodo_pixel *pixel_cambio = datos->RGB_pixeles_imagen->busqueda_indice(
                    coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);

            pixel_cambio->rectangulo.setFillColor(sf::Color(255,0,0,255));
            ptrwindow->draw(pixel_cambio->rectangulo);
            ptrwindow->display();

        }*/
    }
}

void PaintFill::liberarMemoriaDeListaEstados() {
    NodoPixel *nodoAliberar = listaDeEstadosPixeles.getHeatNodo();
    NodoPixel *nextDeNodoAliberar = nodoAliberar->nextNodo;

    while(!nextDeNodoAliberar==NULL){
        free(nodoAliberar);
        nodoAliberar = nextDeNodoAliberar;
        nextDeNodoAliberar = nodoAliberar->nextNodo;
    }
    free(nodoAliberar);
    listaDeEstadosPixeles.head = NULL;  listaDeEstadosPixeles.tail = NULL;
}
