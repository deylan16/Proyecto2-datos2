//
// Created by ludwinr on 12/05/22.
//

#include "Figuras.h"

#include <SFML/Graphics.hpp>
#include "Circulo.h"
#include "Cuadrado.h"
using namespace std;

Figuras::Figuras() {
}

bool Figuras::CrearFiguraCirculo(Datos_juego *datosJuego, sf::CircleShape *figuraCirculo, sf::Vector2f coordsMouse, sf::Event event) {
    bool sePresionaElLienzoEnModoCirculo = false; /* se realiza, debido a que al presionar un boton puede
                                                    que se presione mas de una vez automaticamente*/
    switch(event.type){
        case sf::Event::MouseButtonPressed:{
            Circulo circulo = Circulo();
            bool CreaUnCirculo = circulo.logicCrearCirculo(datosJuego,figuraCirculo,coordsMouse);
            return CreaUnCirculo;
         }
         default:
            return sePresionaElLienzoEnModoCirculo;
    }
}
bool Figuras::CrearFiguraCuadrado(Datos_juego *datosJuego, sf::RectangleShape *figuraCuadrado, sf::Vector2f coordsMouse, sf::Event event) {
    bool sePresionaElLienzoEnModoCuadrado = false; /* se realiza, debido a que al presionar un boton puede
                                                    que se presione mas de una vez automaticamente*/
    switch(event.type){
        case sf::Event::MouseButtonPressed:{
            Cuadrado cuadrado = Cuadrado();
            bool CreaUnCuadrado = cuadrado.logicCrearCuadrado(datosJuego,figuraCuadrado,coordsMouse);
            return CreaUnCuadrado;
        }
        default:
            return sePresionaElLienzoEnModoCuadrado;
    }
}
// no se esta implementando, omitala
bool Figuras::moverCirculo(sf::RenderWindow *window, sf::CircleShape *ultima_figuraSeleccionada,sf::Event event){
    Circulo circulo = Circulo();
    bool resultado = circulo.movimientoCirculo(window,ultima_figuraSeleccionada,event);
}
