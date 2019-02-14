#include <stdio.h>

#define Si 1
#define No -1

int * burbuja(int * arreglo,int n);
int * burbujaOptimizada(int * arreglo,int n);
int * insercion(int * arreglo, int n);
int * seleccion(int * arreglo, int n);
int * shell(int * arreglo, int n);



int * burbuja(int * arreglo,int n)
{
	int aux;
	for (int i=0; i<n-2; i++)
	{
		for (int j=0; j<(n-2)-i;j++)
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

	}while((i<n-1) && cambios!=No)

	return arreglo;
}


int * insercion(int * arreglo, int n)
{
	int j,temp;
	for(int i=0;i<n-1;i++)
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

	for (int k=0;k<n-2;k++)
	{
		p=k;
		for (int i=k+1; i<n-1; i++)
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
	int k= n/2;
	int temp,b;

	while (k >= 1)
	{
		b = 1;

		while(b!=0)
		{
			b=0;
			for (int i=k; i >= n-1; i++)
			{
				if(arreglo[i-k]>arreglo[i])
				{
					temp=arreglo[i];
					arreglo[i] = arreglo[i-k];
					arreglo[i-k] = temp;
					b++;
				}
			}
		}
		k=k/2;
	}
	return arreglo;
}