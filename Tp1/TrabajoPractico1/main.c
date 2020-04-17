#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main()
{

    int continuar = 1;
    int opcion;
    int primerOperando = 0;
    int segundoOperando = 0;
    int usadoPrimero = 0;
    int usadoSegundo = 0;
    int calculosRealizados = 0;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    long long int factorialA;
    long long int factorialB;
    int dividioCero = 0;


    mostrarMenu(primerOperando,segundoOperando,usadoPrimero,usadoSegundo);

    do
    {
        scanf("%d",&opcion);
        switch(opcion)
        {

        //Cambiar el valor del operando A
        case 1:
            system("cls");
            printf("Ingrese el primer operando: ");
            scanf("%d",&primerOperando);
            usadoPrimero = 1;

            //verifico que se hayan usado ambas variables antes de pasarselas a la funcion mostrarMenu()
            if(usadoSegundo == 0)
            {
                mostrarMenu(primerOperando,0,usadoPrimero,usadoSegundo); // pongo 0 porque la funcion mostrarMenu() necesita un valor en ese espacio.
            }
            else
            {
                mostrarMenu(primerOperando, segundoOperando, usadoPrimero, usadoSegundo); // si se usaron todas las variables es posible pasarlas a la funcion mostrarMenu
            }
            break;

        //Cambiar el valor del operando B
        case 2:
            system("cls");
            printf("Ingrese el segundo operando: ");
            scanf("%d",&segundoOperando);
            usadoSegundo = 1;

            //verifico que se hayan usado ambas variables antes de pasarselas a la funcion mostrarMenu()
            if(usadoPrimero == 0)
            {
                mostrarMenu(0,segundoOperando,usadoPrimero,usadoSegundo); // pongo 0 porque la funcion mostrarMenu() necesita un valor en ese espacio.
            }
            else
            {
                mostrarMenu(primerOperando, segundoOperando, usadoPrimero, usadoSegundo); // si se usaron todas las variables es posible pasarlas a la funcion mostrarMenu
            }
            break;

        //Realizar todas las operaciones posibles
        case 3:
            //verifico que esten ambos operandos ingresados
            if(usadoPrimero == 0 || usadoSegundo == 0)
            {
                printf("Antes de poder realizar calculos se necesita que se ingresen los operandos\n");
            }
            else
            {

                //si estan ingresados realizo los calculos
                suma = sumar(primerOperando, segundoOperando);
                resta = restar(primerOperando,segundoOperando);
                multiplicacion = multiplicar(primerOperando, segundoOperando);

                // verifico que no se este dividiendo por cero
                if(segundoOperando == 0)
                {
                    dividioCero = 1;
                }
                else
                {
                    division = dividir(primerOperando,segundoOperando);
                }
                factorialA = factorial(primerOperando);
                factorialB = factorial(segundoOperando);
            }
            calculosRealizados =  1;
            printf("Se realizaron las operaciones\n");
            break;

        //Mostrar los resultados de las operaciones
        case 4:
            //verifico que esten ambos operandos ingresados
            if(usadoPrimero == 0 || usadoSegundo == 0)
            {
                printf("Antes de poder realizar calculos se necesita que se ingresen los operandos\n");
                break;
            }
            if(calculosRealizados== 0)
            {
                printf("Antes de mostrar los resultados se tienen que realizar los calculos\n");
                break;
            }
            else
            {
                printf("El resultado de %d + %d es: %d \n", primerOperando, segundoOperando, suma);
                printf("El resultado de %d - %d es: %d\n", primerOperando, segundoOperando, resta);

                //verifico que no se divida por cero
                if(dividioCero == 1)
                {
                    printf("No es posible dividir por cero\n");
                }
                else
                {
                    printf("El resultado de %d / %d es: %.2f\n", primerOperando, segundoOperando, division);
                }
                printf("El resultado de %d * %d es: %d\n", primerOperando, segundoOperando,multiplicacion);
                if (primerOperando >20)
                {
                    printf("No se puede factorear con un numero mayor a 20, por favor vuelva a ingresar el dato 1\n");
                }
                else
                {
                    printf("El factorial de %d es: %I64d\n", primerOperando, factorialA); // pensaba usar %lld para mostrar long long int pero marca warnings, lo reemplace por %I64d al ser mas compatible
                }
                if (segundoOperando>20)
                {
                    printf("No se puede factorear un numero mayor a 20, por favor vuelva a ingresar el dato 2\n");
                }
                else
                {
                    printf("El factorial de %d es %I64d\n", segundoOperando, factorialB);
                }
                break;
            }

            break;

        //Salir del programa
        case 5:
            continuar = 0;
            break;

        //Valores en el menu fuera de los indicados
        default:
            printf("El valor ingresado no se encuentra dentro de las opciones\n");
            break;
        }
    }
    while(continuar);

    return 0;
}





