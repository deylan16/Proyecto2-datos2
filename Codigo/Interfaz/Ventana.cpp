//
// Created by deyla on 25/4/2022.
//

#include <thread>
#include "Ventana.h"
#include "../BMP/Bmp.h"
#include "../lista doblemente enlazada/Lista_pixeles.h"


Ventana::Ventana(sf::RenderWindow *window) {
    this->ptrwindow = window;

}

void Ventana::ventana_principal() {
    Bmp *tre = new Bmp();

    tre->img=tre->LoadBMP("gr.bmp", &tre->info);
    tre->DisplayInfo(&tre->info);
    //tre->SaveBMP("res3.bmp", &tre->info, tre->img);

    bool yo = true;

    while (ptrwindow->isOpen())
    {



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
        while (ptrwindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                ptrwindow->close();

            if (escribiendo){

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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) ){
                    if(contadorborrar == 1)
                        if(entrada != "")
                            entrada.pop_back();
                        contadorborrar = contadorborrar -1;
                }
            }
        }
        //ptrwindow->clear();

        sf::RectangleShape rectangulo(sf::Vector2f(1100.f, 100.f));
        rectangulo.setFillColor(sf::Color(146,151,158,255));
        rectangulo.setPosition(0,0);

        ptrwindow->draw(rectangulo);









        //componentes->creaLabel(0,0,30,"hola");
        //componentes->creaCajadeTexto(0,200,100,40,entrada);
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
                //seleccionar_jugador2 = true;
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
                //seleccionar_jugador2 = true;
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
                //seleccionar_jugador2 = true;
                contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
            }
        }
        if(componentes->creaBoton_con_imagen(260, 60, 30, 30, prefijo_ruta + "flip_vertical.png")){
            contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
            if (contador_botones == 0){
                std::cout<<"koka"<<std::endl;
                //seleccionar_jugador2 = true;
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
                //seleccionar_jugador2 = true;
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
                multplicador_de_trazo += 1;
                //seleccionar_jugador2 = true;
                contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
            }
        }
        if(componentes->creaBoton(460, 60, 30, 30, "Me")){
            contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
            if (contador_botones == 0){
                std::cout<<"koka"<<std::endl;
                if(multplicador_de_trazo >= 0)
                    multplicador_de_trazo -= 1;
                //seleccionar_jugador2 = true;
                contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
            }
        }
        if(componentes->creaBoton_color(460, 10, 30, 30, datos->rgb_color_seleccionado[0],datos->rgb_color_seleccionado[1],datos->rgb_color_seleccionado[2] )){
            contador_botones -= 1;//sintaxis porque sino lo envia 4 veces
            if (contador_botones == 0){
                std::cout<<"koka"<<std::endl;

                //seleccionar_jugador2 = true;
                contador_botones = contador_original;//sintaxis porque sino lo envia 4 veces
            }
        }


        /*for(int i = 0;i<lienzo->largo;i++){
            ptrwindow->draw(lienzo->busqueda_indice(i));
        }*/

        int x, y;
        int r,g,b;
        if (yo){
            for (y=tre->info.height; y>0; y-=1)
            {
                Lista_pixeles *fila = new Lista_pixeles();
                for (x=0; x<tre->info.width; x+=1)
                {
                    //std::cout<<3*(x+y*info.width)<<std::endl;


                    b=(tre->img[4*(x+y*tre->info.width)]);
                    g=(tre->img[4*(x+y*tre->info.width)+1]);
                    r=(tre->img[4*(x+y*tre->info.width)+2]);
                    //std::cout<<"["<<r<<","<<g<<","<<b<<"]"<<std::endl;

                    //printf("%c", colores[b+g*2+r*4]);
                    sf::RectangleShape rectangulo(sf::Vector2f(1.f, 1.f));
                    rectangulo.setFillColor(sf::Color(r,g,b,255));
                    rectangulo.setPosition(x,(tre->info.height-y)+100);
                    lienzo->append(rectangulo);
                    fila->append(r,g,b,rectangulo);
                    //ptrwindow->draw(rectangulo);
                }
                RGB_pixeles_imagen->append(fila);


            }
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
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                if(100<mousey && mousey<RGB_pixeles_imagen->largo+100 && 0<mousex && mousex<RGB_pixeles_imagen->busqueda_indice(0)->largo){
                    if(modo_activo == "borrador"){
                        cambiar_color_pixel_lienzo(mousex,mousey-100,255,255,255);
                    }
                    if(modo_activo == "picker"){
                        picker(mousex,mousey-100);
                    }
                }
            }

        }
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
    datos->rgb_color_seleccionado[0] = r;
    datos->rgb_color_seleccionado[1] = g;
    datos->rgb_color_seleccionado[2] = b;


}

void Ventana::picker(int x, int y) {
    if(RGB_pixeles_imagen->busqueda_indice(y) != NULL){
        Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(y)->busqueda_indice(x);
        if(pixel != NULL)
        {
            cambiar_color_seleccionado(pixel->R,pixel->G,pixel->B);



        }
    }

}

void Ventana:: redibuja_la_imagen() {

    std::cout<<RGB_pixeles_imagen->largo<<std::endl;
    std::cout<<datos->RGB_pixeles_imagen->largo<<std::endl;
    for(int n = 0;n <datos->RGB_pixeles_imagen->largo; n++)
    {
        for (int u=0; u<datos->RGB_pixeles_imagen->busqueda_indice(n)->largo; u+=1)
        {
            Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(n)->busqueda_indice(u);
            //pixel->rectangulo.setFillColor(sf::Color(0,0,0,255));
            pixel->rectangulo.setPosition(u,n+100);
            ptrwindow->draw( pixel->rectangulo);




        }
    }
}

void Ventana::renderizar() {
    redibuja_la_imagen();

}

