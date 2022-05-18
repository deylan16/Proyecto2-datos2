//
// Created by deyla on 25/4/2022.
//

#ifndef CODIGO_VENTANA_H
#define CODIGO_VENTANA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Componentes.h"
#include "../lista doblemente enlazada/Lista_Doble.h"
#include "../lista doblemente enlazada/Matriz.h"
#include "Datos_juego.h"
#include "../Funcionalidades/Facade_funciones.h"
#include "../Funcionalidades/Figuras.h"

class Ventana {
public:

    sf::RenderWindow *ptrwindow ;
    sf::Event event;
    bool escribiendo = false;
    std::string entrada = "";
    int contador_botones = 8;
    int contador_original = 8;
    int multplicador_de_trazo = 2;
    bool matriz_lista = false;
    std::string modo_activo = "Ninguno";
    Matriz *RGB_pixeles_imagen = new Matriz();
    Lista_Doble<sf::RectangleShape> *lienzo = new Lista_Doble<sf::RectangleShape>();

    // Relacionado con las figuras predeterminadas
    bool figura_seleccionada = false;
    sf::CircleShape circuloActual = sf::CircleShape(0);
    sf::RectangleShape cuadradoActual = sf::RectangleShape(sf::Vector2f(0,0));
    Figuras *figurasPredeterminadas;

    // Elementos visuales
    Componentes *componentes = new Componentes();
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");
    int color_R,color_G,color_B;
    Facade_funciones *funciones = Facade_funciones::GetInstance("Informacion");

    Ventana( sf::RenderWindow *window);
    void ventana_principal();
    void cambiar_color_pixel_lienzo(int x,int y,int r,int g,int b);
    void cambiar_color_seleccionado(int r,int g,int b);
    void picker(int x, int y);
    void redibuja_la_imagen();
    void renderizar();

    void trazar_linea_recta(float coordenada_x_pixel1, float coordenada_y_pixel1,
                            float coordenada_x_pixel2, float coordenada_y_pixel2);

    void seleccion_rectangular(float coordenada_x_pixel1, float coordenada_y_pixel1,
                               float coordenada_x_pixel2, float coordenada_y_pixel2);

    void seleccion_libre(int x, int y);
};


#endif //CODIGO_VENTANA_H
