// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 05-Sep-2023
//Programa en C que lea 3 números y desplegar cuál número es el mayor (usar AND o OR)
//OOEA_Act3_4_932

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

    if (num1 > num2 && num1 >num3)
    {
        printf("El numero %d es el mayor", num1);
    }

    else
    {
        if (num2 > num1 && num2 > num3)
        {
            printf("El numero %d es el mayor", num2);
        }

        else
        {
            printf("El numero %d es el mayor", num3);
        }
        
    }

    return 0;
    
}
