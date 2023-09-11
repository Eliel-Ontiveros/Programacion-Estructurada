// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 05-Sep-2023
//Programa en C que lea 3 números y despegarlos en forma ascendente (usar AND o OR)
//OOEA_Act3_6_932

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
    
    if (num1 > num2 && num1 < num3 && num2 < num3) //Condicional para comprobar el orden ascendente de los numeros introducidos, en este caso se asume que los numeros ordenados de forma ascendente quedaria num2, num1 y num3
    {
        printf("Los numeros ordenados de forma ascendente quedarian:\n");
        printf("%d - %d - %d", num2, num1, num3);
    }

    if (num2 > num1 && num2 < num3 && num1 < num3) //Condicional para comprobar el orden ascendente de los numeros introducidos, en este caso se asume que los numeros ordenados de forma ascendente quedaria num1, num2 y num3
    {
        printf("Los numeros ordenados de forma ascendente quedarian:\n");
        printf("%d - %d - %d", num1, num2, num3);
    }

    if (num3 > num1 && num3 < num2 && num1 < num2) //Condicional para comprobar el orden ascendente de los numeros introducidos, en este caso se asume que los numeros ordenados de forma ascendente quedaria num1, num3 y num2
    {
        printf("Los numeros ordenados de forma ascendente quedarian:\n");
        printf("%d - %d - %d", num1, num3, num2);
    }

     return 0; //Terminamos nuestra funcion principal
            
}