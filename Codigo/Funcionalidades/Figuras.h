//
// Created by ludwinr on 12/05/22.
//

#ifndef CODIGO_FIGURAS_H
#define CODIGO_FIGURAS_H

#include <SFML/Graphics.hpp>
#include "../Interfaz/Datos_juego.h"

class Figuras{
public:

    Figuras();
    bool CrearFiguraCirculo(Datos_juego *datosJuego,sf::CircleShape *figuraCirculo, sf::Vector2f coordsMouse,sf::Event event);
    bool CrearFiguraCuadrado(Datos_juego *datosJuego,sf::RectangleShape *figuraCuadrado, sf::Vector2f coordsMouse,sf::Event event);
    bool moverCirculo(sf::RenderWindow *window,sf::CircleShape *ultima_figuraSeleccionada,sf::Event event);
};

#endif //CODIGO_FIGURAS_H
