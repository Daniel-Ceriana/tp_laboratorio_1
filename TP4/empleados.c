#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "empleados.h"
#include "LinkedList.h"

/** \brief asigna un puntero a un espacio en la memoria reservado
** \return retorna puntero a empleado
*/
eEmpleado* employee_new()
{

    eEmpleado*  auxEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(auxEmpleado!=NULL)
    {
        auxEmpleado->id = 0;
        strcpy(auxEmpleado->nombre," ");
        strcpy(auxEmpleado->apellido," ");
        auxEmpleado->sueldo= 0;
    }

    return auxEmpleado;
}

/** \brief crea un empleado a partir de parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param apellidoStr char*
 * \param sueldoStr char*
 * \return retorna puntero a empleado
 *
 */

eEmpleado* employee_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* sueldoStr)
{

    eEmpleado* auxEmpleado = employee_new();



    if(auxEmpleado!= NULL) //si no es un puntero a null
    {

        if(! (employee_setId(auxEmpleado,atoi(idStr))//si esta todo mal hago un free()
                && employee_setNombre(auxEmpleado,nombreStr)
                && employee_setApellido(auxEmpleado,apellidoStr)
                && employee_setSueldo(auxEmpleado,atoi(sueldoStr)))
          )
        {
            free(auxEmpleado);
            auxEmpleado = NULL;
        }

    }


    return auxEmpleado;
}



/** \brief modifica de un empleado el nombre
 *
 * \param this eEmpleado*
 * \param nombre int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int employee_setNombre(eEmpleado* this,char* nombre)
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
 * \param this eEmpleado*
 * \param nombre int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int employee_getNombre(eEmpleado* this,char* nombre)
{
    int todoOk = 0;

    if(this!= NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }


    return todoOk;
}

/** \brief modifica de un empleado el apellido
 *
 * \param this eEmpleado*
 * \param apellido int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int employee_setApellido(eEmpleado* this,char* apellido)
{
    int todoOk = 0;

    if(this!= NULL && apellido!=NULL && strlen(apellido) >=3 && strlen(apellido)<20 )
    {
        strcpy(this->apellido, apellido);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief consigue de un empleado el apellido
 *
 * \param this eEmpleado*
 * \param apellido int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int employee_getApellido(eEmpleado* this,char* apellido)
{
    int todoOk = 0;

    if(this!= NULL && apellido !=NULL)
    {
        strcpy(apellido,this->apellido);
        todoOk = 1;
    }


    return todoOk;
}

/** \brief modifica de un empleado el id
 *
 * \param this eEmpleado*
 * \param id int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int employee_setId(eEmpleado* this,int id)
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
 * \param this eEmpleado*
 * \param id int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int employee_getId(eEmpleado* this,int* id)
{
    int todoOk = 0;

    if(this!= NULL && id!=NULL )
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}



/** \brief modifica de un empleado el sueldo
 *
 * \param this eEmpleado*
 * \param sueldo int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */

int employee_setSueldo(eEmpleado* this,int sueldo)
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
 * \param this eEmpleado*
 * \param sueldo int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */

int employee_getSueldo(eEmpleado* this,int* sueldo)
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
 * \param this eEmpleado*
 * \return retorna 0 si todo bien o 1 si error
 *
 */

void employee_delete(eEmpleado* this)
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
int employee_ordenaPorId(void* a, void* b)
{
    int retorno = 0;
    eEmpleado* p1;
    eEmpleado* p2;

    if(a!=NULL && b != NULL)
    {
        p1=(eEmpleado*) a;
        p2=(eEmpleado*) b;
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
int employee_ordenaPorNombre(void* a, void* b)
{
    int retorno = 0;

    eEmpleado* p1;
    eEmpleado* p2;

    if(a!=NULL && b != NULL)
    {
        p1=(eEmpleado*) a;
        p2=(eEmpleado*) b;

        retorno = strcmp(p1->nombre, p2->nombre);

    }
}

/** \brief ordena dos datos por apellido
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int employee_ordenaPorApellido(void* a, void* b)
{
    int retorno = 0;

    eEmpleado* p1;
    eEmpleado* p2;

    if(a!=NULL && b != NULL)
    {
        p1=(eEmpleado*) a;
        p2=(eEmpleado*) b;

        retorno = strcmp(p1->apellido, p2->apellido);

    }
}


/** \brief ordena dos datos por sueldo
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int employee_ordenaPorSueldo(void* a, void* b)
{
    int retorno = 0;
    eEmpleado* p1;
    eEmpleado* p2;

    if(a!=NULL && b != NULL)
    {
        p1=(eEmpleado*) a;
        p2=(eEmpleado*) b;
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
