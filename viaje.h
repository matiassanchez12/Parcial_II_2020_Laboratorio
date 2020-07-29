
#ifndef viaje_H_INCLUDED
#define viaje_H_INCLUDED
#include "utn.h"
#define DEST_LEN 50
#define FECHA_LEN 100

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[FECHA_LEN];
    char destino[DEST_LEN];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int importe;
}Viaje;

int viaje_delete(Viaje*);
Viaje* viaje_new(void);
Viaje* viaje_newParameters(int, int, int, char*, char*, int, int, int);

int viaje_printOneViaje(Viaje* this, char* nombrePiloto);
int viaje_printOneViajeConPrecio(Viaje* this, char* nombrePiloto);
int viaje_getAll(Viaje* this,int* idVuelo, int* idAvion, int* idPiloto, int* cantPasajeros, int* horaDespegue, int* horaLlegada, char* fecha, char* destino);
int viaje_getAllSinIdPiloto(Viaje* this,int* idVuelo, int* idAvion, int* cantPasajeros, int* horaDespegue, int* horaLlegada, char* fecha, char* destino);

int viaje_setIdVuelo(Viaje* this,int idVuelo);
int viaje_getIdVuelo(Viaje* this,int* idVuelo);

int viaje_setIdAvion(Viaje* this,int idAvion);
int viaje_getIdAvion(Viaje* this,int* idAvion);

int viaje_setIdPiloto(Viaje* this,int idPiloto);
int viaje_getIdPiloto(Viaje* this,int* idPiloto);

int viaje_setFecha(Viaje* this,char* date);
int viaje_getFecha(Viaje* this,char* date);

int viaje_setDestino(Viaje* this,char* destino);
int viaje_getDestino(Viaje* this,char* destino);

int viaje_setCantPasajeros(Viaje* this,int cantPasaj);
int viaje_getCantPasajeros(Viaje* this,int* cantPasaj);

int viaje_setHrDespegue(Viaje* this,int HrDespegue);
int viaje_getHrDespegue(Viaje* this,int* HrDespegue);

int viaje_setHrLlegada(Viaje* this,int HrLlegada);
int viaje_getHrLlegada(Viaje* this,int* HrLlegada);

int viaje_setPrecio(Viaje* this,int importe);
int viaje_getPrecio(Viaje* this,int* importe);

void viaje_funcCabecera(int option);

#endif // viaje_H_INCLUDED
