#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"




/** \brief asigna un puntero a un espacio en la memoria reservado
 *
 * \param
 * \param
 * \return
 *
 */

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

/** \brief crea un empleado a partir de parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return retorna puntero a empleado
 *
 */

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



/** \brief consigue de un empleado el nombre
 *
 * \param this Employee*
 * \param nombre int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
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

/** \brief consigue de un empleado el nombre
 *
 * \param this Employee*
 * \param nombre int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
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

/** \brief consigue de un empleado el id
 *
 * \param this Employee*
 * \param id int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
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

/** \brief consigue de un empleado el id
 *
 * \param this Employee*
 * \param id int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
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




/** \brief modifica de un empleado las horas trabajadas
 *
 * \param this Employee*
 * \param horastrabajadas int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
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
/** \brief consigue de un empleado las horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
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


/** \brief modifica de un empleado el sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */

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

/** \brief consigue de un empleado el sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */

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

/** \brief elimina el puntero a un empleado de la memoria dinamica
 *
 * \param this Employee*
 * \return retorna 0 si todo bien o 1 si error
 *
 */

void employee_delete(Employee* this)
{
    int todoOk = 0;

    if(this!=NULL)
    {
        free(this);
        this = NULL;
    }
    else
    {
        todoOk = 1;
    }



    return todoOk;
}


/** \brief ordena dos datos por id
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int employee_ordenaPorId(void* a, void* b){
int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a!=NULL && b != NULL){
        p1=(Employee*) a;
        p2=(Employee*) b;
        if(p1->id > p2 ->id)
        {
            retorno = 1;
        }
        else if(p1->id < p2 ->id)
        {
            retorno = -1;
        }

    }

    return retorno;
}
/** \brief ordena dos datos por nombre
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int employee_ordenaPorNombre(void* a, void* b){
int retorno = 0;

    Employee* p1;
    Employee* p2;

    if(a!=NULL && b != NULL){
        p1=(Employee*) a;
        p2=(Employee*) b;

        retorno = strcmp(p1->nombre, p2->nombre);

    }
}
/** \brief ordena dos datos por horas trabajadas
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int employee_ordenaPorHorasTrabajadas(void* a, void* b){
int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a!=NULL && b != NULL){
        p1=(Employee*) a;
        p2=(Employee*) b;
        if(p1->horasTrabajadas > p2 ->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(p1->horasTrabajadas < p2 ->horasTrabajadas)
        {
            retorno = -1;
        }

    }

    return retorno;
}

/** \brief ordena dos datos por sueldo
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int employee_ordenaPorSueldo(void* a, void* b){
int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a!=NULL && b != NULL){
        p1=(Employee*) a;
        p2=(Employee*) b;
        if(p1->sueldo > p2 ->sueldo)
        {
            retorno = 1;
        }
        else if(p1->sueldo < p2 ->sueldo)
        {
            retorno = -1;
        }

    }

    return retorno;
}
