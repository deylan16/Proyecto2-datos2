//
// Created by deylan on 27/04/22.
//

#include <iostream>
#include "Lista_Doble.h"
/*template <typename T>
void Lista_Doble<T>::append(T dato) {
    this->largo += 1;
    if(this->Inicio == nullptr){
        this->Inicio = new Nodo<T>(dato, nullptr, nullptr,largo-1);
        this->Final = this->Inicio;
    }
    else {
        Nodo<T> *tmp = this->Final;
        tmp->next = new Nodo<T>(dato, nullptr, tmp,largo-1);
        this->Final = tmp->next;
        Nodo<T> *tmp2 = this->Final;
        tmp2->prev = tmp;

    }

}


template <typename T>
void Lista_Doble<T>::print() {
    Nodo<T> *actual = this->Inicio;
    int cuenta = 0;
    std::string todo = "[";
    while(actual != nullptr){
        cuenta +=1;
        todo += actual->dato;
        if (cuenta < this->largo){
            todo += ",";
        }
        actual = actual->next;
    }
    todo += "]";
    std::cout<<todo<<std::endl;

}
template <typename T>
std::string Lista_Doble<T>::busqueda_indice(int indice_busqueda) {
    std::string resultado = "Fuera de rango" ;
    Nodo<T> *actual = this->Inicio;
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
template<class T>
void Lista_Doble<T>::appe(T dato) {
    this->largo += 1;
    if(this->Inicio == nullptr){
        this->Inicio = new Nodo<T>(dato, nullptr, nullptr,largo-1);
        this->Final = this->Inicio;
    }
    else {
        Nodo<T> *tmp = this->Final;
        tmp->next = new Nodo<T>(dato, nullptr, tmp,largo-1);
        this->Final = tmp->next;
        Nodo<T> *tmp2 = this->Final;
        tmp2->prev = tmp;

    }
}*/