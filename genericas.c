
#include "genericas.h"

/** \brief Imprime el menu principal del programa
 *
 * \param option int* Puntero donde se guardara la opcion elegida
 * \return int Devuelve [1] opcion tomada con exito, caso contrario [0].
 *
 */
int gen_mainMenu(int* option)
{
    int retorno = 0;
    if(option != NULL)
    {
        printf(">> Bienvenido al menu principal <<\n");
        printf("\n1. Cargar archivo");
        printf("\n2. Imprimir vuelos");
        printf("\n3. Cantidad de pasajeros");
        printf("\n4. Cantidad de pasajeros a Irlanda");
        printf("\n5. Filtrar vuelos cortos");
        printf("\n6. Listar vuelos a Portugal");
        printf("\n7. Filtrar a Alex Lifeson");
        printf("\n8. Filtrar la lista de pilotos por nombre");
        printf("\n9. Salir");

        if(utn_getNumber(option, "\n\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 10, 2))
        {
            retorno = 1;
        }
        else
        {
            printf("\n\nERROR: Intentos agotados, el programa se cerrara..\n");
            *option = 10;
        }
    }
    return retorno;
}

/** \brief Verifica el valor que retorna una funcion y imprime un mensaje por pantalla
 *
 * \param function int funcion a verificar
 * \param msgAllRight char* Mensaje de exito (1)
 * \param msgError char* Mensaje de Error (0)
 * \return void
 *
 */
void gen_checkReturnWithIf(int function, char* msgAllRight, char* msgError)
{
        if(!function)
        {
            printf("%s", msgAllRight);
        }
        else
        {
            printf("%s", msgError);
        }
}

/** \brief Verifica el valor de addOk en base a eso imprime un mensaje
 *
 * \param addOk int Valor a evaluar
 * \return void
 *
 */
void gen_checkCorrectAdd(int addOk)
{
  if(addOk > 0)
  {
       printf("\t-----------------------------\n\t|Empleado cargado con exito!|\n\t-----------------------------\n\n");
  }
  else
  {
      printf("\n- Error!: Intentos agotados. Volviendo al menu principal..\n\n");
  }
}

/** \brief Verifica el tamaño de la lista en base a eso imprime un mensaje
 *
 * \param lengthLl int Tamaño de la lista
 * \return int [0] Si la lista tiene un tamaño menor a 0, [1] Hay datos en la lista
 *
 */
int gen_checkLengthLinkedList(int lengthLl)
{
    int retorno = 0;
    if(lengthLl > 0)
    {
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("  ------------ \n  | Atencion!|\n  ------------");
        printf("\n* No se cargo la lista de empleados.\n* Para cargar la lista seleccione las opciones [1] para cargar modo TXT, [2] para cargar modo BIN o [3] para carga MANUAL, del menu principal.\n\n");
    }
    return retorno;
}

/** \brief Verifica si la lista fue cargada
 *
 * \param loadOk int Valor que indica si el listado fue cargado
 * \param msgAllRight char* Mensaje a mostrar en caso de que el listado sea cargado exitosamente
 * \return void
 *
 */
void gen_checkCorrectLoadedOfEmployees(int loadOk, char* msgAllRight)
{
    if(loadOk > 0)
    {
        printf("%s", msgAllRight);
    }
    else
    {
        system("cls");
        printf("  ------------ \n  | Atencion!|\n  ------------");
        printf("\n* No se encontro el archivo solicitado.\n* Ingresar el nombre correcto de un archivo valido.\n\n");
    }
}
/** \brief Verifica el valor que retorna una funcion y imprime un mensaje por pantalla
 *
 * \param function int funcion a verificar su retorno
 * \param msgAllRight char* Mensaje de exito (1)
 * \param msgError char* Mensaje de Error (-1)
 * \param msgCancelOp char* Mesaje de cancelacion(0)
 * \return void
 *
 */
void gen_checkReturnWithSwitch(int function, char* msgAllRight, char* msgCancelOp, char* msgError)
{
    switch(function)
    {
    case -1:
        printf("%s", msgError);
        break;

    case 0:
        printf("%s", msgCancelOp);
        break;

    case 1:
        printf("%s", msgAllRight);
        break;
    }
}

