#include "piloto.h"

static int isString(char* str);
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

int piloto_delete(ePiloto* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

ePiloto* piloto_new(void)
{
    return (ePiloto*) malloc(sizeof(ePiloto));
}

ePiloto* piloto_newParameters(int idPiloto, char* nombrePiloto)
{
    ePiloto* pAuxPiloto = piloto_new();
    if(pAuxPiloto != NULL && nombrePiloto != NULL)
    {
        if(piloto_setIdPiloto(pAuxPiloto, idPiloto)== -1 ||
                piloto_setNombrePiloto(pAuxPiloto, nombrePiloto)== -1)
        {
            if(!piloto_delete(pAuxPiloto))
            {
                pAuxPiloto = NULL;
            }
        }
    }
    return pAuxPiloto;
}

int piloto_printPiloto(ePiloto* this)
{
    int retorno = -1;
    int idPiloto;
    char nombrePiloto[NAME_LEN];
    if(this != NULL)
    {
        if(!piloto_getIdPiloto(this, &idPiloto) && !piloto_getNombrePiloto(this, nombrePiloto))
        {
            retorno = 0;
            printf("\n%2d\t%15s", idPiloto, nombrePiloto);
        }
    }
    return retorno;
}

int piloto_setIdPiloto(ePiloto* this,int idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto >= 0)
    {
        retorno = 0;
        this->idPiloto = idPiloto;
    }
    return retorno;
}
int piloto_getIdPiloto(ePiloto* this,int* idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto != NULL)
    {
        retorno = 0;
        *idPiloto = this->idPiloto;
    }
    return retorno;
}
int piloto_setNombrePiloto(ePiloto* this,char* nombrePiloto)
{
    int retorno = -1;
    if(this != NULL && nombrePiloto != NULL)
    {
        if(isString(nombrePiloto))
        {
            retorno = 0;
            strcpy(this->nombrePiloto,nombrePiloto);
        }
    }
    return retorno;
}
int piloto_getNombrePiloto(ePiloto* this,char* nombrePiloto)
{
    int retorno = -1;
    if(this != NULL && nombrePiloto != NULL)
    {
        retorno = 0;
        strcpy(nombrePiloto,this->nombrePiloto);
    }
    return retorno;
}
