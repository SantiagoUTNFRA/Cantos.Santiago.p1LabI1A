#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED


#endif // MIBIBLIOTECA_H_INCLUDED

/** \brief Mostrar un menú con opciones de un ABM
 * \param
 * \param
 * \return int retorna 0 si hay Error - (1) si está todo Ok
 */
int menu();

/** \brief pide enteros y valida con minimo y maximo
 *
 * \param texto[] char
 * \param campo *int
 * \param minimo int
 * \param limite int
 * \return int retorna 0 si hay Error [NULL pointer] - (1) si está todo Ok
 *
 */
int getInteger(char texto[],int* campo,int minimo,int limite);

/** \brief pide un caracter y valida un rango
 *
 * \param texto[] char
 * \param campo *int
 * \param tam int
 * \return int retorna 0 si hay Error [NULL pointer]- (1) si está todo Ok
 *
 */
int getCadena(char texto[],char* campo,int tam);

/** \brief pide floats y valida con minimo y maximo
 *
 * \param texto[] char
 * \param campo *float
 * \param minimo int
 * \param limite int
 * \return int retorna 0 si hay Error [NULL pointer] - (1) si está todo Ok
 *
 */
int getFloat(char texto[],float* campo, int minimo, int limite);

int listarMaterial(char lista[]);

int getCharacter(char* character, char* message);

int getString(char* string, char* message, char* messageError, int max);

int validateStringTidy(char* string);

int onlyString(char* string);
