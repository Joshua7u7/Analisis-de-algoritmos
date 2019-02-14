#include <stdio.h>
#include <stdlib.h>
#include "Ordenamiento.h"

int * crearArreglo();
void mostrarArreglo(int * arreglo, int n);

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