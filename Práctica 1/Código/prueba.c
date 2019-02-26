#include <stdio.h>
#include <stdlib.h>
#include "algoritmos/Ordenamiento.h"
#include "Tiempo/tiempo.h"
#include "algoritmos/Ordenamiento.c"
#include "Tiempo/tiempo.c"

int * crearArreglo(int n);
int * llenarArreglo(int * arreglo,int n);

int main(int argc, char** argv)
{
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	int n; 	
	int i; 
	int opcion;

	if (argc!=3) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		printf("\nIndique la opción del algoritmo de 1 a 6\n");
		exit(1);
	} 

	else
	{
		n=atoi(argv[1]);
		opcion=atoi(argv[2]);

	}

	int * arreglo = crearArreglo(n);

	arreglo=llenarArreglo(arreglo,n);

	



	uswtime(&utime0, &stime0, &wtime0);

    arreglo=seleccionDeOrdenamiento( arreglo, n, opcion);

	uswtime(&utime1, &stime1, &wtime1);
/*
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	

	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	mostrarArreglo(arreglo,n,opcion);
*/
	printf("%.10e  %.10e  %.10e \n",wtime1 - wtime0,utime1 - utime0,stime1 - stime0);
	return 0;
}


int * crearArreglo(int n)
{
	int * nuevo;
	nuevo = (int*)malloc(sizeof(int)*n);
	
	if(nuevo==NULL)
	{
		printf("\nMemoria no asignada\n");
		exit(0);
	}
	return nuevo;
}




int * llenarArreglo(int * arreglo,int n)
{
	FILE * archivo;

	int * aux=arreglo;
	
	archivo=fopen("numeros10millones.txt","r");

	char c;
	int cont=0;
	while((c=fgetc(archivo))!=EOF)
	{
		if(cont==n)
			break;

		if(c!='\n')
		{
			*arreglo = atoi(&c);
			arreglo++;	
		}
		cont++;
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