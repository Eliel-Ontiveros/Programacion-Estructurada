// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 05-Sep-2023
// Programa que lee 3 calificaciones y calcule el promedio
//OOEA_Act3_1_932

#include <stdio.h>

int main()
{
    float cal1, cal2, cal3, prom;

    printf("Ingrese una calificacion\n");
    scanf("%f", &cal1);
    printf("Ingrese una calificacion\n");
    scanf("%f", &cal2);
    printf("Ingrese una calificacion\n");
    scanf("%f", &cal3);

    prom = (cal1 + cal2 + cal3) / 3;

    if(prom < 30) 
    {
        printf("Repetir");
    }
    else
    {
        if (prom < 60)
        {
            printf("Extraordinario");
        }

        else
        {
            if (prom < 70)
            {
                printf("Suficiente");
            }

            else
            {
                if (prom < 80)
                {
                    printf("Regular");
                }

                else
                {
                    if (prom < 90)
                    {
                        printf("Bien");
                    }

                    else
                    {
                        if (prom < 98)
                        {
                            printf("Muy bien");
                        }

                        else
                        {
                            printf("Excelente");
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }

    return 0;
}