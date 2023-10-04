#include "chntoky.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validar_num(char mensaje[], int ri, int rf)
{
    int num;
    do 
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &num);
    } 
    while (num < ri || num > rf);
    
    return num;
    
}

void random_vect(int n, int vect[], int ri, int rf)
{
    srand(time(0)); // Inicializa la semilla del generador de números aleatorios

    for(int i = 0; i < n; i++)  /* Ciclo for para recorrer el vector*/
    {
        vect[i] = ri + rand() % (rf - ri + 1); // Genera un número aleatorio entre 1 y 20 y lo guarda en el vector
    }
}

void imp_vector(int n, int vect[])
{
    printf("Vector:\n"); // Imprime el título del vector 
    for(int i = 0; i < n; i++)  // Ciclo for para recorrer el vector 
    {
        printf("%d - ", vect[i]); // Imprime el valor actual del vector 
    }
}