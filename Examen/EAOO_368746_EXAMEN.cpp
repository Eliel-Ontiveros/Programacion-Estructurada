#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Estructura para almacenar datos del análisis de la muestra
struct Estadisticas
{
    float media;
    float moda;
    float mediana;
    float varianza;
    float desviacion_estandar;
    float tercer_cuartil;
};

// Prototipos de funciones
void cargarMuestra(float **muestra, int *n, const char *nombreArchivo);
void imprimirMuestra(float *muestra, int n);
float calcularMediaAritmetica(float *muestra, int n);
float calcularModa(float *muestra, int n);
float calcularMediana(float *muestra, int n);
float calcularVarianza(float *muestra, int n, float media);
float calcularDesviacionEstandar(float varianza);
float calcularTercerCuartil(float *muestra, int n);

void generarArchivoTexto(float *muestra, int n, struct Estadisticas stats);
void generarArchivoBinario(struct Estadisticas stats);

int main()
{
    int opcion;
    int n = 0;
    float *muestra = NULL;
    struct Estadisticas estadisticas;
    const char *nombreArchivo = "tiempos_5k_teem_potros";

    do
    {
        printf("\n--- MENU ---\n");
        printf("1.- Cargar muestra\n");
        printf("2.- Imprimir muestra\n");
        printf("3.- Media aritmetica\n");
        printf("4.- Moda\n");
        printf("5.- Mediana\n");
        printf("6.- Varianza y desviacion estandar\n");
        printf("7.- Tercer cuartil\n");
        printf("8.- Generar archivo Texto\n");
        printf("9.- Generar archivo Binario\n");
        printf("10.- Imprimir archivo Binario\n");
        printf("0.- Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            cargarMuestra(&muestra, &n, nombreArchivo);
            break;
        case 2:
            imprimirMuestra(muestra, n);
            break;
        case 3:
            estadisticas.media = calcularMediaAritmetica(muestra, n);
            printf("Media aritmetica: %.2f\n", estadisticas.media);
            break;
        case 4:
            estadisticas.moda = calcularModa(muestra, n);
            printf("Moda: %.2f\n", estadisticas.moda);
            break;
        case 5:
            estadisticas.mediana = calcularMediana(muestra, n);
            printf("Mediana: %.2f\n", estadisticas.mediana);
            break;
        case 6:
            estadisticas.varianza = calcularVarianza(muestra, n, estadisticas.media);
            estadisticas.desviacion_estandar = calcularDesviacionEstandar(estadisticas.varianza);
            printf("Varianza: %.2f\n", estadisticas.varianza);
            printf("Desviacion estandar: %.2f\n", estadisticas.desviacion_estandar);
            break;
        case 7:
            estadisticas.tercer_cuartil = calcularTercerCuartil(muestra, n);
            printf("Tercer cuartil: %.2f\n", estadisticas.tercer_cuartil);
            break;
        case 8:
            generarArchivoTexto(muestra, n, estadisticas);
            break;
        case 9:
            generarArchivoBinario(estadisticas);
            break;
        case 10:

            break;
        case 0:

            free(muestra);
            break;
        default:
            printf("Opcion no valida. Intentelo de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}

void cargarMuestra(float **muestra, int *n, const char *nombreArchivo)
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        perror("Error");
        return;
    }

    float elemento;
    while (fscanf(archivo, "%f", &elemento) == 1)
    {
        (*n)++;
    }

    *muestra = (float *)malloc(*n * sizeof(float));

    rewind(archivo);

    for (int i = 0; i < *n; i++)
    {
        fscanf(archivo, "%f", &(*muestra)[i]);
    }

    fclose(archivo);
    printf("Muestra cargada correctamente.\n");
}

void imprimirMuestra(float *muestra, int n)
{
    printf("Muestra:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", muestra[i]);
    }
    printf("\n");
}

float calcularMediaAritmetica(float *muestra, int n)
{
    float suma = 0.0;

    for (int i = 0; i < n; i++)
    {
        suma += muestra[i];
    }

    return suma / n;
}

float calcularModa(float *muestra, int n)
{

    return 0.0;
}

float calcularMediana(float *muestra, int n)
{

    return 0.0;
}

float calcularVarianza(float *muestra, int n, float media)
{
    float suma = 0.0;

    for (int i = 0; i < n; i++)
    {
        suma += pow(muestra[i] - media, 2);
    }

    return suma / n;
}

float calcularDesviacionEstandar(float varianza)
{
    return sqrt(varianza);
}

float calcularTercerCuartil(float *muestra, int n)
{
    int i, j;

    float temp;
    float cuartil;

    if (n->muestra < 4)
    {
        printf("Error_5\n");
    }

    for (i = 0; i < n->muestra - 1; i++)
    {
        for (j = 0; j < n->muestra - i - 1; j++)
        {
            if (n->datos[j] > n->muestra[j + 1])
            {
            }
        }
    }
    return 0.0;
}

void generarArchivoTexto(float *muestra, int n, struct Estadisticas stats)
{
    FILE *archivo;
    char nombreArchivo[100];
    printf("Ingrese el nombre del archivo de texto para guardar la informacion: ");

    fgets(nombreArchivo, sizeof(nombreArchivo), stdin);

    nombreArchivo[strcspn(nombreArchivo, "\n")] = '\0';

    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "Muestra:\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(archivo, "%.2f ", muestra[i]);
    }
    fprintf(archivo, "\n");

    fprintf(archivo, "Media aritmetica: %.2f\n", stats.media);

    fclose(archivo);
    printf("Informacion guardada en el archivo correctamente.\n");
}

void generarArchivoBinario(struct Estadisticas stats)
{
    FILE *archivo;
    char nombreArchivo[100];
    printf("Ingrese el nombre del archivo binario para guardar la informacion: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "wb");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fwrite(&stats, sizeof(struct Estadisticas), 1, archivo);

    fclose(archivo);
    printf("Informacion guardada en el archivo binario correctamente.\n");
}
