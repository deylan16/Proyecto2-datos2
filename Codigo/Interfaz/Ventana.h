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
#include "../BMP/Bmp.h"
#include "../Funcionalidades/PaintFill.h"
#include "../Funcionalidades/Seleccion_magica.h"

class Ventana {
public:

    sf::RenderWindow *ptrwindow ;
    sf::Event event;
    bool escribiendo = false;
    std::string entrada = "";
    int contador_botones = 7;
    int contador_original = 7;
    int multplicador_de_trazo = 2;
    bool matriz_lista = false;
    std::string modo_activo = "Ninguno";
    std::string orden_abrir = "Escogiendo";
    std::string orden_ventana_escogiendo = "Escogiendo";
    Matriz *RGB_pixeles_imagen = new Matriz();
    Lista_Doble<sf::RectangleShape> *lienzo = new Lista_Doble<sf::RectangleShape>();
    PaintFill colorDeRellenoLienzo = PaintFill();
    Seleccion_magica seleccion_magica = Seleccion_magica();

    Bmp *tre = new Bmp();

    int clicks_linea_seleccion = 0;
    float coords_linea_seleccion[2][2];
    int estado_seleccion_libre = 1;
    int trazo_seleccion_libre[10000];
    int trazo_seleccion_libre_indice = 0;


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
    void ventana_guardando();
    void ventana_elije_nueva_o_cargar();
    void ventana_elije_nueva_o_cargar_esta_elijiendo();

    void ventana_elije_nueva_o_cargar_ruta_absoluta();
    void verificando_imagen_a_cargar(char *ruta_entrante);
    void ventana_elije_nueva_o_cargar_crear_nuevo_lienzo();
    void creando_lienzo_nuevo(std::string dimensiones);

    void trazar_linea_recta(float coordenada_x_pixel1, float coordenada_y_pixel1,
                            float coordenada_x_pixel2, float coordenada_y_pixel2);

    void trazo_seleccion_libre_append(int coordenada);

    void seleccion_libre(float coordenada_x_pixel1, float coordenada_y_pixel1,
                         float coordenada_x_pixel2, float coordenada_y_pixel2);

    void crear_rectangulo(float coordenada_x_pixel1, float coordenada_y_pixel1,
                          float coordenada_x_pixel2, float coordenada_y_pixel2);

    void crear_circulo(float coordenada_x_borde1, float coordenada_y_borde1,
                       float coordenada_x_borde2, float coordenada_y_borde2);

    void cambiar_color_pixel_seleccion(int x, int y);

    void crear_triangulo(float coordenada_x_pixel1, float coordenada_y_pixel1, float coordenada_x_pixel2,
                         float coordenada_y_pixel2);
};

#endif //CODIGO_VENTANA_H
