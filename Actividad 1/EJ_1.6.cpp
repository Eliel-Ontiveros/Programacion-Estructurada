//Eliel Alfonso Ontiveros Ojeda_368746
//24-Ago-2023 / 24-Ago-2023
//Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar  (ANIDADO POR EL FALSO)
//OOEA_Act1_6_932
#include <stdio.h>
#include <stdio.h>
int main()
{
    int cal1, cal2, cal3;
    float prom;
    printf("Ingrese la calificacion: \n");
    scanf("%d", &cal1);
    printf("Ingrese la calificacion: \n");
    scanf("%d", &cal2);
    printf("Ingrese la calificacion: \n");
    scanf("%d", &cal3);
    prom = (cal1 + cal2 + cal3)/3;
    printf("El promedio es = %.2f\n", prom);
    if (prom < 30)
    {
        printf("REPETIR");
    }
    else if (prom >= 30 && prom < 60)
    {
        printf("EXTRAORDINARIO");
    }
    else if (prom >= 60 && prom < 70)
    {
    printf("SUFICIENTE");
    }
    else if (prom >= 70 && prom < 80)
    {
        printf("REGULAR");
    }
    else if (prom >= 80 && prom < 90)
    {
        printf("BIEN");
    }
    else if (prom >= 90 && prom < 98)
    {
        printf("MUY BIEN");
    }
    else if (prom >= 98 && prom < 100)
    {
        printf("EXCELENTE");
    }
    else if (prom > 100)
    {
        printf("ERROR EN PROMEDIO");
    }
    
    return 0;
}