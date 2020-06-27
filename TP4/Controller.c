#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "empleados.h"
#include "parser.h"
#include "validaciones.h"
#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"r");
    int retorno = 1;

    if(f== NULL)//si no se pudo abrir por alguna razon cierro el programa
    {
        printf("Problemas al abrir el archivo\n\n");
        retorno = 0;
    }
    else
    {
    parser_EmployeeFromText(f, pArrayListEmployee); // cargo todos los empleados en la memoria

    fclose(f);
    }


    return retorno;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    int auxNum;
    int auxError = -1;
    int id;
    int sueldo;

    char buffer[4][25];

    eEmpleado* auxEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");

        printf("***********Alta Empleado***********\n\n");

        if(!ll_isEmpty(pArrayListEmployee))
        {
            int tam = ll_len(pArrayListEmployee);
            int idMaximo = 0;
            int idActual;
            for(int i = 0; i<tam; i++){
                auxEmpleado = ll_get(pArrayListEmployee,i);
                employee_getId(auxEmpleado,&idActual);
                if(idMaximo< idActual){
                    idMaximo=idActual;
                }
            }
            id = idMaximo + 1;

            printf("Ingrese un nombre \n");
            myGets(buffer[1],20);

            printf("Ingrese un apellido \n");
            myGets(buffer[2],20);

            do
            {
                auxError = utn_getNumero(&auxNum,"Ingrese un sueldo: ","Error, vuelva a intentarlo",0,5000000,5);
            }
            while(auxError != 0);
            sueldo = auxNum;

            itoa(id,buffer[0],10);
            itoa(sueldo,buffer[3],10);
            auxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(ll_contains(pArrayListEmployee,auxEmpleado))
            {
                printf("Esta lista ya contiene a un empleado con las mismas caracteristicas, no es posible ingresar otro\n");
            }
            else
            {
                ll_push(pArrayListEmployee,ll_len(pArrayListEmployee),auxEmpleado);
            }

        }
        else
        {
            printf("Antes de poder agregar empleados tiene que cargar algun archivo de datos\n");
        }
    }

    return retorno;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    eEmpleado* auxEmpleado;
    int retorno = -1;
    int auxNum;
    int error;
    int indice;
    system("cls");
    printf("***********Modificar Empleado***********\n\n");

    controller_ListEmployee(pArrayListEmployee);

    do
    {
        error = utn_getNumero(&auxNum,"Ingrese el id del empleado a modificar: ","Error. Id invalido\n",0,50000,5);
    }
    while(error!= 0);

    indice = controller_buscarEmpleadoPorId(auxNum,pArrayListEmployee); //consigo el indice
    if(indice != -1)
    {
        auxEmpleado = (eEmpleado*)ll_get(pArrayListEmployee,indice);
        do
        {
            error = utn_getNumero(&auxNum,"El empleado mostrado es el correcto? 1 si verdadero 0 si falso","Error.Vuelva a intentarlo",0,1,5);
        }
        while(error != 0);

        if(auxNum)
        {
            menuModEmpleado(auxEmpleado,pArrayListEmployee);
            retorno = 0;
        }
        else
        {
            printf("Operacion cancelada\n");
            retorno = -1;
        }
    }
     else
    {
        printf("Operacion cancelada, el id no es valido\n");
        retorno = -1;
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si funciono -1 si error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    eEmpleado* auxEmpleado;
    int retorno = -1;
    int auxNum;
    int error;
    int indice;
    system("cls");
    printf("***********Eliminar Empleado***********\n\n");

    controller_ListEmployee(pArrayListEmployee);

    do
    {
        error = utn_getNumero(&auxNum,"Ingrese el id del empleado a eliminar: ","Error. Id invalido\n",0,50000,5);
    }
    while(error!= 0);

    indice = controller_buscarEmpleadoPorId(auxNum,pArrayListEmployee); //consigo el indice
    if(indice != -1)
    {
        auxEmpleado = (eEmpleado*)ll_get(pArrayListEmployee,indice);
        do
        {
            error = utn_getNumero(&auxNum,"El empleado mostrado es el correcto? 1 si verdadero 0 si falso: ","Error.Vuelva a intentarlo",0,1,5);
        }
        while(error != 0);

        if(error == 0)
        {

            employee_delete(auxEmpleado); //elimina el puntero a la direccion de memoria
            ll_pop(pArrayListEmployee,indice);
            ll_remove(pArrayListEmployee,indice); // elimina el empleado de la linked list
            retorno = 0;
        }
    }
    else
    {
        printf("Operacion cancelada, el id no es valido\n");
        retorno = -1;
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    //validar que no sea null
    eEmpleado* auxEmpleado;

    int auxId;
    char nombre[30];
    char apellido[30];
    int auxSueldo;

    int tam = ll_len(pArrayListEmployee);
    int flag = 0;

    printf("ID   Nombre       Apellido        Sueldo\n");

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            flag = 1;
            auxEmpleado = (eEmpleado*) ll_get(pArrayListEmployee,i);


            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,nombre);
            employee_getApellido(auxEmpleado,apellido);
            employee_getSueldo(auxEmpleado,&auxSueldo);


            printf(" %-4d %-15s %-15s %13d \n",auxId,nombre,apellido,auxSueldo);

        }

        if(!flag)
        {
            printf("Error no hay empleados en la memoria\n");
        }

    }
    else
    {
        printf("\nError al cargar la memoria de los empleados\n");
    }



    return 1;
}


