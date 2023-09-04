//Eliel Alfonso Ontiveros Ojeda_368746
//22-Ago-2023 / 22-Ago-2023
//Algoritmo que a través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual es su SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”
//OOEA_Act1_4_932
#include <stdio.h>
int main()
{
    int op;
    printf("Ingrese si es Hombre o Mujer\n");
    printf("Ingrese 1 para Hombre\n");
    printf("Ingrese 2 para Mujer\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Hola, Eres Hombre\n");
        break;
    case 2:
        printf("Hola, Eres Mujer\n");
        break;
    
    default:
        printf("Opcion invalida\n");
        break;
    }
    return 0;
}