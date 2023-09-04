//Eliel Alfonso Ontiveros Ojeda_368746
//24-Ago-2023 / 27-Ago-2023
//Algoritmo que lea 3 números y desplegar los 3 números en orden ascendente
//OOEA_Act1_9_932
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int a,b,c;

main()
{
printf("Ingrese el primer valor entero\n");
scanf("%d", &a);
printf("Ingrese el segundo valor entero\n");
scanf("%d", &b);
printf("Ingrese el tercer valor entero\n");
scanf("%d", &c);

    if(a<b)
    {
        if (a<c)
        {
            if (b<c)
            {
                printf("Los valores ordenados de menor a mayor son: %d %d %d\n\n", a,b,c);
            }
            else
            {
                printf("Los valores ordenados de menor a mayor son: %d %d %d\n\n", a,c,b);
            }
        }
    else
    {
        printf("Los valores ordenados de menor a mayor son: %d %d %d\n\n", c,a,b);
    }
    }

    else
    {
        if (a<c)
        {
            printf("Los valores ordenados de menor a mayor son: %d %d %d\n\n", b,a,c);
        }
        else if (c<b)
        {
            printf("Los valores ordenados de menor a mayor son: %d %d %d\n\n", c,b,a);
        }
        else
        {
            printf("Los valores ordenados de menor a mayor son: %d %d %d\n\n", b,c,a);
        }
        
}
    return 0;
    
}