/** \brief menu de opciones para controller sortEmployee
 *
 * \return retorna la opcion elegida
 *
 */

int controller_sortEmployeeMenu(){
int retorno;
system("cls");
printf("******************Menu ordenar******************\n\n");

printf("1.Ordenar por id \n");
printf("2.Ordenar por nombre \n");
printf("3.Ordenar por Apellido \n");
printf("4.Ordenar por sueldo \n");
printf("5.Salir \n");

utn_getNumero(&retorno,"Ingrese un numero del 1 al 5: ","Error. Vuelva a intentarlo",1,5,5);
return retorno;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee, LinkedList* lista)
{
    int opcion;
    if(pArrayListEmployee!=NULL && lista != NULL && ll_isEmpty(lista) != 0){
        pArrayListEmployee = ll_clone(lista);
        if(pArrayListEmployee!= NULL)
        {
            opcion = controller_sortEmployeeMenu();
            switch(opcion)
            {
            case 1:
                printf("Ordenando... esta operacion puede tardar unos segundos\n");
                ll_sort(pArrayListEmployee,employee_ordenaPorId,1);
                break;
            case 2:
                printf("Ordenando... esta operacion puede tardar unos segundos\n");
                ll_sort(pArrayListEmployee,employee_ordenaPorNombre,1);
                break;
            case 3:
                printf("Ordenando... esta operacion puede tardar unos segundos\n");
                ll_sort(pArrayListEmployee,employee_ordenaPorApellido,1);
                break;
            case 4:
                printf("Ordenando... esta operacion puede tardar unos segundos\n");
                ll_sort(pArrayListEmployee,employee_ordenaPorSueldo,1);
                break;
            default:
                printf("Llego al maximo de reintentos. Operacion cancelada\n");
                break;
            }

        }
        else
        {
            printf("Error. No hay personas cargadas en la memoria\n");
        }
    }





    return 1;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int tam;

    int id;
    char nombre[20];
    char apellido[20];
    int sueldo;

    int auxNum;
    int error;

    eEmpleado* auxEmpleado;

    printf("\nSeguro/a que quiere sobreescribir los datos?\n");
    do{
    error = utn_getNumero(&auxNum,"Ingrese 1 si es verdadero o 0 si es falso: ", "Error, numero ingresado Incorrecto\n",0,1,5);
    }while(error != 0);

    if(auxNum == 1){

        if(path!=NULL && pArrayListEmployee!=NULL)
        {
            FILE* f = fopen(path,"w");
            tam = ll_len(pArrayListEmployee); // consigo el tamanio de la lista
            fprintf(f,"id,nombre,apellido,sueldo\n");//primer linea del csv

            for(int i = 1; i<tam; i++) // desde 1 para no guardar la primer linea
            {
                auxEmpleado = ll_get(pArrayListEmployee,i);
                employee_getId(auxEmpleado,&id);
                employee_getNombre(auxEmpleado,nombre);
                employee_getApellido(auxEmpleado,apellido);
                employee_getSueldo(auxEmpleado,&sueldo);
                fprintf(f,"%d,%s,%s,%d\n",id,nombre,apellido,sueldo);
                retorno = 1;
            }
            fclose(f);
        }
        else
        {
            retorno = 0;
        }
    }
    else
    {
        printf("Se ha cancelado la operacion\n");
    }

    return retorno;
}


/** \brief busca un empleado con el id
 *
 * \param idBuscado int
 * \param pArrayListEmployee LinkedList*
 * \return retorna indice
 *
 */

