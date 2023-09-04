//Eliel Alfonso Ontiveros Ojeda_368746
//29-Ago-2023 / 
//Conversiones de unidades de medida
//

#include <stdio.h>
int main()
{
    int op;
    float med;
    float cm, inch, ft, km, mill;
    printf("Ingrese el tipo de conversion que hara\n");
    printf("1 - centimetros a pulgadas\n");
    printf("2 - centimetros a pies\n");
    printf("3 - kilometros a millas\n");
    printf("4 - pulgadas a centimetros\n");
    printf("5 - pies a centimetros\n");
    printf("6 - millas a kilometros\n");
    scanf("%d", &op);
    printf("Ingrese el valor que quiere convertir\n");
    scanf("%f", &med);

    if (op == 1)
    {
        inch = med / 2.54;
        printf("%.2f centimetros equivalen a %.2f pulgadas", med, inch);
    }

    else
    {
        if (op == 2)
        {
        ft = med / 30.48;
        printf("%.2f centimetros equivalen a %.2f pies", med, ft);
        }

        else
        {
            if (op == 3)
            {
            mill = med / 1.609;
            printf("%.2f kilometros equivalen a %.2f millas", med, mill);
            }

            else
            {
                if (op == 4)
                {
                cm = med * 2.54;
                printf("%.2f pulgadas equivalen a %.2f centimetros", med, cm);
                }

                else
                {
                    if (op == 5)
                    {
                    cm = med * 30.48;
                    printf("%.2f pies equivalen a %.2f centimetros", med, cm);
                    }

                    else
                    {
                        if (op == 6)
                        {
                        km = med * 1.609;
                        printf("%.2f millas equivalen a %.2f kilometros", med, km);
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    return 0;
}