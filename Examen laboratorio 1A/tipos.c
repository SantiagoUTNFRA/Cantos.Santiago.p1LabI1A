#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipos.h"

int listarTipos(eTipo* lista, int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {

        todoOk = 1;

        printf("\n       ***Listado de Tipos***        \n\n");

        for(int i = 0; i < tam; i++)
        {
            printf("ID: %d \nTIPO: %s", lista[i].idTipo, lista[i].descTipo);
            printf("\n                              \n");
        }
    }

    return todoOk;
}




int cargarTipo(int id, eTipo* lista, int tam, char* destino)
{
    int todoOk=0;

    if(id > 999 && id < 10004 && lista != NULL && tam > 0 && destino != NULL)
    {
        todoOk = 1;

        for(int i = 0; i < tam; i++)
        {
            if(id == lista[i].idTipo)
            {
                strcpy(destino, lista[i].descTipo) ;
                break;
            }
        }
    }

    return todoOk;
}



