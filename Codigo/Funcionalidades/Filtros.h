//
// Created by deylan on 12/05/22.
//

#ifndef CODIGO_FILTROS_H
#define CODIGO_FILTROS_H


#include <string>
#include "../Interfaz/Datos_juego.h"

class Filtros {
public:
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");
    void cual_filtro(std::string tipo_filtro);
    void filtro_negativo();
    void filtro_escala_grises();

};


#endif //CODIGO_FILTROS_H
