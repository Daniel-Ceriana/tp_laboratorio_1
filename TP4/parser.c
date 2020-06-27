#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "empleados.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    eEmpleado* auxEmployee;
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

