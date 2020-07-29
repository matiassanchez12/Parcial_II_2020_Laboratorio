#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "genericas.h"
int main()
{
    int option;
    LinkedList* listaViajes = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();
    int flag  = 0;
    do
    {
        if(gen_mainMenu(&option))
        {
            switch(option)
            {
            case 1:
                if(!controller_Sanchez_loadVuelosFromText("Vuelos.csv", listaViajes)
                        && !controller_Sanchez_loadPilotosFromText("pilotos.csv", listaPilotos))
                {
                    printf("\nTxt de vuelos y txt de pilotos cargados.\n");
                    flag = 1;
                }
                break;
            case 2:
                if(flag == 0 || controller_Sanchez_PrintVuelos(listaViajes, listaPilotos) == -1 )
                {
                    printf("\nOcurrio un error. Cargue el Archivo txt desde la opcion 1.\n");
                }
                break;
            case 3:
                if(flag == 0 || controller_Sanchez_CountPasajeros(listaViajes) == -1)
                {
                    printf("\nOcurrio un error. Cargue el Archivo txt desde la opcion 1.\n");
                }
                break;
            case 4:
                if(flag == 0 || controller_Sanchez_CountPasajerosIrlanda(listaViajes) == -1)
                {
                    printf("\nOcurrio un error. Cargue el Archivo txt desde la opcion 1.\n");
                }
                break;
            case 5:
                if(flag == 0 || controller_Sanchez_FiltrarVuelosCortos("VuelosCortos.csv", listaViajes) == -1)
                {
                    printf("\nOcurrio un error. Cargue el Archivo txt desde la opcion 1.\n");
                }
                else
                {
                    printf("\n Csv con nombre: 'VuelosCortos.csv' fue creado con exito \n");
                }
                break;
            case 6:
                if(flag == 0 || controller_Sanchez_ListarVuelosPortugal(listaViajes, listaPilotos) == -1)
                {
                    printf("\nOcurrio un error. Cargue el Archivo txt desde la opcion 1.\n");
                }
                break;
            case 7:
                if(flag == 0 || controller_Sanchez_ListarVuelosSinAlexLifeson(listaViajes, listaPilotos) == -1)
                {
                   printf("\nOcurrio un error. Cargue el Archivo txt desde la opcion 1.\n");
                }
                break;
            case 8:
                if(flag == 0 || Controller_Sanchez_FiltrarPilotoPorNombre(listaPilotos) == -1)
                {
                    printf("\nOcurrio un error. Cargue el Archivo txt desde la opcion 1.\n");
                }
                break;
            case 9:
                if(!Controller_Sanchez_PreciosDeVuelos(listaViajes, listaPilotos))
                {
                    printf("\n\nTxt cargado con exito!\n\n");
                }
            }
        }
        printf("\n\n");
    }
    while(option != 10);
    return 0;
}
