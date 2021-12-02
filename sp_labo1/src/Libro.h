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
/// @brief
/// reserva memoria para una variable libro
/// @return
eLibro* nuevo_Libro();
/// @brief
/// crea un puntero a un libro con sus datos
/// @param id
/// @param nombre
/// @param autor
/// @param precio
/// @param ideditorial
/// @return
eLibro* nuevo_Parametros(char* id,char* nombre,char* autor,char* precio,char* ideditorial);
//idlibro
/// @brief
/// agrega el campo ID al libro especifico
/// @param this
/// @param id
/// @return
int set_idlibro(eLibro* this,int id);
///  @brief
/// trae el ID del libro especifico
/// @param this
/// @param id
/// @return
int get_idlibro(eLibro* this,int* id);
//nombre
/// @brief
/// agrega el campo nombre al libro especifico
/// @param this
/// @param nombre
/// @return
int set_nombrelibro(eLibro* this,char* nombre);
/// @brief
/// trae el nombre del libro especifico
/// @param this
/// @param nombre
/// @return
int get_nombrelibro(eLibro* this,char* nombre);
//autor
/// @brief
/// agrega el campo autor al libro especifico
/// @param this
/// @param autor
/// @return
int set_autor(eLibro* this,char* autor);
/// @brief
/// trae el nombre del autor del libro especifico
/// @param this
/// @param autor
/// @return
int get_autor(eLibro* this,char* autor);
//precio
/// @brief
/// agrega el campo precio al libro especifico
/// @param this
/// @param precio
/// @return
int set_precio(eLibro* this,float precio);
/// @brief
/// trae el precio del libro especifico
/// @param this
/// @param precio
/// @return
int get_precio(eLibro* this,float* precio);
//ideditorial
/// @brief
/// agrega el campo IDeditorial al libro especifico
/// @param this
/// @param ideditorial
/// @return
int set_ideditorial(eLibro* this,int ideditorial);
/// @brief
/// trae el IDeditorial del libro especifico
/// @param this
/// @param ideditorial
/// @return
int get_ideditorial(eLibro* this,int* ideditorial);
//Funciones
/// @brief
/// elimina el libro elegido
/// @param this
void eliminar_libro(eLibro* this);
/// @brief
/// compara los 2 libros para saber cual es el mayor o el menos
/// @param libro1
/// @param libro2
/// @return
int comparar_libros(void* libro1,void* libro2);
/// @brief
/// filtra los elementos que esten en la editorial MINOTAURO
/// @param elemento
/// @return
int filtrar_libros(void* elemento);
/// @brief
/// mapea los libros y verifica si esta en la editorial que tiene descuento
/// @param elemento
/// @return
int mapear_libros(void* elemento);
int libros_mayor500(void* elemento);
int sumatoria_libros_pearson(void* elemento);
//Archivos
/// @brief
/// carga el archivo de libros
/// @param archivo
/// @param listalibros
/// @return
int cargar_archivo_libros(FILE* archivo,LinkedList* listalibros);
/// @brief
///
/// @param archivo
/// @param listalibros
/// @return
int guardar_archivo_libros(char* archivo,LinkedList* listalibros);
