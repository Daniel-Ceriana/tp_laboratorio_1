#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayEmployees.h"
#include "sectores.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector)
{
    int retorno= -1;
    int indiceSiguiente;
    if(list != NULL && len > 0)
    {

        indiceSiguiente = buscarLibre(list,len);

        if(indiceSiguiente < len)
        {
            list[indiceSiguiente].id = indiceSiguiente;
            strncpy(list[indiceSiguiente].name,name, 50);
            strncpy(list[indiceSiguiente].lastName,lastName,50);
            list[indiceSiguiente].salary = salary;
            list[indiceSiguiente].sector = sector;
            list[indiceSiguiente].isEmpty = 0;

            retorno = 0;

        }
    }



    return retorno;
}

/** \brief Pide los datos necesarios para crear un empleado
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return -1 si ocurrio algun error ( puntero null, longitud invalida o sin espacio en el programa) - 0 si esta todo correcto
 *
 */

int crearEmployee(Employee* list, int len, eSector* sectores, int tamSec)
{
    int retorno = -1;


    //Variables auxiliares-----
    char nombre[51];
    char apellido[51];
    int auxRetorno = -1; // utilizado para verificar que el ingreso de strings sea correcto y no desborde
    float sueldo;
    int sector;
    int id;

    //fin de variables auxiliares-----

    id = buscarLibre(list,len);

    if(id < len)
    {


        if(list != NULL && len > 0)  //verifico que el puntero ingresado no sea null ni de un tamanio incorrecto
        {

            system("cls");
            printf("Id del empleado a crear: %d\n", id); // indico al usuario el id del empleado que esta por agregar

            do
            {
                printf("Ingrese nombre del empleado\n");
                auxRetorno = myGets(nombre,50);
            }
            while(auxRetorno == -1||nombre[0]=='\0');

            do
            {
                printf("Ingrese apellido del empleado\n");
                auxRetorno = myGets(apellido,51);
            }
            while(auxRetorno == -1||apellido[0]=='\0');

            do
            {
                utn_getNumeroFlotante(&sueldo,"Ingrese el sueldo correspondiente al empleado: ", "Ha ocurrido un error. reintente \n",1,1000000,5);
            }
            while(sueldo<1|| sueldo >1000000 );

            mostrarSectores(sectores,tamSec);
            do
            {
                utn_getNumero(&sector,"Ingrese el sector al que pertenece el empleado: ","Ha ocurrido un error. Reintente \n",1,tamSec,5);// existe un maximo de 5 sectores
            }
            while(sector<1 || sector > tamSec);



            addEmployee(list,len,nombre,apellido,sueldo,sector);

            retorno = 0;
        }// verifica que el id ingresado pertenezca a un empleado cargado
    }
    else
    {
        printf("\nMaxima cantidad de empleados alcanzada\n");
        retorno = -1;
    }


    return retorno;
}





void mostrarEmpleado(Employee x,eSector* sectores, int tamSec)
{
    char nombreSector[20];
    cargarDescripcionSector(nombreSector,x.sector,sectores,tamSec);

    printf("%4d    %-15s %-15s %.2f               %s\n", x.id, x.name,x.lastName, x.salary, nombreSector);

}


/** \brief print the content of employees array *
* \param list Employee*
* \param length int *
 \return int (-1 if error) (0 if ok)
 */
int printEmployees(Employee* vec,int tam, eSector* sectores, int tamSec)
{
    int retorno = -1;
    int flag = 0;

    if(vec == NULL)
    {
        printf("\nError.\n");
    }
    else
    {
        printf("\n\n**************Lista de empleados**************\n\n");

        printf("ID      Nombre          Apellido          Sueldo               Sector\n\n");

        for(int i = 0; i <tam; i++)
        {
            if(vec[i].isEmpty == 0)  // si esta lleno
            {
                flag = 1;
                mostrarEmpleado(vec[i], sectores, tamSec);
                retorno = 0;
            }
        }
        if (flag == 0)
        {
            printf("No hay empleados que listar\n\n");
            retorno = -1;
        }
    }

    return retorno;
}





/** \brief Modifica el empleado seleccionado mediante su id
 *
 * \param empleado Employee*
 * \param len int .Tamanio de empleado
 * \param sectores eSector*
 * \param tamSec int .Tamanio de sectores
 * \return
 *
 */

