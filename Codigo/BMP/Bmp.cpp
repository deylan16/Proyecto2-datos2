//
// Created by deyla on 26/4/2022.
//

#include "Bmp.h"



unsigned char *Bmp::LoadBMP(char *filename, bmpInfoHeader *bInfoHeader) {
    FILE *f;
    bmpFileHeader header;     /* cabecera */
    unsigned char *imgdata;   /* datos de imagen */
    uint16_t type;        /* 2 bytes identificativos */

    f=fopen (filename, "r");


    if (!f)
        return NULL;        /* Si no podemos leer, no hay imagen*/

        /* Leemos los dos primeros bytes */
        fread(&type, sizeof(uint16_t), 1, f);
        if (type !=0x4D42)        /* Comprobamos el formato */
            {
            fclose(f);
            return NULL;
            }

            /* Leemos la cabecera de fichero completa */
            fread(&header, sizeof(bmpFileHeader), 1, f);

            /* Leemos la cabecera de información completa */
            fread(bInfoHeader, sizeof(bmpInfoHeader), 1, f);

            /* Reservamos memoria para la imagen, ¿cuánta?
               Tanto como indique imgsize */
            imgdata=(unsigned char*)malloc(bInfoHeader->imgsize);

            /* Nos situamos en el sitio donde empiezan los datos de imagen,
             nos lo indica el offset de la cabecera de fichero*/
            fseek(f, header.offset, SEEK_SET);

            /* Leemos los datos de imagen, tantos bytes como imgsize */
            /*int c;
            while((c= getc(f))!= EOF){
                std::cout<<c<<std::endl;
            }*/
            fread(imgdata, bInfoHeader->imgsize,1, f);


            /* Cerramos */
            fclose(f);

            /* Devolvemos la imagen */
            return imgdata;
}

void Bmp::DisplayInfo(bmpInfoHeader *info) {
    printf("Tamaño de la cabecera: %u\n", info->headersize);
    printf("Anchura: %d\n", info->width);
    printf("Altura: %d\n", info->height);
    printf("Planos (1): %d\n", info->planes);
    printf("Bits por pixel: %d\n", info->bpp);
    printf("Compresión: %d\n", info->compress);
    printf("Tamaño de datos de imagen: %u\n", info->imgsize);
    printf("Resolucón horizontal: %u\n", info->bpmx);
    printf("Resolucón vertical: %u\n", info->bpmy);
    printf("Colores en paleta: %d\n", info->colors);
    printf("Colores importantes: %d\n", info->imxtcolors);
}

void Bmp::TextDisplay(bmpInfoHeader *info, unsigned char *img) {
    int x, y;
    /* Reducimos la resolución vertical y horizontal para que la imagen entre en pantalla */
    //static const int reduccionX=6, reduccionY=4;
    /* Si la componente supera el umbral, el color se marcará como 1. */
    //static const int umbral=90;
    /* Asignamos caracteres a los colores en pantalla */
    static unsigned char colores[9]=" bgfrRGB";
    int r,g,b;

    /* Dibujamos la imagen */
    for (y=info->height; y>0; y--)
    {
        for (x=0; x<info->width; x++)
        {
            b=(img[3*(x+y*info->width)]);
            g=(img[3*(x+y*info->width)+1]);
            r=(img[3*(x+y*info->width)+2]);

            //printf("%c", colores[b+g*2+r*4]);
            std::cout<<"["<<r<<","<<g<<","<<b<<"]";
        }
        printf("\n");
    }
}

void Bmp::SaveBMP(char *filename, bmpInfoHeader *info, unsigned char *imgdata) {
    bmpFileHeader header;
    FILE *f;
    uint16_t type;
    bmpInfoHeader info2;
    info2.headersize = 124;      /* Tamaño de la cabecera */
    info2.width = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;       /* Ancho */
    info2.height= datos->RGB_pixeles_imagen->largo;      /* Alto */
    info2.planes = 1;          /* Planos de color (Siempre 1) */
    info2.bpp = 32;             /* bits por pixel */
    info2.compress = 3;        /* compresión */
    info2.imgsize =info2.width *info2.height *4;     /* tamaño de los datos de imagen */
    info2.bpmx = 0;        /* Resolución X en bits por metro */
    info2.bpmy = 0;        /* Resolución Y en bits por metro */
    info2.colors= 0;      /* colors used en la paleta */
    info2.imxtcolors = 0;      /* Colores importantes. 0 si son todos */

    f=fopen(filename, "w+");
    //info->height = 310;
    header.size=info2.imgsize+sizeof(bmpFileHeader)+sizeof(bmpInfoHeader);
    /* header.resv1=0; */
    /* header.resv2=1; */
    /* El offset será el tamaño de las dos cabeceras + 2 (información de fichero)*/
    header.offset=sizeof(bmpFileHeader)+sizeof(bmpInfoHeader)+2;
    /* Escribimos la identificación del archivo */
    type=0x4D42;
    fwrite(&type, sizeof(type),1,f);
    /* Escribimos la cabecera de fichero */
    fwrite(&header, sizeof(bmpFileHeader),1,f);
    /* Escribimos la información básica de la imagen */
    fwrite(&info2, sizeof(bmpInfoHeader),1,f);
    /* Escribimos la imagen */

    int relleno = ((4-(info2.width*3)%4)%4);
    Nodo_matriz *fila2 = datos->RGB_pixeles_imagen->Final;
    Lista_pixeles *fila = fila2->dato;
    Nodo_pixel *pixel = fila->Inicio;
    int largo_columnas = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo;

    for(int n = 0;n <datos->RGB_pixeles_imagen->largo-2; n++)
    {
        for (int u=0; u<largo_columnas ;u+=1)
        {
            rgb colores_pixel;
            colores_pixel.R = pixel->R;
            colores_pixel.G = pixel->G;
            colores_pixel.B = pixel->B;
            colores_pixel.A = 255;
            fwrite(&colores_pixel, sizeof(colores_pixel), 1, f);
            //pixel->rectangulo.setFillColor(sf::Color(0,0,0,255));
            //pixel->rectangulo.setPosition(u,n+100);

            pixel = pixel->next;
        }
        for (int u=0; u<largo_columnas ;u+=1)
        {
            rgb colores_pixel;
            colores_pixel.R = 0;
            colores_pixel.G = 0;
            colores_pixel.B =0 ;
            colores_pixel.A = 0;
            fwrite(&colores_pixel, sizeof(colores_pixel), 1, f);

        }

        fila2 = fila2->prev;
        fila = fila2->dato;
        pixel = fila->Inicio;
    }

    //fwrite(imgdata, info->imgsize, 1, f);
    fclose(f);
}

