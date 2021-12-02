/*
 * Libros.c
 *
 *  Created on: 24 nov. 2021
 *      Author: lauta
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
eLibro* nuevo_Libro()
{
	eLibro* libronuevo;
	libronuevo=(eLibro*)malloc(sizeof(eLibro));
	return libronuevo;
}
eLibro* nuevo_Parametros(char* id,char* nombre,char* autor,char* precio,char* ideditorial)
{
	eLibro* libronuevo;
	libronuevo=nuevo_Libro();
	//agrego los nuevos pametro al libro nuevo
	set_idlibro(libronuevo, atoi(id));
	set_nombrelibro(libronuevo, nombre);
	set_autor(libronuevo, autor);
	set_precio(libronuevo, atoi(precio));
	set_ideditorial(libronuevo, atoi(ideditorial));
	return libronuevo;
}
//setters
int set_idlibro(eLibro* this,int id)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		this->idlibro=id;
		retorno=1;
	}
	return retorno;
}
int set_nombrelibro(eLibro* this,char* nombre)
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
int set_autor(eLibro* this,char* autor)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		strcpy(this->autor,autor);
		retorno=1;
	}
	return retorno;
}
int set_precio(eLibro* this,float precio)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		this->precio=precio;
	}
	return retorno;
}
int set_ideditorial(eLibro* this,int ideditorial)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		this->ideditorial=ideditorial;
		retorno=1;
	}
	return retorno;
}
//getters
int get_idlibro(eLibro* this,int* id)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		*id=this->idlibro;
		retorno=1;
	}
	return retorno;
}
int get_nombrelibro(eLibro* this,char* nombre)
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
int get_autor(eLibro* this,char* autor)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		strcpy(autor,this->autor);
		retorno=1;
	}
	return retorno;
}
int get_precio(eLibro* this,float* precio)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		*precio=this->precio;
		retorno=1;
	}
	return retorno;
}
int get_ideditorial(eLibro* this,int* ideditorial)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		*ideditorial=this->ideditorial;
		retorno=1;
	}
	return retorno;
}
//Funciones
void eliminar_libro(eLibro* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
int comparar_libros(void* libro1,void* libro2)
{
	int retorno;
	eLibro* librouno;
	eLibro* librodos;
	librouno=(eLibro*)libro1;
	librodos=(eLibro*)libro2;
	retorno=strcmp(librouno->autor,librodos->autor);
	return retorno;
}
int filtrar_libros(void* elemento)
{
	eLibro* libro_aux;
	int retorno;
	retorno=0;
	libro_aux=(eLibro*)elemento;
	if(elemento!=NULL)
	{
		if(libro_aux->ideditorial==4)//el id de la editorial minotauro es 4
		{
			retorno=1;
		}
	}
	return retorno;
}
int mapear_libros(void* elemento)
{
	int retorno;
	retorno=0;
	eLibro* libro_aux;
	libro_aux=(eLibro*)elemento;
	if(elemento!=NULL)
	{
		switch(libro_aux->ideditorial)
		{
			case 1:
				if(libro_aux->precio>=300)
				{
					retorno=1;
				}
				break;
			case 2:
				if(libro_aux->precio<=200)
				{
					retorno=2;
				}
				break;
		}
	}
	return retorno;
}
//archivos
int cargar_archivo_libros(FILE* archivo,LinkedList* listalibros)
{
	int retorno;
	char id[256];
	char nombre[256];
	char nombre2[256];
	char precio[256];
	char ideditorial[256];
	int tam;
	eLibro* aux;
	retorno=-1;
	if(archivo!=NULL)
	{
		fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,nombre2,precio,ideditorial);
		do
		{
			tam=fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,nombre2,precio,ideditorial);
			//printf("%d\n",tam);
			aux=nuevo_Parametros(id, nombre, nombre2, precio, ideditorial);

			if(tam==5)
			{
				ll_add(listalibros,aux);
				//printf("%d %s %s %f %d\n",aux->idlibro,aux->nombre,aux->autor,aux->precio,aux->ideditorial);
				retorno=0;
			}
			else
			{
				eliminar_libro(aux);
				retorno=1;
				break;
			}
		}while(!feof(archivo));
	}
	return retorno;
}
int guardar_archivo_libros(char* archivo,LinkedList* listalibros)
{
	FILE* miarchivo;
	eLibro* aux;
	int i;
	int retorno;
	char direccion_archivo[126]={"src/"};
	char extension[]={".csv"};
	strcat(direccion_archivo,archivo);
	strcat(direccion_archivo,extension);
	retorno=0;
	if(archivo!=NULL&&listalibros!=NULL)
	{
		miarchivo=fopen(direccion_archivo,"w");
		fprintf(miarchivo,"id,nombre,autor,precio,ideditorial\n");
		for(i=0;i<ll_len(listalibros);i++)
		{
			aux=ll_get(listalibros, i);
			fprintf(miarchivo,"%d,%s,%s,%f,%d\n",aux->idlibro,aux->nombre,aux->autor,aux->precio,aux->ideditorial);
		}
		fclose(miarchivo);
	}
	return retorno;
}
