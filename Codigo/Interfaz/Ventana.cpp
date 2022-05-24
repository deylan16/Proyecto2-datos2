//
// Created by deyla on 25/4/2022.
//

#include <thread>
#include "Ventana.h"
#include "../BMP/Bmp.h"
#include "../lista doblemente enlazada/Lista_pixeles.h"
#include <iostream>
#include <unistd.h>
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

        if(orden_abrir == "Guardando"){
            ventana_guardando();


        }
        if(orden_abrir == "paint"){
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
                modo_activo = "lapicero";
                //seleccionar_jugador2 = true;
                contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces

            }

            }
            if(componentes->creaBoton_con_imagen(110, 10, 30, 30, prefijo_ruta + "paint_fill.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    modo_activo = "paintFill";
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
                modo_activo = "seleccion_libre";
                if(estado_seleccion_libre % 2 == 0){
                    std::cout<<"Estado Par"<<std::endl;

                    seleccion_libre(trazo_seleccion_libre[0],
                                    trazo_seleccion_libre[1],
                                    trazo_seleccion_libre[trazo_seleccion_libre_indice-2],
                                    trazo_seleccion_libre[trazo_seleccion_libre_indice-1]);
                    trazo_seleccion_libre_indice = 0;
                }
                estado_seleccion_libre++;
                sleep(1);
                //seleccionar_jugador2 = true;
                contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
            }
        }
            if(componentes->creaBoton_con_imagen(360, 60, 30, 30, prefijo_ruta + "seleccion_rectangular.png")){
            contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
            if (contador_botones == 0){
                std::cout<<"koka"<<std::endl;
                modo_activo = "seleccion_rectangular";
                //seleccionar_jugador2 = true;
                contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
            }
        }
            if(componentes->creaBoton_con_imagen(410, 10, 30, 30, prefijo_ruta + "seleccion_magica.png")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    modo_activo = "seleccion_magica";
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
                    ptrwindow->clear();
                    orden_abrir = "Guardando";

                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(560, 60, 30, 30, "T")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->aplicar_filtro("trueque");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(610, 60, 30, 30, "D")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    funciones->aplicar_filtro("Dividir");
                    ptrwindow->clear();
                    RGB_pixeles_imagen = datos->RGB_pixeles_imagen;
                    redibuja_la_imagen();
                    ptrwindow->display();
                    contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
                }
            }
            if(componentes->creaBoton(1000, 10, 100, 30, "Render")){
                contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
                if (contador_botones == 0){
                    std::cout<<"koka"<<std::endl;
                    std::cout << "Redibujando..." << std::endl;
                    redibuja_la_imagen();
                    //seleccionar_jugador2 = true;
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
                        clicks_linea_seleccion += 1;
                        coords_linea_seleccion[clicks_linea_seleccion - 1][0] = (float)mousex;
                        coords_linea_seleccion[clicks_linea_seleccion - 1][1] = (float)mousey;
                        sleep(1);
                        if (clicks_linea_seleccion == 2)
                        {
                            crear_rectangulo(coords_linea_seleccion[0][0], coords_linea_seleccion[0][1],
                                             coords_linea_seleccion[1][0], coords_linea_seleccion[1][1]);
                            clicks_linea_seleccion = 0;
                        }
                    }
                    if (modo_activo =="lapiz"){
                        cambiar_color_pixel_lienzo(mousex,mousey-100,color_R,color_G,color_B);
                    }
                    if(modo_activo == "lapicero"){
                        clicks_linea_seleccion += 1;
                        coords_linea_seleccion[clicks_linea_seleccion - 1][0] = (float)mousex;
                        coords_linea_seleccion[clicks_linea_seleccion - 1][1] = (float)mousey;
                        sleep(1);
                        if (clicks_linea_seleccion == 2)
                        {
                            trazar_linea_recta(coords_linea_seleccion[0][0], coords_linea_seleccion[0][1],
                                               coords_linea_seleccion[1][0], coords_linea_seleccion[1][1]);
                            clicks_linea_seleccion = 0;
                        }
                    }
                    if(modo_activo == "seleccion_rectangular"){
                        clicks_linea_seleccion += 1;
                        coords_linea_seleccion[clicks_linea_seleccion - 1][0] = (float)mousex;
                        coords_linea_seleccion[clicks_linea_seleccion - 1][1] = (float)mousey;
                        sleep(1);
                        if (clicks_linea_seleccion == 2)
                        {
                            seleccion_rectangular(coords_linea_seleccion[0][0], coords_linea_seleccion[0][1],
                                                  coords_linea_seleccion[1][0], coords_linea_seleccion[1][1]);
                            clicks_linea_seleccion = 0;
                        }
                    }
                    if(modo_activo == "seleccion_libre"){
                        Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(mousey-100)->busqueda_indice(mousex);
                        pixel->rectangulo.setFillColor(sf::Color(255,255,255,255));
                        ptrwindow->draw( pixel->rectangulo);
                        trazo_seleccion_libre_append(mousex);
                        trazo_seleccion_libre_append(mousey);
                    }
                    if(modo_activo == "seleccion_magica"){
                        Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(mousey-100)->busqueda_indice(mousex);
                        pixel->rectangulo.setFillColor(sf::Color(color_R,color_G,color_B,255));
                        ptrwindow->draw( pixel->rectangulo);
                        breadthFirstSearch_Verificar(mousex, mousey-100, 1);
                    }
                    if(modo_activo == "paintFill"){
                        int tempTrazo = multplicador_de_trazo;
                        multplicador_de_trazo = 0;
                        colorDeRellenoLienzo.ptrwindow = ptrwindow;
                        colorDeRellenoLienzo.pintarArea(sf::Vector2f(mousex,mousey-100));
                        multplicador_de_trazo = tempTrazo;
                    }
                }
            }

        /*Generar cuadrado
        clicks_linea_seleccion += 1;
        coords_linea_seleccion[clicks_linea_seleccion - 1][0] = (float)mousex;
        coords_linea_seleccion[clicks_linea_seleccion - 1][1] = (float)mousey;
        sleep(1);
        if (clicks_linea_seleccion == 2)
        {
            crear_rectangulo(coords_linea_seleccion[0][0], coords_linea_seleccion[0][1],
                             coords_linea_seleccion[1][0], coords_linea_seleccion[1][1]);
            clicks_linea_seleccion = 0;
        }
        */


        /*for (int z=0; z<RGB_pixeles_imagen->busqueda_indice(100)->largo; z+=1)
        {
            cambiar_color_pixel_lienzo(z,100);
        }*/
        /*Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(RGB_pixeles_imagen->busqueda_indice(0)->largo/2)->busqueda_indice(0);
        pixel->rectangulo.setFillColor(sf::Color(255,255,255,255));*/

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

