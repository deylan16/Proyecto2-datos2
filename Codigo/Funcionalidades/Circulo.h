//
// Created by ludwinr on 12/05/22.
//

#ifndef CODIGO_CIRCULO_H
#define CODIGO_CIRCULO_H

#include <SFML/Graphics.hpp>
#include "../Interfaz/Datos_juego.h"

class Circulo{

public:
    Circulo();
    bool logicCrearCirculo(Datos_juego *datosJuego,sf::CircleShape *circuloActualSeleccionado, sf::Vector2f coordsMouse);
    void crearCirculo(Datos_juego *datosJuego,sf::CircleShape *circuloActual,sf::Vector2f coordsMouse);
};


#endif //CODIGO_CIRCULO_H
