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


        if (!f){

            return NULL;
        }
              /* Si no podemos leer, no hay imagen*/

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
    //int width = 640;
    //int height = 480;

    /*bmpFileHeader header;
    FILE *f;
    f=fopen(filename, "w+");
    int m_width = datos->RGB_pixeles_imagen->busqueda_indice(0)->largo-1;
    int m_height =  datos->RGB_pixeles_imagen->largo;

    unsigned char badPad[4] = {0,0,0,0};
    const int paddingAmount = ((4-(m_width*3)%4)%4);

    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    const int fileSize = fileHeaderSize + m_width * m_height*3 + paddingAmount * m_width;

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

    informationHeader[8] = m_height;
    informationHeader[9] =m_height >> 8;
    informationHeader[10] =m_height >> 16;
    informationHeader[11] =m_height >> 24;

    informationHeader[12] = 1;
    informationHeader[13] = 0;

    informationHeader[14] = 32;
    informationHeader[15] = 0;

    informationHeader[16] =0;
    informationHeader[17] =0;
    informationHeader[18] =0;
    informationHeader[19] =0;

    informationHeader[20] =0;
    informationHeader[21] =0;
    informationHeader[22] =0;
    informationHeader[23] =0;

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

    fwrite(fileHeader, fileHeaderSize,1,f);
    fwrite(informationHeader, informationHeaderSize,1,f);

    for(int y = m_height-1; y>0 ;y--){
        for(int x = 0; x< m_width;x++){
            Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(y)->busqueda_indice(x);

            unsigned char r = pixel->R;
            unsigned char g = pixel->G;
            unsigned char b = pixel->B;

            unsigned  char color[] = {b,g,r,255};
            fwrite(color, 4,1,f);


        }
        fwrite(badPad, paddingAmount,1,f);
    }












    //fwrite(imgdata, info->imgsize, 1, f);
    fclose(f);*/

    Image image(width, height);
    for(int y = 0; y< height;y++){
        for(int x = 0;x<width;x++){
            Nodo_pixel *pixel = datos->RGB_pixeles_imagen->busqueda_indice(y)->busqueda_indice(x);
            image.SetColor(Color(pixel->R,pixel->G,pixel->B),x,height-1-y);
        }
    }
    image.Export("image.bmp");

}

