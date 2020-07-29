#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define NAME_LEN 50

typedef struct
{
    int idPiloto;
    char nombrePiloto[NAME_LEN];
}ePiloto;

int piloto_delete(ePiloto* this);
ePiloto* piloto_new(void);
ePiloto* piloto_newParameters(int idPiloto, char* nombrePiloto);
int piloto_printPiloto(ePiloto* this);

int piloto_getAll(ePiloto* this, int* idPiloto, char* nombrePiloto);

int piloto_getNombrePiloto(ePiloto* this,char* nombrePiloto);
int piloto_setNombrePiloto(ePiloto* this,char* nombrePiloto);

int piloto_getIdPiloto(ePiloto* this,int* idPiloto);
int piloto_setIdPiloto(ePiloto* this,int idPiloto);