int modificarEmpleado(Employee* empleado, int len, eSector* sectores, int tamSec)
{

    system("cls");
    int idAModificar;
    int obtuvoNumero = -1;
    int correcto = 0;
    int hayEmpleado;
    int campoAModificar;
    int indice;
    float salario;
    int sector;
    char mod;
    int auxRetorno = -1;

    for(int i = 0; i<len; i++) // verifico que haya empleados en el sistema
    {
        if(empleado[i].isEmpty== 0)
        {
            hayEmpleado = 1;
            break;
        }
        else
        {
            hayEmpleado = 0;
        }
    }

    if(hayEmpleado)
    {
        printEmployees(empleado,len,sectores,tamSec);

        do
        {
            obtuvoNumero = utn_getNumero(&idAModificar,"Indique el id del empleado a modificar: ","\nError. No se encuentra el empleado, verifique que exista en la base de datos\n",0,1000,5);
            indice = findEmployeeById(empleado,len,idAModificar);
            if(empleado[indice].isEmpty) // verifica que el id ingresado pertenezca a un empleado cargado
            {
                correcto = 0;
                printf("\nEl id ingresado no pertenece a ningun empleado cargado\n");
            }
            else
            {
                correcto = 1;
            }
        }
        while(obtuvoNumero == -1 || correcto == 0);

        system("cls");



        printf("**********Modificar empleado**********\n\n");
        printf("ID      Nombre          Apellido          Sueldo               Sector\n\n");
        mostrarEmpleado(empleado[indice],sectores,tamSec);

        printf("Confirma la modificacion?('s' para verificar) \n\n");
        fflush(stdin);
        scanf("%c", &mod);

        if(mod== 's'|| mod == 'S')
        {
            campoAModificar = menuMod(); //menu de opciones
            switch(campoAModificar)
            {
            case 1://nombre
                do{
                    printf("Ingrese el nuevo nombre del empleado");
                    auxRetorno = myGets(empleado[indice].name,20);
                }
                while(auxRetorno == -1||empleado[indice].name[0]=='\0');

                break;
            case 2://apellido
                do{
                printf("Ingrese el nuevo apellido del empleado");
                auxRetorno = myGets(empleado[indice].lastName,20);
                }
                while(auxRetorno == -1||empleado[indice].name[0]=='\0');
                break;
            case 3: //salario
                utn_getNumeroFlotante(&salario,"Ingrese el sueldo correspondiente al empleado: ", "Ha ocurrido un error. reintente \n",1,1000000,5);
                empleado[indice].salary = salario;
                break;
            case 4: //sector
                mostrarSectores(sectores,tamSec);
                utn_getNumero(&sector,"Ingrese el sector al que pertenece el empleado: ","Ha ocurrido un error. Reintente \n",1,tamSec,5);
                empleado[indice].sector = sector;
                break;
            default:
                printf("\nSe ha cancelado la operacion\n");
                break;

            }
        }
        else
        {
            printf("\nSe ha cancelado la operacion\n");
        }


    }
    else
    {
        printf("\nNo hay empleados ingresados en el sistema\n");
    }



    return -1;
}


