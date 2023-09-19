#include<string.h>
#include<stdio.h> 

int main()
{
    char nombre[30];
    int x;
    fflush(stdin);
    gets(nombre);
    printf("Mi ciudad es: %s\n", nombre);
    printf("Naci en %s y es mi ciudad\n", nombre);
    x = strlen(nombre);
    printf("%s tiene %d caracteres\n", nombre, x);
    printf("%s tiene %d caracteres\n", nombre, strlen(nombre));

    return 0;

}