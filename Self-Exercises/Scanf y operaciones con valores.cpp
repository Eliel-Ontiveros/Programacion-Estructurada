#include <stdio.h>
int main()
{
    int num1;
    int num2;
    int suma;
    int resta;
    int multiplicacion;
    float division; 
    
    //Se ingresan los valores que utilizaremos más adelante
    printf("Para que los calculos resulten positivos se recomienda que el primer valor sea mayor al segundo\n");
    printf("Ingrese los numeros con los que desea trabajar\n");
    scanf("\n%d %d", &num1, &num2);
    printf("Ingresaste los numeros %d y %d\n", num1, num2);

    //Se realiza la suma de los valores
    printf("Se procedera a realizar los calculos de los valores ingresados");
    suma = num1 + num2;
    printf("\nEl resultado de la suma de los valores es = %d", suma);

    //Se realiza la resta de los valores
    resta = num1 - num2;
    printf("\nEl resultado de la resta de los valores es = %d", resta);

    //Se realiza la multiplicacion de los valores
    multiplicacion = num1 * num2;
    printf("\nEl resultado de la multiplicacion de los valores es = %d", multiplicacion);

    //Se realiza la division de los valores 
    division = num1/num2;
    printf("\nEl resultado de la division de los valores es = %f", division);

    return 0;
}