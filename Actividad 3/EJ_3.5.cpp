// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 05-Sep-2023
//Programa en C que lea 3 números y desplegar el número del medio (usar AND o OR)
//OOEA_Act3_5_932

#include <stdio.h> //Agregamos las librerias que utilizaremos

int main() //Iniciamos nuestra funcion principal
{
    int num1, num2, num3; //Declaramos las variables que utilizaremos

    printf("Ingrese un numero entero\n");
    scanf("%d", &num1); //Escanea un numero entero introducido por el usuario para guardarlo en la variable num1
    printf("Ingrese un numero entero\n");
    scanf("%d", &num2); //Escanea un numero entero introducido por el usuario para guardarlo en la variable num2
    printf("Ingrese un numero entero\n");
    scanf("%d", &num3); //Escanea un numero entero introducido por el usuario para guardarlo en la variable num3

    if (num1 > num2 && num1 < num3) //Condicional para comprobar cual es el numero del medio, en este caso se asume que seria el num1
    {
        printf("El numero %d es el del medio", num1);
    }

    else
    {
        if (num2 > num1 && num2 < num3) //Condicional para comprobar cual es el numero del medio, en este caso se asume que seria el num2
        {
            printf("El numero %d es el del medio", num2);
        }

        else
        {
            if (num3 > num1 && num3 < num2) //Condicional para comprobar cual es el numero del medio, en este caso se asume que seria el num3
            {
                printf("El numero %d es el del medio", num3);
            }
    
        }
        
    }

    return 0; //Terminamos nuestra funcion principal
    
}