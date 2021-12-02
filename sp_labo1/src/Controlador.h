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

int controlador_cargarlibros(char* archivo,LinkedList* listalibros);
int controlador_cargareditoriales(char* archivo,LinkedList* listaeditoriales);
int controlador_sort(LinkedList* listalibros);
void controlador_mostrarlibros(LinkedList* listalibros,LinkedList* listaeditoriales);
void controlador_mostrarlibro(LinkedList* listalibros,LinkedList* listaeditoriales,int indice);
int controlador_listaFiltrada(LinkedList* listalibros,LinkedList* listaeditoriales);
int controlador_listaMapeada(LinkedList* listalibro);
