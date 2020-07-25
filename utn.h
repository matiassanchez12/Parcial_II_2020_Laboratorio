
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///GETS PARA LLAMAR FUERA DE BIBLIO UTN
int utn_getNumber(int* pResult, char* msg,char* msgError, int min, int max, int attemps);
int utn_getNumberFloat(float* pResult,char* msg,char* msgError,float min, float max, int attemps);
int utn_getString(char* pResult,int lenght, char* msg,char* msgError, int attemps);
int utn_getChar(char* pResult, char* msg,char* msgError, int attemps);
int utn_getOnlyTwoChars(char* pResult, char* msg, char* msgError, char charOne, char charTwo, int attemps);
int utn_getAlphanumeric(char* pResult,int lenght, char* msg,char* msgError, int attemps);
int utn_getTelephone(char* pResult,int lenght, char* msg,char* msgError, int attemps);
int utn_getDni(int* pResult, char* msg,char* msgError, int min, int max, int attemps);
int utn_getEmail(char* pResult,int lenght, char* msg,char* msgError, int attemps);
int utn_getCuit(char* pResult,int lenght, char* msg,char* msgError, int attemps);
int utn_getDireccion(char* pResult,int lenght, char* msg,char* msgError, int attemps);
int utn_getNameAndLastName(char* pResult,int lenght, char* msg,char* msgError, int attemps);
