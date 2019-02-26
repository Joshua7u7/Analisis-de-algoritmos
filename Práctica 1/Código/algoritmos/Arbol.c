#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

Arbol crearArbol()
{
	Arbol a= (Arbol)malloc(sizeof(Nodo));
	a = NULL;
	return a;
}

Nodo_Arbol crearNodo(int n)
{
	Nodo_Arbol Nuevo = (Nodo_Arbol)malloc(sizeof(struct nodo));
	Nuevo -> numero = n;
	Nuevo -> izquierdo = NULL;
	Nuevo -> derecho = NULL;
	return Nuevo;
}

void Insertar( Arbol * A, int n)
{
	if(*A==NULL)
	{
		Nodo_Arbol nuevo=crearNodo(n);
		*A=nuevo;
	}
	else
	{
		if((*A)->numero>n)
			Insertar(&(*A)->izquierdo,n);
		else
			Insertar(&(*A)->derecho,n);
	}
}

void InOrden(Arbol * A)
{
	if((*A)==NULL)
		printf(" ");

	if((*A)!=NULL)
	{
		InOrden(&(*A)->izquierdo);
		printf(" %d - ",(*A)->numero);
		InOrden(&(*A)->derecho);
	}
}

