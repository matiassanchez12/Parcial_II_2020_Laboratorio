#include <stdlib.h>
#include "viaje.h"
#include <string.h>
static int isString(char* str);
static int isDate(char* str);
/** \brief Toma una palabra y verifica si tiene solo letras
 *
 * \param str char* Un puntero a una palabra
 * \return int [0] Encontro caracteres que no son letras, [1] La palabra es solo letras.
 *
 */
static int isString(char* str)
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    return ret;
}

//isNumber()

static int isDate(char* str)
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '/') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    return ret;
}

int viaje_delete(Viaje* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

Viaje* viaje_new(void)
{
    return (Viaje*) malloc(sizeof(Viaje));
}

Viaje* viaje_newParameters(int idVuelo, int idAvion, int idPiloto, char* fecha, char* destino, int cantPasaj, int horaDesp, int horaLleg)
{
    Viaje* pViaje = viaje_new();
    if(pViaje != NULL && destino != NULL && fecha != NULL)
    {
        if(viaje_setIdVuelo(pViaje, idVuelo)== -1 ||
                viaje_setIdAvion(pViaje, idAvion)== -1 ||
                viaje_setIdPiloto(pViaje, idPiloto)== -1 ||
                viaje_setFecha(pViaje, fecha)== -1 ||
                viaje_setDestino(pViaje, destino)== -1 ||
                viaje_setCantPasajeros(pViaje, cantPasaj)== -1 ||
                viaje_setHrDespegue(pViaje, horaDesp)== -1 ||
                viaje_setHrLlegada(pViaje, horaLleg)== -1)
        {
            if(!viaje_delete(pViaje))
            {
                pViaje = NULL;
            }
        }
    }
    return pViaje;
}

int viaje_printOneViaje(Viaje* this, char* nombrePiloto)
{
    int retorno = -1;
    int idVuelo;
    int idAvion;
    int cantPasaj;
    int hrDespegue;
    int hrLlegada;
    char date[FECHA_LEN];
    char destino[DEST_LEN];
    if(this != NULL)
    {
        if(!viaje_getIdVuelo(this, &idVuelo) && !viaje_getIdAvion(this, &idAvion)
                && !viaje_getCantPasajeros(this, &cantPasaj) && !viaje_getHrDespegue(this, &hrDespegue) && !viaje_getFecha(this, date)
                && !viaje_getDestino(this, destino) && !viaje_getHrLlegada(this, &hrLlegada))
        {
            printf(" %5d  |  %5d  |  %13s  |  %10d  |  %4d  |  %4d  |  %15s  |  %15s|\n", idVuelo, idAvion, nombrePiloto, cantPasaj, hrDespegue, hrLlegada, date, destino);
            retorno = 0;
        }
    }
    return retorno;
}

int viaje_getAll(Viaje* this,int* idVuelo, int* idAvion, int* idPiloto, int* cantPasajeros, int* horaDespegue, int* horaLlegada, char* fecha, char* destino)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL && destino != NULL)
    {
        if(!viaje_getIdVuelo(this, idVuelo) &&
                !viaje_getIdAvion(this, idAvion) &&
                !viaje_getIdPiloto(this, idPiloto) &&
                !viaje_getFecha(this, fecha) &&
                !viaje_getDestino(this, destino) &&
                !viaje_getCantPasajeros(this, cantPasajeros) &&
                !viaje_getHrDespegue(this, horaDespegue) &&
                !viaje_getHrLlegada(this, horaLlegada))
        {
            retorno = 0;
        }
    }
    return retorno;
}

int viaje_setIdVuelo(Viaje* this,int idVuelo)
{
    int retorno = -1;
    if(this != NULL && idVuelo >= 0)
    {
        retorno = 0;
        this->idVuelo = idVuelo;
    }
    return retorno;
}
int viaje_getIdVuelo(Viaje* this,int* idVuelo)
{
    int retorno = -1;
    if(this != NULL && idVuelo != NULL)
    {
        retorno = 0;
        *idVuelo = this->idVuelo;
    }
    return retorno;
}
int viaje_setIdAvion(Viaje* this,int idAvion)
{
    int retorno = -1;
    if(this != NULL && idAvion >= 0)
    {
        retorno = 0;
        this->idAvion = idAvion;
    }
    return retorno;
}
int viaje_getIdAvion(Viaje* this,int* idAvion)
{
    int retorno = -1;
    if(this != NULL && idAvion != NULL)
    {
        retorno = 0;
        *idAvion = this->idAvion;
    }
    return retorno;
}

