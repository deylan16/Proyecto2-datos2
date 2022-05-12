//
// Created by deylan on 11/05/22.
//

#ifndef CODIGO_GIROS_H
#define CODIGO_GIROS_H


#include "../Interfaz/Datos_juego.h"

class Giros {
public:
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");
    void giro(std::string direccion);
    void giro90derecha();
    void giro90izquierda();
    void flipHorizontal();
    void flipVertical();

};


#endif //CODIGO_GIROS_H
