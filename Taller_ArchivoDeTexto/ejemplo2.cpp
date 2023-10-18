#include <stdio.h>
#include <stdlib.h>

void readtxtfile (void);

int main()
{
    readtxtfile();

    return 0;
}

void readtxtfile (void)
{
    FILE *archivo;
    char contenido;

    archivo = fopen("C:\\Users\\Eliel\\OneDrive\\Documentos\\Universidad\\Programación Estructurada\\Taller_ArchivoDeTexto\\ASCII.txt", "r");

    if (archivo)
    {
        contenido = fgetc(archivo);
        do
        {
            printf("%c", contenido);
        }
        while (!feof(archivo));
        {
            fclose(archivo);
        }
        
    }
}
