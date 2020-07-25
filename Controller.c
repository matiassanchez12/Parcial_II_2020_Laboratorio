#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Puntero al nombre del archivo
 * \param pArrayList LinkedList* Puntero a la lista enlazada
 * \return int [-1] puntero a fileP es NULL o el puntero a la lista es NULL, [< 0] ultimo Id caso contrario.
 *
 */
int controller_Sanchez_loadVuelosFromText(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    int lastId;
    FILE* fileP = fopen(path,"r");
    if(fileP != NULL && pArrayList != NULL)
    {
        lastId = parser_FromTextViajes(fileP, pArrayList);
        if(lastId > 0)
        {
            retorno = lastId;
        }
    }
    return retorno;
}

int controller_Sanchez_loadPilotosFromText(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    int lastId;
    FILE* fileP = fopen(path,"r");
    if(fileP != NULL && pArrayList != NULL)
    {
        lastId = parser_FromTextPilotos(fileP, pArrayList);
        if(lastId > 0)
        {
            retorno = lastId;
        }
    }
    return retorno;
}

int controller_Sanchez_PrintVuelos(LinkedList* pArrayList, LinkedList* pArrayListPiloto)
{
    int retorno = -1;
    int i;
    int auxId;
    char auxNombre[DEST_LEN];
    Viaje* auxElementViaje;
    if(pArrayList != NULL && pArrayListPiloto != NULL)
    {
        retorno = 0;
        for(i = 0; i < ll_len(pArrayList); i++)
        {
            auxElementViaje = ll_get(pArrayList, i);
            if(auxElementViaje != NULL && !viaje_getIdPiloto(auxElementViaje, &auxId))
            {
                if(!info_getNombrePorId(pArrayListPiloto, auxId, auxNombre))
                {
                    viaje_printOneViaje(auxElementViaje, auxNombre);
                }
            }
        }
    }
    return retorno;
}

int controller_Sanchez_PrintPilotos(LinkedList* pArrayList)
{
    int retorno = -1;
    int lenLl;
    int i;
    ePiloto* pAux;
    lenLl = ll_len(pArrayList);
    if(pArrayList != NULL)
    {
        viaje_funcCabecera(1);
        for(i=0; i<lenLl; i++)
        {
            pAux = (ePiloto*) ll_get(pArrayList, i);
            if(pAux != NULL && !piloto_printPiloto(pAux))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int controller_Sanchez_CountPasajeros(LinkedList* pArrayList)
{
    int retorno = -1;
    int (*pFunction)(void*);
    pFunction = info_CountPasajeros;
    int totalDePasajeros;
    if(pArrayList != NULL)
    {
        totalDePasajeros = ll_count(pArrayList, pFunction);
        if(totalDePasajeros != 0)
        {
            printf("El total es : %d", totalDePasajeros);
            retorno = 0;
        }
    }
    return retorno;
}

int controller_Sanchez_CountPasajerosIrlanda(LinkedList* pArrayList)
{
    int retorno = -1;
    int (*pFunction)(void*);
    pFunction = info_CountPasajerosIrlanda;
    int totalDePasajeros;
    if(pArrayList != NULL)
    {
        totalDePasajeros = ll_count(pArrayList, pFunction);
        if(totalDePasajeros != 0)
        {
            printf("El total es : %d", totalDePasajeros);
            retorno = 0;
        }
    }
    return retorno;
}

int controller_Sanchez_FiltrarVuelosCortos(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    LinkedList* auxList = ll_newLinkedList();
    int (*pFunction)(void*);
    pFunction = info_BuscarVuelosCortos;
    if(pArrayList != NULL && path != NULL)
    {
        auxList = ll_filter(pArrayList, pFunction);
        if(auxList != NULL)
        {
            if(!controller_Sanchez_guardarVuelosCortosComoTexto(path,auxList))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int controller_Sanchez_guardarVuelosCortosComoTexto(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    int i;
    FILE* fileP;
    int idVuelo,idAvion,idPiloto,cantPasajeros,horaDespegue,horaLlegada;
    char destino[DEST_LEN], fecha[FECHA_LEN];
    Viaje* pAux;
    if(path != NULL && pArrayList != NULL)
    {
        fileP = fopen(path,"w");
        if(fileP != NULL)
        {
            retorno = 0;
            fprintf(fileP,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
            for(i=0; i<ll_len(pArrayList); i++)
            {
                pAux = ll_get(pArrayList, i);
                if(pAux != NULL)
                {
                    if(!viaje_getAll(pAux, &idVuelo, &idAvion,&idPiloto,&cantPasajeros,&horaDespegue,&horaLlegada,fecha,destino))
                    {
                        fprintf(fileP,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
                    }
                }
            }
            fclose(fileP);
        }
    }
    return retorno;
}

int controller_Sanchez_ListarVuelosPortugal(LinkedList* pArrayList, LinkedList* pArrayListPilotos)
{
    int retorno = -1;
    LinkedList* auxList;
    int (*pFunction)(void*);
    pFunction = info_BuscarVuelosPortugal;
    if(pArrayList != NULL)
    {
        auxList = ll_filter(pArrayList, pFunction);
        if(auxList != NULL)
        {
            if(!controller_Sanchez_PrintVuelos(auxList, pArrayListPilotos))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int controller_Sanchez_ListarVuelosSinAlexLifeson(LinkedList* pArrayList, LinkedList* pArrayListPilotos)
{
    int retorno = -1;
    LinkedList* auxList;
    int (*pFunction)(void*);
    pFunction = info_BuscarVuelosDeAlexLifeson;
    if(pArrayList != NULL)
    {
        auxList = ll_filter(pArrayList, pFunction);
        if(auxList != NULL)
        {
            if(!controller_Sanchez_PrintVuelos(auxList, pArrayListPilotos))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int Controller_Sanchez_FiltrarPilotoPorNombre(LinkedList* pArrayListPilotos)
{
    int retorno = -1;
    LinkedList* auxList;
    int (*pFunction)(void*, char*);
    pFunction = info_FiltrarPilotoX;
    char auxNombre[NAME_LEN];

    if(pArrayListPilotos != NULL)
    {
        if(utn_getNameAndLastName(auxNombre, NAME_LEN, "Ingresar nombre y apellido del piloto: ", "Error.", 3))
        {
            auxList = ll_filter_parametro(pArrayListPilotos, pFunction, auxNombre);
            if(auxList != NULL)
            {
                if(!controller_Sanchez_PrintPilotos(auxList))
                {
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


