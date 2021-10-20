#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

int listarColores(eColor* lista, int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        todoOk = 1;

        printf("\n        ***Listado de Colores***        \n\n");

        for(int i = 0; i < tam; i++)
        {
            printf("ID: %d \nCOLOR: %s", lista[i].idColor, lista[i].nombreColor);
            printf("\n                              \n");
        }
    }

    return todoOk;
}

int cargarColor(int id, eColor* lista, int tam, char destino[])
{
    int todoOk = 0;

    if(id > 4999 && id < 5005 && lista != NULL && tam > 0 && destino != NULL)
    {

        todoOk = 1;

        for(int i = 0; i < tam; i++)
        {
            if(id == lista[i].idColor)
            {
                strcpy(destino, lista[i].nombreColor) ;

                break;
            }
        }
    }

    return todoOk;
}
