//
// Created by ludwinr on 12/05/22.
//

#include "Circulo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Circulo::Circulo() {

}

bool Circulo::logicCrearCirculo(Datos_juego *datosJuego, sf::CircleShape *circuloActualSeleccionado, sf::Vector2f coordsMouse) {
    bool SeSeleccionaElCirculo = false;
    int coordMouseX = coordsMouse.x;
    int coordMouseY = coordsMouse.y;

    if (circuloActualSeleccionado->getRadius() == 0){
        crearCirculo(datosJuego,circuloActualSeleccionado, coordsMouse);
        cout<<"primer circulo"<<endl;
        return SeSeleccionaElCirculo;
    }
    float distanciaEntrePuntos_x = coordMouseX-circuloActualSeleccionado->getPosition().x;
    float distanciaEntrePuntos_y = coordMouseY-circuloActualSeleccionado->getPosition().y;
    int radioCirculo = circuloActualSeleccionado->getRadius();

    if (0<=distanciaEntrePuntos_x && distanciaEntrePuntos_x<=2*radioCirculo && 0<=distanciaEntrePuntos_y && distanciaEntrePuntos_y <=2*radioCirculo){
        SeSeleccionaElCirculo = true;
        return SeSeleccionaElCirculo;
    }
    else{
        crearCirculo(datosJuego,circuloActualSeleccionado,coordsMouse);
        return SeSeleccionaElCirculo;
    }
}
void Circulo::crearCirculo(Datos_juego *datosJuego,sf::CircleShape *circuloActual, sf::Vector2f coordsMouse) {
    int radio = 40;
    int coordMouseX = coordsMouse.x;
    int coordMouseY = coordsMouse.y;
    *circuloActual = sf::CircleShape(radio);
    circuloActual->setPosition(coordMouseX-radio, coordMouseY-radio);
    circuloActual->setFillColor(sf::Color::Transparent);
    circuloActual->setOutlineColor(sf::Color(datosJuego->getColor_R(),datosJuego->getColor_G(),datosJuego->getColor_B(),255));
    circuloActual->setOutlineThickness(5.0);
}
