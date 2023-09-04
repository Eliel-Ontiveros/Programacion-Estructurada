//Eliel Alfonso Ontiveros Ojeda_368746
//27-Ago-2023 / 27-Ago-2023
//Algoritmo que sirva para desplegar el Total de una llamada telefónica
//OOEA_Act1_11_932
#include <stdio.h>
int main()
{
    int op;
    int min;
    float sub_total;
    #define iva 0.16;
    float total;
    float sub_iva;
    int min_extra;
    int plus;
    int base;

    printf("Ingrese que tipo de llamada realizara\n");
    printf("1 - Local\n");
    printf("2 - Nacional\n");
    printf("3 - Internacional\n");
    printf("\n");
    scanf("%d", &op);
    printf("Ingrese cuantos minutos durara la llamada\n");
    scanf("%d", &min);

    if (op == 1)
    {
        printf("\nLlamada local\n");
        sub_total = 3;
        printf("El costo de la llamada sin IVA es de: $%.2f\n", sub_total);
        sub_iva = sub_total * iva;
        total = sub_total + sub_iva;
        printf("El costo total de la llamada es de: $%.2f\n", total);
    }
    else
    {
        if (op == 2)
        {
            printf("\nLlamada nacional\n");
            if (min > 3)
            {
                base = 7;
                min_extra = min - 3;
                printf("Tuvo %d minutos extra\n", min_extra);
                plus = min_extra * 2;
                sub_total = base + plus;
                printf("El costo de la llamada sin IVA es de: $%.2f\n", sub_total);
                sub_iva = sub_total * iva;
                total = sub_total + sub_iva;
                printf("El costo total de la llamada es de: $%.2f\n", total);
            }
            else if (min <= 3)
            {
                base = 7;
                sub_total = base;
                printf("El costo de la llamada sin IVA es de: $%.2f\n", sub_total);
                sub_iva = base * iva;
                total = base + sub_iva;
                printf("El costo total de la llamada es de: $%.2f\n", total);
            }
        
        }
        
        else
        {
            if (op == 3)
            {
                printf("\nLlamada internacional\n");
                if (min > 2)
                {
                    base = 9;
                    min_extra = min - 2;
                    printf("Tuvo %d minutos extra\n", min_extra);
                    plus = min_extra * 4;
                    sub_total = base + plus;
                    printf("El costo de la llamada sin IVA es de: $%.2f\n", sub_total);
                    sub_iva = sub_total * iva;
                    total = sub_total + sub_iva;
                    printf("El costo total de la llamada es de: $%.2f\n", total);
                }
                else if (min <= 2)
                {
                    base = 9;
                    sub_total = base;
                    printf("El costo de la llamada sin IVA es de: $%.2f\n", sub_total);
                    sub_iva = base * iva;
                    total = base + sub_iva;
                    printf("El costo total de la llamada es de: $%.2f\n", total); 
                }
            
            }

        }

    }
    
    return 0;
}