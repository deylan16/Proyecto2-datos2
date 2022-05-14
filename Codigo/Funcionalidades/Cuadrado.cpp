//
// Created by ludwinr on 14/05/22.
//

#include "Cuadrado.h"

Cuadrado::Cuadrado() {

}

bool Cuadrado::logicCrearCuadrado(sf::RenderWindow *window, sf::RectangleShape *cuadradoActualSeleccionado, float mouseX,float mouseY) {
    bool SeSeleccionaElCuadrado = false;

    if (cuadradoActualSeleccionado->getSize().x == 0){
        crearCuadrado(window,cuadradoActualSeleccionado,mouseX,mouseY);
        //cout<<"primer cuadrado"<<endl;
        return SeSeleccionaElCuadrado;
    }
    float distanciaEntrePuntos_x = mouseX-cuadradoActualSeleccionado->getPosition().x;
    float distanciaEntrePuntos_y = mouseY-cuadradoActualSeleccionado->getPosition().y;
    int sizeDelLadoDelCuadrado = cuadradoActualSeleccionado->getSize().x;

    if (0<=distanciaEntrePuntos_x && distanciaEntrePuntos_x<=sizeDelLadoDelCuadrado && 0<=distanciaEntrePuntos_y && distanciaEntrePuntos_y <=sizeDelLadoDelCuadrado){
        //cout<<"se presiona adentro"<<endl;
        SeSeleccionaElCuadrado = true;
        return SeSeleccionaElCuadrado;
    }
    else{
        crearCuadrado(window,cuadradoActualSeleccionado,mouseX,mouseY);
        //cout<<"se crea circulo al presionar afuera"<<endl;
        return SeSeleccionaElCuadrado;
    }

}
void Cuadrado::crearCuadrado(sf::RenderWindow *window, sf::RectangleShape *cuadradoActual, int mouseX,int mouseY) {
    float sizeLadoCuadrado = 50.0;
    sf::Vector2f dimensionCuadrado(sizeLadoCuadrado,sizeLadoCuadrado);
    *cuadradoActual = sf::RectangleShape(dimensionCuadrado);
    cuadradoActual->setPosition(mouseX-(sizeLadoCuadrado/2), mouseY-(sizeLadoCuadrado/2));
    cuadradoActual->setFillColor(sf::Color::Transparent);
    cuadradoActual->setOutlineColor(sf::Color::Black);
    cuadradoActual->setOutlineThickness(5.0);

}
