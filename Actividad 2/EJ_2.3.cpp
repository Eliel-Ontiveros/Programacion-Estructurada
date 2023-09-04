//Eliel Alfonso Ontiveros Ojeda_368746
//29-Ago-2023 / 
//Programa que lea 6 numeros y despliegue el mayor
//OOEA_Act2_3_932

#include <stdio.h>
int main()
{
    int num1, num2, num3, num4, num5, num6;
    printf("Ingrese un numero\n");
    scanf("%d", &num1);
    printf("Ingrese un numero\n");
    scanf("%d", &num2);
    printf("Ingrese un numero\n");
    scanf("%d", &num3);
    printf("Ingrese un numero\n");
    scanf("%d", &num4);
    printf("Ingrese un numero\n");
    scanf("%d", &num5);
    printf("Ingrese un numero\n");
    scanf("%d", &num6);

    if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6)
    {
        printf("El numero %d es el mayor", num1);
    }

    else
    {
        if (num2 > num1 && num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6)
        {
            printf("El numero %d es el mayor", num2);
        }

        else
        {
            if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5 && num3 > num6)
            {
                printf("El numero %d es el mayor", num3);
            }

            else
            {
                if (num4 > num1 && num4 > num2 && num4 > num3 && num4 > num5 && num4 > num6)
                {
                    printf("El numero %d es el mayor");
                }

                else
                {
                    if (num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 && num5 >num6)
                    {
                        printf("El numero %d es el mayor");
                    }

                    else
                    {
                        if (num6 > num1 && num6 > num2 && num6 > num3 && num6 > num4 && num6 > num5)
                        {
                            printf("El numero %d es el mayor");
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    
    return 0;
    
}