#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getUTN.h"

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
