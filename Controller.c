#include "Controller.h"

/** \brief Carga los datos de los vuelos desde el archivo Vuelos.csv (modo texto).
 *
 * \param path char* Puntero al nombre del archivo
 * \param pArrayList LinkedList* Puntero a la lista enlazada
 * \return int [-1] puntero a fileP es NULL o el puntero a la lista es NULL, [0] txt cargado.
 *
 */
int controller_Sanchez_loadVuelosFromText(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    FILE* fileP = fopen(path,"r");
    if(fileP != NULL && pArrayList != NULL)
    {
        if(!parser_FromTextViajes(fileP, pArrayList))
        {
            retorno = 0;
        }
    }
    return retorno;
}
/** \brief Carga los datos de los vuelos desde el archivo Pilotos.csv (modo texto).
 *
 * \param path char* Puntero al nombre del archivo
 * \param pArrayList LinkedList* Puntero a la lista enlazada
 * \return int [-1] puntero a fileP es NULL o el puntero a la lista es NULL, [0] txt cargado.
 *
 */
int controller_Sanchez_loadPilotosFromText(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    FILE* fileP = fopen(path,"r");
    if(fileP != NULL && pArrayList != NULL)
    {
        if(!parser_FromTextPilotos(fileP, pArrayList))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Imprime una lista con todos los vuelos
 *
 * \param pArrayList LinkedList* Puntero a la lista a ser impresa
 * \param pArrayListPiloto LinkedList* Puntero a la lista de pilotos, sirve para tomar el nombre de un piloto
 * \return int [-1] Si alguna de las listas apunta a NULL, [0] Si se imprimio con exito
 *
 */
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
        viaje_funcCabecera(0);
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

int controller_Sanchez_PrintVuelosConPrecio(LinkedList* pArrayList, LinkedList* pArrayListPiloto)
{
    int retorno = -1;
    int i;
    int auxId;
    char auxNombre[DEST_LEN];
    Viaje* auxElementViaje;
    if(pArrayList != NULL && pArrayListPiloto != NULL)
    {
        retorno = 0;
        viaje_funcCabecera(2);
        for(i = 0; i < ll_len(pArrayList); i++)
        {
            auxElementViaje = ll_get(pArrayList, i);
            if(auxElementViaje != NULL && !viaje_getIdPiloto(auxElementViaje, &auxId))
            {
                if(!info_getNombrePorId(pArrayListPiloto, auxId, auxNombre))
                {
                    viaje_printOneViajeConPrecio(auxElementViaje, auxNombre);
                }
            }
        }
    }
    return retorno;
}

/** \brief Imprime la lista de pilotos.
 *
 * \param pArrayList LinkedList* Puntero a la lista de pilotos.
 * \return int [-1] Si el puntero a la lista es NULL, [0] Se imprimio con exito.
 *
 */
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
        printf(" -------------------------------\n");
    }
    return retorno;
}

/** \brief Cuenta la cantidad total de pasajeros de todos los vuelos y lo muestra por pantalla.
 *
 * \param pArrayList LinkedList* Puntero a la lista de vuelos.
 * \return int [-1] La lista apunta a NULL, [0] Todo ok.
 *
 */
