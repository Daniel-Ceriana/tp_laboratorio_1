#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


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

    if(f== NULL)//si no se pudo abrir por alguna razon cierro el programa
    {
        printf("Problemas al abrir el archivo\n\n");
        exit(EXIT_FAILURE);
    }

    parser_EmployeeFromText(f, pArrayListEmployee); // cargo todos los empleados en la memoria

    fclose(f);
    return 1;
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

    if(f==NULL) //si no se pudo abrir por alguna razon cierro el programa
    {
        printf("Problemas al abrir el archivo binario");
        exit(EXIT_FAILURE);
    }

    parser_EmployeeFromBinary(f,pArrayListEmployee); //cargo los empleados a la memoria desde archivo binario


    fclose(f);
    return 1;
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
    return 1;
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

    if(pArrayListEmployee != NULL){
        for(int i = 0; i<tam; i++){
            flag = 1;
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);


            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,nombre);
            employee_getSueldo(auxEmpleado,&auxSueldo);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);

            printf(" %-4d %-15s %-4d %13d \n",auxId,nombre,auxHorasTrabajadas,auxSueldo);

            }

        if(!flag){
            printf("Error no hay empleados en la memoria\n");
        }

        }
    else
    {
        printf("\nError al cargar la memoria de los empleados\n");
    }



    return 1;
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
    return 1;
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
    return 1;
}

