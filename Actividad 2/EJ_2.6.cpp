//Eliel Alfonso Ontiveros Ojeda_368746
//29-Ago-2023 / 
//Programa para calcular el pago total por consumo de agua
//OOEA_Act2_6_932

#include <stdio.h>
int main()
{
    int m3, extra, m3_extra;
    float sub_total, total, sub_iva;
    #define iva 0.16;
    printf("Ingrese la cantidad de m3 de agua consumidos\n");
    scanf("%d", &m3); 

    if (m3 <= 4)
    {
        printf("Debe pagas $50 en su factura");
    }

    else
    {
        if (m3 <= 15)
        {
            m3_extra = m3 - 5;
            sub_total = 50 + (m3_extra * 8);
            printf("El costo del agua sin IVA es = $%.2f\n", sub_total);
            sub_iva = sub_total * iva;
            total = sub_total + sub_iva;
            printf("Debe pagar $%.2f en su factura", total);
        }

        else
        {
            if (m3 <= 50)
            {
                m3_extra = m3 - 16;
                sub_total = 50 + (11 * 8) + (m3_extra * 10);
                printf("El costo del agua sin IVA es = $%.2f\n", sub_total);
                sub_iva = sub_total * iva;
                total = sub_total + sub_iva;
                printf("Debe pagar $%.2f en su factura", total);
            }

            else
            {
                if (m3 >= 51)
                {
                    m3_extra = m3 - 50;
                    sub_total = 478 + (m3_extra * 11);
                    printf("El costo del agua sin IVA es = $%.2f\n", sub_total);
                    sub_iva = sub_total * iva;
                    total = sub_total + sub_iva;
                    printf("Debe pagar $%.2f en su factura", total);
                }
                
            }
            
        }
        
    }
    
    return 0;
    
}