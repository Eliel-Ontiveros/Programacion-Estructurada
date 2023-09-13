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

void der_exam (void);

void tab_mult (void);

void sum_med_arit (void);

void turist_peso (void);

void prom_final (void);

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
    printf("1 - Promedio y Derecho a Examen\n");
    printf("2 - Tabla de Multiplicar del 1 al 10\n");
    printf("3 - Suma y Media Aritmetica\n");
    printf("4 - Promedio Peso de Turistas");
    printf("5- Promedio de Alumno");
    printf("0 - Salir\n");
    printf("Seleccione una de las opciones\n");
    scanf("%d", &op); //Escaneamos la seleccion dentro de la variable op
    
    return op;

}

void menu()
{
    int op; //Volvemos a declarar la variable op para poder llamarla desde la funcion msgs
    do //Mientras op este entre los valor de 1 y 4 se seleccionara una opcion y saldra del bucle
    {
        op = msgs(); //Llamamos a nuestra funcion msgs para guardar el valor de op guardado en ella y guardarla en la funcion menu
        switch (op) 
        {
        case 1: 
            der_exam();

            break;

        case 2:
            tab_mult();

            break;

        case 3:
            sum_med_arit();

            break;

        case 4:

            turist_peso();

            break;

        case 5:

            prom_final();

            break;

        default:
            break;
        }

    } while (op != 0); //Si op es diferente a 0 la opcion saldra del bucle y continuara a la funcion seleccionada
    
}

/*Desarrollo Funcion Derecho a Examen*/
void der_exam()
{

}

/*Desarrollo Funcion Tabla de Multiplicar*/
void tab_mult()
{

}

/*Desarrollo Funcion Suma y Media Aritmetica*/
void sum_med_arit()
{

}

/*Desarrollo Funcion Promedio de Peso Turistas*/
void turist_peso()
{

}

/*Desarrollo Funcion Promedio Final de Alumnos*/
void prom_final()
{
    
}