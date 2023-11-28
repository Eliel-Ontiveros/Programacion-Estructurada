/*
Eliel Alfonso Ontiveros Ojeda_368746
14-Nov-2023 /
REALICE EL SIGUIENTE PROGRAMA QUE CONTENGA UN MENÚ.

MENÚ

1.- AGREGAR (AUTOM 100 REGISTROS)

2.- EDITAR REGISTRO

3.- ELIMINAR REGISTRO (lógico)

4.- BUSCAR

5.- ORDENAR

6- IMPRIMIR

7.- GENERAR ARCHIVO TEXTO

8.- VER ARCHIVO TEXTO

9.- CREAR ARCH BINARIO

10.- CARGAR ARCH BINARIO

11.- MOSTRAR ELIMINADOS

 0.- SALIR
*/

#include "Funciones.h"

#define N 20
#define NR 5000
#define FALSE 0
#define TRUE 1
#define ACTIVO 1
#define INACTIVO 0

void Menu(void);
void ImprimirMenu(void);
void GenArchivoT(tdato vect[], int n);
void LeerArchivoT(void);
int LeerRegistroArchivoT(tdato vect[], int n);
void GenArchivoB(tdato vect[], int n);
int LeerArchivoB(tdato vect[], int n);

int main()
{
    Menu();

    return 0;
}

void Menu(void)
{
    int op, n;
    int i, j;
    int resultado;
    int buscar_num;
    int ord;
    tdato vect[N], reg;
    long buscamatri;
    ord = FALSE;
    n = N - 1;

    do
    {
        system("CLS");
        Menu();
    }

    while (op != 0);
    {
        /* code */
    }
}

int msge()
{
    system("cls");
    printf("----------------------------------\n");
    printf("              Menu\n");
    printf("----------------------------------\n");
    printf("|| 1 - Agregar                  ||\n");
    printf("|| 2 - Editar Registro         ||\n");
    printf("|| 2 - Eliminar Registro        ||\n");
    printf("|| 3 - Buscar                   ||\n");
    printf("|| 4 - Ordenar                  ||\n");
    printf("|| 5 - Imprimir                 ||\n");
    printf("|| 6 - Generar Archivo Texto    ||\n");
    printf("|| 7 - Ver Archivo Texto        ||\n");
    printf("|| 8 - Generar Archivo Binario  ||\n");
    printf("|| 9 - Ver Archivo Binario      ||\n");
    printf("|| 0 - Salir                    ||\n");
    printf("|| Selecciona una opcion:       ||\n");
    printf("----------------------------------\n");
    printf("----------------------------------");
}