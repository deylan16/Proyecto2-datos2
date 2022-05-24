//
// Created by deylan on 24/05/22.
//

#include "PaintFill.h"
PaintFill::PaintFill() {
}


void PaintFill::pintarArea( sf::Vector2f coordsMouse) {
    nodoPixelInicial = nullptr;
    colaDePixeles.clear();
    listaDeEstadosPixeles.head = nullptr;
    listaDeEstadosPixeles.tail= nullptr;

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
        //cout<<"saa"<<colaDePixeles.empty()<<endl;
        pixelActual = colaDePixeles.pop();
        for(int i = 0; i < cantidadPixelesAdyacentes; i++){
            int coord_X_PixelAdyacente = incrementoEnCoordX_nodoAdyacente[i] + pixelActual->coordX;
            int coord_Y_PixelAdyacente = incrementoEnCoordY_nodoAdyacente[i] + pixelActual->coordY;

            if(0<=coord_X_PixelAdyacente && coord_X_PixelAdyacente<datos->RGB_pixeles_imagen->busqueda_indice(0)->largo && coord_Y_PixelAdyacente<datos->RGB_pixeles_imagen->largo && coord_Y_PixelAdyacente>= 0 )
                verificarCoincidenciaColorPixel(coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
        }
        //cout<<"tome"<<colaDePixeles.empty()<<endl;
    }
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
    bool estaba  = false;

    while(!pixelAcomprobarSiFuePintado==NULL){
        estaba  = false;

        coordX_pixelAverificar = pixelAcomprobarSiFuePintado->coordX;
        coordY_pixelAverificar = pixelAcomprobarSiFuePintado->coordY;
        if(coordX_pixelAverificar == coord_X_PixelAdyacente && coordY_pixelAverificar == coord_Y_PixelAdyacente){
            estaba = true;
            break;
            //return;
        }
        pixelAcomprobarSiFuePintado = pixelAcomprobarSiFuePintado->nextNodo;
    }
    if(!estaba)
        pintarPixelDeIgualColor(coord_X_PixelAdyacente, coord_Y_PixelAdyacente);
}

void PaintFill::pintarPixelDeIgualColor( int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente) {
    //cout<<"coordenadada X del pixel inicial: "<< nodoPixelInicial->coordX<<" coordenada X del pixel adyacente: "<<coord_X_PixelAdyacente<<endl;
    //cout<<"coordenadada Y del pixel inicial: "<< nodoPixelInicial->coordY<<" coordenada Y del pixel adyacente: "<<coord_Y_PixelAdyacente<<endl;
    Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);
    if(pixel != NULL){
        //cout<<"R del pixel seleccionado: "<<nodoPixelInicial->R<<". R del pixel adyacente: "<< pixel->R<<endl;
        //cout<<"G del pixel seleccionado: "<<nodoPixelInicial->G<<". G del pixel adyacente: "<< pixel->G<<endl;
        //cout<<"B del pixel seleccionado: "<<nodoPixelInicial->B<<". B del pixel adyacente: "<< pixel->B<<endl;
        //cout<<"\n";

        if(pixel->R == nodoPixelInicial->R && pixel->G == nodoPixelInicial->G && pixel->B == nodoPixelInicial->B){
            int R = datos->getColor_R();
            int G = datos->getColor_G();
            int B = datos->getColor_B();


            Nodo_pixel *pixel_cambio = datos->RGB_pixeles_imagen->busqueda_indice(
                    coord_Y_PixelAdyacente)->busqueda_indice(coord_X_PixelAdyacente);
            pixel_cambio->R = R;
            pixel_cambio->G  = G;
            pixel_cambio->B = B;
            pixel_cambio->rectangulo.setFillColor(sf::Color(R,G,B,255));
            ptrwindow->draw(pixel_cambio->rectangulo);
            ptrwindow->display();

            //colorPixels->set_color_pixel_lienzo(coord_X_PixelAdyacente,coord_Y_PixelAdyacente,R,G,B);

            NodoPixel *nodoVisitado = crearNodoPixelVisitado(coord_X_PixelAdyacente,coord_Y_PixelAdyacente);
            listaDeEstadosPixeles.insertNodo(nodoVisitado);

            NodoPixel *pixelDeMismoColor = new NodoPixel();
            pixelDeMismoColor->nextNodo = NULL;
            pixelDeMismoColor->coordX = coord_X_PixelAdyacente;
            pixelDeMismoColor->coordY = coord_Y_PixelAdyacente;

            colaDePixeles.push(pixelDeMismoColor);
            //cout<<"si entra la porqueria"<<endl;
        }
    }
}