
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "sectores.h"





int cargarDescripcionSector(char* descripcion,int id,eSector* sectores, int tam){

    int todoOk = 0;

    for( int i = 0; i< tam; i++){
        if(sectores[i].id == id){
         strncpy(descripcion,sectores[i].descripcion, 20);
         todoOk = 1;
        }
    }

    return todoOk;
}


void mostrarSectores(eSector* sectores, int tam){

    printf("\n\n**************Lista de Sectores**************\n\n");

    for (int i= 0; i < tam; i++){

        printf("%d. %s\n",sectores[i].id, sectores[i].descripcion );
    }

}
