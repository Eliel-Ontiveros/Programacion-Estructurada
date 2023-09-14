/*
Eliel Alfonso Ontiveros Ojeda_368746
06-Sep-2023 / 08-Sep-2023
PROGRAMA QUE LLAME LOS 4 EJERCICIOS
OOEA_Act5_1_932
*/

/*Agregamos las librerias que utilizaremos*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*Declaramos las funciones que utilizaremos durante la realizacion del programa*/
int resultado;

int msgs(); //Funcion para guardar la seleccion de la funcion que queremos realizar

void menu(); //Esta funcion nos servira para guardar las demas funciones dentro de ella, sera nuestro esqueleto

void fibon (void);

void fact (void);

void cant_dig (void);

int main() /*En nuestra funcion main llamamos solamente al esqueleto donde se encuentran nuestras funciones*/
{
    menu ();

    return 0;
}

/*Desarrollo Funcion MSGS*/
int msgs()
{
    int op; //Declaramos la variable donde guardaremos la opcion de que operacion realizaremos
    system ("CLS"); //Sirve para limpiar la pantalla al momento de llamar nuestra funcion
    printf("-----M E N U-----\n");
    printf("1 - Fibonacci\n");
    printf("2 - Factorial\n");
    printf("3 - Cantidad de digitos\n");
    printf("0 - Salir\n");
    printf("Seleccione una de las opciones\n");
    scanf("%d", &op); //Escaneamos la seleccion dentro de la variable op
    

    return op;
    
}

/*Desarrollo Funcion MENU*/
void menu()
{
    int op; //Volvemos a declarar la variable op para poder llamarla desde la funcion msgs
    do //Mientras op este entre los valor de 1 y 4 se seleccionara una opcion y saldra del bucle
    {
        op = msgs(); //Llamamos a nuestra funcion msgs para guardar el valor de op guardado en ella y guardarla en la funcion menu
        switch (op) 
        {
        case 1: 
            fibon();

            break;

        case 2:
            fact();

            break;

        case 3:
            cant_dig();

            break;

        default:
            break;
        }

    } while (op != 0); //Si op es diferente a 0 la opcion saldra del bucle y continuara a la funcion seleccionada
    
}

/*Desarrollo Funcion Fibonacci*/
void fibon()
{
    int repetir, term1 = 0, term2 = 1, sig_term;

    printf("Ingrese las veces deseas que se realice la secuencia de Fibonacci\n");
    scanf("%d", &repetir);

    for (int i = 1; i <= repetir; ++i) 
    {
        term1 = 0;
        term2 = 1;
        printf("Secuencia de Fibonacci %d: ", i);
        for (int j = 1; j <= i; ++j) 
        {
            printf("%d, ", term1);
            sig_term = term1 + term2;
            term1 = term2;
            term2 = sig_term;
        }
        printf("\n");
    }

    system ("PAUSE");

}

/*Desarrollo Funcion Factorial*/
void fact ()
{

    system ("CLS");

    system ("PAUSE");

}

/*Desarrollo Funcion Cantidad de Digitos*/
void cant_dig ()
{

    system ("CLS");

    system ("PAUSE");

}
