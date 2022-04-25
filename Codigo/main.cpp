#include <iostream>
#include "Interfaz/Ventana.h"
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(1100,1000),"Memoria");
    sf::RenderWindow *ptrwindow;
    ptrwindow = &window;

    Ventana *ventana = new Ventana(ptrwindow);
    ventana->ventana_principal();
    return 0;
}
