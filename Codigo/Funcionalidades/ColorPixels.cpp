//
// Created by ludwinr on 20/05/22.
//

#include "ColorPixels.h"
#include "../lista doblemente enlazada/Nodo_pixel.h"


ColorPixel::ColorPixel(sf::RenderWindow *ptrWindow, Matriz *nuevoRGB_pixeles_image) {
    RGB_pixeles_imagen = nuevoRGB_pixeles_image;
    window = ptrWindow;
}

void ColorPixel::set_color_pixel_lienzo(int x, int y,int r,int g,int b) {
    x -= *trazoSize;
    y -= *trazoSize;
    for(int a = 0;a <3+*trazoSize; a++) {
        for(int l = 0;l <3+*trazoSize; l++) {

            if(RGB_pixeles_imagen->busqueda_indice(y+a) != NULL){
                Nodo_pixel *pixel = RGB_pixeles_imagen->busqueda_indice(y+a)->busqueda_indice(x+l);
                if(pixel != NULL) {
                    pixel->R = r;
                    pixel->B = b;
                    pixel->G = g;
                    pixel->rectangulo.setFillColor(sf::Color(r,g,b,255));
                    window->draw( pixel->rectangulo);
                }
            }
        }
    }
}

void ColorPixel::setDatos(Datos_juego *actualizacionDatosJuego) {
    datos = actualizacionDatosJuego;
}

Datos_juego *ColorPixel::getDatosJuego() {
    return datos;
}

void ColorPixel::setMultiplicadorDeTrazo(int* nuevoMultiplicadorTrazo) {
    trazoSize = nuevoMultiplicadorTrazo;
}

int ColorPixel::getMultiplicadorDeTrazo() {
    return 0;
}

void ColorPixel::setRGB_pixeles_imagen(Matriz *nuevoRGB_pixeles_image) {
    free(RGB_pixeles_imagen);
    RGB_pixeles_imagen = nuevoRGB_pixeles_image;
}

Matriz *ColorPixel::getRGB_pixeles_imagen() {
    return RGB_pixeles_imagen;
}
