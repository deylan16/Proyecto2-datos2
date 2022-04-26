//
// Created by deylan on 25/04/22.
//

#include "Matriz.h"





void Matriz::print() {
    Nodo_matriz *actual = this->Inicio;
    int cuenta = 0;
    std::string todo = "[";
    while(actual != nullptr){
        cuenta +=1;
        actual->dato->print();

        actual = actual->next;
    }
    todo += "]";


}

Lista_pixeles *Matriz::busqueda_indice(int indice_busqueda) {
    Lista_pixeles *resultado = nullptr ;
    Nodo_matriz *actual = this->Inicio;
    for(int i = 0;i < this->largo;i++){
        if(actual->indice == indice_busqueda){
            resultado = actual->dato;
        }
        else{
            actual = actual->next;
        }

    }
    return resultado;
}

void Matriz::append(Lista_pixeles *dato) {
    this->largo += 1;
    if(this->Inicio == nullptr){
        this->Inicio = new Nodo_matriz(dato, nullptr, nullptr,largo-1);
        this->Final = this->Inicio;
    }
    else {
        Nodo_matriz *tmp = this->Final;
        tmp->next = new Nodo_matriz(dato, nullptr, tmp,largo-1);
        this->Final = tmp->next;
        Nodo_matriz *tmp2 = this->Final;
        tmp2->prev = tmp;

    }
}
