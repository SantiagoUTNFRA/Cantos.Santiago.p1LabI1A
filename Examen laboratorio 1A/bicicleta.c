#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bicicleta.h"


int initBicicleta(eBicicleta* lista, int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty=1;
        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarLibre(eBicicleta* lista, int tam)
{
    int desocupado = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                desocupado = i;
                break;
            }
        }
    }

    return desocupado;
}


int altaBicicleta(eBicicleta* lista, int tam, int* nextId, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && nextId != NULL)
    {
        int indice;
        system("cls");
        indice = buscarLibre(lista, tam);

        printf("\nel id de su bicicleta es %d.\n", *nextId);
        lista[indice].idBici = (*nextId);
        (*nextId)++;

        system("pause");
        system("cls");

        getCadena("Marca", lista[indice].marca, 20);
        listarTipos(listaTipo, tamTipo);
        printf("\n\n");

        getInteger("Tipo", &lista[indice].idTipo, 1000, 1003);
        listarColores(listaColor,tamColor);
        printf("\n\n");

        getInteger("Color", &lista[indice].idColor, 5000, 5004);
        listarMaterial(&lista[indice].material);
        printf("\n\n");

        getCadena("Material", &lista[indice].material, 20);

        lista[indice].isEmpty = 0;

        printf("\nBicicleta cargada con exito.\n");
        printf("\n\n");

        mostrarBicicleta(lista[indice], listaTipo, tamTipo, listaColor, tamColor);
        system("pause");
        todoOk = 1;
    }

    return todoOk;
}

/* A terminar.
int altaTrabajo(eBicicleta* lista, int tam, int* nextId, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && nextId != NULL && listaTipo != NULL && tamTipo > 0 && listaColor != NULL && tamColor > 0)
    {
        int indice;
        system("cls");
        indice = buscarLibre(lista, tam);


        todoOk = 1;
    }


    return todoOk;
}
*/

/*
int listarTrabajos(eBicicleta* lista, int tam, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        todoOk = 1;

        system("cls");
        printf("            LISTA DE BICICLETAS             \n\n");
        for(int i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarBicicleta(lista[i], listaTipo, tamTipo, listaColor, tamColor);
                printf("                                    \n");
            }
        }
    }

    return todoOk;
}
*/
int getMaterial(char texto)
{
    int todoOk = 0;
    char auxCad;

        printf("Ingrese material\nCarbono (c)\nAluminio (a) ): \n");
        fflush(stdin);
        scanf("%c", &auxCad);
        while(auxCad != 'a' && auxCad != 'c')
        {
            printf("Error, reingrese material\nCarbono (c)\nAluminio (a) ): \n");
            fflush(stdin);
            scanf("%c", &auxCad);
        }


    texto = auxCad;
    todoOk = 1;

    return todoOk;
}


int listarMaterial(char lista[])
{
    int todoOk = 0;

    printf("\n        ***Material a eleccion***     \n\n");
    printf("\n                                      \n");
    printf("c) Carbono\na) Aluminio");
    printf("\n                                      \n");

    todoOk = 1;

    return todoOk;
}




void mostrarBicicleta(eBicicleta bici, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    char descTipo[20];
    char descColor[20];

    cargarTipo(bici.idTipo, listaTipo, tamTipo, descTipo);
    cargarColor(bici.idColor, listaColor, tamColor, descColor);

    printf("\n----------------------\n");
    printf("[ID]:      %d \nMARCA:       %s \nTIPO:      %s \nCOLOR:     %s \nMATERIAL:     %c \n\n", bici.idBici, bici.marca, descTipo, descColor, bici.material);

}


int mostrarBicicletas(eBicicleta* lista, int tam, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && listaTipo != NULL && tamTipo > 0 && listaColor != NULL && tamColor > 0)
    {
        todoOk = 1;

        system("cls");
        printf("            LISTA DE BICICLETAS             \n\n");
        for(int i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarBicicleta(lista[i], listaTipo, tamTipo, listaColor, tamColor);
                printf("                                    \n");
            }
        }
    }

    return todoOk;
}


int checkBicicletaCargada(eBicicleta* lista, int tam)
{
    int check = 0;

    if(lista != NULL && tam>0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                check = 1;
                break;
            }

        }
    }

    return check;
}


int findBicicletaPorId(eBicicleta* lista, int tam)
{
    int lugar = -1;

    if(lista != NULL && tam > 0)
    {
        int userInput;

        printf("Ingrese ID a modificar: ");
        fflush(stdin);
        scanf("%d", &userInput);

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                continue;
            }
            else if(lista[i].idBici == userInput)
            {
                lugar = i;
                break;
            }
        }
        if(lugar == -1 )

        {
            printf("No se encontro este ID.\t");
            system("pause");
        }
    }

    return lugar;
}


int modificarBicicleta(eBicicleta* list, int tam, int index, eTipo* tipos, int tamTipo, eColor* colores, int tamColor)
{
    int todoOk=0;

    if(list != NULL && tam > 0 && index > -1)
    {
        int opcion;
        printf("------------------------------------\n");
        mostrarBicicleta(list[index], tipos, tamTipo, colores, tamColor);
        printf("------------------------------------\n");
        printf("Que desea modificar?\n1)-Marca\n2)-Tipo\n3)-Color\n4)-Material\n");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            getCadena("marca", list[index].marca, 20);
            printf("\nMarca cambiada exitosamente.\n");
            system("pause");
            break;
        case 2:
            listarTipos(tipos, tamTipo);
            getInteger("tipo", &list[index].idTipo, 1000, 1003);
            printf("\nTipo cambiado exitosamente.\n");
            system("pause");
            break;
        case 3:
            listarColores(colores, tamColor);
            getInteger("color", &list[index].idColor, 5000, 5004);
            printf("\nColor cambiado exitosamente.\n");
            system("pause");
            break;
        case 4:

            printf("\nMaterial modificado exitosamente.\n");
            system("pause");
            break;
        }

        todoOk=1;
    }

    return todoOk;
}


int removeBicicleta(eBicicleta* list, int tam, int index, eTipo* tipos, int tamTipo, eColor* colores, int tamColor)
{
    int todoOk = 0;

    if(list != NULL && tam > 0 && index > -1)
    {
        char rta;

        todoOk = 1;
        printf("------------------------------------\n");
        mostrarBicicleta(list[index], tipos, tamTipo, colores, tamColor);
        printf("------------------------------------\n");
        printf("\n Esta seguro que desea eliminar esta bicicleta? s/n \n");
        fflush(stdin);
        scanf("%c", &rta);

        if(rta == 's')
        {
            list[index].isEmpty=1;

            printf("Bicicleta eliminada exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("No se eliminará esta bicicleta.\n");
            system("pause");
        }

    }

    return todoOk;
}

