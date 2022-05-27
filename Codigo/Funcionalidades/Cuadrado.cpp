//
// Created by ludwinr on 14/05/22.
//

#include "Cuadrado.h"

Cuadrado::Cuadrado() {

}

bool Cuadrado::logicCrearCuadrado(Datos_juego *datosJuego, sf::RectangleShape *cuadradoActualSeleccionado, sf::Vector2f coordsMouse) {
    bool SeSeleccionaElCuadrado = false;
    int coordMouseX = coordsMouse.x;
    int coordMouseY = coordsMouse.y;

    if (cuadradoActualSeleccionado->getSize().x == 0){
        crearCuadrado(datosJuego,cuadradoActualSeleccionado,coordsMouse);
        return SeSeleccionaElCuadrado;
    }
    float distanciaEntrePuntos_x = coordMouseX-cuadradoActualSeleccionado->getPosition().x;
    float distanciaEntrePuntos_y = coordMouseY-cuadradoActualSeleccionado->getPosition().y;
    int sizeDelLadoDelCuadrado = cuadradoActualSeleccionado->getSize().x;

    if (0<=distanciaEntrePuntos_x && distanciaEntrePuntos_x<=sizeDelLadoDelCuadrado && 0<=distanciaEntrePuntos_y && distanciaEntrePuntos_y <=sizeDelLadoDelCuadrado){
        SeSeleccionaElCuadrado = true;
        return SeSeleccionaElCuadrado;
    }
    else{
        crearCuadrado(datosJuego,cuadradoActualSeleccionado,coordsMouse);
        return SeSeleccionaElCuadrado;
    }
}
void Cuadrado::crearCuadrado(Datos_juego *datosJuego, sf::RectangleShape *cuadradoActual, sf::Vector2f coordsMouse) {
    float sizeLadoCuadrado = 50.0;
    int coordMouseX = coordsMouse.x;
    int coordMouseY = coordsMouse.y;

    sf::Vector2f dimensionCuadrado(sizeLadoCuadrado,sizeLadoCuadrado);
    *cuadradoActual = sf::RectangleShape(dimensionCuadrado);
    cuadradoActual->setPosition(coordMouseX-(sizeLadoCuadrado/2), coordMouseY-(sizeLadoCuadrado/2));
    cuadradoActual->setFillColor(sf::Color::Transparent);
    cuadradoActual->setOutlineColor(sf::Color(datosJuego->getColor_R(),datosJuego->getColor_G(),datosJuego->getColor_B(),255));
    cuadradoActual->setOutlineThickness(5.0);
}
