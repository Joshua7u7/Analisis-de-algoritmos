#include <stdio.h>

#ifndef arbol
#define arbol


typedef struct nodo
{
	int numero;
	struct nodo * izquierdo;
	struct nodo * derecho;
}Nodo;

typedef Nodo * Nodo_Arbol;
typedef Nodo * Arbol;

Arbol crearArbol();
Nodo_Arbol crearNodo(int);
void Insertar(Arbol *, int );
void InOrden(Arbol *);





#endif