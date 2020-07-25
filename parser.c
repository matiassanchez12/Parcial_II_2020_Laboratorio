#include "parser.h"

/** \brief Toma uno a uno los datos de los empleados
 *
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayList LinkedList* Puntero a la lista enlazada
 * \return int [-1] si puntero a archivo o puntero a la lista son NULL, caso contrario retorna el ultimo ID
 *
 */
int parser_FromTextViajes(FILE* pFile, LinkedList* pArrayList)
{
    int retorno = -1;
    Viaje* pAuxViaje;
    char bufferScanner[7][500];
    if(pFile!=NULL && pArrayList!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferScanner[0], bufferScanner[1], bufferScanner[2], bufferScanner[3], bufferScanner[4], bufferScanner[5], bufferScanner[6], bufferScanner[7]);
        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferScanner[0], bufferScanner[1], bufferScanner[2], bufferScanner[3], bufferScanner[4], bufferScanner[5], bufferScanner[6], bufferScanner[7])==8)
            {
                pAuxViaje =  viaje_newParameters(atoi(bufferScanner[0]), atoi(bufferScanner[1]), atoi(bufferScanner[2]), bufferScanner[3],  bufferScanner[4], atoi(bufferScanner[5]), atoi(bufferScanner[6]), atoi(bufferScanner[7]));

                if(pAuxViaje != NULL)
                {
                    if(!ll_add(pArrayList, pAuxViaje))
                    {
                        retorno = atoi(bufferScanner[0]);
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
                        retorno = atoi(idPiloto);
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


/** \brief Toma uno a uno los datos de los empleados
 *
 * \param pFile FILE* Puntero a un archivo
 * \param pArrayList LinkedList* Puntero a la lista enlazada
 * \return int [-1] si puntero a archivo o puntero a la lista son NULL, caso contrario retorna el ultimo ID
 *
 */
int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int retorno=-1;
    Viaje* pAuxViaje;
    int lastId;
    if(pArrayList != NULL && pFile != NULL)
    {
        do
        {
            pAuxViaje = viaje_new();
            if(fread(pAuxViaje,sizeof(Viaje),1, pFile) == 1)
            {
                if(pAuxViaje != NULL)
                {
                    if(!ll_add(pArrayList, pAuxViaje))
                    {
                        lastId = pAuxViaje->idVuelo;
                        retorno = lastId;
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

