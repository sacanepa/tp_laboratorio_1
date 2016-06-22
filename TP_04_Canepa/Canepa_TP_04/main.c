#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getUTN.h"
#include "ArrayList.h"
#include "Employee.h"

int main()
{
    int r,i;
    int *auxInt = malloc(sizeof(int));
    float *auxFloat = malloc(sizeof(float));
    int *auxIndex = malloc(sizeof(int));
    int choice;
    Employee *pEmployee = malloc(sizeof(Employee));
    Employee *pEmployee2 = malloc(sizeof(Employee));

    ArrayList *nomina;
    ArrayList *nominaCloned;
    ArrayList *nominaFilter;

    nomina = al_newArrayList();

    r = importFile(nomina,"Nomina.txt");

    do
    {
        choice = menu("\n*************** TP 4 - CANEPA ***************\n\n"
                  "1- Agregar empleado\n2- Modificar empleado\n"
                  "3- Borrar empleado\n4- Listar\n"
                  "5- PUSH empleado\n6- Listar por salario\n"
                  "7- Listar por Nombre\n8- Filtrar salarios\n"
                  "9- Borrar todos\n10- Guardar y Salir\n");

        switch(choice)
        {
        case 1:
            system("cls");

            pEmployee = newEmployee();
            pEmployee2 = searchEmployee(nomina,auxIndex,pEmployee->id);

            if(pEmployee2 == NULL)
            {
                nomina->add(nomina,pEmployee);
            } else {
                printf("Error. El legajo ya existe.");
                printEmployee(pEmployee2,*auxIndex);
            }

            r = nomina->len(nomina);
            printf("Cantidad de empleados: %d\n\n",r);

            system("pause");
            break;

        case 2:
            system("cls");
            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }
            getInt(auxInt,"Ingrese el legajo a editar: ","ERROR",1, 99999999);
            pEmployee = searchEmployee(nomina,auxIndex,*auxInt);

            if(pEmployee == NULL)
            {
                printf("El legajo no existe.");
            } else {
                pEmployee2 = editEmployee(pEmployee);
                printf("Valor Original:\nPosicion: %d\tLegajo: %d\tNombre:%s\tSalario:%.2f\tSector: %d\n\n",*auxIndex,pEmployee->id,pEmployee->name,pEmployee->salary,pEmployee->sector);
                printf("Nuevo valor:   \nPosicion: %d\tLegajo: %d\tNombre:%s\tSalario:%.2f\tSector: %d\n\n",*auxIndex,pEmployee2->id,pEmployee2->name,pEmployee2->salary,pEmployee2->sector);

                if(validaDecision("Confirma modificacion? S/N ")==0)
                    nomina->set(nomina,*auxIndex,pEmployee2);
            }

            system("pause");
            break;

        case 3:
            system("cls");
            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }

            getInt(auxInt,"Ingrese el legajo a eliminar: ","ERROR",1, 99999999);
            pEmployee = searchEmployee(nomina,auxIndex,*auxInt);

            if(pEmployee == NULL)
            {
                printf("El legajo no existe.");
            } else {

                printf("Se eliminira:\nPosicion: %d\tLegajo: %d\tNombre:%s\tSalario:%.2f\tSector: %d\n\n",*auxIndex,pEmployee->id,pEmployee->name,pEmployee->salary,pEmployee->sector);

                if(validaDecision("Confirma eliminacion? S/N ")==0)
                    nomina->pop(nomina,*auxIndex);
            }

            r = nomina->len(nomina);
            printf("Cantidad de empleados: %d\n\n",r);

            system("pause");
            break;

        case 4:
            system("cls");

            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }

            Employee *pEmployeeOr = malloc(sizeof(Employee));
            for(i=0;i<nomina->size;i++)
            {
                pEmployeeOr = nomina->get(nomina,i);
                printEmployee(pEmployeeOr,i);
            }

            r = nomina->len(nomina);
            printf("Cantidad de empleados: %d\n\n",r);

            system("pause");
            break;

        case 5:
            system("cls");
            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }

            pEmployee = newEmployee();

            getInt(auxInt,"\nIngrese la posicion donde desea ingresar: ","ERROR",0, nomina->size);

            nomina->push(nomina,*auxInt,pEmployee);
            r = nomina->len(nomina);
            printf("\nCantidad de empleados: %d\n\n",r);

            system("pause");
            break;

        case 6:
            system("cls");
            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }

            getInt(auxInt,"\n1: Ascendente\n0: Descendente\n\nElija el orden: ","ERROR",0, 1);
            nominaCloned = nomina->clone(nomina);

            r = nomina->containsAll(nomina,nominaCloned);
            if(r != 0)
            {
                for(i=0;i<nominaCloned->size;i++)
                {
                    pEmployee = nominaCloned->get(nominaCloned,i);
                    printEmployee(pEmployee,i);
                }

            }

            r = nomina->len(nomina);
            printf("Cantidad de empleados: %d\n\n",r);

            system("pause");

            nominaCloned->deleteArrayList(nominaCloned);

            break;
        case 7:
            system("cls");
            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }

            getInt(auxInt,"\n1: Ascendente\n0: Descendente\n\nElija el orden: ","ERROR",0, 1);
            nominaCloned = nomina->clone(nomina);
            r = nominaCloned->sort(nominaCloned,compareEmployeeName,*auxInt);

            r = nomina->containsAll(nomina,nominaCloned);
            if(r != 0)
            {
                for(i=0;i<nominaCloned->size;i++)
                {
                    pEmployee = nominaCloned->get(nominaCloned,i);
                    printEmployee(pEmployee,i);
                }

            }

            r = nomina->len(nomina);
            printf("Cantidad de empleados: %d\n\n",r);

            system("pause");

            nominaCloned->deleteArrayList(nominaCloned);

            break;

        case 8:
            system("cls");
            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }

            getFloat(auxFloat,"\nSalarios mayores a:","ERROR",1, 99999999);
            nominaCloned = nomina->clone(nomina);
            nominaCloned->sort(nominaCloned,compareEmployee,0); //sort descendente por salario

            r = nomina->containsAll(nomina,nominaCloned);
            *auxInt = -1;
            if(r != 0)
            {
                for(i=0;i<nominaCloned->size;i++)
                {
                    pEmployee = nominaCloned->get(nominaCloned,i);
                    if(pEmployee->salary >= *auxFloat)
                    {
                        *auxInt = i;
                    }
                }
            }

            if(*auxInt >= 0)
            {
                nominaFilter = nominaCloned->subList(nominaCloned,0,*auxInt);
                for(i=0;i<nominaFilter->size;i++)
                {
                    pEmployee = nominaFilter->get(nominaFilter,i);
                    printEmployee(pEmployee,i);
                }
            }
            r = nominaFilter->len(nominaFilter);
            printf("Cantidad de empleados con salario mayor a %.2f: %d\n\n",*auxFloat,r);
            system("pause");

            nominaCloned->deleteArrayList(nominaCloned);
            nominaFilter->deleteArrayList(nominaFilter);

            break;

        case 9:
            system("cls");
            if(nomina->isEmpty(nomina) != 0)
            {
                printf("Error. Primero ingrese empleados.");
                break;
            }

            nomina->clear(nomina);
            system("pause");
            break;

        case 10:
            system("cls");
            createTxt(nomina);

            nomina->deleteArrayList(nomina);

            break;

        default:
            system("cls");
            printf("\nOpcion invalida. Reingrese.\n");
            system("pause");
            break;
        }
        system("cls");
    } while (choice != 10);

    return 0;
}
