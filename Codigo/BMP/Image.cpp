//
// Created by deylan on 16/05/22.
//

#include <cstdio>
#include <fstream>
#include "Image.h"

Color::Color()
        : r(0),g(0),b(0)
{
}

Color::Color(float r, float g, float b)
        : r(r),g(g),b(b)
{

}

Color::~Color() {

}

void Color::setColor(float r_entrante, float g_entrante, float b_entrante) {
    this->r = r_entrante;
    this->g = g_entrante;
    this->b = b_entrante;
}

Image::Image(int width, int height)
        : m_width(width),m_heigth(height)//,m_colors(std::vector<Color>(width*height))
{
}

Color Image::GetColor(int x, int y) const {
    return m_colors->busqueda_indice(y*m_width+x);
}
Image::~Image() {
}
void Image::SetColor(const Color &color, int x, int y) {
    Color pixel = Color(color.r,color.g,color.b);
    /*pixel.r = ;
    pixel.g = ;
    pixel.b = ;*/
    m_colors->append(pixel);

    //.setColor(color.r,color.g,color.b) ;


}

void Image::Export(const char *path) {
    //bmpFileHeader header;
    /*FILE *f;
    f=fopen(path, "w+");*/
    std::ofstream f;
    f.open(path,std::ios::out| std::ios::binary);

    unsigned char badPad[4] = {0,0,0,255};
    const int paddingAmount = ((4-(m_width*4)%4)%4);

    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    const int fileSize =  fileHeaderSize + informationHeaderSize + m_width * m_heigth*4 + paddingAmount * m_width;
    const int imgSize = m_width * m_heigth*4;

    unsigned char fileHeader[fileHeaderSize];
    uint16_t type=0x4D42;

    fileHeader[0] = type ;
    fileHeader[1] =  type>>8;

    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;

    fileHeader[6] = 0;
    fileHeader[7] = 0;

    fileHeader[8] = 0;
    fileHeader[9] = 0;

    fileHeader[10] = fileHeaderSize + informationHeaderSize;
    fileHeader[11] = 0;
    fileHeader[12] = 0;
    fileHeader[13] = 0;

    unsigned char informationHeader[informationHeaderSize];

    informationHeader[0] = informationHeaderSize;
    informationHeader[1] =0;
    informationHeader[2] =0;
    informationHeader[3] =0;

    informationHeader[4] =m_width;
    informationHeader[5] =m_width>>8;
    informationHeader[6] =m_width>>16;
    informationHeader[7] =m_width>>24;

    informationHeader[8] = m_heigth;
    informationHeader[9] =m_heigth >> 8;
    informationHeader[10] =m_heigth >> 16;
    informationHeader[11] =m_heigth >> 24;

    informationHeader[12] = 1;
    informationHeader[13] = 0;

    informationHeader[14] = 32;
    informationHeader[15] = 0;

    informationHeader[16] =0;
    informationHeader[17] =0;
    informationHeader[18] =0;
    informationHeader[19] =0;

    informationHeader[20] =imgSize;
    informationHeader[21] =imgSize >>8;
    informationHeader[22] =imgSize >> 16;
    informationHeader[23] =imgSize >> 24;

    informationHeader[24] =0;
    informationHeader[25] =0;
    informationHeader[26] =0;
    informationHeader[27] =0;

    informationHeader[28] =0;
    informationHeader[29] =0;
    informationHeader[30] =0;
    informationHeader[31] =0;

    informationHeader[32] =0;
    informationHeader[33] =0;
    informationHeader[34] =0;
    informationHeader[35] =0;

    informationHeader[36] =0;
    informationHeader[37] =0;
    informationHeader[38] =0;
    informationHeader[39] =0;

    f.write(reinterpret_cast<const char *>(fileHeader), fileHeaderSize);
    f.write(reinterpret_cast<const char *>(informationHeader), informationHeaderSize);

    Nodo<Color> *pixel = m_colors->Final;
    for(int y = 0; y< m_heigth ;y++){
        for(int x = 0; x< m_width;x++){




            unsigned char r = static_cast<unsigned char >(pixel->dato.r);
            unsigned char g = static_cast<unsigned char >(pixel->dato.g);
            unsigned char b = static_cast<unsigned char >(pixel->dato.b );

            unsigned  char color[] = {b,g,r};
            f.write(reinterpret_cast<const char *>(color), 4);
            pixel = pixel->prev;



        }
        f.write(reinterpret_cast<const char *>(badPad), paddingAmount);

    }
    //fwrite(imgdata, info->imgsize, 1, f);
    f.close();

}

void Image::Read(const char* path) {



}