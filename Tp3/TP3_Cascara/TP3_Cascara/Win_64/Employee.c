#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"





Employee* employee_new()
{

    Employee*  auxEmpleado = (Employee*) malloc(sizeof(Employee));

    if(auxEmpleado!=NULL)
    {
        auxEmpleado->id = 0;
        strcpy(auxEmpleado->nombre," ");
        auxEmpleado->horasTrabajadas= 0;
        auxEmpleado->sueldo= 0;

    }

    return auxEmpleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    Employee* auxEmpleado = employee_new();



    if(auxEmpleado!= NULL) //si no es un puntero a null
    {

        if(! (employee_setId(auxEmpleado,atoi(idStr))//si esta todo mal hago un free()
                && employee_setNombre(auxEmpleado,nombreStr)
                && employee_setHorasTrabajadas(auxEmpleado,atoi(horasTrabajadasStr))
                && employee_setSueldo(auxEmpleado,atoi(sueldoStr)))
          )
        {
            free(auxEmpleado);
            auxEmpleado = NULL;
        }

    }


    return auxEmpleado;
}




int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this!= NULL && nombre!=NULL && strlen(nombre) >=3 && strlen(nombre)<20 )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this!= NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }


    return todoOk;
}


int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id>=0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if(this!= NULL && id!=NULL )
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}





int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas>=0)
    {
        this-> horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this!= NULL && horasTrabajadas!=NULL )
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo>=0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this!= NULL && sueldo!=NULL )
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}
