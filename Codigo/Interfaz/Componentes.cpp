//
// Created by deyla on 25/4/2022.
//

#include "Componentes.h"
void Componentes::creaCajadeTexto(int posicionx, int posiciony, int ancho, int alto,std::string texto) {
    sf::RectangleShape CajadeTextoNombreJugador(sf::Vector2f(ancho,alto));CajadeTextoNombreJugador.setPosition(posicionx,posiciony);CajadeTextoNombreJugador.setFillColor(sf::Color::Blue);ptrwindow->draw(CajadeTextoNombreJugador);
    sf::Font font2;
    font2.loadFromFile("../AltonaSans-Regular.ttf");
    sf::Text text2;
    text2.setFont(font2);
    text2.setString(texto),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(posicionx,posiciony),ptrwindow->draw(text2);

    if (posicionx<this->mousex && this->mousex<(posicionx+ancho) && this->mousey<(posiciony+alto) && this->mousey>posiciony)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            *ptrescibiendo = true;}
}

void Componentes::setPtrwindow(sf::RenderWindow *window) {
    this->ptrwindow = window;

}

void Componentes::setevent(sf::Event Event) {
    this->event = Event;

}

void Componentes::setposicion_mouse(int entrada_mousex, int entrada_mousey) {
    this->mousex = entrada_mousex;
    this->mousey = entrada_mousey;

}

bool Componentes::creaBoton(int posicionx, int posiciony, int ancho, int alto,std::string texto) {
    sf::Font font2;
    font2.loadFromFile("../AltonaSans-Regular.ttf");
    sf::Text text2;
    text2.setFont(font2);
    sf::RectangleShape BotonAceptar(sf::Vector2f(ancho,alto));BotonAceptar.setPosition(posicionx,posiciony);BotonAceptar.setFillColor(sf::Color::Blue);ptrwindow->draw(BotonAceptar);
    text2.setString(texto),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(posicionx+5,posiciony-5),ptrwindow->draw(text2);
    if (posicionx<this->mousex && this->mousex<(posicionx+ancho) && this->mousey<(posiciony+alto) && this->mousey>posiciony){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            return true;
            //Scliente.Enviar(entrada);
        }
        else
            return false;
    }
    else
        return false;

}

void Componentes::creaLabel(int posicionx, int posiciony, int tamano,std::string texto) {
    sf::Font font2;
    font2.loadFromFile("../AltonaSans-Regular.ttf");
    sf::Text text2;
    text2.setFont(font2);
    text2.setString(texto),text2.setCharacterSize(tamano),text2.setFillColor(sf::Color::Green),text2.setPosition(posicionx,posiciony),ptrwindow->draw(text2);


}

bool Componentes::creaBoton_con_imagen(int posicionx, int posiciony, int ancho, int alto,std::string imagen) {
    sf::Texture textura;
    if(!textura.loadFromFile(imagen))
        std::cout<<"fallo";
    sf::Sprite sprite;
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0,0,ancho,alto));
    sprite.setPosition(posicionx,posiciony);
    ptrwindow->draw(sprite);
    if (posicionx<this->mousex && this->mousex<(posicionx+ancho) && this->mousey<(posiciony+alto) && this->mousey>posiciony){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            return true;
            //Scliente.Enviar(entrada);
        }
        else
            return false;
    }
    else
        return false;
}






