#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "genericas.h"
int main()
{
    /**
    *Sacar el validar por Id de los parsers porque ya no necesito dar de alta manual
    *Validar opciones para se pueda acceder a ellas solamente si se entro a la opcion 1
    */
    int option;
    LinkedList* listaViajes = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();
    int lastId = 0;
    do
    {
        if(gen_mainMenu(&option))
        {
            switch(option)
            {
            case 1:
                lastId = controller_Sanchez_loadVuelosFromText("Vuelos.csv", listaViajes);
                if(lastId != -1 && controller_Sanchez_loadPilotosFromText("pilotos.csv", listaPilotos) > 0)
                {
                    printf("cargado con exito");
                }
                break;
            case 2:
                if(!controller_Sanchez_PrintVuelos(listaViajes, listaPilotos))
                {
                    printf("mostrado mostro");
                }
                break;
            case 3:
                if(!controller_Sanchez_CountPasajeros(listaViajes))
                {
                    printf("\nMostrado mostro");
                }
                break;
            case 4:
                if(!controller_Sanchez_CountPasajerosIrlanda(listaViajes))
                {
                    printf("\nMostrado mostro");
                }
                break;
            case 5:
                if(!controller_Sanchez_FiltrarVuelosCortos("VuelosCortos.csv", listaViajes))
                {
                    printf("Csv Creado con exito");
                }
                break;
            case 6:
                if(!controller_Sanchez_ListarVuelosPortugal(listaViajes, listaPilotos))
                {
                    printf("mostrado!");
                }
                break;
            case 7:
                if(!controller_Sanchez_ListarVuelosSinAlexLifeson(listaViajes, listaPilotos))
                {
                    printf(" Impreso ! ");
                }
                break;
            case 8:
                if(!Controller_Sanchez_FiltrarPilotoPorNombre(listaPilotos))
                {
                    printf("Impreso !");
                }
                break;
            }
        }
        system("pause");
    }
    while(option != 9);
    return 0;
}
