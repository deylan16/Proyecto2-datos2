#include <iostream>
#include "Interfaz/Ventana.h"
#include "lista doblemente enlazada/Lista_doble.h"
#include "lista doblemente enlazada/Matriz.h"
#include "lista doblemente enlazada/Lista_pixeles.h"
#include "BMP/Bmp.h"

//#include <SFML/Graphics.hpp>

void carro()
{
    /*Lista_doble<std::string> *hola = new Lista_doble<std::string>();
    hola->append("tole");
    hola->append("edfg");
    hola->append("agua");
    hola->print();
    std::cout<<hola->busqueda_indice(3)<<std::endl;
    Lista_doble<std::string> *hola2 = new Lista_doble<std::string>();
    hola2->append("3");
    hola2->append("2");
    hola2->append("3");
    hola2->print();
    hola->append("arriiba");
    hola->print();*/

    Lista_pixeles *saa = new Lista_pixeles();
    saa->append(43,89,100);
    saa->append(30,93,170);
    saa->append(56,60,255);
    saa->print();
    Lista_pixeles *saa2 = new Lista_pixeles();
    saa2->append(23,89,100);
    saa2->append(70,93,170);
    saa2->append(96,60,255);
    saa2->print();
    int hi = saa->busqueda_indice(1)->R;
    std::cout<<hi<<std::endl;


    Matriz *tome = new Matriz();
    tome->append(saa);
    tome->append(saa2);

    tome->print();
    std::cout<<tome->busqueda_indice(0)->busqueda_indice(1)->R<<std::endl;


}

int main() {
    /*sf::RenderWindow window(sf::VideoMode(1100,1000),"Memoria");
    sf::RenderWindow *ptrwindow;
    ptrwindow = &window;

    Ventana *ventana = new Ventana(ptrwindow);
    ventana->ventana_principal();*/
    //carro();
    //printf("%d",sizeof(unsigned short));
    //printf("%d",sizeof(unsigned int));
    //printf("%d",sizeof(unsigned long));
    //printf("%d",sizeof(unsigned char));
    Bmp *Abridor = new Bmp();

    FILE* fp = Abridor->Abrir_Bmp("C:\\Users\\deyla\\OneDrive\\Escritorio\\Programacion\\c++\\manejo bmp\\tome.bmp","r");
    //BITMAPFILEHEADER* fileHead = readBmpFileHead(fp);
    //BITMAPINFOHEADER* infoHead = readBmpInfoHead(fp);
    RGBDATA ** data = Abridor->Leer_array_de_pixeles_BMP(fp);

    // Tenga cuidado de evitar subíndices fuera de los límites
    /*for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            printf ("El primer píxel (% d,% d): [% d,% d,% d] \n", 511-i, j + 1, data [i] [j] .blue, data [i] [ j] .green, data [i] [j] .red);
        }
        printf("\n");
    }*/
    //closeBmpImage(fp);
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
    /*sf::RectangleShape rectangulo(sf::Vector2f(1.f, 1.f));
    /rectangulo.setFillColor(sf::Color(data[0][0].red,data[0][0].green,data[0][0].blue,255));
    rectangulo.setFillColor(sf::Color(255,0,0,255));*/
    bool hos = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < 512; i++) {
            for (int j = 0; j < 512; j++) {
                sf::RectangleShape rectangulo(sf::Vector2f(1.f, 1.f));
                rectangulo.setFillColor(sf::Color(data[i][j].red,data[i][j].green,data[i][j].blue,255));
                rectangulo.setPosition(i,j);
                window.draw(rectangulo);
            }

        }

        window.display();
    }
    return 0;
}
//
/*
 g++ -c main.cpp
g++ -c Interfaz/Componentes.cpp
g++ Componentes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
g++ -c Interfaz/Ventana.cpp
g++ Ventana.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system


g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
  */

/*
g++ -c Interfaz/Componentes.cpp
g++ Componentes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

g++ -c Interfaz/Ventana.cpp
g++ Ventana.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system


./sfml-app
  */