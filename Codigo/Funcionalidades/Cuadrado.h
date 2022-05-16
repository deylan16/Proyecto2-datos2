//
// Created by ludwinr on 14/05/22.
//

#ifndef CODIGO_CUADRADO_H
#define CODIGO_CUADRADO_H

#include <SFML/Graphics.hpp>
#include "../Interfaz/Datos_juego.h"

class Cuadrado{

public:
    Cuadrado();

    bool logicCrearCuadrado(Datos_juego *datosJuego,sf::RectangleShape *cuadradoActualSeleccionado, sf::Vector2f coordsMouse);
    void crearCuadrado(Datos_juego *datosJuego,sf::RectangleShape *cuadradoActual,sf::Vector2f coordsMouse);
};

#endif //CODIGO_CUADRADO_H
