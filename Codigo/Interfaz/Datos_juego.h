//
// Created by deylan on 10/05/22.
//

#ifndef CODIGO_DATOS_JUEGO_H
#define CODIGO_DATOS_JUEGO_H

#include <mutex>
#include "../lista doblemente enlazada/Matriz.h"

class Datos_juego {
private:
    static Datos_juego * pinstance_;
    static std::mutex mutex_;
    int color_R = 0;
    int color_G = 0;
    int color_B = 0;

protected:
    Datos_juego(const std::string value): value_(value)
    {
    }
    ~Datos_juego() {}
    std::string value_;
public:

    Datos_juego(Datos_juego &other) = delete;
    void operator=(const Datos_juego &) = delete;
    static Datos_juego *GetInstance(const std::string& value);
    void SomeBusinessLogic()
    {
        // ...
    }
    std::string value() const{
        return value_;
    }
    //******************************
    void setRGBcolor_seleccionado(int R,int G,int B);
    int getColor_R();
    int getColor_G();
    int getColor_B();

    //int rgb_color_seleccionado[3] = {255,255,255 };
    Matriz *RGB_pixeles_imagen ;

};
#endif //CODIGO_DATOS_JUEGO_H
