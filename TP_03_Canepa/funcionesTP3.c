#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesTP3.h"
#include "getUTN.h"

/** \brief desplega menu y solicita una opcion
 * \param item Es el texto desplegado en el menu
 * \return devuelve un entero que representa la opción elegida
 *
 */

int menu (char* item)
{
    int choice; //Almacena la opción del menú elegida por el usuario
    printf(item);
    printf("\n\nSeleccione una opci%cn: ", 162);
    scanf("%d",&choice);

    return choice;

}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* pMovie)
{
    FILE *fBinMovie;
    if (pMovie == NULL)//|| length < 1)
    {
        return -1;
    }

    if (getString(pMovie->titulo,"Ingrese el titulo: ","Error! Largo permitido [ 1 - 20].",1,20) == 0)
    {
        if(checkPelicula(pMovie, pMovie->titulo) == 0) //WAY OUT IF MOVIE EXISTS
        {
            printf("La pelicula ya existe en la base de datos. Ingrese a la opcion 3 (Modificar)\n\n");
            system("pause");
            return -2;
        }

        if (getString(pMovie->genero,"Ingrese el genero: ","Error! Largo permitido [ 1 - 20].",1,20) == 0)
        {
            if (getInt(&pMovie->duracion,"Ingrese la duracion: ","Error! Rango [ 0 - 250].",0,250) == 0)
            {
                if (getString(pMovie->descripcion,"Ingrese la descripcion: ","Error! Largo permitido [ 1 - 600].",1,600) == 0)
                {
                    if (getInt(&pMovie->puntaje,"Ingrese la puntaje: ","Error! Rango [ 0 - 100].",0,100) == 0)
                    {
                        if (getString(pMovie->linkImagen,"Ingrese el link de la imagen: ","Error! Largo permitido [ 1 - 300].",1,300) == 0)
                        {
                            pMovie->isEmpty=0;
                            if((fBinMovie= fopen("index.dat","r+b"))==NULL)
                            {
                                if((fBinMovie= fopen("index.dat","w+b"))==NULL)
                                {
                                    printf("\nEl archivo no puede abrirse");
                                    return -1;
                                }
                            }
                            fflush(stdin);
                            fseek(fBinMovie,0L,SEEK_END);
                            fwrite(pMovie,sizeof(EMovie),1,fBinMovie);
                            fclose(fBinMovie);
                            return 0;
                        }else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
           } else {
                return -1;
           }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
    system("pause");
    return -1;
}

/**
 *  Busca si una pelicula del archivo binario ya existe con el mismo titulo
 *  @param movie la estructura a ser buscada en el archivo
 *  @param *titulo string del titulo
 *  @return retorna -1 o 0 de acuerdo a si se encontro la pelicula o no
 */
int checkPelicula(EMovie* pMovie, char* titulo)
{
    FILE *fBinMovie;
    if (pMovie == NULL)
    {
        return -1;
    }

    if((fBinMovie= fopen("index.dat","r+b"))==NULL)
    {
        if((fBinMovie= fopen("index.dat","w+b"))==NULL)
        {
            printf("\nEl archivo no puede abrirse");
            return -2;
        }
    }

    rewind(fBinMovie);
    while(!feof(fBinMovie))
    {
        fread(pMovie,sizeof(EMovie),1,fBinMovie);
        if(stricmp(titulo,pMovie->titulo)==0)
        {
                fclose(fBinMovie);
                return 0;
        }
    }
    system("pause");
    return -1;
}


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param length cantidad de indices ene l array de estructuras
 *  @param *titulo string del titulo a eliminar
 *  @return retorna -1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* pMovie, char* titulo)
{
    FILE *fBinMovie;
    if (pMovie == NULL)
    {
        return -1;
    }

    if((fBinMovie= fopen("index.dat","r+b"))==NULL)
    {
        if((fBinMovie= fopen("index.dat","w+b"))==NULL)
        {
            printf("\nEl archivo no puede abrirse");
            return -2;
        }
    }

    rewind(fBinMovie);
    while(!feof(fBinMovie))
    {
        fread(pMovie,sizeof(EMovie),1,fBinMovie);
        if(stricmp(titulo,pMovie->titulo)==0)
        {
            printf("\nTitulo: %s\nGenero: %s\nDescripcion: %s\n",pMovie->titulo,pMovie->genero,pMovie->descripcion);
            printf("\nDuracion: %d\nPuntaje: %d\nLink Imagen: %s\n",pMovie->duracion,pMovie->puntaje,pMovie->linkImagen);
            if (validaDecision("Desea eliminar la pelicula? [S/N]")==0)
            {
                pMovie->isEmpty=1;
                fflush(stdin);
                fseek(fBinMovie,(long)(-1)*sizeof(EMovie),SEEK_CUR);
                fwrite(pMovie,sizeof(EMovie),1,fBinMovie);
                fclose(fBinMovie);
                return 0;
            }
            else
            {
                fclose(fBinMovie);
                return -1;
            }
        }
    }
    printf("\n\nLa pelicula no fue encontrada.\n\n");
    fclose(fBinMovie);
    system("pause");
    return -2;
    //return -1;
}

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @param *titulo string del titulo a modificar
 *  @return retorna -1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int modificarPelicula(EMovie* pMovie, char* titulo)
{
    FILE *fBinMovie;
    if (pMovie == NULL)
    {
    //    printf("This error");
        return -1;
    }

    if((fBinMovie= fopen("index.dat","r+b"))==NULL)
    {
        if((fBinMovie= fopen("index.dat","w+b"))==NULL)
        {
            printf("\nEl archivo no puede abrirse");
            system("pause");
            return -2;
        }
    }

    rewind(fBinMovie);
    while(!feof(fBinMovie))
    {
        fread(pMovie,sizeof(EMovie),1,fBinMovie);
        if(stricmp(titulo,pMovie->titulo)==0)
        {
            printf("\nTitulo: %s\nGenero: %s\nDescripcion: %s\n",pMovie->titulo,pMovie->genero,pMovie->descripcion);
            printf("\nDuracion: %d\nPuntaje: %d\nLink Imagen: %s\n",pMovie->duracion,pMovie->puntaje,pMovie->linkImagen);
            if (validaDecision("Desea modificar la pelicula? [S/N]")==0)
            {
                if (validaDecision("Desea modificar el titulo? [S/N]")==0)
                {
                    getString(pMovie->titulo,"Ingrese el titulo: ","Error! Largo permitido [ 1 - 20].",1,20);
                }
                if (validaDecision("Desea modificar la duracion? [S/N]")==0)
                {
                    getInt(&pMovie->duracion,"Ingrese la duracion: ","Error! Rango [ 0 - 250].",0,250);
                }
                if (validaDecision("Desea modificar el genero? [S/N]")==0)
                {
                    getString(pMovie->genero,"Ingrese el genero: ","Error! Largo permitido [ 1 - 20].",1,20);
                }
                if (validaDecision("Desea modificar la descripcion? [S/N]")==0)
                {
                    getString(pMovie->descripcion,"Ingrese la descripcion: ","Error! Largo permitido [ 1 - 600].",1,600);
                }
                if (validaDecision("Desea modificar el puntaje? [S/N]")==0)
                {
                    getInt(&pMovie->puntaje,"Ingrese la puntaje: ","Error! Rango [ 0 - 100].",0,100);
                }
                if (validaDecision("Desea modificar la imagen? [S/N]")==0)
                {
                    getString(pMovie->linkImagen,"Ingrese el link de la imagen: ","Error! Largo permitido [ 1 - 300].",1,300);
                }
            pMovie->isEmpty=0;
            fflush(stdin);
            fseek(fBinMovie,(long)(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(pMovie,sizeof(EMovie),1,fBinMovie);
            fclose(fBinMovie);
            return 0;
            } else {
                return -1;
            }
        }
    }

    printf("\n\nLa pelicula no fue encontrada.\n\n");
    fclose(fBinMovie);
    system("pause");
    return -2;
   // return -1;
}


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
int generarPagina(EMovie* pMovie, char*fileBin, char *fileHtml)
{
    FILE *fTxtMovie;
    FILE *fBinMovie;
    int movieNbr;

    if((fBinMovie = fopen(fileBin, "rb"))==NULL)
    {
        printf("\nEl archivo binario no pudo abrirse.");
        system("pause");
        return -2;
    }
    else
    {
        if((fTxtMovie = fopen(fileHtml, "w"))==NULL)
        {
            printf("\nEl archivo de texto no pudo abrirse.");
            system("pause");
            return -2;
        }
        else
        {
            fprintf(fTxtMovie,"<!DOCTYPE html>\n<html lang='en'>\n<head>\n"
                "\t<meta charset='utf-8'>\n\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
                "\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n"
                "\t<title>Lista peliculas</title>\n"
                "\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n"
                "\t<link href='css/custom.css' rel='stylesheet'>\n"
                "\t\t<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n"
                "\t\t<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n"
                "</head>\n<body>\n"
                "\t<div class='container'>\n"
                "\t\t<div class='row'>\n");

            rewind(fBinMovie);
            while(!feof(fBinMovie))
            {
                movieNbr=fread(pMovie,sizeof(EMovie),1,fBinMovie);
                if(movieNbr != 1)
                {
                    if(feof(fBinMovie))
                    {
                        break;
                    } else {
                        printf("No leyo el ultimo registro");
                        break;
                    }
                }
                if(pMovie->isEmpty == 0)
                {
                    fflush(stdin);
                    fseek(fTxtMovie,0L,SEEK_END);
                    fprintf(fTxtMovie,"\n\n\n\n\n");
                    fprintf(fTxtMovie,"\t\t\t<article class='col-md-4 article-intro'>\n");
                    fprintf(fTxtMovie,"\t\t\t\t<a href='#'>\n");
                    fprintf(fTxtMovie,"\t\t\t\t\t<img class='img-responsive img-rounded' src='%s' alt=''>\n",pMovie->linkImagen);
                    fprintf(fTxtMovie,"\t\t\t\t</a>\n\t\t\t\t<h3>\n");
                    fprintf(fTxtMovie,"\t\t\t\t\t<a href='#'>%s</a>\n",pMovie->titulo);
                    fprintf(fTxtMovie,"\t\t\t\t</h3>\n\t\t\t\t\t\t<ul>\n");
                    fprintf(fTxtMovie,"\t\t\t\t\t\t\t<li>Gnero: %s</li>\n",pMovie->genero);
                    fprintf(fTxtMovie,"\t\t\t\t\t\t\t<li>Puntaje: %d</li>\n",pMovie->puntaje);
                    fprintf(fTxtMovie,"\t\t\t\t\t\t\t<li>Duracion: %d</li>\n",pMovie->duracion);
                    fprintf(fTxtMovie,"\n\t\t\t\t\t\t</ul>\n");
                    fprintf(fTxtMovie,"\t\t\t\t<p>%s</p>\n",pMovie->descripcion);
                    fprintf(fTxtMovie,"\t\t\t</article>\n\n\n\n");
                }
            }
        }

            fprintf(fTxtMovie,"\t\t</div>\n\t\t<!-- /.row -->\n\t</div>\n\t<!-- /.container -->\n"
                "\t<script src='js/bootstrap.min.js'></script>\n"
                "\t\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
                "\t\t<script src='js/holder.min.js'></script>\n"
                "</body>\n"
                "</html>");
    }
    fclose(fTxtMovie);
    fclose(fBinMovie);
    return 0;
}

