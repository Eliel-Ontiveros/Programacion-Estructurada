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

    //archivo = fopen("C:\\Users\\Eliel\\OneDrive\\Documentos\\Universidad\\Programación Estructurada\\Taller_ArchivoDeTexto\\ASCII.txt", "r");
    archivo = fopen("ASCII.txt", "r");
    if(!archivo){
        printf("No se encontro archivo");
    };
    if (archivo)
    {
        while(feof(archivo) == 0)
        {
            contenido = fgetc (archivo);
            printf("%c", contenido);
        }
        
    }
}
