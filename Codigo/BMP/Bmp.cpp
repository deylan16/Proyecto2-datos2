//
// Created by deyla on 26/4/2022.
//

#include "Bmp.h"
#include<stdio.h>

#include<string.h>
#include<stdlib.h>
#pragma pack(pop)
#pragma pack(push)
#pragma pack (1)

#pragma once


FILE *Bmp::Abrir_Bmp(char *Archivo, char *mode) {
    FILE* fp;
    if (strcmp(mode, "r") == 0) {
        mode = "rb";
    }
    else if (strcmp(mode,"w") == 0) {
        mode = "ab";
    }
    else {
        // Mensaje de error de salida
        fprintf (stderr, "Modo de archivo abierto:% s usa error \n", mode);
        // Error al abrir el archivo, devolver el puntero nulo
        return NULL;
    }
    if ((fp = fopen(Archivo,mode)) == NULL) {
        fprintf (stderr, "Abrir archivo:% s fallo \n", Archivo);
        return NULL;
    }
    return fp;
}

Informacion_array_pixeles *Bmp::Leer_informacion_pixeles(FILE *fp) {
    // printf ("% d \ n", sizeof (BITMAPFILEHEADER)); // Este tamaño es de 16 Bytes a la derecha
    Informacion_array_pixeles* fileHead = (Informacion_array_pixeles*)malloc(sizeof(Informacion_array_pixeles));
    if (fileHead == NULL) {
        fprintf (stderr, "Falló la asignación de memoria$$$$");
    }
    if (fread(fileHead, sizeof(Informacion_array_pixeles), 1, fp) != 1) {
        fprintf (stderr, "Error al leer el encabezado del archivo");
    }
    return fileHead;
}

Informacion_encabezado *Bmp::Leer_informacion_encabezado(FILE *fp) {
    //printf("%d\n", sizeof(BITMAPINFOHEADER));
    Informacion_encabezado* Info_encabezado = (Informacion_encabezado*)malloc(sizeof(Informacion_encabezado));
    if (Info_encabezado == NULL) {
        fprintf (stderr, "Falló la asignación de memoria######");
    }
    if (fread(Info_encabezado, sizeof(Informacion_encabezado), 1, fp) != 1) {
        fprintf (stderr, "Error al leer el encabezado");
    }
    /*printf ("Tamaño del encabezado de informacion:% d bytes \n", Info_encabezado-> bHeaderSize);
    printf ("Ancho de imagen:% d pixeles \n", Info_encabezado-> bImageWidth);
    printf ("Altura de la imagen:% d pixeles \n", Info_encabezado-> bImageHeight);
    printf ("Bits de color:% d bits \n", Info_encabezado-> bBitsPerPixel);
    printf ("Pixeles horizontales por metro:% d \n", Info_encabezado-> bXpixelsPerMeter);
    printf ("Pixeles verticales por metro:% d \n", Info_encabezado-> bYpixelsPerMeter);
    printf ("Tamano del bloque de datos:% d bytes \n", Info_encabezado-> bImageSize);
    printf ("Numero de planos:% d \n", Info_encabezado-> bPlanes);
    printf ("Numero total de colores utilizados:% d \n", Info_encabezado-> bTotalColors);
    printf ("Numero total de colores importantes:% d \n", Info_encabezado-> bImportantColors);
    printf ("Algoritmo de compresion:% d \n", Info_encabezado-> bCompression);*/

    return Info_encabezado;
}

RGBDATA **Bmp::createMatrix(int width, int height) {
    // Crea una matriz bidimensional dinámicamente
    RGBDATA** Matrix;
    int i;

    Matrix = (RGBDATA **)malloc(sizeof(RGBDATA*) * height);
    if (Matrix == NULL) {
        fprintf (stderr, "Falló la asignación de memoria@@@@");
        return NULL;
    }

    for (i = 0; i < height; i++) {
        Matrix[i] = (RGBDATA *)malloc(sizeof(RGBDATA) * width);
        if (Matrix[i] == NULL) {
            fprintf (stderr, "Falló la asignación de memoria)))))");
            return NULL;
        }
    }
    return(Matrix);
}

RGBDATA **Bmp::Leer_array_de_pixeles_BMP(FILE *fp) {
    int i = 0, j = 0;

    Informacion_array_pixeles* fileHead = Leer_informacion_pixeles(fp);
    Informacion_encabezado* Info_encabezado = this->Leer_informacion_encabezado(fp);
    width = Info_encabezado->bImageWidth;
    height = Info_encabezado->bImageHeight;
    RGBDATA** data = this->createMatrix(width,height);
    // Si el número de dígitos es menor que 8, la paleta es válida
    if (Info_encabezado->bBitsPerPixel < 8) {
        RGBQUAD* rgbQuad = (RGBQUAD*)malloc(sizeof(RGBQUAD));
        if(rgbQuad == NULL){
            printf ("Falló la asignación de memoria****");
        }
        if (fread(rgbQuad, sizeof(rgbQuad), 1, fp) != 1) {
            printf ("Error al leer la paleta");
        }
    }
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&data[i][j], sizeof(RGBDATA), 1, fp);
        }
    }
    return data;
}