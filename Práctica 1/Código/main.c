#include <stdio.h>
#include <stdlib.h>
#include "Ordenamiento.h"


int * crearArreglo();
void mostrarArreglo(int * arreglo, int n);
int * llenarArreglo(int * arreglo);

int main(int argc, char** argv)
{
	int * arreglo = crearArreglo();

	arreglo=llenarArreglo(arreglo);

	mostrarArreglo(arreglo,7);

	printf("\n");
	
	Arbol_O(arreglo,7);

	return 0;
}


int * crearArreglo()
{
	int * nuevo;
	nuevo = (int*)malloc(sizeof(int)*100);
	
	if(nuevo==NULL)
	{
		printf("\nMemoria no asignada\n");
		exit(0);
	}
	return nuevo;
}

void mostrarArreglo(int * arreglo, int n)
{
	for (int i=0;i<n;i++)
	{
		if((i%10)==0)
		{
			printf("\n");
		}

		printf("%d , ", arreglo[i]);
	}
}


int * llenarArreglo(int * arreglo)
{
	FILE * archivo;

	int * aux=arreglo;
	
	archivo=fopen("N.txt","r");

	char c;

	while((c=fgetc(archivo))!=EOF)
	{
		if(c!='\n')
		{
			*arreglo = atoi(&c);
			arreglo++;	
		}
	}

	arreglo=aux;
	return arreglo;
}


/*
Funcion()

Corre funcion tiempo

Algoritmo ordenamiento

Corre fuicnion tiempo final


Imprimir valores de la tabla

*/