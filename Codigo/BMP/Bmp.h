//
// Created by deyla on 26/4/2022.
//

#ifndef CODIGO_BMP_H
#define CODIGO_BMP_H
typedef unsigned int DWORD;  // 4bytes
typedef unsigned short WORD;  // 2bytes
typedef signed long LARGO;  // 4bytes
typedef unsigned char BYTE;  // 1bytes
typedef struct tagInformacion_array_pixeles {
    WORD bFileType;
    DWORD bFileSize;
    WORD bReserved1;
    WORD bReserved2;
    DWORD bPixelDataOffset;
}Informacion_array_pixeles; //14bytes
/* Estructura de encabezado de información de archivo de mapa de bits */
typedef struct tagInformacion_encabezado {
    DWORD bHeaderSize; // Tamaño total del encabezado de información de imagen (40bytes)
    LARGO bImageWidth; // Ancho de imagen (píxeles)
    LARGO bImageHeight; // Altura de la imagen
    WORD bPlanes; // debería ser 0
    WORD bBitsPerPixel; // Número de píxeles
    DWORD bCompression; // Método de compresión de imagen
    DWORD bImageSize; // Tamaño de imagen (bytes)
    LARGO bXpixelsPerMeter; // píxeles horizontales por metro
    LARGO bYpixelsPerMeter; // Píxeles verticales por metro
    DWORD bTotalColors; // El número total de colores utilizados, si el número de píxeles es mayor que 8, este campo no tiene sentido
    DWORD bImportantColors; // números de color importantes, generalmente inútiles
}Informacion_encabezado; //40bytes
/* Estructura de paleta de archivos de mapa de bits */
typedef struct tagRGBQUAD {
    BYTE	rgbBlue;
    BYTE	rgbGreen;
    BYTE	rgbRed;
    BYTE	rgbReserved;
}RGBQUAD;
/* Estructura de píxeles RGB */
typedef struct tagRGB {
    BYTE blue;
    BYTE green;
    BYTE red;
}RGBDATA;

class Bmp {
public:
    int width = 0, height = 0;
    FILE* Abrir_Bmp(char* Archivo, char* mode);
    Informacion_array_pixeles* Leer_informacion_pixeles(FILE* fp);
    Informacion_encabezado* Leer_informacion_encabezado(FILE* fp);
    RGBDATA** createMatrix(int width,int height);
    RGBDATA** Leer_array_de_pixeles_BMP(FILE* fp);
};


#endif //CODIGO_BMP_H
