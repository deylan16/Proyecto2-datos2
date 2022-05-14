//
// Created by ludwinr on 12/05/22.
//

#ifndef CODIGO_FIGURAS_H
#define CODIGO_FIGURAS_H

#include <SFML/Graphics.hpp>

class Figuras{
public:
    Figuras();
    bool CrearCirculo(sf::RenderWindow *window,sf::CircleShape *figuraCirculo, int mouseX, int mouseY,sf::Event event);
    bool CrearCuadrado(sf::RenderWindow *window,sf::RectangleShape *figuraCuadrado, int mouseX, int mouseY,sf::Event event);
    bool moverCirculo(sf::RenderWindow *window,sf::CircleShape *ultima_figuraSeleccionada,sf::Event event);
};

#endif //CODIGO_FIGURAS_H
