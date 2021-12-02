/*
 * Linkedlist.c
 *
 *  Created on: 24 nov. 2021
 *      Author: lauta
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Libro.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList*));
    if(this!=NULL)
    {
    	this->pFirstNode=NULL;
    	this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux;
    returnAux=-1;
    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode;
	int i;
	pNode=NULL;
	if(this!=NULL&&(nodeIndex>=0&&nodeIndex<this->size))
	{
		pNode=this->pFirstNode;
		for(i=0;i<nodeIndex;i++)
		{
			pNode=pNode->pNextNode;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux;
    Node* auxNodo;
    Node* prevNodo;
    auxNodo=(Node*)malloc(sizeof(Node*));
    returnAux=-1;
    if(this!=NULL&&(nodeIndex>=0&&nodeIndex<=this->size)&&auxNodo!=NULL)
    {
    	auxNodo->pElement=pElement;
    	if(nodeIndex!=0)
    	{
    		prevNodo=getNode(this, nodeIndex-1);
    		if(prevNodo!=NULL)
    		{
    			auxNodo->pNextNode=prevNodo->pNextNode;
    			prevNodo->pNextNode=auxNodo;
    		}

    	}
    	else
    	{
    		auxNodo->pNextNode=this->pFirstNode;
    		this->pFirstNode=auxNodo;
    	}
    	returnAux=0;
    	this->size++;

    }
    	return returnAux;

}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	addNode(this, this->size, pElement);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxnodo;
    if(this!=NULL&&(index>=0&&index<this->size))
    {
    	auxnodo=getNode(this, index);
    	returnAux=auxnodo->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxnodo;
    if(this!=NULL&&(index>=0&&index<this->size))
    {
    	auxnodo=getNode(this, index);
		auxnodo->pElement=pElement;
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxnodo;
    Node* prevnodo;
    if(this!=NULL&&(index>=0&&index<this->size))
    {
    	auxnodo=getNode(this, index);
    	if(index!=0)
    	{
    		prevnodo=getNode(this,index-1);
    		prevnodo->pNextNode=auxnodo->pNextNode;
    	}
    	else
    	{
    		this->pFirstNode=auxnodo->pNextNode;
    	}
    	this->size--;
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {
    	for(i=0;i<this->size;i++)
    	{
    		ll_remove(this, i);
    	}
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    Node* aux;
    int i;
    if(this!=NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		aux=ll_get(this, i);
    		free(aux);
    	}
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {
    	for(i=0;i<this->size;i++)
    	{
    		if(getNode(this, i)->pElement==pElement)
    		{
    			returnAux=i;
    			break;
    		}
    	}

    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(this->size==0)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL&&(index>=0&&index<=this->size))
    {
    	addNode(this, index, pElement);
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;
	Node* auxnodo;
	if(this!=NULL&&(index>=0&&index<this->size))
	{
		auxnodo=getNode(this, index);
		ll_remove(this, index);
		returnAux=auxnodo->pElement;
	}
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {
    	returnAux=0;
    	for(i=0;i<this->size;i++)
    	{
    		if(ll_get(this,i)==pElement)
    		{
    			returnAux=1;
    		}
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    if(this!=NULL&&this2!=NULL)
    {
    	returnAux=1;
    	for(i=0;i<this2->size;i++)
    	{
    		if(ll_contains(this,getNode(this2, i)->pElement)==0)
    		{
    			returnAux=0;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    if(this!=NULL&&(from>=0&&from<this->size)&&(to>from&&to<=this->size))
    {
    	cloneArray=ll_newLinkedList();
    	for(i=from;i<to;i++)
    	{
    		ll_add(cloneArray,ll_get(this,i));
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray=ll_newLinkedList();
    	cloneArray=ll_subList(this, 0, this->size);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    Node* auxnodo;
    int i;
    int j;
    if(this!=NULL&&pFunc!=NULL&&(order==1||order==0))
    {
    	for(i=0;i<=this->size-1;i++)
    	{
    		for(j=i+1;j<this->size;j++)
    		{
    			if( (pFunc( ll_get(this, i), ll_get(this, j) ) > 0 && order) ||(pFunc(ll_get(this, i), ll_get(this, j)) < 0 && !order))
    			{
    				auxnodo=ll_get(this, i);
    				ll_set(this, i,ll_get(this, j));
    				ll_set(this, j, auxnodo);
    			}
    		}
    	}
    	returnAux=0;
    }
    return returnAux;

}
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* lista_filtrada;
	int i;
	lista_filtrada=ll_newLinkedList();
	if(this!=NULL&&fn!=NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			//element=ll_get(this, i);
			if(fn(ll_get(this, i))==1)
			{
				ll_add(lista_filtrada, ll_get(this, i));
			}
		}
	}
	return lista_filtrada;
}
LinkedList* ll_map(LinkedList* this,int(*fn)(void* element))
{
	LinkedList* lista_mapeada;
	int i;
	eLibro* libro_aux;
	lista_mapeada=ll_newLinkedList();
	if(this!=NULL&&fn!=NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			switch(fn(ll_get(this, i)))
			{
				case 1:
					libro_aux=ll_get(this, i);
					libro_aux->precio=libro_aux->precio-(libro_aux->precio)*0.2;
					ll_add(lista_mapeada,libro_aux);
					break;
				case 2:
					libro_aux=ll_get(this,i);
					libro_aux->precio=libro_aux->precio-(libro_aux->precio)*0.1;
					ll_add(lista_mapeada, libro_aux);
					break;
			}
		}
	}
	return lista_mapeada;
}
