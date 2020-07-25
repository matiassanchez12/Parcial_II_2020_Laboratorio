

#include "utn.h"
///****************************************************///
static int getString(char* str, int longitud);
///FUNCIONES QUE TOMAN UN DATO Y LO VALIDAN
static int get_ValidInt(int* pResult);
static int get_ValidFloat(float* pResult);
static int get_ValidString(char* pResult, int len);
static int get_ValidChar(char* pResult);
static int get_ValidAlphanumeric(char* pResult, int len);
static int get_ValidNameAndLastName(char* pResult, int len);
static int get_ValidTelephone(char* pResult, int len);
static int get_ValidDni(int* pResult);
static int get_ValidEmail(char* pResult, int len);
static int get_ValidCuit(char* pResult, int len);
static int get_ValidDireccion(char* pResult, int len);
///FUNCIONES QUE VALIDAN
static int isNumber(char* str);
static int isNumberFloat(char* str);
static int isString(char* str);
static int isAlphaNumeric(char* str);
static int isNameAndLastName(char* str);
static int isDireccion(char* str);
static int isTelephone(char* str);
static int isEmail(char* str);
static int isCuit(char* str);


/** \brief Lee de stdin hasta que haya copiado en el buffer la cantidad de caracteres que se indica en longitud -1.
 *
 * \param str char* Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud int Tamaño de la cadena
 * \return int Retorna 1 si se obtuvo la cadena o 0 Error.
 *
 */
static int getString(char* str, int longitud) /// SCANF
{
    int ret = 0; ///ERROR
    char bufferString[4000];
    if(str != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString),stdin) != NULL && bufferString[0] != '\n')
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            strncpy(str, bufferString, longitud);
            ret  = 1;
        }
    }
    return ret;
}
/** \brief Obtiene una cadena y verifica si el dato es una cadena y si tiene el tamaño correcto.
 *
 * \param pResult char* Un puntero con una cadena de caracteres.
 * \param len int Tamaño maximo de la variable cadena.
 * \return int retorna 0 si hay un error y 1 si se obtuvo la cadena con exito.
 *
 */
static int get_ValidString(char* pResult, int len) ///TOMAR ORACION
{
    int ret = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isString(aux) && strlen(aux)<len)
        {
            strcpy(pResult, aux);
            ret = 1;
        }
    }
    return ret;
}
/** \brief Toma un numero flotante y verifica si es flotante.
 *
 * \param pResult float* Puntero a un numero flotante.
 * \return int 0 si hay un error y 1 si se obtuvo el numero con exito.
 *
 */
static int get_ValidFloat(float* pResult) ///TOMA FLOAT
{
    int ret = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isNumberFloat(aux) != 0)
    {
        *pResult = atof(aux);
        ret = 1;
    }
    return ret;
}
/** \brief Toma un numero entero y verifica si es entero.
 *
 * \param pResult float* Puntero a un numero entero.
 * \return int 0 si hay un error y 1 si se obtuvo el numero con exito.
 *
 */
static int get_ValidInt(int* pResult) ///TOMA INT
{
    int ret = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isNumber(aux))
    {
        *pResult = atoi(aux);
        ret = 1;
    }
    return ret;
}
/** \brief Toma un letra y verifica si es una letra.
 *
 * \param pResult float* Puntero a una letra.
 * \return int 0 si hay un error y 1 si se obtuvo la letra con exito.
 *
 */
static int get_ValidChar(char* pResult) ///TOMA CHAR
{
    int ret = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isString(aux))
    {
        if(strlen(aux) == 1)
        {
            *pResult = aux[0];
            ret = 1;
        }
    }
    return ret;
}
/** \brief Obtiene una cadena y verifica si el dato es alphanumerico y si tiene el tamaño correcto.
 *
 * \param pResult char* Un puntero a una cadena de caracteres.
 * \param len int Tamaño maximo de la variable cadena.
 * \return int retorna 0 si hay un error y 1 si se obtuvo la cadena con exito.
 *
 */
