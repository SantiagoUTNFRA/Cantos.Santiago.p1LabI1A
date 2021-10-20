#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int idTipo;
    char descTipo[20];

}eTipo;

int listarTipos(eTipo* lista, int tam);

int cargarTipo(int id, eTipo* lista, int tam,char destino[]);


#endif // TIPOS_H_INCLUDED
