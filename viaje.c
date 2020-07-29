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

/** \brief Toma una palabra y verifica si es una fecha
 *
 * \param str char* Palabra a analizar.
 * \return int [1] si es una fecha, caso contrario [0]
 *
 */
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

/** \brief Elimina un elemento de tipo viaje
 *
 * \param this Viaje* Puntero al elemento
 * \return int [-1] Elemento apunta a NULL, [0] Elemento eliminado.
 *
 */
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

/** \brief Crea el espacio de memoria para un elemento de tipo viaje
 *
 * \return Viaje* Un puntero al elemento recien creado.
 *
 */
Viaje* viaje_new(void)
{
    return (Viaje*) malloc(sizeof(Viaje));
}

/** \brief Crea espacio de memoria para un elemento del tipo viaje, pero con sus campos inicializados
 *
 * \param idVuelo int Id del vuelo.
 * \param idAvion int Id del Avion.
 * \param idPiloto int Id del piloto.
 * \param fecha char* Fecha del vuelo
 * \param destino char* Destino del vuelo
 * \param cantPasaj int Cantidad de pasajeros
 * \param horaDesp int Hora de despegue
 * \param horaLleg int Hora de llegada
 * \return Viaje* Retorna un puntero al elemento creado, o NULL en caso de error.
 *
 */
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

/** \brief Imprime los datos de un viaje
 *
 * \param this Viaje* Puntero a un elemento
 * \param nombrePiloto char* Nombre de un piloto
 * \return int [-1] los Puntero a this o a nombre del piloto son NULL, [0] Se imprimio con exito
 *
 */
int viaje_printOneViaje(Viaje* this, char* nombrePiloto)
{
    int retorno = -1;
    int idVuelo;
    int idAvion;
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char date[FECHA_LEN];
    char destino[DEST_LEN];
    if(this != NULL)
    {
        if(!viaje_getAllSinIdPiloto(this, &idVuelo, &idAvion,&cantPasajeros,&horaDespegue,&horaLlegada,date,destino))
        {
            printf("  |  %5d    |  %5d     |  %15s   |  %10d  |  %10d  |  %10d  |  %15s  |  %15s|\n", idVuelo, idAvion, nombrePiloto, cantPasajeros, horaDespegue, horaLlegada, date, destino);
            printf("  ----------------------------------------------------------------------------------------------------------------------------------\n");
            retorno = 0;
        }
    }
    return retorno;
}

