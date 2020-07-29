#include "parser.h"

/** \brief Toma uno a uno los datos de los Vuelos
 *
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayList LinkedList* Puntero a la lista enlazada
 * \return int [-1] si puntero a archivo o puntero a la lista son NULL,[0] caso contrario
 *
 */
int parser_FromTextViajes(FILE* pFile, LinkedList* pArrayList)
{
    int retorno = -1;
    Viaje* pAuxViaje;
    char idVuelo[500], idAvion[500], idPiloto[500], fecha[500], destino[500], cantPasajeros[500];
    char horaDespegue[500], horaLlegada[500];
    if(pFile!=NULL && pArrayList!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada)==8)
            {
                pAuxViaje =  viaje_newParameters(atoi(idVuelo), atoi(idAvion), atoi(idPiloto), fecha, destino, atoi(cantPasajeros), atoi(horaDespegue), atoi(horaLlegada));

                if(pAuxViaje != NULL)
                {
                    if(!ll_add(pArrayList, pAuxViaje))
                    {
                        retorno = 0;
                    }
                }
            }
            else
            {
                break;
            }
        }
        while(feof(pFile)==0);

        fclose(pFile);
    }
    return retorno;
}
/** \brief Toma uno a uno los datos de los Pilotos
 *
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayList LinkedList* Puntero a la lista enlazada
 * \return int [-1] si puntero a archivo o puntero a la lista son NULL,[0] caso contrario
 *
 */
int parser_FromTextPilotos(FILE* pFile, LinkedList* pArrayList)
{
    int retorno = -1;
    ePiloto* pAuxPiloto;
    char idPiloto[500];
    char nombrePiloto[500];
    if(pFile!=NULL && pArrayList!=NULL)
    {
        fscanf(pFile, "%[^,],%[^\n]\n",idPiloto, nombrePiloto);
        do
        {
            if(fscanf(pFile, "%[^,],%[^\n]\n",idPiloto, nombrePiloto)==2)
            {
                pAuxPiloto =  piloto_newParameters(atoi(idPiloto), nombrePiloto);

                if(pAuxPiloto != NULL)
                {
                    if(!ll_add(pArrayList, pAuxPiloto))
                    {
                        retorno = 0;
                    }
                }
            }
            else
            {
                break;
            }
        }
        while(feof(pFile)==0);

        fclose(pFile);
    }
    return retorno;
}
