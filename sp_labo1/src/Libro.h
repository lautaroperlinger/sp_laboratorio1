/*
 * Libros.h
 *
 *  Created on: 24 nov. 2021
 *      Author: lauta
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include "Linkedlist.h"
typedef struct
{
	int idlibro;
	char nombre[129];
	char autor[129];
	float precio;
	int ideditorial;
}eLibro;

#endif /* LIBROS_H_ */

eLibro* nuevo_Libro();
eLibro* nuevo_Parametros(char* id,char* nombre,char* autor,char* precio,char* ideditorial);
//idlibro
int set_idlibro(eLibro* this,int id);
int get_idlibro(eLibro* this,int* id);
//nombre
int set_nombrelibro(eLibro* this,char* nombre);
int get_nombrelibro(eLibro* this,char* nombre);
//autor
int set_autor(eLibro* this,char* autor);
int get_autor(eLibro* this,char* autor);
//precio
int set_precio(eLibro* this,float precio);
int get_precio(eLibro* this,float* precio);
//ideditorial
int set_ideditorial(eLibro* this,int ideditorial);
int get_ideditorial(eLibro* this,int* ideditorial);
//Funciones
void eliminar_libro(eLibro* this);
int comparar_libros(void* libro1,void* libro2);
int filtrar_libros(void* elemento);
int mapear_libros(void* elemento);
//Archivos
int cargar_archivo_libros(FILE* archivo,LinkedList* listalibros);
int guardar_archivo_libros(char* archivo,LinkedList* listalibros);
