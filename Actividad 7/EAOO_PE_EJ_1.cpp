/*
Eliel Alfonso Ontiveros Ojeda_368746
23-Sep-2023 / 23-Sep-2023
PROGRAMA QUE LLAME LOS 4 EJERCICIOS
OOEA_Act7_1_932
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validar(char mensaje[], int ri, int rf);
int msge ();
void menu ();
void normal (void);
void alreves (void);
void descendente (void);
void ascendente (void);
void dism_normal (void);
void dism_alreves (void);

int main ()
{
    menu();

    return 0;
}

int msge()  //Corregir las opciones a elegir
{
    int op; //Declaramos la variable donde guardaremos la opcion de que operacion realizaremos
    system ("CLS"); //Sirve para limpiar la pantalla al momento de llamar nuestra funcion
    printf("-----M E N U-----\n");
    printf("1 - NORMAL\n");
    printf("2 - ALREVES\n");
    printf("3 - DESCENDENTE\n");
    printf("4 - ASCENDENTE\n");
    printf("5 - Disminucion normal\n");
    printf("6 - Disminucion alreves\n");
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
        op = msge(); //Llamamos a nuestra funcion msgs para guardar el valor de op guardado en ella y guardarla en la funcion menu
        switch (op) 
        {
        case 1: 
            normal();

            break;

        case 2:
            alreves();

            break;

        case 3:
            descendente();

            break;

        case 4:
            ascendente();

            break;

        case 5:
            dism_normal();

            break;

        case 6:
            dism_alreves();

            break;

        default:
            break;
        }

    } while (op != 0); //Si op es diferente a 0 la opcion saldra del bucle y continuara a la funcion seleccionada
    
}

void normal()
{
    system ("CLS");
    char palabra[30];
    strcpy(palabra, "ENSENADA");
    printf("%s\n", palabra);

    system ("PAUSE");

}

void alreves ()
{
    system ("CLS");
    char palabra[30];
    int longitud;
    strcpy(palabra, "ENSENADA");
    longitud = strlen(palabra);

    for (int i = longitud - 1; i >= 0; i--)
    {
        printf("%c", palabra[i]);
    }

    printf("\n");

    system ("PAUSE");
    
}

void descendente ()
{
    system ("CLS");
    char palabra[30];
    int longitud;
    strcpy(palabra, "ENSENADA");
    longitud = strlen(palabra);

    for (int i = 0; i <= longitud; i++)
    {
        printf("%c\n", palabra[i]);
    }

    system ("PAUSE");
    
}

void ascendente ()
{
    system ("CLS");
    char palabra[30];
    int longitud;
    strcpy(palabra, "ENSENADA");
    longitud = strlen(palabra);

    for (int i = longitud; i >= 0; i--)
    {
        printf("%c\n", palabra[i]);
    }

    system ("PAUSE");
    
}

void dism_normal ()
{
    system ("CLS");
    char palabra[30];
    int longitud;
    strcpy(palabra, "ENSENADA");
    longitud = strlen(palabra);

    for (int i = longitud; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }

    system ("PAUSE");
    
}

void dism_alreves ()
{
    system ("CLS");
    char palabra[30];
    int longitud;
    strcpy(palabra, "ENSENADA");
    longitud = strlen(palabra);

    for (int i = longitud; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
        
    }

    system("PAUSE");
    
}