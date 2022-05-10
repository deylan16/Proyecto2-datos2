//
// Created by deyla on 25/4/2022.
//

#ifndef CODIGO_COMPONENTES_H
#define CODIGO_COMPONENTES_H
#include <iostream>
#include <SFML/Graphics.hpp>


class Componentes {
public:
    bool *ptrescibiendo;
    std::string entrada_texto;
    sf::Event event;
    sf::RenderWindow *ptrwindow ;
    int mousex;
    int mousey;



    void setPtrwindow( sf::RenderWindow *window);
    void setevent( sf::Event Event);
    void creaCajadeTexto(int posicionx, int posiciony, int ancho, int alto,std::string texto);
    void setposicion_mouse(int entrada_mousex,int entrada_mousey);
    bool creaBoton(int posicionx, int posiciony, int ancho, int alto,std::string texto);
    void creaLabel(int posicionx, int posiciony, int tamano,std::string texto);
    bool creaBoton_con_imagen(int posicionx, int posiciony, int ancho, int alto,std::string imagen);
    bool creaBoton_color(int posicionx, int posiciony, int ancho, int alto,int r,int g,int b);
};


#endif //CODIGO_COMPONENTES_H