int viaje_printOneViajeConPrecio(Viaje* this, char* nombrePiloto)
{
    int retorno = -1;
    int idVuelo;
    int idAvion;
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char date[FECHA_LEN];
    char destino[DEST_LEN];
    int precio;
    if(this != NULL)
    {
        if(!viaje_getAllSinIdPiloto(this, &idVuelo, &idAvion,&cantPasajeros,&horaDespegue,&horaLlegada,date,destino) && !viaje_getPrecio(this, &precio))
        {
            printf("  |  %5d    |  %5d     |  %15s   |  %10d  |  %10d  |  %10d  |  %15s  |  %15s|  %10d   \n", idVuelo, idAvion, nombrePiloto, cantPasajeros, horaDespegue, horaLlegada, date, destino, precio);
            printf("  ----------------------------------------------------------------------------------------------------------------------------------\n");
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Recibe un elemento y toma todos los campos mediante getters.
 *
 * \param this Viaje* Puntero al elemento
* \param idVuelo int* Puntero al Id del vuelo.
 * \param idAvion int* Puntero al Id del Avion.
 * \param idPiloto int* Puntero al Id del piloto.
 * \param fecha char* Fecha del vuelo
 * \param destino char* Destino del vuelo
 * \param cantPasaj int* Puntero a la Cantidad de pasajeros
 * \param horaDesp int* Puntero a la Hora de despegue
 * \param horaLleg int* Puntero a la Hora de llegada
 * \return int [-1] Alguno de los puntero son NULL, [0] Datos tomados con exito
 *
 */
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
/** \brief Recibe un elemento y toma todos los campos mediante getters pero sin el Id piloto.
 *
 * \param this Viaje* Puntero al elemento
* \param idVuelo int* Puntero al Id del vuelo.
 * \param idAvion int* Puntero al Id del Avion.
 * \param fecha char* Fecha del vuelo
 * \param destino char* Destino del vuelo
 * \param cantPasaj int* Puntero a la Cantidad de pasajeros
 * \param horaDesp int* Puntero a la Hora de despegue
 * \param horaLleg int* Puntero a la Hora de llegada
 * \return int [-1] Alguno de los puntero son NULL, [0] Datos tomados con exito
 *
 */
int viaje_getAllSinIdPiloto(Viaje* this,int* idVuelo, int* idAvion, int* cantPasajeros, int* horaDespegue, int* horaLlegada, char* fecha, char* destino)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL && destino != NULL)
    {
        if(!viaje_getIdVuelo(this, idVuelo) &&
                !viaje_getIdAvion(this, idAvion) &&
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

/** \brief Recibe un entero para ser asignado a un campo
 *
 * \param this Viaje* Puntero al elemento
 * \param idVuelo int Numero que sera el id del vuelo
 * \return int [-1] This es NULL [0] todo ok.
 *
 */
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
/** \brief Obtiene el campo idVuelo de un elemento
 *
 * \param this Viaje* Elemento del tipo viaje
 * \param idVuelo int* Puntero a la variable int
 * \return int [-1] Algun puntero es NULL [0] Todo ok
 *
 */
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
/** \brief Recibe un entero para ser asignado a un campo
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param idAvion int Entero que ocupara el campo idAvion
 * \return int [-1] This es NULL o idAvion >= 0, [0] Todo ok
 *
 */
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

/** \brief Obtiene el campo idAvion de un elemento
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param idAvion int* Puntero a la variable int con el id del avion
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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

/** \brief Recibe un entero para ser asignado a un campo
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param idPiloto int  Variable int con el id del piloto
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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
/** \brief Obtiene el campo idPiloto de un elemento
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param idPiloto int* Puntero a la variable int con el id del piloto
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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

/** \brief Recibe un string para ser asignado a un campo
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param date char* Puntero a la variable char con la fecha
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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
/** \brief Obtiene el campo fecha de un elemento
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param date char* Puntero a la variable char con la fecha
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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

/** \brief Recibe un string para ser asignado a un campo
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param destino char* Puntero a la variable char con el destino
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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
/** \brief Obtiene el campo destino de un elemento
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param destino char* Puntero a la variable char con el destino
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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

/** \brief Recibe un entero para ser asignado a un campo
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param cantPasaj int Variable int con la cantidad de pasajeros
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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
/** \brief Obtiene el campo CantPasajeros de un elemento
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param cantPasaj int* Puntero al variable int con la cantidad de pasajeros
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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

/** \brief Recibe un entero para ser asignado a un campo
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param HrDespegue int variable int con la hora de despegue
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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
/** \brief Obtiene el campo horaDespegue de un elemento
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param HrDespegue int* Puntero al variable int con la hora de despegue
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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

/** \brief Recibe un entero para ser asignado a un campo
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param HrLlegada int variable int con la hora de llegada
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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
/** \brief Obtiene el campo horaLlegada de un elemento
 *
 * \param this Viaje* Puntero a un elemento de la entidad viaje
 * \param HrLlegada int* Puntero al variable int con la hora de llegada
 * \return int [-1] This es NULL, [0] Todo ok
 *
 */
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

int viaje_setPrecio(Viaje* this,int importe)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->importe = importe;
    }
    return retorno;

}

int viaje_getPrecio(Viaje* this,int* importe)
{
    int retorno = -1;
    if(this != NULL && importe != NULL)
    {
        retorno = 0;
        *importe = this->importe;
    }
    return retorno;
}


void viaje_funcCabecera(int option)
{
    switch(option)
    {
    case 0:
        printf("\n\t\t   ************************\n\t\t   **---------------------**");
        printf("\n\t\t   **|  Lista de Vuelos  |**\n");
        printf("\t\t   **---------------------**\n\t\t   ************************\n");
        printf("  ----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("  | Id Vuelo  |  Id Avion  | Nombre del Piloto  |  Cant Pasaj  |  Hr Despegue  |  Hr Llegada  |      Fecha        |      Destino    |\n");
        printf("  ----------------------------------------------------------------------------------------------------------------------------------\n\n");

        break;
    case 1:
        printf("\n\t\t   ************************\n\t\t   **--------------------**");
        printf("\n\t\t   **| Lista de pilotos |**\n");
        printf("\t\t   **--------------------**\n\t\t   ************************\n");
        printf("  -------------------------------\n");
        printf(" |Id Piloto  |  Nombre del Piloto| \n");
        printf("  -------------------------------\n");

        break;
    case 2:
        printf("\n\t\t   ************************\n\t\t   **---------------------**");
        printf("\n\t\t   **|  Lista de Vuelos  |**\n");
        printf("\t\t   **---------------------**\n\t\t   ************************\n");
        printf("  ----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("  | Id Vuelo  |  Id Avion  | Nombre del Piloto  |  Cant Pasaj  |  Hr Despegue  |  Hr Llegada  |      Fecha        |      Destino    |     Precio      |\n");
        printf("  ----------------------------------------------------------------------------------------------------------------------------------\n\n");

        break;

    }
}
