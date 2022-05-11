//
// Created by deylan on 11/05/22.
//

#include "Giros.h"

void Giros::giro(std::string direccion) {
    if(direccion == "90derecha"){
        giro90derecha();
    }
}

void Giros::giro90derecha() {
    Matriz *matrizbase = datos->RGB_pixeles_imagen;
    Matriz *matriznueva = new Matriz();
    for(int x = 0 ;x < matrizbase->busqueda_indice(0)->largo;x++){
        Lista_pixeles *fila = new Lista_pixeles();
        for(int y = matrizbase->largo-1;y>0 ;y--){


            Nodo_pixel *pixel = matrizbase->busqueda_indice(y)->busqueda_indice(x);
            pixel->rectangulo.setPosition(y,x+100);
            fila->append(pixel->R,pixel->G,pixel->B,pixel->rectangulo);


        }
        matriznueva->append(fila);
    }
    datos->RGB_pixeles_imagen = matriznueva;


}
