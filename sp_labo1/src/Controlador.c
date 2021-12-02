/*
 * Controlador.c
 *
 *  Created on: 24 nov. 2021
 *      Author: lauta
 */
#include <string.h>
#include "Controlador.h"
#include "Libro.h"
#include "Editorial.h"
#include "Funciones.h"
int controlador_cargarlibros(char* archivo,LinkedList* listalibros)
{
	FILE* miarchivo;
	int retorno;
	char direccion_archivo[126]={"src/"};
	char extension[]={".csv"};
	strcat(direccion_archivo,archivo);
	strcat(direccion_archivo,extension);
	miarchivo=fopen(direccion_archivo,"r");
	retorno=0;
	if(cargar_archivo_libros(miarchivo, listalibros)==0)
	{
		retorno=1;
		fclose(miarchivo);
	}
	return retorno;
}
int controlador_cargareditoriales(char* archivo,LinkedList* listaeditoriales)
{
	FILE* miarchivo;
	int retorno;
	char direccion_archivo[126]={"src/"};
	char extension[]={".csv"};
	strcat(direccion_archivo,archivo);
	strcat(direccion_archivo,extension);
	miarchivo=fopen(direccion_archivo,"r");
	retorno=0;
	if(cargar_archivo_editoriales(miarchivo, listaeditoriales)==0)
	{
		retorno=1;
		fclose(miarchivo);
	}
	return retorno;
}
int controlador_sort(LinkedList* listalibros)
{
	int (*pFunc)(void*,void*);
	pFunc=&comparar_libros;
	ll_sort(listalibros,pFunc,1);
    return 1;
}
void controlador_mostrarlibro(LinkedList* listalibros,LinkedList* listaeditoriales,int indice)
{
	eEditorial* auxeditorial;
	eLibro*  auxlibro;
	if(listaeditoriales!=NULL&&listalibros!=NULL)
	{
		auxlibro=ll_get(listalibros, indice);
		auxeditorial=ll_get(listaeditoriales, auxlibro->ideditorial-1);
		if(auxeditorial!=NULL&&auxlibro!=NULL)
		{
			printf("%d %10s %35s %35f %35s\n",auxlibro->idlibro,auxlibro->nombre,auxlibro->autor,auxlibro->precio,auxeditorial->nombre);
		}

	}
}


void controlador_mostrarlibros(LinkedList* listalibros,LinkedList* listaeditoriales)
{
	int i;
	if(listaeditoriales!=NULL&&listalibros!=NULL)
	{
		puts("ID          NOMBRE                                    AUTOR                            PRECIO                   EDITORIAL\n");
		puts("===========================================================================================================================");
		for(i=0;i<ll_len(listalibros);i++)
		{
			controlador_mostrarlibro(listalibros, listaeditoriales, i);
		}
	}
}
int controlador_listaFiltrada(LinkedList* listalibros,LinkedList* listaeditorial)
{
	int retorno;
	LinkedList* lista_aux;
	char archivo_nuevo[129];
	int (*pFun)(void*);
	pFun=&filtrar_libros;
	lista_aux=ll_newLinkedList();
	retorno=0;
	if(listalibros!=NULL&&listaeditorial!=NULL&&pFun!=NULL)
	{
		lista_aux=ll_filter(listalibros, pFun);
		if(lista_aux!=NULL)
		{
			PedirCadena(archivo_nuevo, "Ingrese el nombre del archivo nuevo.", "No esta permitido ese nombre", 126);//pide el nombre del archivo nuevo
			guardar_archivo_libros(archivo_nuevo, lista_aux);//crea el archivo nuevo
			retorno=1;
		}

	}
	return retorno;
}
int controlador_listaMapeada(LinkedList* listalibro)
{
	int retorno;
	LinkedList* lista_mapeada;
	lista_mapeada=ll_newLinkedList();
	int (*pFun)(void*);
	pFun=&mapear_libros;
	char archivo_nuevo[129];
	retorno=0;
	if(listalibro!=NULL&&pFun!=NULL)
	{
		lista_mapeada=ll_map(listalibro,pFun);
		if(lista_mapeada!=NULL)
		{
			PedirCadena(archivo_nuevo, "Ingrese el nombre del archivo nuevo.", "No esta permitido ese nombre", 126);
			guardar_archivo_libros(archivo_nuevo, lista_mapeada);
			retorno=1;
		}
	}
	return retorno;
}
int controlador_librosmayor500(LinkedList* listalibro)
{
	int retorno;
	int total;
	int (*pFun)(void*);
	pFun=&libros_mayor500;
	retorno=0;
	if(listalibro!=NULL)
	{
		total=(int)ll_count(listalibro,pFun);
		printf("El total de libros con precio mayor a 500 es:%d\n",total);
		retorno=1;
	}
	return retorno;
}
int controlador_sumatoriaPearson(LinkedList* listalibro)
{
	int retorno;
	float total;
	int (*pFun)(void*);
	pFun=&sumatoria_libros_pearson;
	retorno=0;
	if(listalibro!=NULL)
	{
		total=ll_count(listalibro,pFun);
		printf("La sumatoria de precios de los libros de la editorial PEARSON es:%f\n",total);
		retorno=1;
	}
	return retorno;
}
