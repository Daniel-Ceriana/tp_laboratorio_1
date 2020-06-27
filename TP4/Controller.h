#include "empleados.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee, LinkedList* lista);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_listarMejoresPagos(LinkedList* pArrayListEmployee,int (*pFunc)(void* ,void*));
int controller_reiniciarDatos(LinkedList* pArrayListEmployee);

int controller_buscarEmpleadoPorId(int idBuscado,LinkedList* pArrayListEmployee);
int menuModEmpleado(eEmpleado* this,LinkedList* pArrayListEmployee);
int menuModEmpleadoSeleccion();
