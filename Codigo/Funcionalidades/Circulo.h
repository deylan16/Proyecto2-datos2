//
// Created by ludwinr on 12/05/22.
//

#ifndef CODIGO_CIRCULO_H
#define CODIGO_CIRCULO_H

#include <SFML/Graphics.hpp>

class Circulo{

public:
    Circulo();

    bool logicCrearCirculo(sf::RenderWindow *window,sf::CircleShape *circuloActualSeleccionado, float mouseX, float mouseY);
    void crearCirculo(sf::RenderWindow *window,sf::CircleShape *circuloActual,int mouseX, int mouseY);
    bool movimientoCirculo(sf::RenderWindow *window,sf::CircleShape *ultima_figuraSeleccionada,sf::Event event);
};


#endif //CODIGO_CIRCULO_H
