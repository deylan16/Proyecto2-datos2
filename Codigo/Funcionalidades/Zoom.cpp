//
// Created by ludwinr on 25/05/22.
//

#include "Zoom.h"
#include "../lista doblemente enlazada/Nodo_pixel.h"
#include "../lista doblemente enlazada/Nodo_matriz.h"
#include <iostream>
using namespace std;

Zoom::Zoom() {
    historialZoom.ultimoMovimiento = new MovimientosZoom();
    historialZoom.ultimoMovimiento->anteriorMovimientoZoom = NULL;
    historialZoom.ultimoMovimiento->zoomSelectionPosicion_X = 0;
    historialZoom.ultimoMovimiento->zoomSelectionPosicion_Y = 0;
}

void Zoom::zoom_in(sf::Vector2f coordsMouse,int numeroDeZoom) {
    largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo; // ancho (x)
    largo_filas = datos->RGB_pixeles_imagen->largo-2; // alto (y)
    sf:: Vector2f nuevasCoordenadasZoom = getPositionZoom(coordsMouse,numeroDeZoom);

    int coordX_inicialZoom = nuevasCoordenadasZoom.x,  coordY_inicialZoom = nuevasCoordenadasZoom.y;

    Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(coordY_inicialZoom)->busqueda_indice(coordX_inicialZoom);
    for(int n = 100;n <largo_filas; n+=numeroDeZoom) {
        for (int u = 0; u<largo_columnas ;u+=numeroDeZoom) {

            sf::RectangleShape nuevoRectangulo(sf::Vector2f(numeroDeZoom,numeroDeZoom));
            nuevoRectangulo.setPosition(u,n);
            nuevoRectangulo.setFillColor(sf::Color(pixel->R,pixel->G,pixel->B,255));
            ptrWindow->draw(nuevoRectangulo);
            pixel = pixel->next;
        }

        coordY_inicialZoom++;
        pixel = datos->RGB_pixeles_imagen->busqueda_indice(coordY_inicialZoom)->busqueda_indice(coordX_inicialZoom);
    }
    ptrWindow->display();


    cout<<"sale"<<endl;

    MovimientosZoom *nuevoMovimiento = new MovimientosZoom();
    nuevoMovimiento->zoomSelectionPosicion_X = nuevasCoordenadasZoom.x; // se toman estas coordenadas pues no cambian
    nuevoMovimiento->zoomSelectionPosicion_Y = nuevasCoordenadasZoom.y; // se toman estas coordenadas pues no cambian

    if(historialZoom.ultimoMovimiento->anteriorMovimientoZoom == NULL){
        historialZoom.ultimoMovimiento = nuevoMovimiento;
        historialZoom.ultimoMovimiento->anteriorMovimientoZoom = NULL;
    }else {
        nuevoMovimiento->anteriorMovimientoZoom = historialZoom.ultimoMovimiento;
        historialZoom.ultimoMovimiento = nuevoMovimiento;
    }
}

void Zoom::zoom_out(int numeroDeZoom){
    MovimientosZoom *actualMovimientoZoom = historialZoom.ultimoMovimiento; // es el que se elimina, si se esta en el sexto se envia las coordenadas del cuarto
    int coordZoomAregresar_X,  coordZoomAregresar_Y;

    if(actualMovimientoZoom->anteriorMovimientoZoom !=NULL){
        historialZoom.ultimoMovimiento = actualMovimientoZoom->anteriorMovimientoZoom;
        coordZoomAregresar_X = historialZoom.ultimoMovimiento->zoomSelectionPosicion_X;
        coordZoomAregresar_Y = historialZoom.ultimoMovimiento->zoomSelectionPosicion_Y;

    } else{coordZoomAregresar_X = 0, coordZoomAregresar_Y = 100; }

    cout<<"zoom out"<<endl;
    // Antes de ser eliminado el ultimo movimiento de zoom, se ejecuta para volver al estado anterior
    zoom_in(sf::Vector2f(coordZoomAregresar_X,coordZoomAregresar_Y),numeroDeZoom);

    free(actualMovimientoZoom); actualMovimientoZoom = NULL;
}

sf::Vector2f Zoom::getPositionZoom(sf::Vector2f mousePositionPressZoom,int numeroDeZoom){
    int coordX_zoom,  coordY_zoom;
    int escalaDePixelesInicial = 2;

    if(numeroDeZoom == escalaDePixelesInicial){
        coordX_zoom = mousePositionPressZoom.x;
        coordY_zoom = mousePositionPressZoom.y;
    }else{
        coordX_zoom = historialZoom.ultimoMovimiento->zoomSelectionPosicion_X+(mousePositionPressZoom.x / numeroDeZoom);
        coordY_zoom = historialZoom.ultimoMovimiento->zoomSelectionPosicion_Y+(mousePositionPressZoom.y /numeroDeZoom);
    }
    if(coordX_zoom > largo_columnas/numeroDeZoom){
        coordX_zoom = largo_columnas/numeroDeZoom;
    }
    if(coordY_zoom > largo_filas/numeroDeZoom){
        coordY_zoom = largo_filas/numeroDeZoom;
    }

    sf::Vector2f nuevasCoordenadasZoom(coordX_zoom,coordY_zoom);
    return nuevasCoordenadasZoom;
}
