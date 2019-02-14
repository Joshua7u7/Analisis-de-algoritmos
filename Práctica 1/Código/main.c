#include <stdio.h>
#include <stdlib.h>
#include "Ordenamiento.h"

int * crearArreglo();

int main(int argc, char** argv)
{
	int * arreglo = crearArreglo();

	printf("\n%d\n",sizeof(arreglo));

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