#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    char buffer[4][255];
    int cant;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]); // me salteo la primer linea

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]); // cargo los datos separados por coma en un buffer

        if(cant !=4)
        {
            break;
        }

        auxEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]); //carga el empleado segun los parametros

        ll_add(pArrayListEmployee,auxEmployee);

    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;

    int auxId;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    char buffer[125];

    int cant;

    while(!feof(pFile))
    {
        cant = scanf("%[^\n]",buffer);
        if(cant !=4)//si el fread no puede leer los parametros que vienen en la estructura Employee, sale de la estructura repetitiva
        {
            break;
        }

        //auxEmpleado = employee_newParametros(auxId,nombre,horasTrabajadas,sueldo); //carga el empleado segun los parametros

//        ll_add(pArrayListEmployee,auxEmpleado);
    }



    return 1;
}
