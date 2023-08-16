#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
    int num1;
    int num2;
    int num3;
    printf("Ingrese el primer numero\n");
    scanf("%d", num1);
    printf("Ingrese el segundo numero\n");
    scanf("%d", num2);
    printf("Ingrese el tercer numero\n");
    scanf("%d", num3);
    if ((num1>num2 && num1<num3)||(num1<num2 && num1>num3))
    printf("El numero del medio es : ",num1);
    if ((num2>num1 && num2<num3)||(num2<num1 && num2>num3))
    printf("El numero del medio es: ",num2);
    if ((num3>num1 && num3<num2)||(num3<num1 && num3>num2))
    printf("El numero del medio es: ",num3);
    return 0;
    
}