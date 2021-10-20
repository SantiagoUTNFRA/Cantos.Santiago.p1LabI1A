#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include"miBiblioteca.h"
#include "tipos.h"
#include "color.h"

typedef struct
{
    int idBici;
    char marca[20];
    int idTipo;
    int idColor;
    char material;
    int isEmpty;

}eBicicleta;


/** \brief indicar que todas las posiciones en la matriz están vacías, esta función coloca la bandera (isEmpty) en VERDADERO en todas las posiciones de la matriz
 *
 * \param lista eBicicleta*
 * \param tam int
 * \return int
 *
 */
int initBicicleta(eBicicleta* lista, int tam);

/** \brief Encontrar un lugar con índice 0 o 1
 *
 * \param lista eBicicleta*
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eBicicleta* lista, int tam);

/** \brief agregar en una lista existente los valores recibidos como parámetros en la primera posición vacía
 *
 * \param lista eBicicleta*
 * \param tam int
 * \param nextId int*
 * \param listaTipo eTipo*
 * \param tamTipo int
 * \param listaColor eColor*
 * \param tamColor int
 * \return int
 *
 */
int altaBicicleta(eBicicleta* lista, int tam, int* nextId, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor);


/** \brief
 *
 * \param texto[] char
 * \return int
 *
 */
int getMaterial(char texto);


/** \brief mostrar el contenido de un vector bicicletas
 *
 * \param bici eBicicleta
 * \param lista eTipo*
 * \param tam int
 * \param listaColor eColor*
 * \param tamColor int
 * \return void
 *
 */
void mostrarBicicleta(eBicicleta bici,eTipo* lista, int tam, eColor* listaColor, int tamColor);

/** \brief mostrar el contenido de la matriz de empleados
 *
 * \param lista eBicicleta*
 * \param tam int
 * \param listaTipos eTipo*
 * \param tamTipos int
 * \param listaC eColor*
 * \param tamColor int
 * \return int
 *
 */
int mostrarBicicletas(eBicicleta* lista, int tam, eTipo* listaTipos,int tamTipos, eColor* listaC, int tamColor);

/** \brief
 *
 * \param lista eBicicleta*
 * \param tam int
 * \return int
 *
 */
int checkBicicletaCargada(eBicicleta* lista, int tam);

/** \brief Encontrar bicicleta por Id en devuelve la posición del índice en la matriz
 *
 * \param lista eBicicleta*
 * \param tam int
 * \return int
 *
 */
int findBicicletaPorId(eBicicleta* lista, int tam);

/** \brief Mostrar un menú al cliente para su modificación de datos.
 *
 * \param list eBicicleta*
 * \param tam int
 * \param index int
 * \param tipos eTipo*
 * \param tamT int
 * \param colores eColor*
 * \param tamColor int
 * \return int
 *
 */
int modificarBicicleta(eBicicleta* list, int tam, int index, eTipo* tipos, int tamT, eColor* colores, int tamColor);

/** \brief Eliminar una bicicleta por Id (poner la bandera isEmpty en 1)
 *
 * \param list eBicicleta*
 * \param tam int
 * \param index int
 * \param tipos eTipo*
 * \param tamT int
 * \param colores eColor*
 * \param tamColor int
 * \return int
 *
 */
int removeBicicleta(eBicicleta* list, int tam, int index, eTipo* tipos, int tamT, eColor* colores, int tamColor);

/** \brief
 *
 * \param lista eBicicleta*
 * \param tam int
 * \param nextId int*
 * \param listaTipo eTipo*
 * \param tamTipo int
 * \param listaColor eColor*
 * \param tamColor int
 * \return int
 *
 */
int altaTrabajo(eBicicleta* lista, int tam, int* nextId, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor);

#endif // BICICLETA_H_INCLUDED
