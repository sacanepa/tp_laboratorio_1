#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int i=0;

    do
    {
        if (i!=0)
        {
            printf("%s",eMessage);
            if (validaS_N() == 1 && i<3)
            {
                printf("%s",message);
                scanf("%d",input);
            } else
            {
                return -1;
            }

        } else
        {
            printf("%s",message);
            scanf("%d",input);
        }
    i++;
    } while (*input < lowLimit || *input > hiLimit);

    //*input = 44;
    return 0;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getDate(long int* pDate,char message[])
{
    int wDay, wMonth, wYear;

    if (getInt(&wDay,"Ingrese el dia (DD): ","Error. Formato DD.", 01, 31) == 0)
        {
            if (getInt(&wMonth,"Ingrese el mes (MM): ","Error. Formato MM.", 01, 12) == 0)
            {
                if (getInt(&wYear,"Ingrese el dia (YYYY): ","Error. Formato YYYY.", 1900, 2999) == 0)
                {
                      *pDate = (long)wDay + ((long)wMonth * 100) +  ((long)wYear * 10000);
                      return 0;
                }else {
                      return -1;
                }
            }else {
                return -1;
            }
        }else {
            return -1;
        }
    return -1;
}


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getLongInt(long int* input,char message[],char eMessage[],long int lowLimit,long int hiLimit)
{
  /*  int i=0;

    do
    {
        if (i!=0)
        {
            printf("%s",eMessage);
            if (validaS_N() == 1 && i<3)
            {
                printf("%s",message);
                scanf("%ld",input);
            } else
            {
                return -1;
            }

        } else
        {
            printf("%s",message);
            scanf("%ld",input);
        }
    i++;
    } while (*input < lowLimit || *input > hiLimit);
*/
    //*input = 44;
    return 0;
}


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int i=0;

    do
    {
        if (i!=0)
        {
            printf("%s",eMessage);
            if (validaS_N() == 1 && i<3)
            {
                printf("%s",message);
                scanf("%f",input);
            } else
            {
                return -1;
            }

        } else
        {
            printf("%s",message);
            scanf("%f",input);
        }
    i++;
    } while (*input < lowLimit || *input > hiLimit);

    //*input = 1234.88;
    return 0;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getAvg(float* input1,float* input2,float *solution)
{

    *solution = *input1 / *input2;

    return 0;
}
/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mÃ­nima de la cadena
* \param hiLimit Longitud mÃ¡xima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int i=0;
    char buffer[1024];
    int nbrChar;

    do
    {
        if (i!=0)
        {
            printf("%s",eMessage);
            if (validaS_N() == 1 && i<3)
            {
                printf("%s",message);
                fflush(stdin);
                gets(buffer);
                nbrChar=strlen(buffer);
            } else
            {
                return -1;
            }

        } else
        {
            printf("%s",message);
            fflush(stdin);
            gets(buffer);
            nbrChar=strlen(buffer);
        }
    i++;
    } while (nbrChar < lowLimit || nbrChar > hiLimit);

    strcpy(input,buffer);
    return 0;
}
int validaS_N(void)
{
    char respuesta;
    int i;

    printf("Ingresa de nuevo? S/N?");
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta = toupper(respuesta);
    i=0;

    while(respuesta != 'S' && respuesta != 'N' && i<3){
        printf("ERROR REINGRESE, Continua S/N?");
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = toupper(respuesta);
        i++;
    }

    if(respuesta == 'S'){
        return 1;
    }
    else{
        return 0;
    }
}

int validaDecision(char message[])
{
    char respuesta;
    int i;

    printf("%s",message);
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta = toupper(respuesta);
    i=0;

    while(respuesta != 'S' && respuesta != 'N' && i<3){
        printf("ERROR REINGRESE, Continua S/N?");
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = toupper(respuesta);
        i++;
    }

    if(respuesta == 'S'){
        return 0;
    }
    else{
        return -1;
    }
}
