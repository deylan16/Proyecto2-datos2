//
// Created by deylan on 25/05/22.
//

#include "Seleccion_magica.h"
Seleccion_magica::Seleccion_magica() {
}

void Seleccion_magica::pintarArea( sf::Vector2f coordsMouse) {
    colaDePixeles.clear();

    int coordMouseX = coordsMouse.x; int coordMouseY = coordsMouse.y;
    Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(coordMouseY)->busqueda_indice(coordMouseX);
    nodoPixelInicial = colaDePixeles.front();
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
NodoPixel* Seleccion_magica::crearNodoPixelVisitado(int coordMouseX, int coordMouseY) {
    NodoPixel *pixelVisitado = new NodoPixel();
    pixelVisitado->coordX = coordMouseX; pixelVisitado->coordY = coordMouseY;
    pixelVisitado->visitado = true;
    pixelVisitado->nextNodo = NULL;
    return pixelVisitado;
}

void Seleccion_magica::verificarCoincidenciaColorPixel( int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
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

void Seleccion_magica::pintarPixelDeIgualColor( int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
    Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);

    if(pixel != NULL){
        if(pixel->R == nodoPixelInicial->R && pixel->G == nodoPixelInicial->G && pixel->B == nodoPixelInicial->B){



            Nodo_pixel *pixel_cambio = datos->RGB_pixeles_imagen->busqueda_indice(coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);

            pixel_cambio->rectangulo.setFillColor(sf::Color(pixel_cambio->R ,pixel_cambio->G,pixel_cambio->B,0));
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

        else{
            Nodo_pixel *pixel_cambio = datos->RGB_pixeles_imagen->busqueda_indice(
                    coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);
            int r = nodoPixelInicial->R;
            int g = nodoPixelInicial->G;
            int b = nodoPixelInicial->B;
            if (r == 255 && g == 255 && b == 255)
            {
                pixel_cambio->rectangulo.setFillColor(sf::Color(0, 0, 0, 255));
                ptrwindow->draw(pixel_cambio->rectangulo);
            }
            else
            {
                pixel_cambio->rectangulo.setFillColor(sf::Color(255, 255, 255, 255));
                ptrwindow->draw(pixel_cambio->rectangulo);
            }
            //pixel_cambio->rectangulo.setFillColor(sf::Color(255,,0,255));
            ptrwindow->draw(pixel_cambio->rectangulo);
            ptrwindow->display();

        }
    }
}

void Seleccion_magica::liberarMemoriaDeListaEstados() {
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
