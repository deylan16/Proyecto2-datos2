//
// Created by deyla on 26/4/2022.
//

#ifndef CODIGO_BMP_H
#define CODIGO_BMP_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct bmpFileHeader
{
    /* 2 bytes de identificación */
    uint32_t size;        /* Tamaño del archivo */
    uint16_t resv1;       /* Reservado */
    uint16_t resv2;       /* Reservado */
    uint32_t offset;      /* Offset hasta hasta los datos de imagen */
} bmpFileHeader;

typedef struct bmpInfoHeader
{
    uint32_t headersize;      /* Tamaño de la cabecera */
    uint32_t width;       /* Ancho */
    uint32_t height;      /* Alto */
    uint16_t planes;          /* Planos de color (Siempre 1) */
    uint16_t bpp;             /* bits por pixel */
    uint32_t compress;        /* compresión */
    uint32_t imgsize;     /* tamaño de los datos de imagen */
    uint32_t bpmx;        /* Resolución X en bits por metro */
    uint32_t bpmy;        /* Resolución Y en bits por metro */
    uint32_t colors;      /* colors used en la paleta */
    uint32_t imxtcolors;      /* Colores importantes. 0 si son todos */
} bmpInfoHeader;

class Bmp {
public:
    bmpInfoHeader info;
    unsigned char *img;

    unsigned char *LoadBMP(char *filename, bmpInfoHeader *bInfoHeader);
    void DisplayInfo(bmpInfoHeader *info);
    void TextDisplay(bmpInfoHeader *info, unsigned char *img);
    void SaveBMP(char *filename, bmpInfoHeader *info, unsigned char *imgdata);
};



#endif //CODIGO_BMP_H
