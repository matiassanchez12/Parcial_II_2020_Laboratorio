#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

int controller_Sanchez_loadVuelosFromText(char* path, LinkedList* pArrayList);
int controller_Sanchez_loadPilotosFromText(char* path, LinkedList* pArrayList);

int controller_Sanchez_PrintVuelos(LinkedList* pArrayList, LinkedList* pArrayListPiloto);
int controller_Sanchez_PrintPilotos(LinkedList* pArrayListEmployee);

int controller_Sanchez_CountPasajeros(LinkedList* pArrayList);
int controller_Sanchez_CountPasajerosIrlanda(LinkedList* pArrayList);

int controller_Sanchez_FiltrarVuelosCortos(char* path, LinkedList* pArrayList);
int controller_Sanchez_guardarVuelosCortosComoTexto(char* path, LinkedList* pArrayList);

int Controller_Sanchez_FiltrarPilotoPorNombre(LinkedList* pArrayListPilotos);
int controller_Sanchez_ListarVuelosPortugal(LinkedList* pArrayList, LinkedList* pArrayListPilotos);
int controller_Sanchez_ListarVuelosSinAlexLifeson(LinkedList* pArrayList, LinkedList* pArrayListPilotos);