static int get_ValidAlphanumeric(char* pResult, int len)
{
    int ret = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isAlphaNumeric(aux) && strlen(aux)<len)
        {
            strcpy(pResult, aux);
            ret = 1;
        }
    }
    return ret;
}
/** \brief Obtiene una cadena y verifica si el dato es alphanumerico y si tiene el tamaño correcto.
 *
 * \param pResult char* Un puntero a una cadena de caracteres.
 * \param len int Tamaño maximo de la variable cadena.
 * \return int retorna 0 si hay un error y 1 si se obtuvo la cadena con exito.
 *
 */
static int get_ValidNameAndLastName(char* pResult, int len)
{
    int ret = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isNameAndLastName(aux) && strlen(aux)<len)
        {
            strcpy(pResult, aux);
            ret = 1;
        }
    }
    return ret;
}
/** \brief Obtiene una cadena y verifica si el dato es una direccion y si tiene el tamaño correcto.
 *
 * \param pResult char* Un puntero a una cadena de caracteres.
 * \param len int Tamaño maximo de la variable cadena.
 * \return int retorna 0 si hay un error y 1 si se obtuvo la cadena con exito.
 *
 */
static int get_ValidDireccion(char* pResult, int len)
{
    int ret = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isDireccion(aux) && strlen(aux)<len)
        {
            strcpy(pResult, aux);
            ret = 1;
        }
    }
    return ret;
}
/** \brief Obtiene una cadena y verifica si el dato es un telefono y si tiene el tamaño correcto.
 *
 * \param pResult char* Un puntero a una cadena de caracteres.
 * \param len int Tamaño maximo de la variable cadena.
 * \return int retorna 0 si hay un error y 1 si se obtuvo la cadena con exito.
 *
 */
static int get_ValidTelephone(char* pResult, int len)
{
    int ret = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isTelephone(aux) && strlen(aux)<len)
        {
            strcpy(pResult, aux);
            ret = 1;
        }
    }
    return ret;
}
/** \brief Obtiene un numero entero y verifica si el dato es un dni.
 *
 * \param pResult char* Un puntero a un numero entero.
 * \return int retorna 0 si hay un error y 1 si se obtuvo el entero con exito.
 *
 */
static int get_ValidDni(int* pResult)
{
    int ret = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isNumber(aux))
    {
        *pResult = atoi(aux);
        ret = 1;
    }
    return ret;
}
/** \brief Obtiene una cadena y verifica si el dato es un email y si tiene el tamaño correcto.
 *
 * \param pResult char* Un puntero a una cadena de caracteres.
 * \param len int Tamaño maximo de la variable cadena.
 * \return int retorna 0 si hay un error y 1 si se obtuvo la cadena con exito.
 *
 */
static int get_ValidEmail(char* pResult, int len)
{
    int ret = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isEmail(aux) && strlen(aux)<len)
        {
            strcpy(pResult, aux);
            ret = 1;
        }
    }
    return ret;
}
/** \brief Obtiene una cadena y verifica si el dato es un cuit y si tiene el tamaño correcto.
 *
 * \param pResult char* Un puntero a una cadena de caracteres.
 * \param len int Tamaño maximo de la variable cadena.
 * \return int retorna 0 si hay un error y 1 si se obtuvo la cadena con exito.
 *
 */
static int get_ValidCuit(char* pResult, int len)
{
    int ret = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isCuit(aux) && strlen(aux)<len)
        {
            strcpy(pResult, aux);
            ret = 1;
        }
    }
    return ret;
}

/** \brief Verifica si la cadena es solo numeros
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es solo numeros, caso contrario 0
 *
 */
static int isNumber(char* str) ///VERIFICA SI ES SOLO NUMEROS, SINO DEVUELVE 0
{
    int ret = 1;
    int i = 0;
    while(str[i] != '\0')
    {
        if(i == 0 && (str[i] == '+' || str[i] == '-'))
        {
            i++;
            continue;
        }
        if(str[i] > '9' || str[i] < '0')
        {
            ret = 0;///ERROR TERMINA BUCLE
            break;
        }
        i++;
    }
    return ret; ///TODOS NUMEROS : OK
}
/** \brief Verifica si la cadena es solo numeros flotantes
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es un flotante, caso contrario 0
 *
 */
static int isNumberFloat(char* str)
{
    int ret = 1;
    int i = 0;
    if(str[0] == '-')
    {
        i = 1;
    }
    while(str[i] != '\0')
    {
        if (str[i] == '.')
        {
            i++;
            continue;
        }
        if(str[i] < '0' || str[i] > '9')
        {
            ret = 0;
            break;
        }
        i++;
    }
    return ret;
}
/** \brief Verifica si la cadena es solo letras
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es solo de letras, caso contrario 0
 *
 */
