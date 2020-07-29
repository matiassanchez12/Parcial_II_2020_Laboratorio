#include "informes.h"

///FUNCIONES CRITERIO Y INFORMES

/** \brief Cuenta la cantidad de pasajeros de todos los vuelos
 *
 * \param pElement void* Puntero a un elemento
 * \return int [-1] el elemento es NULL, [0] todo ok.
 *
 */
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
/** \brief Cuenta la cantidad de pasajeros a Irlanda
 *
 * \param pElement void* Puntero a un elemento
 * \return int [-1] el elemento es NULL, [0] todo ok.
 *
 */
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

/** \brief Busca los vuelos de duracion menor a 3 horas
 *
 * \param pElement void* Puntero a un elemento
 * \return int [0] Elemento es NULL, [1] El vuelo es menor a 3 horas
 *
 */
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

/** \brief Busca los vuelos a Portugal
 *
 * \param pElement void* Puntero a un elemento
 * \return int [0] Elemento es NULL, [1] El vuelo es de portugal
 *
 */
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

/** \brief Busca los vuelos que tienen al piloto Alex Lifeson
 *
 * \param pElement void* Puntero a un elemento
 * \return int [0] Elemento es NULL, [1] Alex lifeson es el piloto
 *
 */
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

/** \brief Recibe un elemento y un nombre de un piloto que sera filtrado
 *
 * \param pElement void* Puntero a un elemento
 * \param auxNombre char* Nombre del piloto
 * \return int [0] El elemento o el nombre son NULL, [1] todo ok.
 *
 */
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

/** \brief Busca el elemento con el id del piloto, y se obtiene el nombre de este elemento
 *
 * \param pArrayListPiloto LinkedList* Puntero a la lista enlazada de pilotos.
 * \param idPiloto int Id de un piloto.
 * \param auxNombre char* Nombre del piloto.
 * \return int [-1] La lista o el nombre son NULL, [0] Se encontro el nombre
 *
 */
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

/** \brief Recibe el nombre de un piloto y verifica si existe, caso positivo devuelve el id del piloto
 *
 * \param pArrayListPiloto LinkedList* lista de pilotos.
 * \param auxNombre char* nombre del piloto.
 * \return int [-1] El nombre no existe, caso contrario devuelve el id del piloto;
 *
 */
int info_checkNombrePiloto(LinkedList* pArrayListPiloto, char* auxNombre)
{
    int retorno = -1;
    ePiloto* auxPiloto;
    char auxNombreElement[NAME_LEN];
    int auxIdPiloto = -1;
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

                if(!piloto_getNombrePiloto(auxPiloto, auxNombreElement) && strcmp(auxNombreElement, auxNombre) == 0
                        && !piloto_getIdPiloto(auxPiloto, &auxIdPiloto))
                {
                    retorno = auxIdPiloto;
                }
            }
        }
    }
    return retorno;
}

void* info_SetPrecioDeVuelos(void* element)
{
    void* auxElement = NULL;
    char destino[DEST_LEN];
    int cantPasajeros;
    int precio;

    if(element != NULL )
    {
        auxElement = (Viaje*)element;
        if(!viaje_getDestino(element, destino)
                && !viaje_getCantPasajeros(element,&cantPasajeros))
        {
            if(strcmp(destino, "Portugal") == 0)
            {
                precio = cantPasajeros * 1000;
                viaje_setPrecio(auxElement, precio);
            }
            else
            {
                precio = cantPasajeros * 1500;
                viaje_setPrecio(auxElement, precio);
            }
        }
    }
    return auxElement;
}
