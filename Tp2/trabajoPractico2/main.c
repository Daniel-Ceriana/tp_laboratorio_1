#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayEmployees.h"
#include "sectores.h"

#define CANTSECTORES 5 // cantidad de sectores


int menu();

int main()
{
    int cantEmpleados = 1000; // Cantidad maxima de empleados---- Verificar limites con esta variable

    Employee empleados[cantEmpleados];
    eSector sectores[] = { {1,"Logistica"},{2,"Ventas"},{3,"Sistemas"},{4,"RRHH"},{5,"Compras"} };






    int continuar =1;
    int opcion;

    //Inicializar empleados
    if( initEmployees(empleados, cantEmpleados) == -1)
    {
        printf("Hubo un error al inicializar los empleados, vuelva a intentar");
    }



    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            if(crearEmployee(empleados,cantEmpleados,sectores,CANTSECTORES)==0)
            {
                printf("\nEmpleado cargado\n");
            }
            else
            {
                printf("\nHa ocurrido un error al intentar cargar empleado\n");
            }
            break;
        case 2:
            modificarEmpleado(empleados,cantEmpleados,sectores,CANTSECTORES);
            break;
        case 3:
            bajaEmpleado(empleados,cantEmpleados,sectores,CANTSECTORES);
            break;
        case 4:
            informar(empleados,cantEmpleados, sectores, CANTSECTORES);
            break;
        case 5:
            continuar = 0;
            break;

        default:
            printf("\nHa ocurrido un error, vuelva a intentarlo\n");
            break;
        }
        system("pause");


    }
    while(continuar);



    return 0;
}



int menu()
{

    int opcion;
    system("cls");
    printf("*********Menu opciones*********\n\n");
    printf("1.Alta empleado\n");
    printf("2.Modificar empleado\n");
    printf("3.Baja empleado\n");
    printf("4.Informar\n");
    printf("5.Salir\n");
    utn_getNumero(&opcion,"Ingrese un valor del 1 al 5: ","Error, se ha ingresado un valor incorrecto, vuelva a intentar\n",1,5,5);



    return opcion;
}

