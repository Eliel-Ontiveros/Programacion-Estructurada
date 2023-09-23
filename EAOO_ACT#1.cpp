/*
Eliel Alfonso Ontiveros Ojeda_368746
06-Sep-2023 / 08-Sep-2023
PROGRAMA QUE LLAME LOS 4 EJERCICIOS
OOEA_Act5_1_932
*/

#include <stdio.h>

/*Declaramos nuestras funciones con las que trabajaremos*/
void menu();
void menuFibonacci(void);
void fibonacciFor(void);
void fibonacciWhile(void);
void fibonacciDoWhile(void);
void menuFactorial(void);
void factorialFor(void);
void factorialWhile(void);
void factorialDoWhile(void);
void menuDigitCounter(void);
void digitCounterFor(void);
void digitCounterWhile(void);
void digitCounterDoWhile(void);

/*Iniciamos nuestra funcion main*/
int main()
{
    menu();
    
    return 0;
}

/*Desarrollo de la funcion menu*/
void menu()
{
    int op;
    start:
    printf("MENU:\n");
    printf("1 - Fibonacci\n");
    printf("2 - Factorial\n");
    printf("3 - Cantidad de digitos\n");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        menuFibonacci();
        break;
    case 2:
        menuFactorial();
        break;
    case 3:
        menuDigitCounter();
        break;
    default:
        printf("Selecciona una opcion valida");
        goto start;
        break;
    }
}

void menuFibonacci()
{
    int op;
    
    start:
    printf("Menu Fibonacci:\n");
    printf("1 - For\n");
    printf("2 - While\n");
    printf("3 - Do While\n");
    printf("Selecciona una opcion\n");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        fibonacciFor();
        break;
    case 2:
        fibonacciWhile();
        break;
    case 3:
        fibonacciDoWhile();
        break;
    default:
        printf("Opcion no valida");
        goto start;
        break;
    }
}


void fibonacciFor()
{
    int num;
    int n1 = -1, n2 = 1, aux = n1+n2;
    
    printf("Numero para la serie fibonacci\n");
    scanf("%i", &num);
    for (int i = 0; i < num ; i++)
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%i\n", aux);
    }

}


void fibonacciWhile()
{
    int num;
    int n1 = -1, n2 = 1, aux = n1+n2;
    
    printf("Numero para la serie fibonacci\n");
    scanf("%i", &num);
    
    int i = 0;
    while (i < num)
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%i\n", aux);
        i++;
    }
}


void fibonacciDoWhile()
{
    int num;
    int n1 = -1, n2 = 1, aux = n1+n2;
    
    printf("Numero para la serie fibonacci\n");
    scanf("%i", &num);

    int i = 0;
    do
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%i\n", aux);
        i++;
    } while (i < num);
}


void menuFactorial()
{
    int op;
    
    start:
    printf("Menu Factorial:\n");
    printf("1 - For\n");
    printf("2 - While\n");
    printf("3 - Do While\n");
    printf("Selecciona una opcion\n");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        factorialFor();
        break;
    case 2:
        factorialWhile();
        break;
    case 3:
        factorialDoWhile();
        break;
    default:
        printf("Opcion no valida");
        goto start;
        break;
    }
}


void factorialFor()
{
    int result = 1, num;

    printf("Numero a sacar el factorial\n");
    scanf("%i", &num);  

    for (int i = 0; i <= num; i++)
    {
        result = result * i; 
    }

    printf("El factorial del numero %i es = %i", num, result);
}


void factorialWhile()
{
    int result = 1, num;

    printf("Numero a sacar el factorial\n");
    scanf("%i", &num);  

    int i = 1;
    while (i <= num)
    {
        result = result * i;
        i++;
    }

    printf("El factorial del numero %i es = %i", num, result);
}


void factorialDoWhile()
{
    int result = 1, num;

    printf("Numero a sacar el factorial\n");
    scanf("%i", &num);  

    int i = 1;
    do
    {
        result = result * i;
        i++;
    } while (i <= num);

    printf("El factorial del numero %i es = %i", num, result);
}


void menuDigitCounter()
{
    int op;
    
    start:
    printf("Menu Contar Digitos:\n");
    printf("1 - For\n");
    printf("2 - While\n");
    printf("3 - Do While\n");
    printf("Selecciona una opcion\n");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        digitCounterFor();
        break;
    case 2:
        digitCounterWhile();
        break;
    case 3:
        digitCounterDoWhile();
        break;
    default:
        printf("Opcion no valida");
        goto start;
        break;
    }
}


void digitCounterFor()
{
    int num, aux, dig;
    int i = 0;
    
    printf("Numero a contar los digitos\n");
    scanf("%i", &num);
    
    aux = num;
    for (i; aux > 0; i++)
    {
        aux = aux / 10;
    }
    
    printf("%i", i);
}


void digitCounterWhile()
{
    int num, aux, dig;
    
    printf("Numero a contar los digitos\n");
    scanf("%i", &num);
    
    aux = num;
    int i = 0;
    while (aux > 0)
    {
        aux = aux / 10;
        i++;
    }

    printf("%i", i);
}


void digitCounterDoWhile()
{
    int num, aux, dig;
    
    printf("Numero a contar los digitos\n");
    scanf("%i", &num);
    
    aux = num;
    int i = 0;
    do
    {
        aux = aux / 10;
        i++;
    } while (aux > 0);

    printf("%i", i);
}