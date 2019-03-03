#include <stdio.h>
#include "Ordenamiento.h"
#include "Arbol.h"
#include "Arbol.c"

int * burbuja(int * arreglo,int n)
{
	int aux;
	for (int i=0; i<=n-2; i++)
	{
		for (int j=0; j<=(n-2)-i;j++)
		{
			if (arreglo[j]>arreglo[j+1])
			{
				aux=arreglo[j];
				arreglo[j]=arreglo[j+1];
				arreglo[j+1]=aux;
			}
		}
	}
	return arreglo;
}


int * burbujaOptimizada(int * arreglo,int n)
{
	int cambios = No;
	int i=0;
	int aux;

	do
	{
		cambios = No;

		for (int j=0;j<(n-2)-i;j++)
		{
			if(arreglo[i] < arreglo[j])
			{
				aux = arreglo[j];
				arreglo[j] = arreglo[i];
				arreglo[i] = aux;
				cambios = Si;
			}
		}
		i++;

	}while((i<n-1) && cambios!=No);

	return arreglo;
}


int * insercion(int * arreglo, int n)
{
	int j,temp;
	for(int i=0;i<=n-1;i++)
	{
		j=i;
		temp=arreglo[i];

		while ((j>0) && (temp<arreglo[j-1]))
		{
			arreglo[j] = arreglo[j-1];
			j--;
		}
		arreglo[j]=temp;
	}
	return arreglo;
}


int * seleccion(int * arreglo,int n)
{
	int p,temp;

	for (int k=0;k<=n-2;k++)
	{
		p=k;
		for (int i=k+1; i<=n-1; i++)
		{
			if (arreglo[i] < arreglo[p])
				p = i;
		}
		temp = arreglo[p];
		arreglo[p] = arreglo[k];
		arreglo[k] = temp;
	}

	return arreglo;
}

int * shell(int * arreglo, int n)
{
	int temp;
 
	for(int cont=n/2;cont!=0;cont/=2)
		for(int pasos=1;pasos!=0;)
		{
			pasos=0;
			for(int i=cont;i<n;i++)
				if(arreglo[i-cont]>arreglo[i])
				{
					temp=arreglo[i];
					arreglo[i]=arreglo[i-cont];
					arreglo[i-cont]=temp;
					pasos++;
				}
		}
	return arreglo;
}

void Arbol_O (int * arreglo,int n)
{
	Arbol A = crearArbol();
	for(int i=0;i<n;i++)
	{
		Insertar(&A,arreglo[i]);
	}
	//InOrden(&A);
}

void mostrarArreglo(int * arreglo, int n,int opcion)
{
	if(opcion==6)
	{   
		Arbol A = crearArbol();
		for(int i=0;i<n;i++)
		{
			Insertar(&A,arreglo[i]);
		}
		InOrden(&A);
	}

	else
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
	
}


int * seleccionDeOrdenamiento(int * arreglo, int n, int opcion)
{
	switch(opcion)
	{
		case 1:
			return burbuja(arreglo,n);
		break;
		case 2:
			return burbujaOptimizada(arreglo,n);
		break;
		case 3:
			return insercion(arreglo,n);
		break;
		case 4:
			return seleccion(arreglo,n);
		break;
		case 5:
			return shell(arreglo,n);
		break;

		case 6:
			 Arbol_O(arreglo,n);
			 return arreglo;
		break;
	}
}