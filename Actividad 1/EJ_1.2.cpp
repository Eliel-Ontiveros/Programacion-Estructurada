//Eliel Alfonso Ontiveros Ojeda_368746
//22-Ago-2023 / 22-Ago-2023
//Algoritmo que lea un número entero, y desplegar si el número es “PAR” o “IMPAR”
//OOEA_Act1_2_932
#include <stdio.h>
int main()
{
    int num;
    int residuo;
    printf("Ingrese un numero entero\n");
    scanf("%d", &num);
    residuo = num % 2;
    if (residuo == 0)
    {
        printf("%d Es un numero PAR", num);
    }
    else
    {
        printf("Es un numero IMPAR", num);
    }
    
    return 0;
}