#include <stdio.h>
#include <stdlib.h>
#include "funcionesTP3.h"

//#define MAX 5

int main()
{
    int choice; //Almacena la opción del menu elegida por el usuario
    EMovie movie;
    EMovie *pMovie;
    char auxTitulo[20];
    int r;

    pMovie = &movie;
    //printf("%p\n",pMovie);

    do
    {
        choice = menu("\n*************** TP 3 - CANEPA ***************\n\n"
                  "1- Agregar pelicula\n2- Borrar pelicula\n"
                  "3- Modificar pelicula\n4- Generar pagina web\n"
                  "5- Salir\n\n");

        switch(choice)
        {
            case 1:
                 //ALTA
                system("cls");
                printf("\n*************** AGREGAR PELICULA ***************\n\n");

                r = agregarPelicula(pMovie);
                system("cls");
                printf("\n*************** AGREGAR PELICULA ***************\n\n");
                if (r == 0)
                {
                    printf("\n\nLa pelicula fue cargada correctamente.\n\n");
                    system("pause");
                } else if(r == -1)
                {
                    printf("\n\nEl registro no fue cargado.\n\n");
                    system("pause");
                }

                break;

            case 2:
                //BORRAR
                system("cls");
                printf("\n*************** ELIMINAR PELICULA ***************\n\n");
                printf("Ingrese el titulo de la pelicula a borrar: ");
                fflush(stdin);
                gets(auxTitulo);
                r = borrarPelicula(pMovie,auxTitulo);
                system("cls");
                printf("\n*************** ELIMINAR PELICULA ***************\n\n");
                if (r == 0)
                {
                    printf("\nLa pelicula fue borrada!\n\n");
                    system("pause");
                } else if(r == -1)
                {
                    printf("\n\nLa pelicula no fue borrada.\n\n");
                    system("pause");
                }
                break;
            case 3:
             //MODIFICAR
                system("cls");
                printf("\n*************** MODIFICAR PELICULA ***************\n\n");
                printf("Ingrese el titulo de la pelicula a modificar: ");
                fflush(stdin);
                gets(auxTitulo);
                r = modificarPelicula(pMovie, auxTitulo);
                system("cls");
                printf("\n*************** MODIFICAR PELICULA ***************\n\n");
                if (r == 0)
                {
                    printf("\nLa pelicula fue modificada!\n\n");
                    system("pause");
                } else if(r == -1)
                {
                    printf("\n\nNo se modifico la pelicula.\n\n");
                    system("pause");
                }

               break;
            case 4:
             //GENERAR FILE
                system("cls");
                printf("\n*************** CREAR PAGINA WEB ***************\n\n");

                r = generarPagina(pMovie,"index.dat", "index.html");
                if (r == 0)
                {
                    printf("\nLa pagina web fue creada!\n\n");
                    system("pause");
                } else
                {
                    printf("\n\nError. No se pudo crear la pagina web.\n\n");
                    system("pause");
                }
               break;
            case 5:
               //SALIR
               break;
            default:
                printf("\n\nOpci%cn inexistente. Reintente.\n\n",162);
                system("pause");
                break;
        }

    system("cls");

    }while (choice != 5);

    printf("\n\n*** Good bye! ***\n");
    return 0;
}