static int isString(char* str)
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    return ret;
}
/** \brief Verifica si la cadena es un alfanumerico
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es un alfanumerico, caso contrario 0
 *
 */
static int isAlphaNumeric(char* str)
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '1' || str[i] > '9'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    return ret; ///TODO OK
}

/** \brief Verifica si la cadena es un nombre y un apellido
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es un alfanumerico, caso contrario 0
 *
 */
static int isNameAndLastName(char* str)
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
    return ret; ///TODO OK
}
/** \brief Verifica si la cadena es una direccion
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es una direccion, caso contrario 0
 *
 */
static int isDireccion(char* str)
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '1' || str[i] > '9'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    return ret;
}
/** \brief Verifica si la cadena es un telefono
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es un telefono, caso contrario 0
 *
 */
static int isTelephone(char* str)
{
    int ret = 1;
    int i=0;
    int count = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '-')
        {
        count ++;
        }
        if((str[i] != '-') && (str[i] > '9' || str[i] < '0'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    if(count != 1)
    {
        ret = 0;
    }
    return ret;
}
/** \brief Verifica si la cadena es un email
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es un email, caso contrario 0
 *
 */
static int isEmail(char* str)
{
    int ret = 1;
    int i=0;
    int count = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '@' || str[i] == '.')
        {
        count ++;
        }
        if((str[i] != '@') && (str[i] != '.') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '1' || str[i] > '9'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    if(count != 2)
    {
        ret = 0;
    }
    return ret;
}
/** \brief Verifica si la cadena es un cuit
 *
 * \param str char* Un puntero a una cadena de caracteres
 * \return int 1 la cadena es un cuit, caso contrario 0
 *
 */
static int isCuit(char* str)
{
    int ret = 1;
    int i=0;
    int count = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '-')
        {
        count ++;
        }
        if((str[i] != '-') && (str[i] < '1' || str[i] > '9'))
        {
            ret = 0;
            break;
        }
        i++;
    }
    if(count != 2)
    {
        ret = 0;
    }
    return ret;
}

/** \brief  Solicita un numero, y se verifica si lo es, caso positivo lo devuelve como resultado
 *
 * \param pResult int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param msg char* Mensaje que se mostrara al usuario para pedir el numero
 * \param msgError char* Mensaje de error en caso de que no sea un numero
 * \param min int Tamaño minimo que puede tener el numero
 * \param max int Tamaño maximo que puede tener el numero
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar numeros
 * \return int 1 se obtuvo el numero, caso contrario 0
 *
 */
