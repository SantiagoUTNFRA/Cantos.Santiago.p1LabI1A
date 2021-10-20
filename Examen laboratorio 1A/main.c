#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bicicleta.h"
#include "miBiblioteca.h"
#include "tipos.h"
#include "color.h"
#include "servicios.h"
#include "fecha.h"


#define TAMBICI 1000
#define TAMTIP 4
#define TAMCOL 5
#define TAMSERV 4




int main()
{
    char seguir = 's';

    eBicicleta listaBicis[100];



    int nextId = 1;

    eTipo tipos[TAMTIP] = { {1000, "Rutera"}, {1001, "Carrera"}, {1002, "Mountain"}, {1003, "BMX"} };

    eColor colores[TAMCOL] = { {5000, "Gris"}, {5001, "Negro"}, {5002, "Blanco"}, {5003, "Azul"}, {5004, "Rojo"} };

    eServicio servicios[TAMSERV] = { {20000, "Limpieza",30}, {20001, "Parche",400}, {20002, "Centrado",500}, {20003, "Cadena",450} };


    initBicicleta(listaBicis, TAMBICI);

    do
    {
        switch(menu())
        {
        case 1:

            altaBicicleta(listaBicis, TAMBICI, &nextId, tipos, TAMTIP, colores, TAMCOL);

            break;

        case 2:

            if(checkBicicletaCargada(listaBicis, TAMBICI))
            {
                modificarBicicleta(listaBicis, TAMBICI, findBicicletaPorId(listaBicis, TAMBICI), tipos, TAMTIP, colores, TAMCOL);
            }
            else
            {
                printf("Primero deberia cargar una bicicleta.");
                system("pause");
            }

            break;
        case 3:

            if(checkBicicletaCargada(listaBicis, TAMBICI))
            {
                removeBicicleta(listaBicis, TAMBICI, findBicicletaPorId(listaBicis, TAMBICI), tipos, TAMTIP, colores, TAMCOL);
            }
            else
            {
                printf("Primero deberia cargar una bicicleta.");
                system("pause");
            }

            break;
        case 4:

            if(checkBicicletaCargada(listaBicis, TAMBICI))
            {
                mostrarBicicletas(listaBicis, TAMBICI, tipos, TAMTIP, colores, TAMCOL);
                system("pause");
            }
            else
            {
                printf("Primero deberia cargar una bicicleta.");
                system("pause");
            }

            break;
        case 5:

            listarTipos(tipos, TAMTIP);
            system("pause");
            break;

        case 6:

            listarColores(colores, TAMCOL);
            system("pause");
            break;

        case 7:

            listarServicios(servicios, TAMSERV);
            system("pause");
            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

            seguir = 'n';
            printf("\nHasta la proxima!");
            break;

        default:
            printf("Opcion no valida, reingrese.");
            system("pause");
            break;

        }
    } while(seguir == 's');

    return 0;
}
