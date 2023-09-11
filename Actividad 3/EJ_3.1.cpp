// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 05-Sep-2023
// Programa que lee 3 calificaciones y calcule el promedio
//OOEA_Act3_1_932

#include <stdio.h> //Agregamos las librerias que utilizaremos

int main() //Iniciamos nuestra funcion principal
{
    float cal1, cal2, cal3, prom; //Declaramos las variables que utilizaremos

    printf("Ingrese una calificacion\n");
    scanf("%f", &cal1); //Escanea una calificacion ingresada por el usuario y la guarda en la variable cal1
    printf("Ingrese una calificacion\n");
    scanf("%f", &cal2); //Escanea una calificacion ingresada por el usuario y la guarda en la variable cal2
    printf("Ingrese una calificacion\n");
    scanf("%f", &cal3); //Escanea una calificacion ingresada por el usuario y la guarda en la variable cal3

    prom = (cal1 + cal2 + cal3) / 3; //Calcular el promedio de las 3 calificaciones y lo guarda en la variable prom
    printf("El promedio es = %.2f\n", prom);

    if(prom < 30) //Condicional para comprobar el promedio del usuario, si es menor a 30 se imprimira Repetir
    {
        printf("Repetir");
    }
    else
    {
        if (prom < 60) //Condicional para comprobar el promedio del usuario, si es menor a 60 se imprimira Extraordinario
        {
            printf("Extraordinario");
        }

        else
        {
            if (prom < 70) //Condicional para comprobar el promedio del usuario, si es menor a 70 se imprimira Suficiente
            {
                printf("Suficiente");
            }

            else
            {
                if (prom < 80) //Condicional para comprobar el promedio del usuario, si es menor a 80 se imprimira Regular
                {
                    printf("Regular");
                }

                else
                {
                    if (prom < 90) //Condicional para comprobar el promedio del usuario, si es menor a 90 se imprimira Bien
                    {
                        printf("Bien");
                    }

                    else
                    {
                        if (prom < 98)//Condicional para comprobar el promedio del usuario, si es menor a 98 se imprimira Muy bien
                        { 
                            printf("Muy bien");
                        }

                        else
                        {
                            printf("Excelente"); //Si no cumple ninguna de las condiciones anterior se asume que el promedio es 99 o 100 e imprimira Excelente
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }

    return 0; //Terminamos nuestra funcion principal
}