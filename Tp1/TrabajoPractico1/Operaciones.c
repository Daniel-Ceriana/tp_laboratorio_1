#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"



int sumar(int a, int b)
{

    int resultado;
    resultado = a + b;

    return resultado;
}
int restar(int a, int b)
{

    int resultado;
    resultado= a-b;

    return resultado;
}
int multiplicar(int a, int b)
{

    int resultado;
    resultado = a*b;

    return resultado;
}
float dividir(int a, int b)
{

    float resultado;

    resultado = (float)a / b;

    return resultado;
}
long long int factorial(long long int a)
{

    long long int fact;
    if(a > 20)
    {
        fact = 0;
    }
    if(a< 0)
    {
        fact = 0;
    }
    else
    {
        if (a == 1 || a == 0)
        {
            fact = 1;
        }
        else
        {
            fact = a* factorial(a-1);
        }
    }

    return fact;
}
void mostrarMenu(int a, int b, int usadoA, int usadoB)
{

    system("cls");
    if(usadoA == 0 && usadoB == 0)
    {
        printf("1-Ingresar el primer operando A = X\n");
        printf("2-Ingresar el segundo operando B = Y\n");
    }
    else if( usadoA && usadoB == 0)
    {
        printf("1-Ingresar el primer operando A = %d\n", a);
        printf("2-Ingresar el segundo operando B = Y\n");
    }
    else if(usadoA == 0 && usadoB)
    {
        printf("1-Ingresar el primer operando A = X\n");
        printf("2-Ingresar el segundo operando B = %d\n", b);
    }
    else
    {
        printf("1-Ingresar el primer operando A = %d\n", a);
        printf("2-Ingresar el segundo operando B = %d\n", b);
    }
    printf("3-Calcular todas las operaciones\n");
    printf("4-Informar resultados\n");
    printf("5-Salir\n");

}
