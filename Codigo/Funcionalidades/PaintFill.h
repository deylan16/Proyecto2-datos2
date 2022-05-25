//
// Created by deylan on 24/05/22.
//

#ifndef CODIGO_PAINTFILL_H
#define CODIGO_PAINTFILL_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Interfaz/Datos_juego.h"
#include "../lista doblemente enlazada/QueuePixels.h"

#include "../lista doblemente enlazada/LinkedListPixels.h"

using namespace std;
class PaintFill {
public:
    sf::RenderWindow *ptrwindow ;
    PaintFill();
    void pintarArea( sf::Vector2f coordsMouse);

private:

    Datos_juego *datos = Datos_juego::GetInstance("Informacion");
    NodoPixel *nodoPixelInicial = nullptr;
    QueuePixels colaDePixeles;
    LinkedListPixels listaDeEstadosPixeles;
    int cantidadPixelesAdyacentes = 4;
    NodoPixel* crearNodoPixelVisitado(int coordMouseX, int coordMouseY);
    void verificarCoincidenciaColorPixel( int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente);
    void pintarPixelDeIgualColor( int coord_X_PixelAdyacente, int coord_Y_PixelAdyacente);
    void liberarMemoriaDeListaEstados();

    // incremento o decremento para obtener posibles nodos adyacentes en el eje horizontal
    int incrementoEnCoordX_nodoAdyacente[4] = {0,0,1,-1};

    // incremento o decremento para obtener posibles nodos adyacentes en el eje vertical
    int incrementoEnCoordY_nodoAdyacente[4]= {1,-1,0,0};

};


#endif //CODIGO_PAINTFILL_H
