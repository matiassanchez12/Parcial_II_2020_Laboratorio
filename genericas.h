#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int gen_mainMenu(int* option);
void gen_checkReturnWithSwitch(int function, char* msgAllRight, char* msgCancelOp, char* msgError);
void gen_checkReturnWithIf(int function, char* msgAllRight, char* msgError);
int gen_checkLengthLinkedList(int lengthLl);
void gen_checkCorrectLoadedOfEmployees(int loadOk, char* msgAllRight);
void gen_checkCorrectAdd(int addOk);
