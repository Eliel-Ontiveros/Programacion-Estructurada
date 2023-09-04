//Eliel Alfonso Ontiveros Ojeda_368746
//24-Ago-2023 / 27-Ago-2023
//Programa que sirva para calcular el salario semanal de un trabajador
//OOEA_Act2_4_932


#include <stdio.h>
int main()
{
    float h_semanales, salario_h, salario_normal, salario_extra, salario_total, h_extras;
    int jornada = 40;
    printf("Ingrese las horas trabajadas durante la semana\n");
    scanf("%f", &h_semanales);
    printf("Ingrese el salario pagado por hora\n");
    scanf("%f", &salario_h);

    if (h_semanales <= jornada)
    {
        salario_total = h_semanales * salario_h;
        printf("\nEn total se le pagara al trabajador por laborar durante %.0f horas la cantidad de: $%.2f", h_semanales, salario_total);
    }

    else
    {
        if (jornada && h_semanales <= 49)
        {
            salario_normal = jornada * salario_h;
            printf("\nEl salario base por cumplir su jornada laboral es: $%.2f\n", salario_normal);
            h_extras = h_semanales - jornada;
            salario_extra = h_extras * (salario_h * 2);
            printf("Se le debera pagar $%.2f por trabajar %.0f horas extras\n", salario_extra, h_extras);
            salario_total = salario_normal + salario_extra;
            printf("En total se le pagara al trabajador por laborar durante %.0f horas la cantidad de: $%.2f", h_semanales, salario_total);
        }

        else
        {
            if (h_semanales >= 50)
            {
                salario_normal = (jornada * salario_h);
                printf("\nEl salario base por cumplir su jornada laboral es: $%.2f\n", salario_normal);
                h_extras = h_semanales - 49;
                salario_extra = (h_extras * (salario_h * 3)) + 180;
                printf("Se le debera pagar $%.2f por trabajar %.0f horas extras\n", salario_extra, h_extras+9);
                salario_total = (salario_normal + salario_extra);
                printf("En total se le pagara al trabajador por laborar durante %.0f horas la cantidad de: $%.2f", h_semanales, salario_total);
            }
            
        }
        
    }

    return 0;
}