//
// Created by ludwinr on 12/05/22.
//

#include "Circulo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Circulo::Circulo() {

}

bool Circulo::logicCrearCirculo(sf::RenderWindow *window, sf::CircleShape *circuloActualSeleccionado, float mouseX, float mouseY) {
    bool SeSeleccionaElCirculo = false;

    if (circuloActualSeleccionado->getRadius() == 0){
        crearCirculo(window,circuloActualSeleccionado,mouseX,mouseY);
        cout<<"primer circulo"<<endl;
        return SeSeleccionaElCirculo;
    }
    float distanciaEntrePuntos_x = mouseX-circuloActualSeleccionado->getPosition().x;
    float distanciaEntrePuntos_y = mouseY-circuloActualSeleccionado->getPosition().y;
    int radioCirculo = circuloActualSeleccionado->getRadius();

    if (0<=distanciaEntrePuntos_x && distanciaEntrePuntos_x<=2*radioCirculo && 0<=distanciaEntrePuntos_y && distanciaEntrePuntos_y <=2*radioCirculo){
        //cout<<"se presiona adentro"<<endl;
        SeSeleccionaElCirculo = true;
        return SeSeleccionaElCirculo;
    }
    else{
        crearCirculo(window,circuloActualSeleccionado,mouseX,mouseY);
        //cout<<"se crea circulo al presionar afuera"<<endl;
        return SeSeleccionaElCirculo;
    }
}
void Circulo::crearCirculo(sf::RenderWindow *window,sf::CircleShape *circuloActual, int mouseX, int mouseY) {
    int radio = 40;
    *circuloActual = sf::CircleShape(radio);
    circuloActual->setPosition(mouseX-radio, mouseY-radio);
    circuloActual->setFillColor(sf::Color::Transparent);
    circuloActual->setOutlineColor(sf::Color::Black);
    circuloActual->setOutlineThickness(5.0);
}

//no se esta implementando aun
bool Circulo::movimientoCirculo(sf::RenderWindow *window, sf::CircleShape *ultima_figuraSeleccionada,sf::Event event){
    //float x_posicionExactaMovimiento = sf::Mouse::getPosition(*window).x-ultima_figuraSeleccionada->getPosition().x;
    //float y_posicionExactaMovimiento = sf::Mouse::getPosition(*window).y-ultima_figuraSeleccionada->getPosition().y;
    bool seSeleccionaFigura = true;

    ultima_figuraSeleccionada->setPosition(sf::Mouse::getPosition(*window).x/*-x_posicionExactaMovimiento*/,sf::Mouse::getPosition(*window).y/*-y_posicionExactaMovimiento*/);

    /*switch (event.type) {
        case sf::Event::MouseMoved:{
            cout<<"se modifica la posicion"<<endl;
            ultima_figuraSeleccionada->setPosition(sf::Mouse::getPosition(*window).x/*-x_posicionExactaMovimiento*///, sf::Mouse::getPosition(*window).y/*-y_posicionExactaMovimiento*/);
           /* break;
        }
        case sf::Event::MouseButtonReleased:{
            seSeleccionaFigura = false;
            //ultima_figuraSeleccionada->setOutlineColor(sf::Color::Yellow);
            break;
        }
        default:
            break;
    }*/
    //printf("si pasa\n");
    window->draw(*ultima_figuraSeleccionada);
    return seSeleccionaFigura;
}