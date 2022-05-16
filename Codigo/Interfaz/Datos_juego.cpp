//
// Created by deylan on 10/05/22.
//

#include "Datos_juego.h"
Datos_juego* Datos_juego::pinstance_{nullptr};

Datos_juego *Datos_juego::GetInstance(const std::string &value) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Datos_juego(value);
    }
    return pinstance_;
}

void Datos_juego::setRGBcolor_seleccionado(int R, int G, int B) {
    color_R = R;
    color_G = G;
    color_B = B;
}

int Datos_juego::getColor_R() {
    return color_R;
}

int Datos_juego::getColor_G() {
    return color_G;
}

int Datos_juego::getColor_B() {
    return color_B;
}

std::mutex Datos_juego::mutex_;