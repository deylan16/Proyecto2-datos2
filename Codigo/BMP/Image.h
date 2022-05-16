//
// Created by deyla on 13/5/2022.
//

#ifndef CODIGO_IMAGE_H
#define CODIGO_IMAGE_H

#include <vector>
#include "../Interfaz/Datos_juego.h"

struct Color{
    float r,g,b;
    float a = 255;
    Color();
    Color(float r,float g,float b);
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
    std::vector<Color> m_colors;



};


#endif //CODIGO_IMAGE_H
