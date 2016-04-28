#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arraysUTN.h"
#include "getUTN.h"


/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array and the ids to zero
 * \param pPers person* Pointer to array of person
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int init(person* pPers, int length)
{
    int i;
    if (pPers == NULL)
    {
        return -1;
    }

    if (length < 1)
    {
        return -1;
    }

    for (i=0 ; i < length ; i++)
    {
        pPers[i].isEmpty = 1;
        pPers[i].id =0;
    }
    return 0;
}


/** \brief asks for all data needed to enter in the array
 *
 * \param pPers person*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */

int addPeople(person* pPers, int length)
{
    int i,j;

    if (pPers == NULL)
    {
        return -1;
    }

    if (length < 1)
    {
        return -1;
    }

    for (i=0 ; i < length ; i++)
    {
        if (pPers[i].isEmpty == 1)
        {
            if (getInt(&pPers[i].id,"Ingrese el DNI: ","Error! Rango [ 1 - 999999999].",1,999999999) == 0)
            {
                for(j = 0; j < length ; j++)
                {
                    if(j==i){
                        continue;
                    }
                    if(pPers[j].id == pPers[i].id)
                    {
                        printf("\nEl DNI ya fue cargado!\n\n");
                        system("pause");
                        return -1;
                    }
                }
                if (getString(pPers[i].name,"Ingrese el nombre y apellido: ","Error! Largo permitido [ 1 - 50].",1,50) == 0)
                {
                    if (getInt(&pPers[i].age,"Ingrese la edad: ","Error! Rango [ 0 - 120].",0,120) == 0)
                    {
                        pPers[i].isEmpty = 0;
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
        }
    }
    printf("Todos los registros estan ocupados. Borre alguno y vuelva a intentar\n\n");
    system("pause");
    return -1;
}

/** \brief Remove a person by Id (put isEmpty Flag in 1 and changes id to 0)
 *
 * \param pPers person*
 * \param length int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a person] - (0) if Ok
 *
 */
int removePerson(person* pPers, int length, int id)
{
    int i;
    if (pPers == NULL)
    {
        return -1;
    }

    if (length < 1)
    {
        return -1;
    }
    for(i = 0; i < length ; i++)
    {
        if(id == pPers[i].id)
        {
            pPers[i].isEmpty = 1;
            pPers[i].id = 0;
            return 0;
        }
    }
   return -1;
}

/** \brief Sort the elements in the array of person by Name
 *
 * \param pPers person*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a person] - (0) if Ok
 *
 */
int sortPersonByName(person* pPers, int length)
{
    int i,j;
    person aux;

    if (pPers == NULL)
    {
        return -1;
    }

    if (length < 1)
    {
        return -1;
    }

    for (i = 0; i<length-1; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(stricmp(pPers[i].name,pPers[j].name)>0)
            {
                aux=pPers[i];
                pPers[i]=pPers[j];
                pPers[j]=aux;
            }
        }
    }
    return 0;
}

/** \brief shows the list of people
 *
 * \param pPers person*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a person] - (0) if Ok
 *
 */
int printPerson(person* pPers, int length)
{
    int i;
    if (pPers == NULL)
    {
        return -1;
    }

    if (length < 1)
    {
        return -1;
    }

    printf("\nId\t\tName\t\t\t\tAge");
    for(i=0; i< length; i++)
    {
        if(!pPers[i].isEmpty)
        {
           printf("\n%8i\t%-16s\t\t%2d",pPers[i].id, pPers[i].name, pPers[i].age);
        }
    }
    return 0;
}


/** \brief shows a graph of the elements in the array separated by age range
 *
 * \param pPers person*
 * \param length int
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a person] - (0) if Ok
 *
 */
int printAgeGraph(person* pPers, int length)
{
    int i;
    int g1=0;
    int g2=0;
    int g3=0;
    int gTotal;

    if (pPers == NULL)
    {
        return -1;
    }

    if (length < 1)
    {
        return -1;
    }


    for(i=0; i< length; i++)
    {
        if(pPers[i].isEmpty == 0)
        {
            if (pPers[i].age < 18)
            {
                g1++;
            } else if (pPers[i].age > 35)
            {
                g3++;
            } else
            {
                g2++;
            }
        }
    }
    gTotal = g1+g2+g3;

    for (i=gTotal;i>0;i--)
    {
        if(i <= g1 && i <= g2 && i <= g3)
        {
            printf("  *  |  *  |  *  \n");
        } else if(i <= g1 && i <= g2 && i > g3)
        {
            printf("  *  |  *  |     \n");
        } else if(i <= g1 && i > g2 && i > g3)
        {
            printf("  *  |     |     \n");
        } else if(i > g1 && i > g2 && i <= g3)
        {
            printf("     |     |  *  \n");
        } else if(i > g1 && i <= g2 && i <= g3)
        {
            printf("     |  *  |  *  \n");
        } else if(i <= g1 && i > g2 && i <= g3)
        {
            printf("  *  |     |  *  \n");
        } else if(i > g1 && i <= g2 && i > g3)
        {
            printf("     |  *  |     \n");
        }
    }
    printf(" <18 |19-35| >35 \n\n");
    return 0;
}
