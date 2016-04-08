/** \brief desplega menu y solicita una opcion
 * \param item Es el texto desplegado en el menu
 * \return devuelve un entero que representa la opci�n elegida
 *
 */

int menu (char* item)
{
    int choice; //Almacena la opci�n del men� elegida por el usuario
    printf(item);
    printf("\n\nSeleccione una opci%cn: ", 162);
    scanf("%d",&choice);

    return choice;

}

/** \brief funci�n utilizada para pedir los operandos
 * \param x Es el identificador del operando proveniente de la opci�n seleccionada por el usuario en el men�
 * \return devuelve un float que se almacena en las variables de la funci�n main
 *
 */
float getFloat(char x)
{
    float number;
    printf("Ingrese el operando %c = ",x);
    scanf("%f",&number);
    return number;
}

/** \brief funci�n utilizada para sumar
 * \param x Primer operando
 * \param y Segundo operando
 * \return devuelve un float que es el resultado de la operaci�n
 *
 */
float sum(float x,float y)
{
    float solution;
    solution = x + y;
    return solution;
}

/** \brief funci�n utilizada para restar
 * \param x Primer operando
 * \param y Segundo operando
 * \return devuelve un float que es el resultado de la operaci�n
 *
 */
float substract(float x,float y)
{
    float solution;
    solution = x - y;
    return solution;
}

/** \brief funci�n utilizada para dividir
 * \param x Primer operando
 * \param y Segundo operando
 * \return devuelve un float que es el resultado de la operaci�n
 *
 */
float division(float x,float y)
{
    float solution;
    solution = x / y;
    return solution;
}

/** \brief funci�n utilizada para multiplicar
 * \param x Primer operando
 * \param y Segundo operando
 * \return devuelve un float que es el resultado de la operaci�n
 *
 */

float times(float x,float y)
{
    float solution;
    solution = x * y;
    return solution;
}

/** \brief funci�n utilizada para calcular el factorial
 * \param x Primer operando
 * \return devuelve un float que es el resultado de la funci�n recursiva
 *
 */

long factorial(long x)//FALTA VALIDAR NUMERO NEGATIVO
{
    long solution;
    if (x!=1)
    {
        solution = x * factorial(x-1);
        return solution;
    } else
    {
        return 1;
    }
}
/** \brief funci�n utilizada para validar si el numero es cero
 *
 * \param x Es el numero recibido desde la funci�n que quiere validar si el valor es cero
 * \return devuelve 1 si el valor es distinto de 0
 *
 */

int validateZero(float x)
{
    while (x==0)
    {
        return 0;
    }

    return 1;
}
/** \brief funci�n utilizada para validar si el numero es menor a cero
 *
 * \param x Es el numero long recibido desde la funci�n que quiere validar si el valor es negativo
 * \return devuelve 1 si el valor no es negativo
 *
 */

int validateNeg(long x)
{

    while (x<0)
    {
        return 0;
    }

    return 1;
}

