//
// Created by ludwinr on 25/05/22.
//

#ifndef CODIGO_ZOOM_H
#define CODIGO_ZOOM_H
#include <SFML/Graphics.hpp>
#include "../Interfaz/Datos_juego.h"

struct MovimientosZoom{
    MovimientosZoom *anteriorMovimientoZoom;
    int zoomSelectionPosicion_X;
    int zoomSelectionPosicion_Y;
};

struct HistorialZoom{
    MovimientosZoom *ultimoMovimiento;
};

class Zoom {
public:
    Zoom();
    sf::RenderWindow *ptrWindow;
    void realizarZoom(sf::Vector2f coordsMouse, int numeroDeZoom, char tipoZoom);

private:
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");
    void zoom_in(sf::Vector2f coordsMouse, int numeroDeZoom);
    void zoom_out(int numeroDeZoom);
    void logicZoom(sf::Vector2f coordsMouse,int numeroDeZoom);

    sf::Vector2f getPosicionAjustadaZoomIn(sf::Vector2f mousePositionPressZoom,int numeroDeZoom);
    sf::Vector2f getPosicionAjustadaZoomOut(sf::Vector2f mousePositionPressZoom,int numeroDeZoom);
    void actualizarHistorialDeMovimientosZoom(sf::Vector2f coordsDeMovimientoZoom);

    int largo_columnas;
    int largo_filas;
    HistorialZoom historialZoom;
    bool seLlama_A_zoomIn;
    bool historialMovimientosZoomNulo;
};


#endif //CODIGO_ZOOM_H