int controller_Sanchez_CountPasajeros(LinkedList* pArrayList)
{
    system("cls");
    int retorno = -1;
    int (*pFunction)(void*);
    pFunction = info_CountPasajeros;
    int totalDePasajeros;
    if(pArrayList != NULL)
    {
        totalDePasajeros = ll_count(pArrayList, pFunction);
        if(totalDePasajeros != 0)
        {
            printf("Cantidad total de pasajeros: %d", totalDePasajeros);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Cuenta la cantidad total de pasajeros a Irlanda y lo muestra por pantalla.
 *
 * \param pArrayList LinkedList* Puntero a la lista de vuelos.
 * \return int [-1] La lista apunta a NULL, [0] Todo ok.
 *
 */
int controller_Sanchez_CountPasajerosIrlanda(LinkedList* pArrayList)
{
    system("cls");
    int retorno = -1;
    int (*pFunction)(void*);
    pFunction = info_CountPasajerosIrlanda;
    int totalDePasajeros;
    if(pArrayList != NULL)
    {
        totalDePasajeros = ll_count(pArrayList, pFunction);
        if(totalDePasajeros != 0)
        {
            printf("Cantidad de pasajeros a Irlanda : %d", totalDePasajeros);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Coloca los vuelos menores a 3 horas en un nuevo Linked List y los guarda en un archivo .csv
 *
 * \param path char* Nombre del archivo nuevo
 * \param pArrayList LinkedList* Puntero al listado de vuelos
 * \return int [-1] El nombre o la lista apuntan a NULL, [0] si se creó el nuevo archivo correctamente.
 *
 */
int controller_Sanchez_FiltrarVuelosCortos(char* path, LinkedList* pArrayList)
{
    system("cls");
    int retorno = -1;
    LinkedList* auxList = ll_newLinkedList();
    int (*pFunction)(void*);
    pFunction = info_BuscarVuelosCortos;
    if(pArrayList != NULL && path != NULL)
    {
        auxList = ll_filter(pArrayList, pFunction);
        if(auxList != NULL)
        {
            if(!controller_Sanchez_guardarVuelosTXT(path,auxList))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Guarda la lista de vuelos en un archivo txt.
 *
 * \param path char* Nombre del archivo.
 * \param pArrayList LinkedList* Puntero a la lista enlazada de vuelos.
 * \return int [-1] El nombre del archivo o la linkedList apuntan a NULL, [0] Archivo creado con exito.
 *
 */
int controller_Sanchez_guardarVuelosTXT(char* path, LinkedList* pArrayList)
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

int controller_Sanchez_guardarVuelosTXTConPrecio(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    int i;
    FILE* fileP;
    int idVuelo,idAvion,idPiloto,cantPasajeros,horaDespegue,horaLlegada, precio;
    char destino[DEST_LEN], fecha[FECHA_LEN];
    Viaje* pAux;
    if(path != NULL && pArrayList != NULL)
    {
        fileP = fopen(path,"w");
        if(fileP != NULL)
        {
            retorno = 0;
            fprintf(fileP,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada, precio\n");
            for(i=0; i<ll_len(pArrayList); i++)
            {
                pAux = ll_get(pArrayList, i);
                if(pAux != NULL)
                {
                    if(!viaje_getAll(pAux, &idVuelo, &idAvion,&idPiloto,&cantPasajeros,&horaDespegue,&horaLlegada,fecha,destino)
                            && !viaje_getPrecio(pAux, &precio))
                    {
                        fprintf(fileP,"%d,%d,%d,%s,%s,%d,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada, precio);
                    }
                }
            }
            fclose(fileP);
        }
    }
    return retorno;
}

/** \brief Crea una nueva lista con los vuelos a portugal y los imprime por pantalla.
 *
 * \param pArrayList LinkedList* Puntero a la Lista de vuelos.
 * \param pArrayListPilotos LinkedList* Puntero a la lista de pilotos.
 * \return int [-1] Alguna de las listas apunta a NULL, [0] Todo ok.
 *
 */
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
                if(!ll_deleteLinkedList(auxList))
                {
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Imprime una lista de vuelos sin alex Lifeson.
 *
 * \param pArrayList LinkedList* Puntero a la lista de vuelos
 * \param pArrayListPilotos LinkedList* Puntero a la lista de Pilotos
 * \return int [-1] Alguna de las listas apunta a NULL, [0] Todo ok.
 *
 */
int controller_Sanchez_ListarVuelosSinAlexLifeson(LinkedList* pArrayList, LinkedList* pArrayListPilotos)
{
    system("cls");
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
                if(!ll_deleteLinkedList(auxList))
                {
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Se imprime el listado de pilotos, sin un determinado piloto
 *
 * \param pArrayListPilotos LinkedList* Puntero a la lista de Pilotos.
 * \return int [-1] La lista de Pilotos apunta a NULL, [0] Lista impresa con exito.
 *
 */
int Controller_Sanchez_FiltrarPilotoPorNombre(LinkedList* pArrayListPilotos)
{
    system("cls");
    int retorno = -1;
    LinkedList* auxList;
    int (*pFunction)(void*, char*);
    pFunction = info_FiltrarPilotoX;
    char auxNombre[NAME_LEN];

    if(pArrayListPilotos != NULL)
    {
        controller_Sanchez_PrintPilotos(pArrayListPilotos);
        printf("----------------------------------------------------------------------------------------------------------------");
        if(utn_getNameAndLastName(auxNombre, NAME_LEN, "\n***Ingresar nombre y apellido del piloto: ", "\nError.", 3)
                && info_checkNombrePiloto(pArrayListPilotos, auxNombre) >= 0)
        {
            printf("----------------------------------------------------------------------------------------------------------------\n**NUEVA LISTA**\n");
            auxList = ll_filter_parametro(pArrayListPilotos, pFunction, auxNombre);
            if(auxList != NULL)
            {
                if(!controller_Sanchez_PrintPilotos(auxList))
                {
                    retorno = 0;
                }
            }
        }
        else
        {
            printf("\nError, no existe el piloto ingresado.\n");
        }
    }
    return retorno;
}

int Controller_Sanchez_PreciosDeVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
    system("cls");
    int retorno = -1;
    LinkedList* auxList;
    LinkedList* auxList2;
    void* (*pFunction)(void*);
    int (*pFunction2)(void*);
    pFunction = info_SetPrecioDeVuelos;
    pFunction2 = info_BuscarVuelosPortugal;
    if(pArrayListVuelos != NULL)
    {
        auxList = ll_map(pArrayListVuelos, pFunction);
        if(auxList != NULL)
        {
            auxList2 = ll_filter(auxList, pFunction2);
            if(auxList2 != NULL
                    && !controller_Sanchez_PrintVuelosConPrecio(auxList2, pArrayListPilotos)
                    && !controller_Sanchez_guardarVuelosTXTConPrecio("VuelosConPrecio.csv", auxList2))
            {
                retorno = 0;
            }
        }

    }
    return retorno;
}
