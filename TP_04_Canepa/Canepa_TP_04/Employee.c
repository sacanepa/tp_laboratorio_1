#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "ArrayList.h"
#include "getUTN.h"


/**
* Imports the text file into the arrayList
*\param *pList Pointer to ArrayList
*\param *fName name of the file to be used as input
*\return [-1] Invalid data
*        [0] All data added to list
*
*/
int importFile(ArrayList *pList, char *fName)
{
    int r;
    char auxStr[256];
    FILE *f;
    Employee *pAuxEmp;

    if(pList == NULL)
        return -1;

    f = fopen(fName, "r");
    if(f == NULL)
    {
        printf("\nEl archivo no pudo abrirse.\n");
        return -1;
    }

    while (fgets(auxStr, 255, f))
    {
        //printf("RESULT %s",auxStr);
        pAuxEmp = malloc(sizeof(Employee));
        if(pAuxEmp != NULL)
        {
            r = validateEmployee(pAuxEmp,auxStr);

            //printf("RESULT %d",r);
            if(r == 0)
                r = pList->add(pList,pAuxEmp);
        }
    }
    fclose(f);
    return 0;
}



/**
* Validates that string in file has all the data needed in structure
*\param pEmployee Pointer to structure from which elements will be added
*\param input String to validate
*\return [-1] Invalid data
*        [0] All data added to structure
*
*/
int validateEmployee(Employee *pEmployee, char *input)
{
    Employee auxEmp;
    char *auxString;

    auxString = strtok(input, ",");
    //printf("TEST 1 RESULT %s\n",auxString);
    if(strlen(auxString) > 8)
        return -1;

    auxEmp.id = atoi(auxString); //converts the string to int

    auxString = strtok(NULL, ",");
    //printf("TEST 2 RESULT %s\n",auxString);
    if(strlen(auxString) > 50)
        return -1;

    strcpy(auxEmp.name, auxString);

    auxString = strtok(NULL, ",");
    //printf("TEST 3 RESULT %s\n",auxString);
    if(strlen(auxString) > 50)
        return -1;

    strcpy(auxEmp.lastName, auxString);

    auxString = strtok(NULL, ",");
    //printf("TEST 4 RESULT %s\n",auxString);
    auxEmp.salary = atof(auxString);//converts string to float

    if(auxEmp.salary <  0)
        return -1;

    auxString = strtok(NULL, "\n");
    //printf("TEST 5 RESULT %s\n",auxString);
    if(strlen(auxString) > 1)
        return -1;

    auxEmp.sector = atoi(auxString);

    auxEmp.isEmpty = 0;

    *pEmployee = auxEmp;
    return 0;
}


/**
* Compares two employees by salary
*\param *pEmployeeA void pointer to employee 1
*\param *pEmployeeB void pointer to employee 2
*\return [1] EmployeeA > EmployeeA
*        [1] EmployeeA < EmployeeB
*        [0] EmployeeA = EmployeeB
*
*/

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;
}


/**
* Compares two employees by name
*\param *pEmployeeA void pointer to employee 1
*\param *pEmployeeB void pointer to employee 2
*\return [1] EmployeeA > EmployeeA
*        [1] EmployeeA < EmployeeB
*        [0] EmployeeA = EmployeeB
*
*/

int compareEmployeeName(void* pEmployeeA,void* pEmployeeB)
{

    if(stricmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)>0)
    {
        return 1;
    }
    if(stricmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)<0)
    {
        return -1;
    }
    return 0;
}


/**
* Prints in screen the employee data
*\param *p Pointer to employee
*\param index int of counter
*\return void
*/

void printEmployee(Employee* p, int index)
{
    printf("Pos.: %2d\tLeg.: %d\tNombre:%s\tSalario:%.2f\tSector: %d\n\n",index,p->id,p->name,p->salary,p->sector);
}

/** \brief Generates a new employee
 *
 * \param pEmployee employee*
 * \return Employee* Return (NULL) if Error [NULL pointer] - (Pointer to Employee) if Ok
 *
 */
