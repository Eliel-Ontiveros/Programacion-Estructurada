//Eliel Alfonso Ontiveros Ojeda_368746
//03-Ago-2023 / 
//Calcular el promedio final de 4 examenes cancelando la calificacion menor
//

#include <stdio.h>
int main()
{
    float cal1, cal2, cal3, cal4, prom;
    
    printf("Ingrese calificacion\n");
    scanf("%f", &cal1);
    printf("Ingrese calificacion\n");
    scanf("%f", &cal2);
    printf("Ingrese calificacion\n");
    scanf("%f", &cal3);
    printf("Ingrese calificacion\n");
    scanf("%f", &cal4);

    if (cal1 < cal2 && cal1 < cal3 && cal1 < cal4)
    {
        prom = (cal2 + cal3 + cal4) / 4;
        printf("El promedio final es = %.2f", prom);
    }

    else
    {
        if (cal2 < cal1 && cal2 < cal3 && cal2 < cal4)
        {
            prom = (cal1 + cal3 + cal4) / 4;
            printf("El promedio final es = %.2f", prom); 
        }

        else
        {
            if (cal3 < cal1 && cal3 < cal2 && cal3 < cal4)
            {
                prom = (cal1 + cal2 + cal4) / 4;
                printf("El promedio final es = %.2f", prom);
            }

            else
            {
                if (cal4 < cal1 && cal4 < cal2 && cal4 < cal3)
                {
                    prom = (cal1 + cal2 + cal3) / 4;
                    printf("El promedio final es = %.2f", prom);
                }
                
            }
            
        }
        
    }
    
    return 0;

}