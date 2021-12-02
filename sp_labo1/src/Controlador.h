/*
 * Controlador.h
 *
 *  Created on: 24 nov. 2021
 *      Author: lauta
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#endif /* CONTROLADOR_H_ */
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Libro.h"
#include "Editorial.h"
/// @brief
/// carga el archivo de libro a la lista
/// @param archivo
/// @param listalibros
/// @return
int controlador_cargarlibros(char* archivo,LinkedList* listalibros);
/// @brief
/// carga el archivo de editoriales a la lista
/// @param archivo
/// @param listaeditoriales
/// @return
int controlador_cargareditoriales(char* archivo,LinkedList* listaeditoriales);
/// @brief
/// ordena los libros segun su autor de forma ascendente
/// @param listalibros
/// @return
int controlador_sort(LinkedList* listalibros);
/// @brief
/// muestra los todos los libros y las editoriales de las que corresponden
/// @param listalibros
/// @param listaeditoriales
void controlador_mostrarlibros(LinkedList* listalibros,LinkedList* listaeditoriales);
/// @brief
/// muestra un libro en especifico y su editorial correspondiente
/// @param listalibros
/// @param listaeditoriales
/// @param indice
void controlador_mostrarlibro(LinkedList* listalibros,LinkedList* listaeditoriales,int indice);
/// @brief
/// filtra la lista y crea un archivo con los libros filtrados
/// @param listalibros
/// @param listaeditoriales
/// @return
int controlador_listaFiltrada(LinkedList* listalibros,LinkedList* listaeditoriales);
/// @brief
/// crea una lista con los libros con descuentos
/// @param listalibro
/// @return
int controlador_listaMapeada(LinkedList* listalibro);
int controlador_librosmayor500(LinkedList* listalibro);
int controlador_sumatoriaPearson(LinkedList* listalibro);
