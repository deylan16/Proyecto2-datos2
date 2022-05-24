//
// Created by deyla on 25/4/2022.
//

#include <thread>
#include "Ventana.h"
#include "../BMP/Bmp.h"
#include "../lista doblemente enlazada/Lista_pixeles.h"
#include <iostream>
using namespace std;


Ventana::Ventana(sf::RenderWindow *window) {
    this->ptrwindow = window;

}

void Ventana::ventana_principal() {

    //tre->SaveBMP("res3.bmp", &tre->info, tre->img);

    bool yo = true;

    while (ptrwindow->isOpen()){

        //componentes->setWindow(window);
        int mousex =sf::Mouse::getPosition(*ptrwindow).x;
        int mousey = sf::Mouse::getPosition( *ptrwindow).y;
        sf::Event Event{};
        event = Event;
        componentes->setPtrwindow(ptrwindow);
        componentes->setevent(event);
        componentes->ptrescibiendo = &escribiendo;
        componentes->setposicion_mouse(mousex,mousey);

        //sf::RenderWindow window(sf::VideoMode(tre->info.width, tre->info.height), "SFML works!");

        int contadorborrar = 1;
        while (ptrwindow->pollEvent(event)){

            color_R = datos->getColor_R(); color_G = datos->getColor_G(); color_B=datos->getColor_B();

            if (event.type == sf::Event::Closed)
                ptrwindow->close();

            if (escribiendo){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period) ){
                    if(contadorborrar == 1)
                        entrada.append(".");
                    contadorborrar = contadorborrar -1;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){
                    if(contadorborrar == 1)
                        entrada.append("a");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) ){
                    if(contadorborrar == 1)
                        entrada.append("b");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) ){
                    if(contadorborrar == 1)
                        entrada.append("c");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ){
                    if(contadorborrar == 1)
                        entrada.append("d");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) ){
                    if(contadorborrar == 1)
                        entrada.append("e");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) ){
                    if(contadorborrar == 1)
                        entrada.append("f");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) ){
                    if(contadorborrar == 1)
                        entrada.append("g");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) ){
                    if(contadorborrar == 1)
                        entrada.append("h");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) ){
                    if(contadorborrar == 1)
                        entrada.append("i");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) ){
                    if(contadorborrar == 1)
                        entrada.append("j");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) ){
                    if(contadorborrar == 1)
                        entrada.append("k");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) ){
                    if(contadorborrar == 1)
                        entrada.append("l");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) ){
                    if(contadorborrar == 1)
                        entrada.append("m");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) ){
                    if(contadorborrar == 1)
                        entrada.append("n");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) ){
                    if(contadorborrar == 1)
                        entrada.append("o");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) ){
                    if(contadorborrar == 1)
                        entrada.append("p");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ){
                    if(contadorborrar == 1)
                        entrada.append("q");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) ){
                    if(contadorborrar == 1)
                        entrada.append("r");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ){
                    if(contadorborrar == 1)
                        entrada.append("s");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) ){
                    if(contadorborrar == 1)
                        entrada.append("t");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) ){
                    if(contadorborrar == 1)
                        entrada.append("u");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) ){
                    if(contadorborrar == 1)
                        entrada.append("v");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ){
                    if(contadorborrar == 1)
                        entrada.append("w");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) ){
                    if(contadorborrar == 1)
                        entrada.append("x");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) ){
                    if(contadorborrar == 1)
                        entrada.append("y");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ){
                    if(contadorborrar == 1)
                        entrada.append("z");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) ){
                    if(contadorborrar == 1)
                        entrada.append("0");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) ){
                    if(contadorborrar == 1)
                        entrada.append("1");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) ){
                    if(contadorborrar == 1)
                        entrada.append("2");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) ){
                    if(contadorborrar == 1)
                        entrada.append("3");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) ){
                    if(contadorborrar == 1)
                        entrada.append("4");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) ){
                    if(contadorborrar == 1)
                        entrada.append("5");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) ){
                    if(contadorborrar == 1)
                        entrada.append("6");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) ){
                    if(contadorborrar == 1)
                        entrada.append("7");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) ){
                    if(contadorborrar == 1)
                        entrada.append("8");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) ){
                    if(contadorborrar == 1)
                        entrada.append("9");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) ){
                    if(contadorborrar == 1)
                        if(entrada != "")
                            entrada.pop_back();
                        contadorborrar = contadorborrar -1;
                }
            }
        }
        //ptrwindow->clear();
        if(orden_abrir == "Escogiendo"){
            ptrwindow->clear();
            ventana_elije_nueva_o_cargar();

        }
        else{
            sf::RectangleShape rectangulo(sf::Vector2f(1100.f, 100.f));
            rectangulo.setFillColor(sf::Color(146,151,158,255));
            rectangulo.setPosition(0,0);

            ptrwindow->draw(rectangulo);
            std::string prefijo_ruta = "Imagenes/";
            if(componentes->creaBoton_con_imagen(10, 10, 30, 30, prefijo_ruta + "Borrador.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    modo_activo = "borrador";
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(10, 60, 30, 30, prefijo_ruta + "Lapiz.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    modo_activo = "lapiz";
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(60, 10, 30, 30, prefijo_ruta + "picker.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    modo_activo = "picker";
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(60, 60, 30, 30, prefijo_ruta + "Lapicero.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(110, 10, 30, 30, prefijo_ruta + "paint_fill.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(110, 60, 30, 30, prefijo_ruta + "circulo.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //circulo
                    modo_activo = "circulo";
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(160, 10, 30, 30, prefijo_ruta + "Triangulo.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(160, 60, 30, 30, prefijo_ruta + "Cuadrado.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    modo_activo = "cuadrado";
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(210, 10, 30, 30, prefijo_ruta + "zoom_positivo.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(210, 60, 30, 30, prefijo_ruta + "zoom_negativo.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(260, 10, 30, 30, prefijo_ruta + "flip_horizontal.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->giro("flipHorizontal");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(260, 60, 30, 30, prefijo_ruta + "flip_vertical.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->giro("flipVertical");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();

                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(310, 10, 30, 30, prefijo_ruta + "giro_derecha.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->giro("90derecha");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(310, 60, 30, 30, prefijo_ruta + "giro_izquierda.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->giro("90izquierda");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(360, 10, 30, 30, prefijo_ruta + "seleccion_libre.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(360, 60, 30, 30, prefijo_ruta + "seleccion_rectangular.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton_con_imagen(410, 10, 30, 30, prefijo_ruta + "seleccion_magica.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(410, 60, 30, 30, "Ma")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    multplicador_de_trazo += 3;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(460, 60, 30, 30, "Me")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    if(multplicador_de_trazo >= 0)
                        multplicador_de_trazo -= 3;
                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            //if(componentes->creaBoton_color(460, 10, 30, 30, datos->rgb_color_seleccionado[0],datos->rgb_color_seleccionado[1],datos->rgb_color_seleccionado[2] )){
            if(componentes->creaBoton_color(460, 10, 30, 30, color_R,color_G,color_B )){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;

                    //seleccionar_jugador2 = true;
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(510, 10, 30, 30, "N")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->aplicar_filtro("negativo");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(510, 60, 30, 30, "G")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->aplicar_filtro("escala_grises");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(560, 10, 30, 30, "S")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    tre->SaveBMP("hola.bmp", &tre->info, tre->img);
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }

            if (yo){

                yo = false;
                for(int n = 0;n <RGB_pixeles_imagen->largo; n++)
                {
                    for (int u=0; u<RGB_pixeles_imagen->busqueda_indice(n)->largo; u+=1)
                    {
                        Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(n)->busqueda_indice(u);
                        //pixel->rectangulo.setFillColor(sf::Color(0,0,0,255));
                        ptrwindow->draw( pixel->rectangulo);

                    }
                }
                datos->RGB_pixeles_imagen = this->RGB_pixeles_imagen;

                matriz_lista = true;



            }
            if (modo_activo != "ninguno"){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    if(100<mousey && mousey<RGB_pixeles_imagen->largo+100 && 0<mousex && mousex<RGB_pixeles_imagen->busqueda_indice(0)->largo){
                        if(modo_activo == "borrador"){
                            cambiar_color_pixel_lienzo(mousex,mousey-100,255,255,255);
                        }
                        if(modo_activo == "picker"){
                            picker(mousex,mousey-100);
                        }
                        if(modo_activo == "circulo"){
                            figura_seleccionada = figurasPredeterminadas->CrearFiguraCirculo(datos,&circuloActual, sf::Vector2f (mousex,mousey),event);
                            ptrwindow->draw(circuloActual);
                        }
                        if(modo_activo == "cuadrado"){
                            figura_seleccionada = figurasPredeterminadas->CrearFiguraCuadrado(datos,&cuadradoActual,sf::Vector2f (mousex,mousey),event);
                            ptrwindow->draw(cuadradoActual);
                        }
                        if (modo_activo =="lapiz"){
                            cambiar_color_pixel_lienzo(mousex,mousey-100,color_R,color_G,color_B);
                        }
                    }
            }
        }









        ptrwindow->display();
    }

}

void Ventana::cambiar_color_pixel_lienzo(int x, int y,int r,int g,int b) {
    if(multplicador_de_trazo == 0 ){
        if(RGB_pixeles_imagen->busqueda_indice(y) != NULL){
            Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(y)->busqueda_indice(x);
            if(pixel != NULL)
            {
                pixel->R = r;
                pixel->B = b;
                pixel->G = g;
                pixel->rectangulo.setFillColor(sf::Color(r,g,b,255));
                //redibuja_la_imagen();
                ptrwindow->draw( pixel->rectangulo);
            }
        }
    }

    if(multplicador_de_trazo != 0){
        x -= multplicador_de_trazo;
        y -= multplicador_de_trazo;
        for(int a = 0;a <3+multplicador_de_trazo; a++)
        {
            for(int l = 0;l <3+multplicador_de_trazo; l++)
            {
                if(RGB_pixeles_imagen->busqueda_indice(y+a) != NULL){
                    Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(y+a)->busqueda_indice(x+l);
                    if(pixel != NULL)
                    {
                        pixel->R = r;
                        pixel->B = b;
                        pixel->G = g;
                        pixel->rectangulo.setFillColor(sf::Color(r,g,b,255));
                        //redibuja_la_imagen();
                        ptrwindow->draw( pixel->rectangulo);
                    }
                }
            }
        }

    }
}

void Ventana::cambiar_color_seleccionado( int r, int g, int b) {
    //datos->rgb_color_seleccionado[0] = r;
    //datos->rgb_color_seleccionado[1] = g;
    //datos->rgb_color_seleccionado[2] = b;
    datos->setRGBcolor_seleccionado(r,g,b);

}

void Ventana::picker(int x, int y) {
    if(RGB_pixeles_imagen->busqueda_indice(y) != NULL){
        Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(y)->busqueda_indice(x);
        if(pixel != NULL){
            cambiar_color_seleccionado(pixel->R,pixel->G,pixel->B);
        }
    }

}

void Ventana:: redibuja_la_imagen() {

    Nodo_matriz *fila2 = datos->RGB_pixeles_imagen->Inicio;
    Lista_pixeles *fila = fila2->dato;
    Nodo_pixel *pixel = fila->Inicio;
    int largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;

    for(int n = 0;n <datos->RGB_pixeles_imagen->largo-2; n++)
    {
        for (int u=0; u<largo_columnas ;u+=1)
        {

            //pixel->rectangulo.setFillColor(sf::Color(0,0,0,255));
            pixel->rectangulo.setPosition(u,n+100);
            ptrwindow->draw( pixel->rectangulo);
            pixel = pixel->next;
        }
        fila2 = fila2->next;
        fila = fila2->dato;
        pixel = fila->Inicio;
    }
}

void Ventana::renderizar() {
    redibuja_la_imagen();

}

void Ventana::ventana_elije_nueva_o_cargar() {
    componentes->creaLabel(0,0,30,"Bienvenido a paint++");
    componentes->creaLabel(0,40,30,"Que deseas hacer");
    if(orden_ventana_escogiendo == "Escogiendo"){
        ventana_elije_nueva_o_cargar_esta_elijiendo();

    }
    if(orden_ventana_escogiendo == "Escribiendo ruta"){
        ventana_elije_nueva_o_cargar_ruta_absoluta();

    }
    if(orden_ventana_escogiendo == "Elijio nueva"){
        ventana_elije_nueva_o_cargar_crear_nuevo_lienzo();

    }




}

void Ventana::ventana_elije_nueva_o_cargar_esta_elijiendo() {
    if(componentes->creaBoton(0, 80, 300, 30, "Nueva")){
        contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
        if (contador_botones == 0){
            std::cout<<"koka"<<std::endl;
            orden_ventana_escogiendo = "Elijio nueva";

            contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
        }
    }
    if(componentes->creaBoton(0, 120, 300, 30, "Cargar")){
        contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
        if (contador_botones == 0){
            std::cout<<"koka"<<std::endl;
            orden_ventana_escogiendo = "Escribiendo ruta";


            contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
        }
    }
}

void Ventana::ventana_elije_nueva_o_cargar_ruta_absoluta() {
    componentes->creaLabel(0,80,30,"Por favor escribe la ruta absoluta o el nombre en caso de estar en la carpeta predeterminada");

    componentes->creaCajadeTexto(0,120,300,30,entrada);
    if(componentes->creaBoton(0, 160, 300, 30, "Aceptar")){
        contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
        if (contador_botones == 0){
            std::cout<<"koka"<<std::endl;
            std::cout<<entrada[0]<<std::endl;



            verificando_imagen_a_cargar(const_cast<char *>(entrada.c_str()));


            contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
        }
    }

}

void Ventana::verificando_imagen_a_cargar(char *ruta_entrante) {

    FILE *f;
    char ruta_n;

    std::cout<<"***"<<ruta_entrante<<std::endl;
    f=fopen (ruta_entrante, "r");


    if (!f)
        componentes->creaLabel(0,200,30,"Error en la ruta");
    else{


        tre->img=tre->LoadBMP(ruta_entrante, &tre->info);
        tre->DisplayInfo(&tre->info);
        orden_abrir = "paint";
        for (int y=tre->info.height; y>0; y-=1)
        {
            Lista_pixeles *fila = new Lista_pixeles();
            for (int x=0; x<tre->info.width; x+=1)
            {
                //std::cout<<3*(x+y*info.width)<<std::endl;


                int b=(tre->img[4*(x+y*tre->info.width)]);
                int g=(tre->img[4*(x+y*tre->info.width)+1]);
                int r=(tre->img[4*(x+y*tre->info.width)+2]);
                int a = (tre->img[4*(x+y*tre->info.width)+3]);
                //std::cout<<"["<<r<<","<<g<<","<<b<<"]"<<std::endl;

                //printf("%c", colores[b+g*2+r*4]);
                sf::RectangleShape rectangulo(sf::Vector2f(1.f, 1.f));
                rectangulo.setFillColor(sf::Color(r,g,b,255));
                rectangulo.setPosition(x,(tre->info.height-y)+100);
                lienzo->append(rectangulo);
                fila->append(r,g,b,rectangulo);
                fila->Final->A = a;
                //ptrwindow->draw(rectangulo);
            }
            RGB_pixeles_imagen->append(fila);


        }
        ptrwindow->clear();

    }

}

void Ventana::ventana_elije_nueva_o_cargar_crear_nuevo_lienzo() {
    componentes->creaLabel(0,80,30,"Por favor escribe el ancho y alto(anchoxalto)");
    componentes->creaCajadeTexto(0,120,300,30,entrada);
    if(componentes->creaBoton(0, 160, 300, 30, "Aceptar")){
        contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
        if (contador_botones == 0){
            std::cout<<"koka"<<std::endl;
            creando_lienzo_nuevo(entrada);





            contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
        }
    }

}

void Ventana::creando_lienzo_nuevo(std::string dimensiones) {
    std::string ancho = "";
    std::string alto = "";
    std::string division = "x";
    int tracto = 1;
    for(int i = 0;i < dimensiones.length();i++){

        std::string letra;
        letra += dimensiones[i];
        std::cout<<letra <<std::endl;
        if(letra != "x"){
            if(tracto == 1){
                ancho +=dimensiones[i];
            }
            else{
                alto+=dimensiones[i];
            }
        }
        else
            tracto = 2;

    }
    std::cout<<ancho<<"w"<<alto<<std::endl;
    orden_abrir = "paint";
    for (int y=0; y< std::stoi(alto); y++)
    {
        Lista_pixeles *fila = new Lista_pixeles();
        for (int x=0; x<std::stoi(ancho) ;x+=1)
        {
            //std::cout<<3*(x+y*info.width)<<std::endl;


            int b=255;
            int g=255;
            int r=255;
            int a = 255;
            //std::cout<<"["<<r<<","<<g<<","<<b<<"]"<<std::endl;

            //printf("%c", colores[b+g*2+r*4]);
            sf::RectangleShape rectangulo(sf::Vector2f(1.f, 1.f));
            rectangulo.setFillColor(sf::Color(r,g,b,255));
            rectangulo.setPosition(x,y+100);
            lienzo->append(rectangulo);
            fila->append(r,g,b,rectangulo);
            fila->Final->A = a;
            //ptrwindow->draw(rectangulo);
        }
        RGB_pixeles_imagen->append(fila);


    }
    ptrwindow->clear();


}

