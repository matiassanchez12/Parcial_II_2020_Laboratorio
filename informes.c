#include "informes.h"

///FUNCIONES CRITERIO Y INFORMES

int info_CountPasajeros(void* pElement)
{
    int retorno = -1;
    int pasajeros;
    if(pElement != NULL)
    {
        if(!viaje_getCantPasajeros((Viaje*) pElement, &pasajeros) && pasajeros > 0)
        {
            retorno = pasajeros;
        }
    }
    return retorno;
}

int info_CountPasajerosIrlanda(void* pElement)
{
    int retorno = -1;
    int cantPasajeros;
    char auxDestino[DEST_LEN];
    if(pElement != NULL)
    {
        if(!viaje_getCantPasajeros((Viaje*) pElement, &cantPasajeros) && !viaje_getDestino((Viaje*) pElement, auxDestino))
        {
            if(cantPasajeros > 0 && strcmp(auxDestino, "Irlanda") == 0)
            {
                retorno = cantPasajeros;
            }
        }
    }
    return retorno;
}

int info_BuscarVuelosCortos(void* pElement)
{
    int retorno = 0;
    int tiempo, hrLlegada, hrDespegue;
    if(pElement != NULL)
    {
        if(!viaje_getHrDespegue((Viaje*) pElement, &hrDespegue) && !viaje_getHrLlegada((Viaje*) pElement, &hrLlegada))
        {
            tiempo = hrLlegada - hrDespegue;
            if(tiempo < 3)
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int info_BuscarVuelosPortugal(void* pElement)
{
    int retorno = 0;
    char destino[DEST_LEN];
    if(pElement != NULL)
    {
        if(!viaje_getDestino((Viaje*) pElement, destino))
        {
            if(strcmp("Portugal", destino)==0)
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int info_BuscarVuelosDeAlexLifeson(void* pElement)
{
    int retorno = 0;
    int auxId;
    if(pElement != NULL)
    {
        if(!viaje_getIdPiloto((Viaje*) pElement, &auxId))
        {
            if(auxId != 1)
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int info_FiltrarPilotoX(void* pElement, char* auxNombre)
{
    int retorno = 0;
    char nombrePilotoElement[NAME_LEN];

    if(pElement != NULL && auxNombre != NULL)
    {
        if(!piloto_getNombrePiloto((ePiloto*)pElement, nombrePilotoElement))
        {
            if(strcmp(nombrePilotoElement, auxNombre) != 0)
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int info_getNombrePorId(LinkedList* pArrayListPiloto, int idPiloto, char* auxNombre)
{
    int retorno = -1;
    ePiloto* auxPiloto;
    int auxId;
    int i;
    int lenList;
    if(pArrayListPiloto != NULL && auxNombre != NULL)
    {
        lenList = ll_len(pArrayListPiloto);
        if(lenList > 0)
        {
            for(i=0; i<lenList; i++)
            {
                auxPiloto = ll_get(pArrayListPiloto, i);

                if(!piloto_getIdPiloto(auxPiloto, &auxId) && (auxId == idPiloto))
                {
                    if(!piloto_getNombrePiloto(auxPiloto, auxNombre))
                    {
                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}
