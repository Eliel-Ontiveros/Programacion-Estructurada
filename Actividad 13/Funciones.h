#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 5000
#define FALSE 0
#define TRUE 1
#define ACTIVO 1
#define INACTIVO 0

typedef struct _tdato
{
	int status;
	long matricula;
	char nombre[30];
	char apPat[30];
	char apMat[30];
	int edad;
	char sexo[10];
	char puesto[20];
	int numero_tel;
} tdato;

int Ordenar(tdato vect[], int n);

long genMatricula(int rangoMin, int rangoMax)
{
	long matricula;
	int limite;
	limite = rangoMax - rangoMin;
	matricula = (long)(rand() % limite) + rangoMin;
	return matricula;
}

void genNombre(int num, char nom[])
{

	char palabra[20][10] = {"Maria", "Jose", "Juan", "Luis", "Francisco", "Jesus", "Ana", "Rosa", "Jorge", "Miguel", "Carlos", "Juana", "Martha", "Guadalupe", "Pedro", "Manuel", "Victor", "Antonio", "Alejandro", "Margarita"};
	strcpy(nom, palabra[num]);
}

void genapPat(int num, char pat[])
{
	char palabra[20][10] = {"Hernandez", "Garcia", "Martinez", "Lopez", "Gonzalez", "Perez", "Rodriguez", "Sanchez", "Ramirez", "Cruz", "Flores", "Gomez", "Morales", "Vazquez", "Reyes", "Jimenez", "Torres", "Diaz", "Gutierrez", "Ruiz"};
	strcpy(pat, palabra[num]);
}

void genapMat(int num, char mat[])
{
	char palabra[20][10] = {"Gonzalez", "Rodriguez", "Gomez", "Fernandez", "Lopez", "Diaz", "Martinez", "Perez", "Romero", "Sanchez", "Martinez", "Lopez", "Gonzalez", "Perez", "Rodriguez", "Sanchez", "Ramirez", "Cruz", "Flores", "Gomez"};
	strcpy(mat, palabra[num]);
}

int genEdad(int rangoMin, int rangoMax)
{
	int Edad, limite;
	limite = rangoMax - rangoMin;
	Edad = (rand() % limite) + rangoMin;
	return Edad;
}

void genSexo(int num, char sexo[])
{
	if (num <= 10)
	{
		strcpy(sexo, "Hombre");
	}
	else
	{
		strcpy(sexo, "Mujer");
	}
}

void genPuesto(int num, char pues[])
{
	char palabra[20][40] = {"Manager", "Ventas", "Contador", "RH", "Sub-Manager", "Mantenimiento", "Almacen"};
	strcpy(pues, palabra[num % 7]); // Use modulo to ensure it stays within the array bounds
}

tdato genRegistro()
{
	int num;
	num = rand() % 20;
	tdato reg;
	reg.status = 1;
	reg.matricula = genMatricula(100000, 199999);
	genNombre(num, reg.nombre);
	genapPat(num, reg.apPat);
	genapMat(num, reg.apMat);
	reg.edad = genEdad(18, 30);
	genSexo(num, reg.sexo);
	genPuesto(num, reg.puesto);
	return reg;
}

void ImprimirVect(tdato vect[], int n)
{
    system("cls");
    int i;
    printf("--------------------------------------------------------\n");
    printf("  No Matricula Nombre    apPat     apMat    Puesto    Edad Sexo  \n");
    printf("--------------------------------------------------------\n");

    int registrosImpresos = 0;

    for (i = 0; i <= n; i++)
    {
        if (vect[i].status == 1)
        {
            printf("||%-2d %-9ld %-9s %-9s %-9s %-12s %-2d %-6s||\n", i + 1, vect[i].matricula, vect[i].nombre, vect[i].apPat, vect[i].apMat, vect[i].puesto, vect[i].edad, vect[i].sexo);

            registrosImpresos++;

            if (registrosImpresos % 100 == 0)
            {
                printf("--------------------------------------------------------\n");
                printf("Presiona Enter para continuar...");
                system("PAUSE"); 
                system("cls");
                printf("--------------------------------------------------------\n");
                printf("  No Matricula Nombre    apPat     apMat    Puesto    Edad Sexo  \n");
                printf("--------------------------------------------------------\n");
            }
        }
    }

    if (registrosImpresos % 100 != 0)
    {
        printf("--------------------------------------------------------\n");
    }

    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    system("PAUSE");
}




int BuscarSec(tdato vect[], int n, long buscamatri)
{
    int i;
    for (i = 0; i < n; i++)  // Cambiado el operador <= a <
    {
        if (vect[i].matricula == buscamatri && vect[i].status == ACTIVO)
        {
            return i;
        }
    }
    return -1;
}


int EliminarLogico(tdato vect[], int n, int buscanum)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		if (i == buscanum - 1)
		{
			vect[i].status = 0;
			return i;
		}
	}
	return -1;
}

int Ordenar(tdato vect[], int n)
{
	int i, j;
	tdato temp;
	int registrosActivos = 0;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (vect[i].matricula > vect[j].matricula)
			{
				temp = vect[i];
				vect[i] = vect[j];
				vect[j] = temp;
			}
		}

		if (vect[i].status == ACTIVO)
		{
			registrosActivos++;
		}
	}

	return registrosActivos;
}
