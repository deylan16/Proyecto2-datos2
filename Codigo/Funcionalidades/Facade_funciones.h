//
// Created by deylan on 11/05/22.
//

#ifndef CODIGO_FACADE_FUNCIONES_H
#define CODIGO_FACADE_FUNCIONES_H

#include <mutex>
#include "../lista doblemente enlazada/Matriz.h"
#include "../Interfaz/Datos_juego.h"

class Facade_funciones {
private:
    static Facade_funciones * pinstance_;
    static std::mutex mutex_;

protected:
    Facade_funciones(const std::string value): value_(value)
    {
    }
    ~Facade_funciones() {}
    std::string value_;
public:

    Facade_funciones(Facade_funciones &other) = delete;
    void operator=(const Facade_funciones &) = delete;
    static Facade_funciones *GetInstance(const std::string& value);
    void SomeBusinessLogic()
    {
        // ...
    }
    std::string value() const{
        return value_;
    }

    //******************************
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");
    Matriz *RGB_pixeles_imagen  = datos->RGB_pixeles_imagen;

    void borrador(int x,int y);
    void giro(std::string direccion);

};


#endif //CODIGO_FACADE_FUNCIONES_H
