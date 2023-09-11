// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 05-Sep-2023
// Programa en C que sirva para el juego del CHINCHAMPU (Condicion anidada)
//OOEA_Act3_2_932

/*Agregamos las librerias que utilizaremos*/
#include <stdio.h>
/*Librerias para la utilizacion de las funciones srand y rand*/
#include <time.h>
#include <stdlib.h>

int main() //Iniciamos nuestra funcion principal
{
    int op, comp; //Declaramos las variables que utilizaremos

    printf("Ingrese la opcion con la que jugara\n");
    printf("1 - Piedra\n");
    printf("2 - Papel\n");
    printf("3 - Tijera\n");
    scanf("%d", &op); //Escanea un la opciones elegida por el usuario y la guarda en la variable op
    srand(time(NULL)); //Llamamos a la funcion srand para posteriormente generar un numero aleatorio, time(NULL) utiliza el reloj de la computadora para generar el numero
    comp = 1 + rand() %3; //Se genera un numero aleatorio entre 1 y 3, lo guardamos en la variable comp

    if (op == 1) //Condicional para comprobar la seleccion del usuario, en este caso el usuario eligio piedra
    {
        if (comp == 1) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio piedra por lo que es empate
        {
            printf("\nElegiste Piedra\n");
            printf("La computadora eligio Piedra\n");
            printf("Empate");
        }

        else
        {
            if (comp == 2) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio papel por lo que perdio el usuario
            {
                printf("\nElegiste Piedra\n");
                printf("La computadora elegio Papel\n");
                printf("Perdiste");
            }

            else
            {
                if (comp == 3) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio tijera por lo que gano el usuario
                {
                    printf("\nElegiste Piedra\n");
                    printf("La computadora eligio Tijera\n");
                    printf("Ganaste");
                }
                
            }
            
        }
        
    }

    else
    {
        if (op == 2) //Condicional para comprobar la seleccion del usuario, en este caso eligio papel
        {
            if (comp == 1) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio piedra por lo gano el usuario
            {
                printf("\nElegiste Papel\n");
                printf("La computadora eligio Piedra\n");
                printf("Ganaste");
            }

            else
            {
                if (comp == 2) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio papel por lo que es empate
                {
                    printf("\nElegiste papel\n");
                    printf("La computadora eligio Papel\n");
                    printf("Empate");
                }

                else
                {
                    if (comp == 3) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio piedra por lo que perdio el usuario
                    {
                        printf("\nElegiste papel\n");
                        printf("La computadora eligio Tijera\n");
                        printf("Perdiste");
                    }
                    
                }
                
            }
            
        }

        else
        {
            if (op == 3) //Condicional para comprobar la seleccion del usuario, en este caso eligio tijera
            {
                if (comp == 1) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio piedra por lo que perdio el usuario
                {
                    printf("\nElegiste Tijera\n");
                    printf("La computadora eligio Piedra\n");
                    printf("Perdiste");
                }

                else
                {
                    if (comp == 2) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio papel por lo que gano el usuario
                    {
                        printf("\nElegiste Tijera\n");
                        printf("La computadora eligio Papel\n");
                        printf("Ganaste");
                    }

                    else
                    {
                        if (comp == 3) //Condicional para comprobar el resultado del juego, en este caso la computadora eligio tijera por lo que es empate
                        {
                            printf("\nElegiste Tijera\n");
                            printf("La computadora eligio Tijera\n");
                            printf("Empate");
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }

    return 0; //Terminamos nuestra funcion principal
    
}