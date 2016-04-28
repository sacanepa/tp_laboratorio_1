#include <stdio.h>
#include <stdlib.h>
#include "../utn.h"
#define ATTEMPTS 3


int main()
{
    int answer;//corresponde a la opción del menú seleccionada por el usuario
    float number1=0,number2=0;//corresponde a las dos variables donde se guardan los operandos (A y B) ingresados por el usuario
    int flag1=0,flag2=0; //variables utilizadas para chequear si es la primera operacion
    int i=0; //variable para contar intentos
    do
    {
        system("cls");

        if (flag1==0 && flag2==0)
        {
            printf("\n***CALCULADORA***\n\n1.Ingresar 1er operando (A=x) \n"
                    "2.Ingresar 2do operando (B=y)\n");
        }else if (flag1==1 && flag2==0)
        {
            printf("\n***CALCULADORA***\n\n1.Ingresar 1er operando (A=%.2f) \n"
                 "2.Ingresar 2do operando (B=y)\n",number1);
        } else
        {
            printf("\n***CALCULADORA***\n\n1.Ingresar 1er operando (A=%.2f) \n"
                 "2.Ingresar 2do operando (B=%.2f)\n",number1,number2);
        }

        answer = menu("3.Calcular la SUMA (A+B)\n4.Calcular la RESTA (A-B)\n5.Calcular la DIVISION (A/B)\n"
                 "6.Calcular la MULTIPLICACION (A*B)\n7.Calcular el FACTORIAL (A!)\n"
                 "8.Calcular TODAS LAS OPERACIONES\n9.SALIR\n");

        switch(answer)
        {
            case 1:
                number1 = getFloat('A');
                system("cls");
                flag1=1;
                i=0;
                break;

            case 2:
                number2 = getFloat('B');
                system("cls");
                flag2=1;
                i=0;
                break;

            case 3:
                system("cls");
                printf("\nRESULTADO ---> A + B = %.2f\n\n",sum(number1,number2));
                system("pause");
                number1=0;
                number2=0;
                flag1=0;
                flag2=0;
                i=0;
                break;

            case 4:
                system("cls");
                printf("\nRESULTADO ---> A - B = %.2f\n\n",substract(number1,number2));
                system("pause");
                number1=0;
                number2=0;
                flag1=0;
                flag2=0;
                i=0;
                break;

            case 5:
                system("cls");
                if (validateZero(number2)==0)
                {
                    printf("\nERROR MATEMATICO ---> Operando B = 0\n\n");
                    system("pause");
                } else
                {
                    printf("\nRESULTADO ---> A / B = %.2f\n\n",division(number1,number2));
                    system("pause");
                }
                number1=0;
                number2=0;
                flag1=0;
                flag2=0;
                i=0;
                break;

            case 6:
                system("cls");
                printf("\nRESULTADO ---> A * B = %.2f\n\n",times(number1,number2));
                system("pause");
                number1=0;
                number2=0;
                flag1=0;
                flag2=0;
                i=0;
                break;

            case 7:
                system("cls");
                number1=(long)number1;
                if (validateNeg(number1)==0)
                {
                    printf("\nERROR MATEMATICO ---> Operando A es Negativo\n\n");
                    number1=0;
                    number2=0;
                    flag1=0;
                    flag2=0;
                } else
                {
                    printf("\nRESULTADO ---> A! = %ld\n\n",factorial(number1));
                }
                system("pause");
                number1=0;
                number2=0;
                flag1=0;
                flag2=0;
                i=0;
                break;

            case 8:
                system("cls");
                printf("RESULTADOS:\n");
                printf("3. A + B = %.2f\n",sum(number1,number2));
                printf("4. A - B = %.2f\n",substract(number1,number2));
                if (validateZero(number2)==0)
                {
                    printf("5. ERROR MATEMATICO ---> Operando B = 0\n");
                } else
                {
                    printf("5. A / B = %.2f\n",division(number1,number2));
                }
                printf("6. A * B = %.2f\n",times(number1,number2));
                number1=(long)number1;
                if (validateNeg(number1)==0)
                {
                    printf("7. ERROR MATEMATICO ---> Operando A es Negativo\n\n");
                } else
                {
                    printf("7. A! = %ld\n\n",factorial(number1));
                }
                system("pause");
                number1=0;
                number2=0;
                flag1=0;
                flag2=0;
                i=0;
                break;

            case 9:
                break;

            default:
                i++;
                if (i<ATTEMPTS)
                {
                    printf("Opci%cn inexistente. Intento %d/%d\n\n",162,i,ATTEMPTS);
                }
                else
                {
                    printf("\nOpci%cn inexistente. El programa se cerrar%c\n\n",162,160);
                    answer=9;
                }
                system("pause");
                break;
        }

    } while(answer != 9);

    system("cls");
    printf("\n\n***HASTA LUEGO***\n\n");

    return 0;
}