int viaje_setIdPiloto(Viaje* this,int idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto >= 0)
    {
        retorno = 0;
        this->idPiloto = idPiloto;
    }
    return retorno;
}
int viaje_getIdPiloto(Viaje* this,int* idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto != NULL)
    {
        retorno = 0;
        *idPiloto = this->idPiloto;
    }
    return retorno;
}

int viaje_setFecha(Viaje* this,char* date)
{
    int retorno = -1;
    if(this != NULL && date != NULL)
    {
        if(isDate(date))
        {
            retorno = 0;
            strcpy(this->fecha,date);
        }
    }
    return retorno;
}
int viaje_getFecha(Viaje* this,char* date)
{
    int retorno = -1;
    if(this != NULL && date != NULL)
    {
        retorno = 0;
        strcpy(date,this->fecha);
    }
    return retorno;
}

int viaje_setDestino(Viaje* this,char* destino)
{
    int retorno = -1;
    if(this != NULL && destino != NULL)
    {
        if(isString(destino))
        {
            retorno = 0;
            strcpy(this->destino,destino);
        }
    }
    return retorno;
}
int viaje_getDestino(Viaje* this,char* destino)
{
    int retorno = -1;
    if(this != NULL && destino != NULL)
    {
        retorno = 0;
        strcpy(destino,this->destino);
    }
    return retorno;
}

int viaje_setCantPasajeros(Viaje* this,int cantPasaj)
{
    int retorno = -1;
    if(this != NULL && cantPasaj >= 0)
    {
        retorno = 0;
        this->cantPasajeros = cantPasaj;
    }
    return retorno;
}
int viaje_getCantPasajeros(Viaje* this,int* cantPasaj)
{
    int retorno = -1;
    if(this != NULL && cantPasaj != NULL)
    {
        retorno = 0;
        *cantPasaj = this->cantPasajeros;
    }
    return retorno;
}

int viaje_setHrDespegue(Viaje* this,int HrDespegue)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->horaDespegue = HrDespegue;
    }
    return retorno;
}
int viaje_getHrDespegue(Viaje* this,int* HrDespegue)
{
    int retorno = -1;
    if(this != NULL && HrDespegue != NULL)
    {
        retorno = 0;
        *HrDespegue = this->horaDespegue;
    }
    return retorno;
}

int viaje_setHrLlegada(Viaje* this,int HrLlegada)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->horaLlegada = HrLlegada;
    }
    return retorno;

}
int viaje_getHrLlegada(Viaje* this,int* HrLlegada)
{
    int retorno = -1;
    if(this != NULL && HrLlegada != NULL)
    {
        retorno = 0;
        *HrLlegada = this->horaLlegada;
    }
    return retorno;
}

void viaje_funcCabecera(int option)
{
    if(option == 0)
    {
        printf("\n\t\t   ************************\n\t\t   **--------------------**");
        printf("\n\t\t   **|Lista de viajes|**\n");
        printf("\t\t   **--------------------**\n\t\t   ************************\n");
        printf("  ---------------------------------------------------------\n");
        printf("  | Id Vuelo  |  Id Avion  |Id Piloto  |  Cant Pasaj  |  Hr Despegue  |  Hr Llegada  |  Fecha  |  Destino \n");
    }
    else
    {
        printf("\n\t\t   ************************\n\t\t   **--------------------**");
        printf("\n\t\t   **|Lista de pilotos|**\n");
        printf("\t\t   **--------------------**\n\t\t   ************************\n");
        printf("  ---------------------------------------------------------\n");
        printf(" Id Piloto  |  Nombre del Piloto \n");
    }
}
