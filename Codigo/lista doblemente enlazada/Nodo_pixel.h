//
// Created by deylan on 26/04/22.
//

#ifndef CODIGO_NODO_PIXEL_H
#define CODIGO_NODO_PIXEL_H


class Nodo_pixel {
public:

    Nodo_pixel(int R_entrante, int G_entrante, int B_entrante, Nodo_pixel *next_entrante, Nodo_pixel *prev_entrante,int indice_entrante);
    Nodo_pixel *next= nullptr;
    Nodo_pixel *prev= nullptr;
    int indice;

    int R;
    int G;
    int B;


};


#endif //CODIGO_NODO_PIXEL_H
