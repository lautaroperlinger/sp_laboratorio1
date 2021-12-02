/*
 * Editorial.c
 *
 *  Created on: 25 nov. 2021
 *      Author: lauta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editorial.h"
eEditorial* nueva_editorial()
{
	eEditorial* editorialnueva;
	editorialnueva=(eEditorial*)malloc(sizeof(eEditorial));
	return editorialnueva;
}
eEditorial* nuevo_Parametros_editorial(char* ideditorial,char* nombre)
{
	eEditorial* editorialnueva;
	editorialnueva=nueva_editorial();
	set_id_editorial(editorialnueva, atoi(ideditorial));
	set_nombreeditorial(editorialnueva, nombre);
	return editorialnueva;
}
//setters
int set_id_editorial(eEditorial* this,int id)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		this->ideditorial=id;
		retorno=1;
	}
	return retorno;
}
int set_nombreeditorial(eEditorial* this,char* nombre)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}
//getters
int get_id_editorial(eEditorial* this,int* id)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		*id=this->ideditorial;
		retorno=1;
	}
	return retorno;
}
int get_nombreeditorial(eEditorial* this,char* nombre)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}
//funciones
void eliminar_editorial(eEditorial* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
//archivo
int cargar_archivo_editoriales(FILE* archivo,LinkedList* listaeditorial)
{
	int retorno;
	char nombre[256];
	char ideditorial[256];
	int tam;
	eEditorial* aux;
	retorno=-1;
	if(archivo!=NULL)
	{
		fscanf(archivo,"%[^,],%[^\n]\n",ideditorial,nombre);
		do
		{
			tam=fscanf(archivo,"%[^,],%[^\n]\n",ideditorial,nombre);
			//printf("%d\n",tam);
			aux=nuevo_Parametros_editorial(ideditorial, nombre);
			//printf("%d %s \n",aux->ideditorial,aux->nombre);
			if(tam==2)
			{
				ll_add(listaeditorial,aux);
				retorno=0;
			}
			else
			{
				eliminar_editorial(aux);
				retorno=1;
				break;
			}
		}while(!feof(archivo));
	}
	return retorno;
}
