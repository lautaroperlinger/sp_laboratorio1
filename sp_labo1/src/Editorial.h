/*
 * Editorial.h
 *
 *  Created on: 25 nov. 2021
 *      Author: lauta
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "LinkedList.h"
typedef struct
{
	int ideditorial;
	char nombre[129];
}eEditorial;


#endif /* EDITORIAL_H_ */
/// @brief
/// reserva en memoria el espacio para una variable editorial
/// @return
eEditorial* nueva_editorial();
/// @brief
/// le agrega los campos hardcodeados a la variable
/// @param ideditorial
/// @param nombre
/// @return
eEditorial* nuevo_Parametros_editorial(char* ideditorial,char* nombre);
//ideditorial
/// @brief
/// crea el campo IDeditorial en la editorial especifica
/// @param this
/// @param id
/// @return
int set_id_editorial(eEditorial* this,int id);
/// @brief
/// trae el IDeditorial de la editorial especifica
/// @param this
/// @param id
/// @return
int get_id_editorial(eEditorial* this,int* id);
//nombre
/// @brief
/// crea el campo nombre  a la editorial especifica
/// @param this
/// @param nombre
/// @return
int set_nombreeditorial(eEditorial* this,char* nombre);
/// @brief
/// trae el nombre de la editorial especifica
/// @param this
/// @param nombre
/// @return
int get_nombreeditorial(eEditorial* this,char* nombre);
//funciones
/// @brief
/// elimina una editorial especifica
/// @param this
void eliminar_editorial(eEditorial* this);
//archivo
/// @brief
/// carga en la lista el archivo corrrespondiente a la lista editorial
/// @param archivo
/// @param listaeditorial
/// @return
int cargar_archivo_editoriales(FILE* archivo,LinkedList* listaeditorial);
