#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
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

    parser_EmployeeFromText(f, pArrayListEmployee); // cargo todos los empleados en la memoria

    fclose(f);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"rb"); // preparo al archivo bin para leerlo
    int retorno = 1;

    if(f==NULL) //si no se pudo abrir por alguna razon cierro el programa
    {
        printf("Problemas al abrir el archivo binario");
        retorno = 0;
    }

    parser_EmployeeFromBinary(f,pArrayListEmployee); //cargo los empleados a la memoria desde archivo binario


    fclose(f);
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
    int horasTrabajadas;
    int sueldo;

    char buffer[4][25];

    Employee* auxEmpleado;


    system("cls");

    printf("***********Alta Empleado***********\n\n");

    if(ll_len(pArrayListEmployee)>1)
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
        //realloc(pArrayListEmployee,ll_len(pArrayListEmployee)+1);
        id = idMaximo + 1;

        printf("Ingrese un nombre \n");
        myGets(buffer[1],20);

        do
        {
            auxError = utn_getNumero(&auxNum,"Ingrese las horas trabajadas: ","Error, vuelva a intentarlo",0,1000,5);
        }
        while(auxError != 0);
        horasTrabajadas = auxNum;

        do
        {
            auxError = utn_getNumero(&auxNum,"Ingrese un sueldo: ","Error, vuelva a intentarlo",0,5000000,5);
        }
        while(auxError != 0);
        sueldo = auxNum;

        itoa(id,buffer[0],10);
        itoa(horasTrabajadas,buffer[2],10);
        itoa(sueldo,buffer[3],10);
        //realloc(pArrayListEmployee,ll_len(pArrayListEmployee)+sizeof(LinkedList));
        auxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
        ll_add(pArrayListEmployee,auxEmpleado);
    }
    else
    {
        printf("Antes de poder agregar empleados tiene que cargar algun archivo de datos\n");
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
    Employee* auxEmpleado;

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

    /*ll_indexOf(pArrayListEmployee,);

    ll_get();*/
    indice = controller_buscarEmpleadoPorId(auxNum,pArrayListEmployee); //consigo el indice

    auxEmpleado = (Employee*)ll_get(pArrayListEmployee,indice);
    do
    {
        error = utn_getNumero(&auxNum,"El empleado mostrado es el correcto? 1 si verdadero 0 si falso","Error.Vuelva a intentarlo",0,1,5);
    }
    while(error != 0);

    if(auxNum)
    {
        menuModEmpleado(auxEmpleado,pArrayListEmployee);
    }
    else
    {
        printf("Operacion cancelada\n");
    }





    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    Employee* auxEmpleado;

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

    auxEmpleado = (Employee*)ll_get(pArrayListEmployee,indice);
    do
    {
        error = utn_getNumero(&auxNum,"El empleado mostrado es el correcto? 1 si verdadero 0 si falso: ","Error.Vuelva a intentarlo",0,1,5);
    }
    while(error != 0);

    if(error == 0)
    {

        employee_delete(auxEmpleado); //elimina el puntero a la direccion de memoria
        ll_remove(pArrayListEmployee,indice); // elimina el empleado de la linked list

    }




    return 1;
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
    Employee* auxEmpleado;

    int auxId;
    char nombre[30];
    int auxSueldo;
    int auxHorasTrabajadas;

    int tam = ll_len(pArrayListEmployee);
    int flag = 0;

    printf("ID   Nombre       Horas Trabajadas Sueldo\n");

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            flag = 1;
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);


            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,nombre);
            employee_getSueldo(auxEmpleado,&auxSueldo);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);

            printf(" %-4d %-15s %-4d %13d \n",auxId,nombre,auxHorasTrabajadas,auxSueldo);

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
printf("3.Ordenar por horas trabajadas \n");
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
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0){

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
            ll_sort(pArrayListEmployee,employee_ordenaPorHorasTrabajadas,1);
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
    int horasTrabajadas;
    int sueldo;

    int auxNum;
    int error;

    Employee* auxEmpleado;

    printf("\nSeguro/a que quiere sobreescribir los datos?\n");
    do{
    error = utn_getNumero(&auxNum,"Ingrese 1 si es verdadero o 0 si es falso: ", "Error, numero ingresado Incorrecto\n",0,1,5);
    }while(error != 0);

    if(auxNum == 1){

        if(path!=NULL && pArrayListEmployee!=NULL)
        {
            FILE* f = fopen(path,"w");
            tam = ll_len(pArrayListEmployee); // consigo el tamanio de la lista
            fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");//primer linea del csv

            for(int i = 1; i<tam; i++) // desde 1 para no guardar la primer linea
            {
                auxEmpleado = ll_get(pArrayListEmployee,i);
                employee_getId(auxEmpleado,&id);
                employee_getNombre(auxEmpleado,nombre);
                employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas);
                employee_getSueldo(auxEmpleado,&sueldo);
                fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    if(path!=NULL)
    {
        FILE* f= fopen(path,"wb");

        Employee* auxEmployee;

        if(f!= NULL && pArrayListEmployee!=NULL)
        {

            int tam = ll_len(pArrayListEmployee);

            for(int i = 0; i< tam; i++)
            {
                auxEmployee = (Employee*)ll_get(pArrayListEmployee,i); // consigo al empleado a guardar


                if(auxEmployee!=NULL)
                {
                    employee_getId(auxEmployee,&id);
                    employee_getNombre(auxEmployee,nombre);
                    employee_getHorasTrabajadas(auxEmployee,&horasTrabajadas);
                    employee_getSueldo(auxEmployee,&sueldo);


                    fwrite(&id,sizeof(int),1,f);
                    fwrite(nombre,strlen(nombre),1,f);
                    fwrite(&horasTrabajadas,sizeof(int),1,f);
                    fwrite(&sueldo,sizeof(int),1,f);
                }
            }

        }
        else
        {
            printf("ERROR: no se pudo abrir el archivo para guardar los datos \n");
            retorno = 0;
        }

        fclose(f);
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
    Employee* auxEmpleado;

    int auxId;
    char nombre[30];
    int auxSueldo;
    int auxHorasTrabajadas;

    int tam = ll_len(pArrayListEmployee);
    int flag = 0;

    printf("ID   Nombre       Horas Trabajadas Sueldo\n");

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            flag = 1;
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);

            employee_getId(auxEmpleado,&auxId);
            if( auxId == idBuscado)
            {
                employee_getNombre(auxEmpleado,nombre);
                employee_getSueldo(auxEmpleado,&auxSueldo);
                employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
                printf(" %-4d %-15s %-4d %13d \n",auxId,nombre,auxHorasTrabajadas,auxSueldo);
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

int menuModEmpleado(Employee* this,LinkedList* pArrayListEmployee)
{

    int error;
    int retorno = 0;
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
        break;
    case 2:
        do
        {
            error = utn_getNumero(&auxNum,"Ingrese las horas trabajadas","Error.Vuelva a intentarlo",0,10000,5);
        }
        while(error != 0);
        employee_setHorasTrabajadas(this,auxNum);
        break;
    case 3:
        do
        {
            error = utn_getNumero(&auxNum,"Ingrese el sueldo","Error.Vuelva a intentarlo",0,500000,5);
        }
        while(error != 0);
        employee_setSueldo(this,auxNum);
        break;
    }



    return retorno;
}


int menuModEmpleadoSeleccion()
{

    int retorno = 0;

    printf("1.Nombre \n");
    printf("2.Horas Trabajadas \n");
    printf("3.Sueldo \n");
    printf("4.Salir de esta pantalla\n");


    utn_getNumero(&retorno,"Ingrese un numero del 1 al 4: ","Error. Numero ingresado no valido\n",1,4,5);



    return retorno;
}

