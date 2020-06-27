#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "LinkedList.h"
#include "Controller.h"
#include "validaciones.h"
int menu();

int main()
{
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaOrdenada = ll_newLinkedList();

    int option = 0;
    int continuar = 1;
    do
    {
        option = menu();
        switch(option)
        {
        case 1:
            controller_loadFromText("datos.csv",lista);
            break;
        case 2:

            break;
        case 3:
            controller_addEmployee(lista);
            break;
        case 4:
            controller_editEmployee(lista);
            break;
        case 5:
            controller_removeEmployee(lista);
            break;
        case 6:
            controller_ListEmployee(lista);
            break;
        case 7:
            controller_sortEmployee(listaOrdenada,lista);
            break;
        case 8:
            if(ll_containsAll(listaOrdenada,lista))
            {
            controller_ListEmployee(listaOrdenada);
            }
            else
            {
                printf("La lista ordenada no esta actualizada con todos los elementos, vuelva a ordenar\n");
            }
            break;
        case 9:
            controller_listarMejoresPagos(lista,employee_ordenaPorSueldo);
            break;
        case 10:
            controller_reiniciarDatos(lista);
            break;
        case 11:
            ll_deleteLinkedList(lista);
            ll_deleteLinkedList(listaOrdenada);
            break;
        case 12:
            controller_saveAsText("datos.csv",lista);
            break;
        case 13:
            ll_deleteLinkedList(lista);
            ll_deleteLinkedList(listaOrdenada);
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











    return 0;
}

int menu()
{
    system("cls");
    int retorno = 0;

    printf("1.Cargar los datos de los empleados desde el archivo data.csv  \n");
    printf("3.Alta de empleado  \n");
    printf("4.Modificar datos de empleado  \n");
    printf("5.Baja de empleado \n");
    printf("6.Listar empleados  \n");
    printf("7.Ordenar empleados  \n");
    printf("8.Listar empleados ordenados \n");
    printf("9.Listar los 5 empleados mejores pagos\n");
    printf("10.Reinciar todos los datos de los empleados de la lista\n");
    printf("11.Eliminar datos de memoria dinamica\n");
    printf("12.Guardar los datos de los empleados en el archivo data.csv\n");
    printf("13.Salir   \n");

    fflush(stdin);

    utn_getNumero(&retorno,"Ingrese un numero del 1 al 19: ","Error. Numero no valido \n",1,13,5);


    return retorno;






}
