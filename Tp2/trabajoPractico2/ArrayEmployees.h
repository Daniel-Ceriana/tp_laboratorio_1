#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED
#include "sectores.h"

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector);
int crearEmployee(Employee* list, int len, eSector* sectores, int tamSec);
void mostrarEmpleado(Employee x,eSector* sectores, int tamSec);
int printEmployees(Employee* vec,int tam, eSector* sectores, int tamSec);
int findEmployeeById(Employee* list, int len,int id);
int modificarEmpleado(Employee* empleado, int len, eSector* sectores, int tamSec);
int buscarLibre(Employee vec[], int tam);
int bajaEmpleado(Employee* list, int len, eSector* sectores, int tamSec);
int menuMod();
int sortEmployees(Employee* list, int len, int order);
int informar(Employee* list, int len, eSector* sectores, int tamSec);
int menuInformar();
void promediarSalarios(Employee* list,int len,float* promedioSalarios, int* totalSalarios, int* contMayoresPromedio);


