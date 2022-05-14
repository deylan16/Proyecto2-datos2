//
// Created by ludwinr on 14/05/22.
//

#ifndef CODIGO_CUADRADO_H
#define CODIGO_CUADRADO_H

#include <SFML/Graphics.hpp>

class Cuadrado{

public:
    Cuadrado();

    bool logicCrearCuadrado(sf::RenderWindow *window,sf::RectangleShape *cuadradoActualSeleccionado, float mouseX, float mouseY);
    void crearCuadrado(sf::RenderWindow *window,sf::RectangleShape *cuadradoActual,int mouseX, int mouseY);
};

#endif //CODIGO_CUADRADO_H
