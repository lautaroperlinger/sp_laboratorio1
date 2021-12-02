/*
 * Funciones.c
 *
 *  Created on: 25 nov. 2021
 *      Author: lauta
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

void Menu(int* opcion,char mensaje[],char mensajeError[],int maximo,int minimo)
{
	int auxiliar;
	int flag;
	flag=0;
	if(opcion!=0&&mensaje!=0&&mensajeError!=0&&maximo>minimo)
	{
		printf("%s",mensaje);
		scanf("%d",&auxiliar);
		do
		{

			if(auxiliar>=minimo&&auxiliar<=maximo)
			{
				*opcion=auxiliar;
				break;
			}
			else
			{
					printf("%s",mensajeError);
					scanf("%d",&auxiliar);
			}
		}while(flag==0);
	}
}
int ValidarCadena(char cadena[])
{
	int retorno;
	int i;
	int total;
	total=0;
	char buffer[4096];
	fflush(stdin);
	gets(buffer);
	retorno=0;
	if(cadena!=0)
	{
		for(i=0;i<strlen(buffer);i++)
		{
			total=total+isdigit(buffer[i]);
		}
		if(total==0)
		{
			retorno=1;
			strcpy(cadena,buffer);
		}
	}
	return retorno;
}
void PedirCadena(char cadena[],char mensaje[],char mensaje_error[],int tamanio)
{
	int retorno;
	char buffer[tamanio];
	int flag;
	flag=0;
	do
		{
			if(flag==0)
			{
				printf("%s",mensaje);
				flag=1;

			}
			else
			{
				printf("%s",mensaje_error);
			}
			retorno=ValidarCadena(buffer);
		}while(strlen(buffer)>tamanio||retorno!=1);
	strcpy(cadena,buffer);
}
int ValidarEntero(int* entero)
{
	int retorno;
	int i;
	int total;
	total=0;
	char buffer[4096];
	scanf("%s",buffer);
	retorno=0;
	if(entero!=0)
	{
		for(i=0;i<strlen(buffer);i++)
		{
			total=total+isdigit(buffer[i]);
		}
		if(total!=0)
		{
			retorno=1;
			*entero=atoi(buffer);
		}
	}
	return retorno;
}
void PedirEntero(int* entero,char mensaje[],int minimo,int maximo)
{
	int auxiliarEntero;
	do
	{
		printf("%s",mensaje);
		if(ValidarEntero(&auxiliarEntero)!=0)
		{
			*entero=auxiliarEntero;
		}
	}while(auxiliarEntero<minimo||auxiliarEntero>maximo||auxiliarEntero==0);
	*entero=auxiliarEntero;
}
void PedirFlotante(char mensaje[],float* flotante,float tamanioMinimo)
{
	float numero;
	do
	{
		printf("%s",mensaje);
		scanf("%f",&numero);
	}while(numero<tamanioMinimo);
	*flotante=numero;
}

