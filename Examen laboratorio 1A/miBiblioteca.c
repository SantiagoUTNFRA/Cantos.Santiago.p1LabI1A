#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"

int menu()
{
    int opcion;

    system("cls");
    printf("----------------------------------\n");
    printf("-        MENU BICICLETERIA       -\n");
    printf("----------------------------------\n");
    printf("\t1) ALTA BICICLETA\n");
    printf("\t2) MODIFICAR BICICLETA\n");
    printf("\t3) BAJA BICICLETA\n");
    printf("\t4) LISTAR BICICLETAS\n");
    printf("\t5) LISTAR TIPOS\n");
    printf("\t6) LISTAR COLORES\n");
    printf("\t7) LISTAR SERVICIOS\n");
    printf("\t8) ALTA TRABAJO\n");
    printf("\t9) LISTAR TRABAJOS\n");
    printf("\t10) SALIR\n\n");

    getInteger("opcion", &opcion, 0, 0);


    return opcion;
}

int getInteger(char* texto, int* campo, int minimo, int maximo)
{
    int todoOk = 0;

    int auxInt;

    if(!maximo)
    {
        maximo = 1000000000;
    }
    if(texto != NULL && campo != NULL && maximo > -1)
    {
        printf("Ingrese %s: \n", texto);
        fflush(stdin);
        scanf("%d", &auxInt);
        while(auxInt < minimo || auxInt > maximo)
        {
            printf("Invalido. Reingresar %s.\n" ,texto);
            fflush(stdin);
            scanf("%d", &auxInt);
        }
        *campo = auxInt;

        todoOk = 1;
    }

    return todoOk;
}

int getCadena(char* texto, char* campo, int tam)
{
    int todoOk = 0;

    char auxStr[100];

    if(texto != NULL && campo != NULL && tam > 0)
    {
        printf("Ingrese %s:\n", texto);
        fflush(stdin);
        gets(auxStr);
        while(strlen(auxStr) == 0 || strlen(auxStr) > tam)
        {
            printf("Invalido. Reingresar %s:\n", texto);
            fflush(stdin);
            gets(auxStr);
        }
        strcpy(campo, auxStr);

        todoOk = 1;
    }

    return todoOk;
}

int getFloat(char* texto, float* campo, int minimo, int maximo)
{
    int todoOk = 0;

    float auxFloat;

    if(!maximo)
    {
        maximo = 1000000000;
    }
    if(texto != NULL && campo != NULL && maximo > -1 )
    {
        printf("Ingrese %s: \n",texto);
        fflush(stdin);
        scanf("%f", &auxFloat);
        while(auxFloat < minimo || auxFloat  >maximo)
        {
            printf("Invalido. Reingresar %s.\n", texto);
            fflush(stdin);
            scanf("%f", &auxFloat);
        }
        *campo = auxFloat;

        todoOk = 1;
    }

    return todoOk;
}


int getString(char* string, char* message, char* messageError, int max)
{
    int todoOk = -1;
    char auxCad[256];

    if(string != NULL && message != NULL && messageError != NULL && max > 0)
    {
        printf("%s", message);
        fflush(stdin);
        gets(auxCad);

        onlyString(auxCad);

        while(strlen(auxCad) > max)
        {
            printf("%s", messageError);
            fflush(stdin);
            gets(auxCad);

            onlyString(auxCad);
        }
        validateStringTidy(auxCad);

        strcpy(string, auxCad);
        todoOk = 0;
    }

    return todoOk;
}

int validateStringTidy(char* string)
{
    int todoOk = 0;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);

        while( string[i] != '\0')
        {
            if( string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }
            i++;
        }

        todoOk = 1;
    }

    return todoOk;
}


int onlyString(char* string)
{
    int todoOk = 0;
    int i=0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if( string[i] != ' ' )
            {
                if( (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') )
                {
                    todoOk = 1;
                    while(todoOk)
                    {
                        printf("Error, no se permiten numeros o simbolos. Reingrese: ");
                        fflush(stdin);
                        gets(string);
                        i = 0;
                        todoOk = 0;
                    }
                }
            }
            i++;
        }
    }

    return todoOk;
}
