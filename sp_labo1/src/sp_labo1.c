/*
 ============================================================================
 Name        : segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Funciones.h"
#include "Controlador.h"
#define CAD 129
int main(void)
{
	setbuf(stdout,NULL);
	LinkedList* listalibros;
	listalibros=ll_newLinkedList();
	LinkedList* listaeditoriales;
	listaeditoriales=ll_newLinkedList();
	int opcion;
	char nombre_archivo_libros[CAD];
	char nombre_archivo_editoriales[CAD];
	int flaglibros;
	int flageditoriales;
	flaglibros=0;
	flageditoriales=0;
	do
	{
		Menu(&opcion, "1-Cargas lista de libros\n2-Cargar lista de editoriales\n3-Ordenar autores\n4-Imprimir libros\n5-Listar libros de editorial MINOTAURO\n6-mapear la lista con descuento\n7-Determinar cuántos libros cuestan mas de $500.\n8-Determinar la sumatoria de precios de los libros de la editorial PEARSON\n9-Salir\n", "Opcion no valida.\n", 9, 0);
		switch(opcion)
		{
			case 1:
				PedirCadena(nombre_archivo_libros, "Ingrese el nombre del archivo de libros .","Porfavor,ingrese bien el dato.\n", CAD);
				if(controlador_cargarlibros(nombre_archivo_libros, listalibros)==1)
				{
					puts("Se cargo el archivo de libros con exito.\n");
					flaglibros=1;
				}
				else
				{
					puts("ERROR.\n");
				}
				break;
			case 2:
				PedirCadena(nombre_archivo_editoriales, "Ingrese el nombre del archivo de editoriales", "Porfavor,ingrese bien el dato.\n", CAD);
				if(controlador_cargareditoriales(nombre_archivo_editoriales, listaeditoriales)==1)
				{
					puts("Se cargo el archivo de editoriales con exito.\n");
					flageditoriales=1;
				}
				else
				{
					puts("ERROR.\n");
				}
				break;
			case 3:
				if(flageditoriales==1)
				{
					controlador_sort(listalibros);
				}
				else
				{
					puts("primero se tiene que agregar los libros.\n");

				}
				break;
			case 4:
				if(flaglibros==1&&flageditoriales==1)
				{
					controlador_mostrarlibros(listalibros, listaeditoriales);
				}
				else
				{
					puts("primero se tienen que cargar los archivos de libros y editoriales.\n");
				}
				break;
			case 5:
				if(flaglibros==1&&flageditoriales==1)
				{
					if(controlador_listaFiltrada(listalibros, listaeditoriales)==1)
					{
						puts("Se filtro con exito.\n");
					}
					else
					{
						puts("No se pudo filtrar la lista.\n");
					}
				}
				else
				{
					puts("primero se tiene que cargar los archivos de libros y editoriales.\n");
				}
				break;
			case 6:
				if(flaglibros==1&&flageditoriales==1)
				{
					if(controlador_listaMapeada(listalibros)==1)
					{
						puts("Se creo el archivo mapeado correctamente.\n");
					}
					else
					{
						puts("No se pudo mapear la lista.\n");
					}
				}
				else
				{
					puts("primero se tiene que cargar los archivos de libros y editoriales.\n");
				}
				break;
			case 7:
				if(flaglibros==1&&flageditoriales==1)
				{
					if(controlador_librosmayor500(listalibros)==1)
					{
						puts("Se determino correctamente la cantidad de libros.\n");
					}
					else
					{
						puts("Error.\n");
					}
				}
				else
				{
					puts("primero se tiene que cargar los archivos de libros y editoriales.\n");
				}
				break;
			case 8:
				if(flaglibros==1&&flageditoriales==1)
				{
					if(controlador_sumatoriaPearson(listalibros)==1)
					{
						puts("Se determino correctamente la sumatoria de la editorial PEARSON.\n");
					}
					else
					{
						puts("Error.\n");
					}
				}
				else
				{
					puts("primero se tiene que cargar los archivos de libros y editoriales.\n");
				}
				break;
		}
	}while(opcion!=9);
	return EXIT_SUCCESS;
}
