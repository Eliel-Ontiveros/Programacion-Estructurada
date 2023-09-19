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
int validar(char mensaje[], int ri, int rf);
int askToExit();
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
    printf("4 - Promedio Peso de Turistas\n");
    printf("5 - Promedio de Alumno\n");
    printf("0 - Salir\n");
    printf("Seleccione una de las opciones\n");
    scanf("%d", &op); //Escaneamos la seleccion dentro de la variable op
    
    return op;

}

/*Desarrollo Funcion Menu*/
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
    int i, j, calificacion, total = 0;
    float promedio;

    for(i = 0; i < 40; i++) 
    {
        promedio = 0;

        for(j = 0; j < 5; j++) 
        {
            printf("Unidad %d, alumno %d\n", j + 1, i + 1);
            calificacion = validar("Ingrese la calificacion\n", 0, 100);
            promedio += calificacion;
        }

        promedio /= 5;

        if(promedio < 50) 
        {
            total++;
        }
    }

    printf("La cantidad de alumnos que no tienen derecho al examen de nivelacion es: %d\n", total);

    system ("PAUSE");   

}

/*Desarrollo Funcion Tabla de Multiplicar*/
void tab_mult()
{
    int i, j;

    for(i = 1; i <= 10; i++) 
    {
        printf("TABLA DEL %d\n", i);

        for(j = 1; j <= 10; j++) 
        {
            printf("%d * %d = %d\n", i, j, i*j);
        }

        printf("PRESIONA UNA TECLA PARA CONTINUAR.\n");
        getchar();

    }

    system ("PAUSE"); 

}

/*Desarrollo Funcion Suma y Media Aritmetica*/
void sum_med_arit()
{
    int n, i, num;
    int suma = 0;
    float media;

    n = validar("Ingrese la cantidad de numeros a leer\n", 1, 100);

    for(i = 0; i < n; i++) 
    {
        num = validar("Ingrese el numero %d\n", 0, 1000);
        suma += num;
    }

    media = (float)suma / n;

    printf("La suma de los numeros es: %d\n", suma);
    printf("La media aritmetica es: %.2f\n", media);

    system ("PAUSE"); 

}

/*Desarrollo Funcion Promedio de Peso Turistas*/
void turist_peso()
{
    int i, turistas = 0;
    float peso, totalPeso = 0, promedioPeso;

    for(i = 0; i < 10 && totalPeso <= 700; i++) 
    {
        peso = validar("Ingrese el peso del turista %d\n", 1, 300);
        totalPeso += peso;
        turistas++;
    }

    promedioPeso = totalPeso / turistas;

    printf("El promedio de peso de los turistas es: %.2f\n", promedioPeso);

    if(turistas == 10) 
    {
        printf("Se cumplio la condicion del maximo de turistas\n");
    } 

    else
    {
        if (totalPeso > 700)
        {
            printf("Se cumplio la condicion del maximo de peso\n");
        }
        
    }

    system ("PAUSE"); 

}

/*Desarrollo Funcion Promedio Final de Alumnos*/
void prom_final()
{
    int examen1, examen2, examen3;
    float promedio;

	examen1 = validar("Ingrese la calificacion del primer examen parcial\n", 0, 100);
	examen2 = validar("Ingrese la calificacion del segundo examen parcial\n", 0, 100);
	examen3 = validar("Ingrese la calificacion del tercer examen parcial\n", 0, 100);

	promedio = (examen1 + examen2 + examen3) / 3.0;

	if(promedio >= 70) 
    {
		printf("Aprobado\n");
	} 

    else
    {
        if (promedio < 70 && promedio >=50)
        {
            printf("Repetir materia\n");
        }

        else
        {
            if (promedio <50)
            {
                printf("Repetir materia\n");
            }
            
        }
        
    }

    system ("PAUSE"); 

}

int validar(char mensaje[], int ri, int rf)
{
    int num;
    do 
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &num);
    } 
    while (num < ri || num > rf);
    
    return num;
    
}