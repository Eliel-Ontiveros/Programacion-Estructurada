//Eliel Alfonso Ontiveros Ojeda_368746
//24-Ago-2023 / 24-Ago-2023
//Algoritmo que lea 3 números y desplegar cuál número es el menor y su valor
//OOEA_Act1_7_932
#include <stdio.h>
int main()
{
    int num1, num2, num3;
    printf("Ingrese el primer numero\n");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero\n");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero\n");
    scanf("%d", &num3);
    if (num1 < num2 && num1 < num3)
    {
        printf("El numero %d es el menor", num1);
    }
    else if (num2 < num1 && num2 < num3)
    {
        printf("El numero %d es el menor", num2);
    }
    else if (num3 < num1 && num3 < num2)
    {
        printf("El numero %d es el menor", num3);
    }
    return 0;
}