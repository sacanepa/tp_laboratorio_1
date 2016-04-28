#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuUTN.h" //function menu
#include "getUTN.h" //functions to get data
#include "arraysUTN.h" // functions to comply with each option in the menu

#define MAX 20 //number of elements in the struct array
#define LENGTH 51

int main()
{
    int choice; //Almacena la opción del menu elegida por el usuario
    person pers[MAX];//estructura que almacena cada una de las personas cargadas
    int r;//variable utilizada para validar si las funciones devuelven un valor válido
    int auxId;
    int flag = 0;

    do
    {
        if (flag == 0)
        {
            r = init(pers, MAX);
        }

        choice = menu("\n*************** TP 2 - CANEPA ***************\n\n"
                  "1. AGREGAR UNA PERSONA\n2. BORRAR UNA PERSONA\n"
                  "3. IMPRIMIR LISTA ORDENADA POR NOMBRE\n"
                  "4. IMPRIMIR GRAFICO DE EDADES.\n5. SALIR\n\n");

        switch (choice)
        {
            case 1:
                //ALTA
                system("cls");
                printf("\n*************** ALTA ***************\n\n");
                r = addPeople(pers, MAX);
                system("cls");
                if (r == 0)
                {
                    printf("\n\nEl registro fue cargado correctamente.\n\n");
                    flag = 1;
                } else
                {
                    printf("\n\nError. El registro no fue cargado.\n\n");
                }
                system("pause");
                break;
            case 2:
                //BORRAR
                if (flag == 0)
                {
                    system("cls");
                    printf("\n\nError. A%cn no se han cargado registros.\n\n",163);
                    system("pause");
                    break;
                }
                system("cls");
                printf("\n*************** BAJA ***************\n\n");
                printf("Ingrese el DNI a borrar: ");
                scanf("%d",&auxId);
                r = removePerson(pers,MAX,auxId);
                system("cls");
                if (r == 0)
                {
                    printf("\nEl registro fue borrado!\n\n");
                } else
                {
                    printf("\n\nError. Registro inexistente.\n\n");
                }
                system("pause");
                break;
            case 3:
                //IMPRIMIR X NOMBRE
                system("cls");
                printf("\n*************** LISTADO ***************\n\n");
                if (flag == 0)
                {
                    system("cls");
                    printf("\n\nError. A%cn no se han cargado registros.\n\n",163);
                    system("pause");
                    break;
                }

                r = sortPersonByName(pers,MAX);
                if (r == 0)
                {
                    r = printPerson(pers,MAX);
                    printf("\n\n");
                } else{
                    printf("\n\nError. Los registros no pudieron ordenarse.\n\n");
                }
                system("pause");
                break;
            case 4:
                //IMPRIMIR GRAFICO
                system("cls");
                printf("\n*************** GRAFICO ***************\n\n");
                if (flag == 0)
                {
                    system("cls");
                    printf("\n\nError. A%cn no se han cargado registros.\n\n",163);
                    system("pause");
                    break;
                }
                if (r == 0)
                {
                    r = printAgeGraph(pers,MAX);
                    printf("\n\n");
                } else{
                    printf("\n\nError. El grafico no pudo crearse.\n\n");
                }
                system("pause");
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
