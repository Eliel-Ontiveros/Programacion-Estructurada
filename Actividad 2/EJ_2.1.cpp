// Eliel Alfonso Ontiveros Ojeda_368746
// 29-Ago-2023 /
// Calculadora de las operaciones basicas
//OOEA_Act2_1_932

#include <stdio.h>
int main()
{
    float num1, num2, op;
    int suma, resta, multiplicacion;
    float division;
    printf("Seleccione que operacion es la que quiere realizar\n");
    printf("1 - Suma\n");
    printf("2 - Resta\n");
    printf("3 - Multipllicacion\n");
    printf("4 - Division\n");
    scanf("%f", &op);
    printf("Ingrese el primer numero\n");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero\n");
    scanf("%f", &num2);

    if (op == 1)
    {
        suma = num1 + num2;
        printf("El resultado de la suma es = %d", suma);
    }
    else
    {
        if (op == 2)
        {
            resta = num1 - num2;
            printf("El resultado de la resta es = %d", resta);
        }
        else
        {
            if (op == 3)
            {
                multiplicacion = num1 * num2;
                printf("El resultado de la multiplicacion es = %d", multiplicacion);
            }
            else
            {
                if (op == 4)
                {
                    division = num1 / num2;
                    printf("El resultado de la division es = %.2f", division);
                }
            }
        }
    }

    return 0;
}