int buscarLibre(Employee vec[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}




/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findEmployeeById( Employee vec[],int len,int id )
{
    int indice = -1;
    if(vec != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (vec[i].id == id && vec[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1) *
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok * */
int removeEmployee(Employee* list, int len, int id, eSector* sectores, int tamSec)
{

    int retorno = -1;


    system("cls");
    int indice;
    char baja;


    indice = findEmployeeById(list,len,id);

    printf("ID      Nombre          Apellido          Sueldo               Sector\n\n");
    mostrarEmpleado(list[indice],sectores,tamSec);


    printf("Confirma la baja?('s' para verificar) \n\n");
    fflush(stdin);
    scanf("%c", &baja);

    if(baja== 's'|| baja == 'S')
    {
        list[indice].isEmpty = 1;
        printf("\n\nSe le dio de baja al empleado\n\n");
    }
    else
    {
        printf("\nSe ha cancelado la operacion\n");
    }
    return retorno;
}




int bajaEmpleado(Employee* list, int len, eSector* sectores, int tamSec)
{

    int retorno = -1;
    int indiceABuscar;
    int encontrado;
    int hayEmpleado;

    if(list != NULL && len >0)
    {


        for(int i = 0; i<len; i++)
        {
            if(list[i].isEmpty== 0)
            {
                hayEmpleado = 1;
                break;
            }
            else
            {
                hayEmpleado = 0;
            }
        }


        if(hayEmpleado)
        {
            printEmployees(list,len,sectores,tamSec);
            do
            {
                utn_getNumero(&indiceABuscar,"Ingrese el indice del empleado: ","Error, vuelva a intentarlo",0,1000,5);
                encontrado = findEmployeeById(list,len,indiceABuscar);
                if(encontrado < 0)
                {
                    printf("\n\nEl empleado no existe\n\n");
                }
            }
            while(encontrado <0);
            removeEmployee(list,len,encontrado,sectores,tamSec);
        }
        else
        {
            printf("\n\nNo hay empleados en el sistema\n\n");
        }
    }
    else
    {
        retorno = -1;
    }



    return retorno;
}

int menuMod()
{
    int retorno =-1;

    printf("\n\n1.Nombre\n");
    printf("2.Apellido\n");
    printf("3.Salario\n");
    printf("4.Sector\n");
    printf("5.Salir\n");

    utn_getNumero(&retorno,"Ingrese un numero del 1 al 5: ","Error. se ha ingresado un numero invalido. Reintente\n\n",1,5,5);

    return retorno;
}




/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int retorno =-1;
    Employee auxEmpleado;

    if(list == NULL || len <= 0)
    {
        retorno = -1;
    }
    else
    {
        for(int i = 0; i<len-1; i++)
        {
            for(int j= i+1; j<len; j++)
            {
                if(list[i].isEmpty ==0 && list[j].isEmpty == 0)
                {
                    if(order)
                    {
                        if( strncmp(list[i].lastName,list[j].lastName,sizeof(auxEmpleado.lastName))> 0 )
                        {
                            auxEmpleado = list[i];
                            list[i] = list[j];
                            list[j] = auxEmpleado;
                        }
                        else if( strncmp(list[i].lastName,list[j].lastName,sizeof(auxEmpleado.lastName)) == 0 && list[i].sector > list[j].sector)
                        {
                            auxEmpleado = list[i];
                            list[i] = list[j];
                            list[j] = auxEmpleado;
                        }
                        retorno = 0;
                    }
                    else
                    {
                        if( strncmp(list[j].lastName,list[i].lastName,sizeof(auxEmpleado.lastName))> 0 )
                        {
                            auxEmpleado =list[i];
                            list[i] = list[j];
                            list[j] = auxEmpleado;
                        }
                        else if( strncmp(list[i].lastName,list[j].lastName,sizeof(auxEmpleado.lastName)) == 0 && list[i].sector < list[j].sector)
                        {
                            auxEmpleado = list[i];
                            list[i] = list[j];
                            list[j] = auxEmpleado;
                        }
                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}

int informar(Employee* list, int len, eSector* sectores, int tamSec)
{

    int retorno = -1;
    int opcion;
    float promedioSalarios;
    int totalSalarios;
    int contMayoresPromedio;
    int hayEmpleado;
    Employee tempList[len];




    if(list != NULL && len > 0){

        for(int i = 0; i<len; i++) // verifico que haya empleados en el sistema
        {
            if(list[i].isEmpty== 0)
            {
                hayEmpleado = 1;
                break;
            }
            else
            {
                hayEmpleado = 0;
            }
        }
                if(hayEmpleado){
                    for(int i = 0; i<len; i++){
                        tempList[i] = list[i];
                    }

                    opcion = menuInformar();

                    switch(opcion){
                        case 1:
                            sortEmployees(tempList,len,1);
                            printEmployees(tempList,len,sectores,tamSec);
                            break;
                        case 2:
                            promediarSalarios(list,len,&promedioSalarios,&totalSalarios,&contMayoresPromedio);
                            printf("\nEl total de salarios es: %d\n", totalSalarios);
                            printf("El promedio de salarios es: %.2f\n",promedioSalarios);
                            printf("La cantidad de empleados que superan al promedio en salarios es: %d\n",contMayoresPromedio);
                            break;
                        default:
                            printf("Ha ocurrido un error. Se ha cancelado la operacion\n");
                            break;

                    }
                }
                else
                {
                    printf("\nNo hay empleados cargados en el sistema\n");
                }

    }




    return retorno;
}

int menuInformar()
{
    system("cls");
    printf("************Menu informar************\n\n");

    int opcion = -1;
    printf("1.Listado de empleados ordenados por apellido alfabeticamente\n");
    printf("2.Total y promedio de los salarios\n");
    utn_getNumero(&opcion,"Ingrese un numero del 1 al 2: ","Error. Numero ingresado invalido\n",1,2,5);

    return opcion;
}

void promediarSalarios(Employee* list, int len, float* promedioSalarios, int* totalSalarios, int* contMayoresPromedio){

float acumulador = 0;
int contador = 0;
*contMayoresPromedio = 0;
    for(int i = 0; i< len; i++){ //acumulo el total de los salarios
        if(list[i].isEmpty == 0){
            acumulador += list[i].salary;
            contador++;
        }
    }
*promedioSalarios = acumulador / contador;
*totalSalarios = acumulador;

    for(int i = 0; i<len; i++){ //cuento la cantidad de empleados que superan el promedio en salario
        if(list[i].isEmpty == 0 && *promedioSalarios < list[i].salary  ){
            *contMayoresPromedio+=1;
        }


    }

}
