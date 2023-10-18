/*
Eliel Alfonso Ontiveros Ojeda
17/Oct/2023
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archivo;
    char contenido;

    archivo = fopen("AllStars.txt", "r");

    if(archivo == NULL)
    {
        printf("Error al momento de abrir archivo\n");
    }

    else
    {
        printf("El contenido del archivo es:\n \n");

        while(feof(archivo) == 0)
        {
            contenido = fgetc (archivo);
            printf("%c", contenido);
        }
    }

    fclose(archivo);
    getchar();

    return 0;
}