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
    void zoom_in(sf::Vector2f coordsMouse, int numeroDeZoom);
    void zoom_out(int numeroDeZoom);

private:
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");
    sf::Vector2f getPositionZoom(sf::Vector2f mousePositionPressZoom,int numeroDeZoom);
    int largo_columnas;
    int largo_filas;
    HistorialZoom historialZoom;
};


#endif //CODIGO_ZOOM_H
