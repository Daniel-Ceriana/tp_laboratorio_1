#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
    int guardarTxt;
    int option = 0;
    int continuar = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        option = menu();
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            guardarTxt=controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.bin",listaEmpleados);
            break;
        case 10:
            if(guardarTxt){
                ll_deleteLinkedList(listaEmpleados);
            }
            continuar = 0;
            break;
        default:
            printf("Error. Opcion inexistente vuelva a intentarlo\n");
            break;
        }
        system("pause");
    }
    while(continuar);

    return 0;
}

int menu()
{
    system("cls");
    int retorno = 0;

    printf("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)  \n");
    printf("2.Cargar los datos de los empleados desde el archivo data.csv (modo binario)  \n");
    printf("3.Alta de empleado  \n");
    printf("4.Modificar datos de empleado  \n");
    printf("5.Baja de empleado \n");
    printf("6.Listar empleados  \n");
    printf("7.Ordenar empleados  \n");
    printf("8.Guardar los datos de los empleados en el archivo data.csv (modo texto) \n");
    printf("9.Guardar los datos de los empleados en el archivo data.csv (modo binario)  \n");
    printf("10.Salir   \n");

    fflush(stdin);
   // scanf("%d",&retorno);

    utn_getNumero(&retorno,"Ingrese un numero del 1 al 10: ","Error. Numero no valido \n",1,10,5);


    return retorno;
}
