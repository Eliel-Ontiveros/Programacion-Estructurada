/*
Eliel Alfonso Ontiveros Ojeda_368746
06-Sep-2023 / 08-Sep-2023
PROGRAMA QUE LLAME LOS 4 EJERCICIOS
OOEA_Act5_1_932
*/

/*Agregamos las librerias que utilizaremos durante la realizacion del programa*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Declaramos las variables en donde guardaremos nuestras funciones*/
int msgs (); //Funcion para guardar la seleccion de la funcion que queremos realizar

void menu (); //Esta funcion nos servira para guardar las demas funciones dentro de ella, sera nuestro esqueleto

void num_desc (void); //Funcion que despliega todos los numeros enteros positivos menores de n en orden descendente. 

void par_impar (void); /*Funcion que genera 40 numeros aleatorios del 0 al 200, despliega los números y la leyenda de cada número si es par o impar, 
la cantidad de los números pares e impares así como la suma de los números pares o impares.*/

void max_min (void); //Funcion que genera N(35) cantidad de numeros entre el 100 y el 200, despliega cual es el numero mayor y el menor.

void tab_mult (void); //Funcion que despliega la tabla de multiplicar de un numero solicitado entre el 1 y el 20.

/*En nuestra funcion main llamamos solamente al esqueleto donde se encuentran nuestras funciones*/
int main()
{
    menu();

    return 0;
}

/*Desarrollo Funcion MSGS*/
int msgs()
{
    int op; //Declaramos la variable donde guardaremos la opcion de que operacion realizaremos
    system ("CLS"); //Sirve para limpiar la pantalla al momento de llamar nuestra funcion
    printf("-----M E N U-----\n");
    printf("1 - Ordenar numero de forma descendente\n");
    printf("2 - Numero Pares e Impares generados aleatoriamente en un rango del 0 a 200\n");
    printf("3 - Desplegar el numero mayor y menor entre 100 y 200 generados aleatoriamente\n");
    printf("4 - Tablas de multiplicar\n");
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
            num_desc();

            break;

        case 2:
            par_impar();

            break;

        case 3:
            max_min();

            break;

        case 4:
            tab_mult();

            break;
        
        default:
            break;
        }

    } while (op != 0); //Si op es diferente a 0 la opcion saldra del bucle y continuara a la funcion seleccionada
    
}

/*Desarrollo Funcion NUMERO DESCENDENTE*/
void num_desc()
{
    system ("CLS");
    int num; //Declaramos la variable donde guardaremos el numero que analizaremos

    printf("Ingrese el numero que quiera analizar\n");
    scanf("%d", &num); //Escaneamos la seleccion dentro de la variable num
    printf("Los numeros quedarian acomodados de la siguiente manera\n");
    printf("%d\n", num); //Imprime el numero que ingreso el usuario

    for (int i =  num - 1; i > 0 ; i--) //Ciclo que imprimira de manera descendente los numeros, no saldra hasta que num sea igual a 1
    {
        printf("%d\n", i);
    }

    system ("PAUSE"); //Detiene la funcion y pide al usuario que pulse una tecla para regresar a la funcion menu
    
}

