#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicios.h"

int listarServicios(eServicio* lista, int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        todoOk = 1;
        printf("\n      LISTA DE NUESTROS SERVICIOS      \n");

        for(int i = 0; i < tam; i++)
        {
            printf("ID: %d \nSERVICIO: %s \nPRECIO: $%d", lista[i].idServ, lista[i].descripcionServicio, lista[i].precio);
            printf("\n                                   \n");
        }

    }
    return todoOk;
}

