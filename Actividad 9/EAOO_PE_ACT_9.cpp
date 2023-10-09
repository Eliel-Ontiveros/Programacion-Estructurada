/*
Eliel Alfonso Ontiveros Ojeda_368746
03-Oct-2023 / 08-Oct-2023
#Describir el Programa#
OOEA_Act9_1_932
*/

#include "chntoky.h"

int msgs ();
void menu ();
void valor_vector(int *vector, int tam);

int main()
{
    menu();

    return 0;
}


int msgs()
{
    int op; //Declaramos la variable donde guardaremos la opcion de que operacion realizaremos
    system ("CLS"); //Sirve para limpiar la pantalla al momento de llamar nuestra funcion
    printf("-----M E N U-----\n");
    printf("1 - Llenar Vector\n");
    printf("2 - Llenar Matriz\n");
    printf("3 - Imprimir Vector\n");
    printf("4 - Imprimir Matriz\n");
    printf("5 - Ordenar Vector\n");
    printf("6 - Buscar Valor En El Vector\n");
    printf("0 - Salir\n");
    op = validar_num("Seleccione una de las opciones\n", 0, 6);
    

    return op;
    
}

void menu()
{
    int op; //Volvemos a declarar la variable op para poder llamarla desde la funcion msgs
    int tam;
    tam = 15;
    int vect[tam];
    int matriz[4][4];
    int valor;


    do //Mientras op este entre los valor de 1 y 4 se seleccionara una opcion y saldra del bucle
    {
        op = msgs(); //Llamamos a nuestra funcion msgs para guardar el valor de op guardado en ella y guardarla en la funcion menu
        switch (op) 
        {
        case 1: 
            llenar_vector(vect, tam, 100, 200);

            break;

        case 2:
            llenar_matriz(matriz, 1, 16);

            break;

        case 3:
            imprimir_vector(vect, tam, "Vector");

            break;

        case 4:
            imprimir_matriz(matriz, "Matriz");

            break;

        case 5:
            ordenar_vector(vect, tam);

            break;

        case 6:
            valor_vector(vect, tam);

            break;
        
        default:
            break;
        }

    } while (op != 0); //Si op es diferente a 0 la opcion saldra del bucle y continuara a la funcion seleccionada
    
}

void valor_vector(int vect[], int tam)
{
    int valor;
    int existe;
    valor = validar_num("Ingrese el numero que desea buscar en el vector(Rango de 100 a 200)\n", 100, 200);
    existe = buscar_vector(vect, tam, valor);

    if(existe != -1)
    {
        printf("El numero existe dentro del vector, esta en la posicion: %d \n", existe);
    }

    else
    {
        printf("El numero ingresado no se encuentra dentro del vector\n");
    }

    system ("PAUSE");
    
}