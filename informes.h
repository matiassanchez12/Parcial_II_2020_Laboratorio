#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int info_CountPasajeros(void* pElement);

int info_CountPasajerosIrlanda(void* pElement);

int info_BuscarVuelosCortos(void* pElement);

int info_BuscarVuelosPortugal(void* pElement);

int info_BuscarVuelosDeAlexLifeson(void* pElement);

int info_FiltrarPilotoX(void* pElement, char* auxNombre);

int info_getNombrePorId(LinkedList* pArrayListPiloto, int idPiloto, char* auxNombre);

int info_checkNombrePiloto(LinkedList* pArrayListPiloto, char* auxNombre);

void* info_SetPrecioDeVuelos(void* element);
