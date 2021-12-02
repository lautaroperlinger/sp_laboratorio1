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
eEditorial* nueva_editorial();
eEditorial* nuevo_Parametros_editorial(char* ideditorial,char* nombre);
//ideditorial
int set_id_editorial(eEditorial* this,int id);
int get_id_editorial(eEditorial* this,int* id);
//nombre
int set_nombreeditorial(eEditorial* this,char* nombre);
int get_nombreeditorial(eEditorial* this,char* nombre);
//funciones
void eliminar_editorial(eEditorial* this);
//archivo
int cargar_archivo_editoriales(FILE* archivo,LinkedList* listaeditorial);
