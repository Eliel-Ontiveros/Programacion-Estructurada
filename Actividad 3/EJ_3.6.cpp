// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 /
//Programa en C que lea 3 números y despegarlos en forma ascendente (usar AND o OR)
//OOEA_Act3_6_932

#include <stdio.h>

int main()
{
    int num1, num2, num3;

    printf("Ingrese un numero entero\n");
    scanf("%d", &num1);
    printf("Ingrese un numero entero\n");
    scanf("%d", &num2);
    printf("Ingrese un numero entero\n");
    scanf("%d", &num3);
    
    if (num1 > num2 && num1 < num3 && num2 < num3)
    {
        printf("Los numeros ordenados de forma ascendente quedarian:\n");
        printf("%d - %d - %d", num2, num1, num3);
    }

    if (num2 > num1 && num2 < num3 && num1 < num3)
    {
        printf("Los numeros ordenados de forma ascendente quedarian:\n");
        printf("%d - %d - %d", num1, num2, num3);
    }

    if (num3 > num1 && num3 < num2 && num1 < num2)
    {
        printf("Los numeros ordenados de forma ascendente quedarian:\n");
        printf("%d - %d - %d", num1, num3, num2);
    }

     return 0;
            
}