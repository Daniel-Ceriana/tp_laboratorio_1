#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct{
int id;
char descripcion[20];

}eSector;

#endif // SECTORES_H_INCLUDED
int cargarDescripcionSector(char* descripcion,int id,eSector* sectores, int tam);
void mostrarSectores(eSector* sectores, int tam);