int controller_buscarEmpleadoPorId(int idBuscado,LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    eEmpleado* auxEmpleado;

    int auxId;
    char nombre[30];
    char apellido[30];
    int auxSueldo;

    int tam = ll_len(pArrayListEmployee);
    int flag = 0;

    printf("ID   Nombre       Horas Trabajadas Sueldo\n");

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            flag = 1;
            auxEmpleado = (eEmpleado*) ll_get(pArrayListEmployee,i);

            employee_getId(auxEmpleado,&auxId);
            if( auxId == idBuscado)
            {
                employee_getNombre(auxEmpleado,nombre);
                employee_getSueldo(auxEmpleado,&auxSueldo);
                employee_getApellido(auxEmpleado,apellido);
                printf(" %-4d %-15s %-15s %13d \n",auxId,nombre,apellido,auxSueldo);
                retorno = ll_indexOf(pArrayListEmployee,auxEmpleado);
                break;
            }
        }

        if(!flag)
        {
            printf("Error no hay empleados en la memoria\n");
        }

    }
    else
    {
        printf("\nError al cargar la memoria de los empleados\n");
    }

    return retorno;

}
/** \brief modifica al empleado segun lo solicidato
 *
 * \param  this eEmpleado*
 * \param  pArrayListEmployee LinkedList*
 * \return retorna 0 si todo ok o -1 si error
 *
 */

int menuModEmpleado(eEmpleado* this,LinkedList* pArrayListEmployee)
{

    int error;
    int retorno = -1;
    int opcion;
    int auxNum;
    char buffer[20];

    opcion = menuModEmpleadoSeleccion();
    switch(opcion)
    {
    case 1:
        printf("Ingrese un nombre \n");
        myGets(buffer,20);
        employee_setNombre(this,buffer);
        retorno = 0;
        break;
    case 2:
        printf("Ingrese un apellido \n");
        myGets(buffer,20);
        employee_setApellido(this,buffer);
        retorno = 0;
        break;
    case 3:
        do
        {
            error = utn_getNumero(&auxNum,"Ingrese el sueldo","Error.Vuelva a intentarlo",0,500000,5);
        }
        while(error != 0);
        employee_setSueldo(this,auxNum);
        retorno = 0;
        break;
    }



    return retorno;
}

/** \brief muestra un menu de seleccion
 * \return retorna un valor del 1 al 4
 *
 */

int menuModEmpleadoSeleccion()
{

    int retorno = 0;

    printf("1.Nombre \n");
    printf("2.Apellido \n");
    printf("3.Sueldo \n");
    printf("4.Salir de esta pantalla\n");


    utn_getNumero(&retorno,"Ingrese un numero del 1 al 4: ","Error. Numero ingresado no valido\n",1,4,5);



    return retorno;
}
/** \brief recibe una lista completa y muestra los
 *
 * \param pArrayListEmployee LinkedList* lista con todos los datos
 * \return retorna -1 si hubo algun error, 0 si todoOk
 *
 */

int controller_listarMejoresPagos(LinkedList* pArrayListEmployee,int (*pFunc)(void* ,void*))
{
    int retorno = -1;
    LinkedList* listaOrdenada = ll_newLinkedList();
    LinkedList* listaReducida = ll_newLinkedList();
    if(pArrayListEmployee!=NULL)
    {
        listaOrdenada = ll_clone(pArrayListEmployee);
        ll_sort(listaOrdenada,pFunc,0);
        listaReducida = ll_subList(listaOrdenada,0,5);

        controller_ListEmployee(listaReducida);

        ll_deleteLinkedList(listaOrdenada);
        ll_deleteLinkedList(listaReducida);
        retorno = 0;
    }
    return retorno;
}
/** \brief pone los campos del la lista de empleados en 0 o en " "
 *
 * \param pArrayListEmployee LinkedList*
 * \return 0 si todo ok, -1 si error
 *
 */

int controller_reiniciarDatos(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int cant;
    //eEmpleado* auxEmpleado = employee_new();
    eEmpleado* auxAReiniciar;


    if(pArrayListEmployee != NULL)
    {
        cant = ll_len(pArrayListEmployee);
        for(int i = 0; i<cant;i++)
        {
            auxAReiniciar = ll_get(pArrayListEmployee,i);
            strcpy(auxAReiniciar->nombre," ");
            strcpy(auxAReiniciar->apellido," ");
            auxAReiniciar->sueldo = 0;
            retorno = ll_set(pArrayListEmployee,i,auxAReiniciar);
        }

        if(retorno != 0)
        {
            printf("Hubo un error al reiniciar los datos\n");
        }

    }

    return retorno;
}

