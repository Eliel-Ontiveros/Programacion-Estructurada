// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 05-Sep-2023
//Programa en C que lea 3 números y desplegar el número del medio (usar AND o OR)
//OOEA_Act3_5_932

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

    if (num1 > num2 && num1 < num3)
    {
        printf("El numero %d es el del medio", num1);
    }

    else
    {
        if (num2 > num1 && num2 < num3)
        {
            printf("El numero %d es el del medio", num2);
        }

        else
        {
            if (num3 > num1 && num3 < num2)
            {
                printf("El numero %d es el del medio", num3);
            }

            else
            {
                printf("Corrige el codigo");
            }
            
        }
        
    }

    return 0;
    
}