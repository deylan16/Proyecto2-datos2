//
// Created by deyla on 26/4/2022.
//

#include "Bmp.h"
#include "Image.h"


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
    int width = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo-1;
    int height = datos->RGB_pixeles_imagen->largo;
    Image image(width, height);
    for(int y = 0; y< height;y++){
        for(int x = 0;x<width;x++){
            Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(y)->busqueda_indice(x);

            image.SetColor(Color(pixel->R,pixel->G,pixel->B),x,height-1-y);
        }
    }
    image.Export(filename);

}