Employee* newEmployee()
{
    float *auxFloat = malloc(sizeof(float));
    int *auxInt = malloc(sizeof(int));
    char aux[40];
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        getInt(auxInt,"Ingrese legajo: ","ERROR",1, 99999999);
        pEmployee->id = *auxInt;
        getString(aux,"Ingrese nombre: ","Error",1,40);
        strcpy(pEmployee->name,aux);
        getString(aux,"Ingrese apellido: ","Error",1,40);
        strcpy(pEmployee->lastName,aux);
        getFloat(auxFloat,"Ingrese salario: ","ERROR",1, 1000000);
        pEmployee->salary = *auxFloat;
        getInt(auxInt,"Ingrese sector: ","ERROR",1, 4);
        pEmployee->sector = *auxInt;
        pEmployee->isEmpty = 0;

        returnAux = pEmployee;
    }

    return returnAux;

}

/** \brief Search employee
 *
 * \param *pList Pointer to arrayList
 * \param *index pointer to int of position of the element in the arrayList
 * \param auxId index of element to look for
* \return Employee* Return (NULL) if Error [NULL pointer] - (Pointer to Employee) if Ok
 *
 */
Employee* searchEmployee(ArrayList* pList,int *index,int auxId)
{
    int i;
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        for(i=0;i<pList->size;i++)
            {
                pEmployee = pList->get(pList,i);
                if(pEmployee->id == auxId)
                {
                    *index = pList->indexOf(pList,pEmployee);
                    returnAux = pEmployee;
                    break;
                }
            }
    }

    return returnAux;
}


/** \brief Modifies an employee
 *
 * \param pEmployee employee* Original to edit
* \return Employee* Return (NULL) if Error [NULL pointer] - (Pointer to Employee) if Ok
 *
 */
Employee* editEmployee(Employee *pEmpOriginal)
{
    float *auxFloat = malloc(sizeof(float));
    int *auxInt = malloc(sizeof(int));
    char aux[40];
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        if(validaDecision("Desea editar numero de legajo? S/N")==0)
        {
            getInt(auxInt,"Ingrese legajo: ","ERROR",1, 99999999);
            pEmployee->id = *auxInt;
        } else {
            pEmployee->id = pEmpOriginal->id;
        }

        if(validaDecision("Desea editar nombre y apellido? S/N")==0)
        {
            getString(aux,"Ingrese nombre: ","Error",1,40);
            strcpy(pEmployee->name,aux);
            getString(aux,"Ingrese apellido: ","Error",1,40);
            strcpy(pEmployee->lastName,aux);
        } else {
            strcpy(pEmployee->name,pEmpOriginal->name);
            strcpy(pEmployee->lastName,pEmpOriginal->lastName);
        }

        if(validaDecision("Desea editar salario? S/N")==0)
        {
            getFloat(auxFloat,"Ingrese salario: ","ERROR",1, 1000000);
            pEmployee->salary = *auxFloat;
        } else {
            pEmployee->salary = pEmpOriginal->salary;
        }

        if(validaDecision("Desea editar sector? S/N")==0)
        {
            getInt(auxInt,"Ingrese sector: ","ERROR",1, 4);
            pEmployee->sector = *auxInt;
        } else {
            pEmployee->sector = pEmpOriginal->sector;
        }

        pEmployee->isEmpty = 0;

        returnAux = pEmployee;
    }

    return returnAux;

}


/**
* Generates a text file split by commas with all the employees
* \param *pEmployee Pointer to Arraylist
* \param *fileEmp char Pointer to file name
* \return void
*
*/

void createTxt(ArrayList *pList)
{
     int i;
     FILE *f;
     Employee *pEmpAux = malloc(sizeof(Employee));
     f=fopen("Nomina.txt", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         for(i=0; i<pList->size; i++)
         {
            pEmpAux = (Employee*) pList->get(pList,i);
            if(pEmpAux->isEmpty == 0)
            {
                fprintf(f,"%d,%s,%s,%.2f,%d\n", pEmpAux->id, pEmpAux->name, pEmpAux->lastName, pEmpAux->salary,pEmpAux->sector);
            }
         }
      }

      fclose(f);

      printf("Cambios guardados.\n");
      system("pause");
}
