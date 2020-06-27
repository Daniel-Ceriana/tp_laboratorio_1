#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct{

int id;
char nombre[20];
char apellido[20];
float sueldo;



}eEmpleado;


#endif // EMPLEADOS_H_INCLUDED


eEmpleado* employee_new();
eEmpleado* employee_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* sueldoStr);
int employee_setNombre(eEmpleado* this,char* nombre);
int employee_getNombre(eEmpleado* this,char* nombre);
int employee_setApellido(eEmpleado* this,char* apellido);
int employee_getApellido(eEmpleado* this,char* apellido);
int employee_setId(eEmpleado* this,int id);
int employee_getId(eEmpleado* this,int* id);
int employee_setSueldo(eEmpleado* this,int sueldo);
int employee_getSueldo(eEmpleado* this,int* sueldo);
void employee_delete(eEmpleado* this);
int employee_ordenaPorId(void* a, void* b);
int employee_ordenaPorNombre(void* a, void* b);
int employee_ordenaPorApellido(void* a, void* b);
int employee_ordenaPorSueldo(void* a, void* b);
