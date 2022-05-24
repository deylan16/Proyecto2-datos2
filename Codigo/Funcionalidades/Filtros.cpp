//
// Created by deylan on 12/05/22.
//

#include "Filtros.h"

void Filtros::cual_filtro(std::string tipo_filtro) {
    if(tipo_filtro == "negativo")
        filtro_negativo();
    if(tipo_filtro == "escala_grises")
        filtro_escala_grises();
    if(tipo_filtro == "trueque")
        filtro_trueque();
    if(tipo_filtro == "Dividir")
        filtro_dividir();

}

void Filtros::filtro_negativo() {
    Nodo_matriz *fila2 = datos->RGB_pixeles_imagen->Inicio;
    Lista_pixeles *fila = fila2->dato;
    Nodo_pixel *pixel = fila->Inicio;
    int largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;

    for(int n = 0;n <datos->RGB_pixeles_imagen->largo-2; n++)
    {
        for (int u=0; u<largo_columnas ;u+=1)
        {
            pixel->R = 255-pixel->R;
            pixel->G = 255-pixel->G;
            pixel->B = 255-pixel->B;
            pixel->rectangulo.setFillColor(sf::Color(pixel->R,pixel->G,pixel->B,255));



            pixel = pixel->next;
        }
        fila2 = fila2->next;
        fila = fila2->dato;
        pixel = fila->Inicio;
    }
}

void Filtros::filtro_escala_grises() {
    Nodo_matriz *fila2 = datos->RGB_pixeles_imagen->Inicio;
    Lista_pixeles *fila = fila2->dato;
    Nodo_pixel *pixel = fila->Inicio;
    int largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;

    for(int n = 0;n <datos->RGB_pixeles_imagen->largo-2; n++)
    {
        for (int u=0; u<largo_columnas ;u+=1)
        {
            int gris = 0.299*pixel->R+0.587*pixel->G+0.114*pixel->B;
            pixel->R = gris;
            pixel->G = gris;
            pixel->B = gris;
            pixel->rectangulo.setFillColor(sf::Color(pixel->R,pixel->G,pixel->B,255));



            pixel = pixel->next;
        }
        fila2 = fila2->next;
        fila = fila2->dato;
        pixel = fila->Inicio;
    }

}

void Filtros::filtro_trueque() {
    Nodo_matriz *fila2 = datos->RGB_pixeles_imagen->Inicio;
    Lista_pixeles *fila = fila2->dato;
    Nodo_pixel *pixel = fila->Inicio;
    int largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;

    for(int n = 0;n <datos->RGB_pixeles_imagen->largo-2; n++)
    {
        for (int u=0; u<largo_columnas ;u+=1)
        {
            int r_antes = pixel->R;
            int b_antes = pixel->B;

            pixel->R = b_antes ;
            pixel->G = pixel->G;
            pixel->B = r_antes;
            pixel->rectangulo.setFillColor(sf::Color(pixel->R,pixel->G,pixel->B,255));



            pixel = pixel->next;
        }
        fila2 = fila2->next;
        fila = fila2->dato;
        pixel = fila->Inicio;
    }

}

void Filtros::filtro_dividir() {
    Nodo_matriz *fila2 = datos->RGB_pixeles_imagen->Inicio;
    Lista_pixeles *fila = fila2->dato;
    Nodo_pixel *pixel = fila->Inicio;
    int largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;

    for(int n = 0;n <datos->RGB_pixeles_imagen->largo-2; n++)
    {
        for (int u=0; u<largo_columnas ;u+=1)
        {

            pixel->R = pixel->R/2 ;
            pixel->G = pixel->G/2;
            pixel->B = pixel->B/2;
            pixel->rectangulo.setFillColor(sf::Color(pixel->R,pixel->G,pixel->B,255));



            pixel = pixel->next;
        }
        fila2 = fila2->next;
        fila = fila2->dato;
        pixel = fila->Inicio;
    }
}
