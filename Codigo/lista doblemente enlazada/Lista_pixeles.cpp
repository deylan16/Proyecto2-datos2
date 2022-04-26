//
// Created by deylan on 26/04/22.
//

#include <string>
#include <iostream>
#include "Lista_pixeles.h"

void Lista_pixeles::append(int R, int G, int B) {
    this->largo += 1;
    if(this->Inicio == nullptr){
        this->Inicio = new Nodo_pixel(R,G,B, nullptr, nullptr,largo-1);
        this->Final = this->Inicio;
    }
    else {
        Nodo_pixel *tmp = this->Final;
        tmp->next = new Nodo_pixel(R,G,B, nullptr, tmp,largo-1);
        this->Final = tmp->next;
        Nodo_pixel*tmp2 = this->Final;
        tmp2->prev = tmp;

    }
}

void Lista_pixeles::print() {
    Nodo_pixel *actual = this->Inicio;
    int cuenta = 0;
    std::string todo = "[";
    while(actual != nullptr){
        cuenta +=1;
        todo += "["+ std::to_string(actual->R) + ","+ std::to_string(actual->G) + ","+ std::to_string(actual->B) + "]";
        if (cuenta < this->largo){
            todo += ",";
        }
        actual = actual->next;
    }
    todo += "]";
    std::cout<<todo<<std::endl;

}

Nodo_pixel * Lista_pixeles::busqueda_indice(int indice_busqueda) {
    int resultado[3] = {0,0,0};
    Nodo_pixel *actual = this->Inicio;
    for(int i = 0;i < this->largo;i++){
        if(actual->indice == indice_busqueda){
            resultado[0]  = actual->R;
            resultado[1]  = actual->G;
            resultado[2]  = actual->B;
            break;

        }
        else{
            actual = actual->next;
        }

    }

    return actual;
}
