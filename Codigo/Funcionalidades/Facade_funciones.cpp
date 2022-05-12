//
// Created by deylan on 11/05/22.
//

#include "Facade_funciones.h"
#include "Giros.h"
#include "Filtros.h"

Facade_funciones* Facade_funciones::pinstance_{nullptr};

Facade_funciones *Facade_funciones::GetInstance(const std::string &value) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Facade_funciones(value);
    }
    return pinstance_;
}

std::mutex Facade_funciones::mutex_;

void Facade_funciones::giro(std::string direccion) {
    Giros *girar = new Giros();
    girar->giro(direccion);
}

void Facade_funciones::aplicar_filtro(std::string tipo_filtro){
    Filtros *filtrador = new Filtros();
    filtrador->cual_filtro(tipo_filtro);
}