int utn_getNumber(int* pResult, char* msg,char* msgError, int min, int max, int attemps)
{
    int ret = 0;
    int aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && min <= max && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidInt(&aux) && aux <= max && aux >= min)
            {
                *pResult = aux;
                ret  = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita un numero flotante, y se verifica si lo es, caso positivo lo devuelve como resultado
 *
 * \param pResult int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param msg char* Mensaje que se mostrara al usuario para pedir el numero
 * \param msgError char* Mensaje de error en caso de que no sea un numero
 * \param min int Tamaño minimo que puede tener el numero
 * \param max int Tamaño maximo que puede tener el numero
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar numeros
 * \return int 1 se obtuvo el numero, caso contrario 0
 *
 */
int utn_getNumberFloat(float* pResult,char* msg,char* msgError,float min, float max, int attemps)
{
    int ret = 0;
    float aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && min <= max && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidFloat(&aux) && aux <= max && aux >= min)
            {
                *pResult = aux;
                ret  = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una letra, y se verifica si lo es, caso positivo lo devuelve como resultado
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param msg char* Mensaje que se mostrara al usuario para pedir la letra
 * \param msgError char* Mensaje de error en caso de que no sea una letra
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar una letra
 * \return int 1 se obtuvo la letra, caso contrario 0
 *
 */
int utn_getChar(char* pResult, char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidChar(&aux))
            {
                *pResult = aux;
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si lo es, caso positivo la devuelve como resultado
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param lenght int Tamaño maximo de la palabra
 * \param msg char* Mensaje que se mostrara al usuario para pedir la palabra
 * \param msgError char* Mensaje de error en caso de que no sea una palabra
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar una palabra
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0
 *
 */
int utn_getString(char* pResult, int lenght, char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidString(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una letra, y se verifica entre unicamente 2 letras si es alguna de ellas
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param msg char* Mensaje que se mostrara al usuario para pedir la letra
 * \param msgError char* Mensaje de error en caso de que no sea una letra
 * \param charOne char letra1 que verifica la igualdad
 * \param charTwo char letra2 que verifica la igualdad
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar la letra correcta
 * \return int 1 se obtuvo la letra con exito, caso contrario 0
 *
 */
int utn_getOnlyTwoChars(char* pResult, char* msg, char* msgError, char charOne, char charTwo, int attemps)
{
    int ret = 0;
    char aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidChar(&aux)&& (aux == charOne || aux == charTwo))
            {
                *pResult = aux;
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si es un alfanumerico, caso positivo la devuelve como resultado.
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param lenght int Tamaño maximo de la palabra.
 * \param msg char* Mensaje que se mostrara al usuario para pedir la alfanumerico.
 * \param msgError char* Mensaje de error en caso de que no sea un alfanumerico.
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar un alfanumerico.
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0.
 *
 */
int utn_getAlphanumeric(char* pResult,int lenght, char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidAlphanumeric(aux, sizeof(aux))  &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si es un nombre y un apellido, caso positivo retorna la misma.
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param lenght int Tamaño maximo de la palabra.
 * \param msg char* Mensaje que se mostrara al usuario para pedir la alfanumerico.
 * \param msgError char* Mensaje de error en caso de que no sea un alfanumerico.
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar un alfanumerico.
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0.
 *
 */
int utn_getNameAndLastName(char* pResult,int lenght, char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidNameAndLastName(aux, sizeof(aux))  &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si es una direccion, caso positivo la devuelve como resultado.
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param lenght int Tamaño maximo de la palabra.
 * \param msg char* Mensaje que se mostrara al usuario para pedir la direccion.
 * \param msgError char* Mensaje de error en caso de que no sea una direccion.
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar una direccion.
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0.
 *
 */
int utn_getDireccion(char* pResult,int lenght,char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidDireccion(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si es un telefono, caso positivo la devuelve como resultado.
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param lenght int Tamaño maximo de la palabra.
 * \param msg char* Mensaje que se mostrara al usuario para pedir el telefono.
 * \param msgError char* Mensaje de error en caso de que no sea un telefono.
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar un telefono.
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0.
 *
 */
int utn_getTelephone(char* pResult,int lenght,char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidTelephone(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si es un dni, caso positivo la devuelve como resultado.
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param lenght int Tamaño maximo de la palabra.
 * \param msg char* Mensaje que se mostrara al usuario para pedir el dni.
 * \param msgError char* Mensaje de error en caso de que no sea un dni.
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar un dni.
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0.
 *
 */
int utn_getDni(int* pResult, char* msg,char* msgError, int min, int max, int attemps)
{
    int ret = 0;
    int aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && min <= max && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidDni(&aux) && aux <= max && aux >= min )
            {
                *pResult = aux;
                ret  = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si es un email, caso positivo la devuelve como resultado.
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param lenght int Tamaño maximo de la palabra.
 * \param msg char* Mensaje que se mostrara al usuario para pedir el email.
 * \param msgError char* Mensaje de error en caso de que no sea un email.
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar un email.
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0.
 *
 */
int utn_getEmail(char* pResult,int lenght,char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidEmail(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
/** \brief Solicita una palabra, y se verifica si es un cuit, caso positivo la devuelve como resultado.
 *
 * \param pResult char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param lenght int Tamaño maximo de la palabra.
 * \param msg char* Mensaje que se mostrara al usuario para pedir el cuit.
 * \param msgError char* Mensaje de error en caso de que no sea un cuit.
 * \param attemps int Intentos que se le da al usuario en caso de no ingresar un cuit.
 * \return int 1 se obtuvo la palabra con exito, caso contrario 0.
 *
 */
int utn_getCuit(char* pResult,int lenght, char* msg,char* msgError, int attemps)
{
    int ret = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidCuit(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                ret = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return ret;
}
