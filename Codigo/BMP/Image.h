//
// Created by deylan on 16/05/22.
//

#ifndef CODIGO_IMAGE_H
#define CODIGO_IMAGE_H


#include "../Interfaz/Datos_juego.h"

struct Color{
    float r,g,b;
    float a = 255;
    Color();
    Color(float r,float g,float b);
    void setColor(float r_entrante,float g_entrante,float b_entrante);
    ~Color();
};


class Image {
public:
    Image(int width,int height);
    ~Image();
    Datos_juego *datos = Datos_juego::GetInstance("Informacion");

    Color GetColor(int x,int y) const;
    void SetColor(const Color& color,int x,int y);
    void Read(const char* path);
    void Export(const char* path);
private:
    int m_width;
    int m_heigth;
    Lista_Doble<Color> *m_colors = new Lista_Doble<Color>();


};


#endif //CODIGO_IMAGE_H