void Ventana::redibuja_la_imagen() {

    Nodo_matriz *fila2 = datos->RGB_pixeles_imagen->Inicio;
    Lista_pixeles *fila = fila2->dato;
    Nodo_pixel *pixel = fila->Inicio;
    int largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;

    for(int n = 0;n <datos->RGB_pixeles_imagen->largo-2; n++)
    {
        for (int u=0; u<largo_columnas ;u+=1)
        {

            pixel->rectangulo.setFillColor(sf::Color(pixel->R,pixel->G,pixel->B,255));
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

void Ventana::trazar_linea_recta(float coordenada_x_pixel1, float coordenada_y_pixel1, float coordenada_x_pixel2, float coordenada_y_pixel2) {
    float pendiente, origen;
    int minimo, maximo, ambito, dominio, r, g, b;
    r = color_R;
    g = color_G;
    b = color_B;

    if (abs(coordenada_x_pixel1 - coordenada_x_pixel2) < 50)
    {
        pendiente = ((coordenada_x_pixel1 - coordenada_x_pixel2) / (coordenada_y_pixel1 - coordenada_y_pixel2));
        origen = coordenada_x_pixel1 - (pendiente * coordenada_y_pixel1);
        if (coordenada_y_pixel1 > coordenada_y_pixel2)
        {
            minimo = coordenada_y_pixel2;
            maximo = coordenada_y_pixel1;
            while (minimo <= maximo) {
                dominio = (pendiente * minimo) + origen;
                cambiar_color_pixel_lienzo(dominio, minimo - 100, r, g, b);
                minimo++;
            }
        }
        else
        {
            minimo = coordenada_y_pixel1;
            maximo = coordenada_y_pixel2;
            while (minimo <= maximo) {
                dominio = (pendiente * minimo) + origen;
                cambiar_color_pixel_lienzo(dominio, minimo - 100, r, g, b);
                minimo++;
            }
        }
    }
    else
    {
        pendiente = ((coordenada_y_pixel1 - coordenada_y_pixel2) / (coordenada_x_pixel1 - coordenada_x_pixel2));
        origen = coordenada_y_pixel1 - (pendiente * coordenada_x_pixel1);
        if (coordenada_x_pixel1 > coordenada_x_pixel2)
        {
            minimo = coordenada_x_pixel2;
            maximo = coordenada_x_pixel1;
            while (minimo <= maximo) {
                ambito = (pendiente * minimo) + origen;
                cambiar_color_pixel_lienzo(minimo, ambito - 100, r, g, b);
                minimo++;
            }
        }
        else
        {
            minimo = coordenada_x_pixel1;
            maximo = coordenada_x_pixel2;
            while (minimo <= maximo) {
                ambito = (pendiente * minimo) + origen;
                cambiar_color_pixel_lienzo(minimo, ambito - 100, r, g, b);
                minimo++;
            }
        }
    }
}

void Ventana::seleccion_rectangular(float coordenada_x_pixel1, float coordenada_y_pixel1, float coordenada_x_pixel2, float coordenada_y_pixel2)
{
    seleccion_libre(coordenada_x_pixel1, coordenada_y_pixel1, coordenada_x_pixel2, coordenada_y_pixel1);
    seleccion_libre(coordenada_x_pixel2, coordenada_y_pixel1, coordenada_x_pixel2, coordenada_y_pixel2);
    seleccion_libre(coordenada_x_pixel2, coordenada_y_pixel2, coordenada_x_pixel1, coordenada_y_pixel2);
    seleccion_libre(coordenada_x_pixel1, coordenada_y_pixel2, coordenada_x_pixel1, coordenada_y_pixel1);
}

void Ventana::trazo_seleccion_libre_append(int coordenada){
    trazo_seleccion_libre[trazo_seleccion_libre_indice] = coordenada;
    trazo_seleccion_libre_indice++;
}

void Ventana::seleccion_libre(float coordenada_x_pixel1, float coordenada_y_pixel1, float coordenada_x_pixel2, float coordenada_y_pixel2) {
    float pendiente, origen;
    int minimo, maximo, ambito, dominio;

    if (abs(coordenada_x_pixel1 - coordenada_x_pixel2) < 50)
    {
        pendiente = ((coordenada_x_pixel1 - coordenada_x_pixel2) / (coordenada_y_pixel1 - coordenada_y_pixel2));
        origen = coordenada_x_pixel1 - (pendiente * coordenada_y_pixel1);
        if (coordenada_y_pixel1 > coordenada_y_pixel2)
        {
            minimo = coordenada_y_pixel2;
            maximo = coordenada_y_pixel1;
            while (minimo <= maximo) {
                dominio = (pendiente * minimo) + origen;
                Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(minimo-100)->busqueda_indice(dominio);
                pixel->rectangulo.setFillColor(sf::Color(255,255,255,255));
                ptrwindow->draw( pixel->rectangulo);
                minimo++;
            }
        }
        else
        {
            minimo = coordenada_y_pixel1;
            maximo = coordenada_y_pixel2;
            while (minimo <= maximo) {
                dominio = (pendiente * minimo) + origen;
                Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(minimo-100)->busqueda_indice(dominio);
                pixel->rectangulo.setFillColor(sf::Color(255,255,255,255));
                ptrwindow->draw( pixel->rectangulo);
                minimo++;
            }
        }
    }
    else
    {
        pendiente = ((coordenada_y_pixel1 - coordenada_y_pixel2) / (coordenada_x_pixel1 - coordenada_x_pixel2));
        origen = coordenada_y_pixel1 - (pendiente * coordenada_x_pixel1);
        if (coordenada_x_pixel1 > coordenada_x_pixel2)
        {
            minimo = coordenada_x_pixel2;
            maximo = coordenada_x_pixel1;
            while (minimo <= maximo) {
                ambito = (pendiente * minimo) + origen;
                Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(ambito-100)->busqueda_indice(minimo);
                pixel->rectangulo.setFillColor(sf::Color(255,255,255,255));
                ptrwindow->draw( pixel->rectangulo);
                minimo++;
            }
        }
        else
        {
            minimo = coordenada_x_pixel1;
            maximo = coordenada_x_pixel2;
            while (minimo <= maximo) {
                ambito = (pendiente * minimo) + origen;
                Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(ambito-100)->busqueda_indice(minimo);
                pixel->rectangulo.setFillColor(sf::Color(255,255,255,255));
                ptrwindow->draw( pixel->rectangulo);
                minimo++;
            }
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


void Ventana::crear_rectangulo(float coordenada_x_pixel1, float coordenada_y_pixel1, float coordenada_x_pixel2, float coordenada_y_pixel2)
{
    int minimo_x, minimo_y, maximo_x, maximo_y, minimo_x_fijo, r, g, b;
    r = color_R;
    g = color_G;
    b = color_B;
    if (coordenada_x_pixel1 > coordenada_x_pixel2)
    {
        minimo_x = coordenada_x_pixel2;
        minimo_x_fijo = coordenada_x_pixel2;
        maximo_x = coordenada_x_pixel1;
        if (coordenada_y_pixel1 > coordenada_y_pixel2)
        {
            minimo_y = coordenada_y_pixel2;
            maximo_y = coordenada_y_pixel1;
            while (minimo_y <= maximo_y)
            {
                while (minimo_x <= maximo_x)
                {
                    cambiar_color_pixel_lienzo(minimo_x, minimo_y - 100, r, g, b);
                    minimo_x++;
                }
                minimo_y++;
                minimo_x = minimo_x_fijo;
            }
        }
        else
        {
            minimo_y = coordenada_y_pixel1;
            maximo_y = coordenada_y_pixel2;
            while (minimo_y <= maximo_y)
            {
                while (minimo_x <= maximo_x)
                {
                    cambiar_color_pixel_lienzo(minimo_x, minimo_y - 100, r, g, b);
                    minimo_x++;
                }
                minimo_y++;
                minimo_x = minimo_x_fijo;
            }
        }
    }
    else
    {
        minimo_x = coordenada_x_pixel1;
        minimo_x_fijo = coordenada_x_pixel1;
        maximo_x = coordenada_x_pixel2;
        if (coordenada_y_pixel1 > coordenada_y_pixel2)
        {
            minimo_y = coordenada_y_pixel2;
            maximo_y = coordenada_y_pixel1;
            while (minimo_y <= maximo_y)
            {
                while (minimo_x <= maximo_x)
                {
                    cambiar_color_pixel_lienzo(minimo_x, minimo_y - 100, r, g, b);
                    minimo_x++;
                }
                minimo_y++;
                minimo_x = minimo_x_fijo;
            }
        }
        else
        {
            minimo_y = coordenada_y_pixel1;
            maximo_y = coordenada_y_pixel2;
            while (minimo_y <= maximo_y)
            {
                while (minimo_x <= maximo_x)
                {
                    cambiar_color_pixel_lienzo(minimo_x, minimo_y - 100, r, g, b);
                    minimo_x++;
                }
                minimo_y++;
                minimo_x = minimo_x_fijo;
            }
        }
    }
}

void Ventana::breadthFirstSearch_Verificar(int coordenada_x, int coordenada_y, int nivel){
    Nodo_pixel *pixel_seleccionado = RGB_pixeles_imagen->busqueda_indice(coordenada_y)->busqueda_indice(coordenada_x);
    int r_seleccionado, g_seleccionado, b_seleccionado, minimo_x, minimo_y, maximo_x, maximo_y, minimo_x_fijo, minimo_y_fijo, lado, i, r1, g1, b1, r2, g2, b2;

    r_seleccionado = pixel_seleccionado->R;
    g_seleccionado = pixel_seleccionado->G;
    b_seleccionado = pixel_seleccionado->B;

    minimo_x = coordenada_x - nivel;
    minimo_y = coordenada_y - nivel;
    minimo_x_fijo = coordenada_x - nivel;
    minimo_y_fijo = coordenada_y - nivel;

    maximo_x = coordenada_x + nivel;
    maximo_y = coordenada_y + nivel;

    bool pintar_nivel = false;

    lado = (2 * nivel) + 1;
    i = 0;

    while(i <= lado)
    {
        Nodo_pixel *pixel1 = RGB_pixeles_imagen->busqueda_indice(minimo_y)->busqueda_indice(minimo_x);
        r1 = pixel1->R;
        g1 = pixel1->G;
        b1 = pixel1->B;

        Nodo_pixel *pixel2 = RGB_pixeles_imagen->busqueda_indice(maximo_y)->busqueda_indice(minimo_x);
        r2 = pixel2->R;
        g2 = pixel2->G;
        b2 = pixel2->B;

        if((r1 == r_seleccionado && g1 == g_seleccionado && b1 == b_seleccionado) || (r2 == r_seleccionado && g2 == g_seleccionado && b2 == b_seleccionado))
        {
            pintar_nivel = true;
        }
        minimo_x++;
        i++;
    }

    minimo_x = minimo_x_fijo;
    i = 0;

    while(i <= lado)
    {
        Nodo_pixel *pixel1 = RGB_pixeles_imagen->busqueda_indice(minimo_y)->busqueda_indice(minimo_x);
        r1 = pixel1->R;
        g1 = pixel1->G;
        b1 = pixel1->B;

        Nodo_pixel *pixel2 = RGB_pixeles_imagen->busqueda_indice(minimo_y)->busqueda_indice(maximo_x);
        r2 = pixel2->R;
        g2 = pixel2->G;
        b2 = pixel2->B;

        if((r1 == r_seleccionado && g1 == g_seleccionado && b1 == b_seleccionado) || (r2 == r_seleccionado && g2 == g_seleccionado && b2 == b_seleccionado))
        {
            pintar_nivel = true;
        }
        minimo_y++;
        i++;
    }

    if(pintar_nivel)
    {
        std::cout << "Pintar Nivel: " << nivel << std::endl;
        breadthFirstSearch_Pintar(coordenada_x, coordenada_y, nivel);
    }
}

void Ventana::breadthFirstSearch_Pintar(int coordenada_x, int coordenada_y, int nivel)
{
    Nodo_pixel *pixel_seleccionado = RGB_pixeles_imagen->busqueda_indice(coordenada_y)->busqueda_indice(coordenada_x);
    int r_seleccionado, g_seleccionado, b_seleccionado, minimo_x, minimo_y, maximo_x, maximo_y, minimo_x_fijo, minimo_y_fijo, lado, i, r1, g1, b1, r2, g2, b2, red, green, blue;

    r_seleccionado = pixel_seleccionado->R;
    g_seleccionado = pixel_seleccionado->G;
    b_seleccionado = pixel_seleccionado->B;

    red = color_R;
    green = color_G;
    blue = color_B;

    minimo_x = coordenada_x - nivel;
    minimo_y = coordenada_y - nivel;
    minimo_x_fijo = coordenada_x - nivel;
    minimo_y_fijo = coordenada_y - nivel;

    maximo_x = coordenada_x + nivel;
    maximo_y = coordenada_y + nivel;

    lado = (2 * nivel) + 1;
    i = 0;

    while(i <= lado)
    {
        Nodo_pixel *pixel1 = RGB_pixeles_imagen->busqueda_indice(minimo_y)->busqueda_indice(minimo_x);
        r1 = pixel1->R;
        g1 = pixel1->G;
        b1 = pixel1->B;

        if(r1 == r_seleccionado && g1 == g_seleccionado && b1 == b_seleccionado)
        {
            pixel1->rectangulo.setFillColor(sf::Color(red,green,blue,255));
            ptrwindow->draw( pixel1->rectangulo);
        }

        Nodo_pixel *pixel2 = RGB_pixeles_imagen->busqueda_indice(maximo_y)->busqueda_indice(minimo_x);
        r2 = pixel2->R;
        g2 = pixel2->G;
        b2 = pixel2->B;

        if(r2 == r_seleccionado && g2 == g_seleccionado && b2 == b_seleccionado)
        {
            pixel2->rectangulo.setFillColor(sf::Color(red,green,blue,255));
            ptrwindow->draw( pixel2->rectangulo);
        }

        minimo_x++;
        i++;
    }

    minimo_x = minimo_x_fijo;
    i = 0;

    while(i <= lado)
    {
        Nodo_pixel *pixel1 = RGB_pixeles_imagen->busqueda_indice(minimo_y)->busqueda_indice(minimo_x);
        r1 = pixel1->R;
        g1 = pixel1->G;
        b1 = pixel1->B;

        if(r1 == r_seleccionado && g1 == g_seleccionado && b1 == b_seleccionado)
        {
            pixel1->rectangulo.setFillColor(sf::Color(red,green,blue,255));
            ptrwindow->draw( pixel1->rectangulo);
        }

        Nodo_pixel *pixel2 = RGB_pixeles_imagen->busqueda_indice(minimo_y)->busqueda_indice(maximo_x);
        r2 = pixel2->R;
        g2 = pixel2->G;
        b2 = pixel2->B;

        if(r2 == r_seleccionado && g2 == g_seleccionado && b2 == b_seleccionado)
        {
            pixel2->rectangulo.setFillColor(sf::Color(red,green,blue,255));
            ptrwindow->draw( pixel2->rectangulo);
        }
        minimo_y++;
        i++;
    }

    nivel++;
    breadthFirstSearch_Verificar(coordenada_x, coordenada_y, nivel);
}

void Ventana::ventana_guardando() {
    componentes->creaLabel(0,80,30,"Por favor escribe el nombre de tu archivo");

    componentes->creaCajadeTexto(0,120,300,30,entrada);
    if(componentes->creaBoton(0, 160, 300, 30, "Aceptar")){
        contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
        if (contador_botones == 0){
            std::cout<<"koka"<<std::endl;
            std::cout<<entrada[0]<<std::endl;
            std::string nuevo = entrada + ".bmp";
            tre->SaveBMP(const_cast<char *>(nuevo.c_str()), &tre->info, tre->img);
            orden_abrir = "paint";
            ptrwindow->clear();
            redibuja_la_imagen();


            contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
        }
    }

}