/*Desarrollo Funcion NUMEROS PAR E IMPAR*/
void par_impar()
{
    system ("CLS");
    int num[40]; //Declaramos la variable donde guardaremos los numeros aleatorios
    int pares = 0; //Variable donde guardaremos si el numero es par
    int impares = 0; //Variable donde guardaremos si el numero es impar
    int sum_pares = 0; //Variable donde guardaremos la suma de los numeros pares
    int sum_impares = 0; //Variable donde guardaremos la suma de los numeros impares
    srand(time(NULL)); //Llamamos la funcion que generara los numeros aleatorios

    for (int i = 0; i < 40; i++) //Ciclo en el cual generamos 40 numeros aleatorios
    {
            num[i] = rand() %201; //Generara un numero entre el 0 y 200
            printf("Numero aleatorio = %d\n", num[i]); //Imprime el numero aleatorio

            if (num[i] % 2 == 0) //Condicional para determinar si el numero aleatorio es par
            {
                printf("Es un numero par\n");
                pares++; //Contador para contar cuantos numeros son pares, si el numero es par va sumando 1 a la variable pares
                sum_pares += num[i]; //Dentro de la variable sum_pares se va realizado la suma del numero aleatorio por el proximo numero generado
            }

            else //En caso de no se par entrara aqui el numero, lo cual lo convertira en un numero impar
            {
                printf("Es un numero impar\n");
                impares ++; //Contador para contar cuantos numeros son impares, si el numero es par va sumando 1 a la variable impares
                sum_impares += num[i]; //Dentro de la variable sum_impares se va realizado la suma del numero aleatorio por el proximo numero generado
            }
            
    }

    printf("La cantidad de numeros pares es = %d\n", pares); //Imprime la cantidad de numeros pares
    printf("La cantidad de numeros impares es = %d\n", impares); //Imprime la cantidad de numeros impares
    printf("La suma de los numeros pares es = %d\n", sum_pares); //Imprime la suma de todos los numeros pares generados
    printf("La suma de los numeros impares es = %d\n", sum_impares); //Imprime la suma de todos los numeros impares generados
    

    system ("PAUSE"); //Detiene la funcion y pide al usuario que pulse una tecla para regresar a la funcion menu
}

/*Desarrollo Funcion NUMEROS MAXIMO Y MINIMO*/
void max_min()
{
    system ("CLS");
    int num;
    int min = 200; // Inicializar con un valor alto
    int max = 100; // Inicializar con un valor bajo

    srand(time(NULL));

    for (int i = 0; i < 35; i++) // Generar 35 numeros aleatorios y encontrar el mínimo y el máximo
    {
        num = rand() % 101 + 100; // Generar numero aleatorio entre 100 y 200
        printf("%d\n", num); //Imprime el numero generado

        if (num < min) //Condicional para comprobar si el numero generado es menor al minimo establecido
        {
            min = num; //Si se cumple la condicion guarda el numero dentro de la variable min
        }

        if (num > max) //Condicional para comprobar si el numero generado es mayor al mayor establecido
        {
            max = num; //Si se cumple la condicion guarda el numero dentro de la variable max0
        }
    }

    printf("Numero menor: %d\n", min); //Imprime el numero menor de los generados aleatoriamente
    printf("Numero mayor: %d\n", max); //Imprime el numero mayor de los generados aleatoriamente 

    system ("PAUSE"); //Detiene la funcion y pide al usuario que pulse una tecla para regresar a la funcion menu

}

/*Desarrollo Funcion Tablas de Multiplicar*/
void tab_mult()
{
    inicio: //Agrupa el codigo dentro de la etiqueta llamada inicio
    system ("CLS"); //Limpia la pantalla al entrar en la funcion
    int num, resultado; //Declaramos las valiables que utilizaremos 
    printf("Ingrese un numero entre el 1 y el 20 para ver su tabla de multiplicar\n");
    scanf("%d", &num); //Escanea el valor ingresado en la variable num
    printf("Tabla del %d\n", num); //Imprime cual sera la tabla que se generara segun lo que ingrese el usuario

    if (num > 20) //Analiza si el numero ingresado es mayor a 20
    {
        goto inicio; //Si cumple la condicion vuelve a reproducir el codigo, viaja a la etiqueta inicio
    }
    if (num < 1)
    {
        goto inicio; //Si cumple la condicion vuelve a reproducir el codigo, viaja a la etiqueta inicio
    }
    

    for (int i = 1; i <= 10; i++) //Bucle que realiza la multiplicacion hasta el 10
    {
        resultado = num * i; //Guarda dentro de la variable resultado el producto de la multiplicacion
        printf("%d * %d = %d\n", num, i, resultado); //Imprime el producto de cada termino individualmente
    }

    system ("PAUSE"); //Detiene la funcion y pide al usuario que pulse una tecla para regresar a la funcion menu
    
}