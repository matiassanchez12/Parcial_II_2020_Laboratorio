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

/** \brief Elimina un elemento de la entidad piloto
 *
 * \param this ePiloto* Puntero a un elemento
 * \return int [-1]El elemento es NULL, [0] Elemento eliminado con exito.
 *
 */
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

/** \brief Crea un espacio de memoria con el tamaño de la entidad epiloto
 *
 * \return ePiloto* Un puntero al espacio de memoria creado
 *
 */
ePiloto* piloto_new(void)
{
    return (ePiloto*) malloc(sizeof(ePiloto));
}

/** \brief Crea un espacio de memoria con el tamaño de la entidad epiloto pero con sus campos inicializados
 *
 * \param idPiloto int Id del piloto del elemento.
 * \param nombrePiloto char* Nombre del piloto del elemento.
 * \return ePiloto* Un puntero al espacio de memoria creado
 *
 */
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

/** \brief Imprime un elemento del tipo ePiloto
 *
 * \param this ePiloto* Puntero a un elemento
 * \return int [-1]This es NULL, [0] Se imprimio con exito
 *
 */
int piloto_printPiloto(ePiloto* this)
{
    int retorno = -1;
    int idPiloto;
    char nombrePiloto[NAME_LEN];
    if(this != NULL)
    {
        if(!piloto_getAll(this, &idPiloto, nombrePiloto))
        {
            retorno = 0;
            printf(" |  %2d\t       |%15s |\n", idPiloto, nombrePiloto);
        }
    }
    return retorno;
}

/** \brief Toma todos los los campos de un elemento
 *
 * \param this ePiloto* Puntero a un elemento
 * \param idPiloto int* Puntero a una variable int donde guardar el id
 * \param nombrePiloto char* Puntero a una variable string donde guardar el nombre
 * \return int [-1] This o idPiloto o nombrePiloto son NULL, [0] todo ok.
 *
 */
int piloto_getAll(ePiloto* this, int* idPiloto, char* nombrePiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto != NULL && nombrePiloto != NULL)
    {
        if(!piloto_getIdPiloto(this, idPiloto) && !piloto_getNombrePiloto(this, nombrePiloto))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Asigna al campo idPiloto un valor
 *
 * \param this ePiloto* Puntero a un elemento de tipo epiloto
 * \param idPiloto int Un valor de tipo int que sera el idPiloto
 * \return int [-1] This es NULL o idPiloto >= 0 [0] todo ok.
 *
 */
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
/** \brief Obtiene el valor del campo idPiloto
 *
 * \param this ePiloto*  Puntero a un elemento de tipo epiloto
 * \param idPiloto int* Puntero a una variable int
 * \return int [-1] This es NULL o idPiloto es NULL [0] todo ok.
 *
 */
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
/** \brief Asigna al campo nombrePiloto un valor
 *
 * \param this ePiloto* Puntero a un elemento de tipo epiloto
 * \param nombrePiloto char* Puntero al nombre del piloto
 * \return int [-1] This es NULL o nombrePiloto es NULL [0] todo ok.
 *
 */
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
/** \brief Obtiene el valor del campo nombrePiloto
 *
 * \param this ePiloto* Puntero a un elemento de tipo epiloto
 * \param nombrePiloto char* Puntero al nombre del piloto
 * \return int [-1] This es NULL o nombrePiloto es NULL [0] todo ok.
 *
 */
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
