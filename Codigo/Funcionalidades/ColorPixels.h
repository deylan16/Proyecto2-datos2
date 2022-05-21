//
// Created by ludwinr on 20/05/22.
//

#ifndef CODIGO_COLORPIXELS_H
#define CODIGO_COLORPIXELS_H
#include "../Interfaz/Datos_juego.h"
#include <SFML/Graphics.hpp>
#include "../lista doblemente enlazada/Matriz.h"

class ColorPixel{

public:
    ColorPixel(sf::RenderWindow *ptrWindow,Matriz *nuevoRGB_pixeles_image);

    void set_color_pixel_lienzo(int x, int y,int r,int g,int b);
    void setDatos(Datos_juego *actualizacionDatosJuego);
    Datos_juego* getDatosJuego();
    void setMultiplicadorDeTrazo(int* nuevoMultiplicadorTrazo);
    int getMultiplicadorDeTrazo();
    void setRGB_pixeles_imagen(Matriz *nuevoRGB_pixeles_image);
    Matriz* getRGB_pixeles_imagen();

private:
    Datos_juego *datos; // al inicio
    sf::RenderWindow *window; // al inicio
    Matriz *RGB_pixeles_imagen; // al inicio
    int *trazoSize; // setiarlo en el constructor de ventana, por medio de su metodo set
};



#endif //CODIGO_COLORPIXELS_H
