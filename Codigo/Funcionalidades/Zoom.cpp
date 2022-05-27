//
// Created by ludwinr on 25/05/22.
//

#include "Zoom.h"
#include "../lista doblemente enlazada/Nodo_pixel.h"
#include "../lista doblemente enlazada/Nodo_matriz.h"
#include <iostream>
using namespace std;

Zoom::Zoom() {
    historialZoom.ultimoMovimiento = new MovimientosZoom{NULL,0,0};
    historialMovimientosZoomNulo = true;
}

void Zoom::realizarZoom(sf::Vector2f coordsMouse, int numeroDeZoom, char tipoZoom) {
    largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo; // ancho (x)
    largo_filas = datos->RGB_pixeles_imagen->largo-2; // alto (y)
    char zoomPositivo = '+';

    if(tipoZoom == zoomPositivo){
        seLlama_A_zoomIn = true;
        zoom_in(coordsMouse,numeroDeZoom);

    }else{
        seLlama_A_zoomIn = false;
        zoom_out(numeroDeZoom);
    }
}

void Zoom::zoom_in(sf::Vector2f coordsMouse, int numeroDeZoom) {
    sf::Vector2f nuevasCoordenadasAjustadasZoom = getPosicionAjustadaZoomIn(coordsMouse,numeroDeZoom);
    logicZoom(nuevasCoordenadasAjustadasZoom,numeroDeZoom);
}

void Zoom::zoom_out(int numeroDeZoom){
    MovimientosZoom *actualMovimientoZoom = historialZoom.ultimoMovimiento; // es el que se elimina, si se esta en el sexto se envia las coordenadas del cuarto
    historialZoom.ultimoMovimiento = actualMovimientoZoom->anteriorMovimientoZoom;
    int coordZoomAregresar_X,  coordZoomAregresar_Y;

    if(actualMovimientoZoom->anteriorMovimientoZoom !=NULL){
        coordZoomAregresar_X = historialZoom.ultimoMovimiento->zoomSelectionPosicion_X;
        coordZoomAregresar_Y = historialZoom.ultimoMovimiento->zoomSelectionPosicion_Y;

    } else{
        MovimientosZoom *movimientoInicialZoomNulo = new MovimientosZoom{NULL,0,0};
        historialZoom.ultimoMovimiento = movimientoInicialZoomNulo;
        coordZoomAregresar_X = 0, coordZoomAregresar_Y = 0; numeroDeZoom=1; // coordenadas del principio de la imagen
        historialMovimientosZoomNulo = true;
    }
    // Antes de ser eliminado el ultimo movimiento de zoom, se ejecuta para volver al estado anterior
    logicZoom(sf::Vector2f(coordZoomAregresar_X,coordZoomAregresar_Y),numeroDeZoom);
    free(actualMovimientoZoom); actualMovimientoZoom = NULL;
}

void Zoom::logicZoom(sf::Vector2f coordsMouse,int numeroDeZoom) {
    int coordX_inicialZoom = coordsMouse.x,  coordY_inicialZoom = coordsMouse.y;

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
    if(seLlama_A_zoomIn){ actualizarHistorialDeMovimientosZoom(coordsMouse);}
}

void Zoom::actualizarHistorialDeMovimientosZoom(sf::Vector2f coordsDeMovimientoZoom) {

    if(historialZoom.ultimoMovimiento->anteriorMovimientoZoom == NULL && historialMovimientosZoomNulo){
        historialZoom.ultimoMovimiento->zoomSelectionPosicion_X = coordsDeMovimientoZoom.x;
        historialZoom.ultimoMovimiento->zoomSelectionPosicion_Y = coordsDeMovimientoZoom.y;
        historialMovimientosZoomNulo = false;
    }else {
        MovimientosZoom *nuevoMovimiento_zoomIn = new MovimientosZoom();

        // se toman estas coordenadas pues no cambian
        nuevoMovimiento_zoomIn->zoomSelectionPosicion_X = coordsDeMovimientoZoom.x; // se toman estas coordenadas pues no cambian
        nuevoMovimiento_zoomIn->zoomSelectionPosicion_Y = coordsDeMovimientoZoom.y;
        nuevoMovimiento_zoomIn->anteriorMovimientoZoom = historialZoom.ultimoMovimiento;
        historialZoom.ultimoMovimiento = nuevoMovimiento_zoomIn;
    }
}

sf::Vector2f Zoom::getPosicionAjustadaZoomIn(sf::Vector2f mousePositionPressZoom,int numeroDeZoom){
    int coordX_zoom,  coordY_zoom ;
    sf::Vector2f nuevasCoordenadasZoom;
    int escalaDePixelesInicial = 2;
    //if(historialZoom.ultimoMovimiento == NULL){ return nuevasCoordenadasZoom = sf::Vector2f(coordX_zoom,coordY_zoom);}

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
    nuevasCoordenadasZoom = sf::Vector2f(coordX_zoom,coordY_zoom);
    return nuevasCoordenadasZoom;
}

