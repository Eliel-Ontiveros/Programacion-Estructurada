//Algoritmo que lea 4 calificaciones de un alumno
//22-Ago-2023 / 22-Ago-2023
//Calcular y desplegar el promedio acompañado de la leyenda APROBADO o REPROBADO
//OOEA_Act1_1_932
#include <stdio.h>
int main()
{
    float cal [4];
    float prom = 0;
    int x;

    for (int i = 0; i < 4; i++)
    {
        printf("Ingrese la calificacion %d\n", i +1);
        scanf("%f", &cal[i]);
        prom += cal[i];
        printf("\n");
    }
    for (int y = 0; y < 4; y++)
    {
        for (y = 0, x = 1; x <= 4; y++, x++)
            if(cal[y] > cal[x])
            {
                int temp = cal[x];
                cal[x] = cal[y];
                cal[y] = temp;
            }
            
    }
        for (int i = 0; i <= 4, i++;)
    {
        printf("%d ", cal[i]);
    }
    printf("El promedio de las calificaciones es = %.2f\n", prom / 4);

    if (prom > 60)
    {
        printf("APROBADO");
    }
    else
    {
        printf("REPROBADO");
    }
    

     return 0;
}