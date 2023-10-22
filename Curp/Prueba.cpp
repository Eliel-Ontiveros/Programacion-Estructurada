#include <stdio.h>
#include <string.h>
#include "palabras_inconvenientes.h"
#include "chntoky.h"

void nombre_completo(char nombre1[], char nombre2[], char ap_paterno[], char ap_materno[]);
void estados(char* estado);
void fecha_nacimiento(int dia, int mes, int anio);
int sexo();
int anio_bisiesto(int anio);

// Función para reemplazar palabras inconvenientes
void cens_curp(char *text, char cens_lista[][100], char reemplazar_lista[][100], int n_palabras)
{
    for (int i = 0; i < n_palabras; i++)
    {
        char *palabra = cens_lista[i];
        char *reemplazo = reemplazar_lista[i];
        char *posicion = text;

        while ((posicion = strstr(posicion, palabra)) != NULL)
        {
            int largo = strlen(palabra);
            int remp_largo = strlen(reemplazo);

            memmove(posicion + remp_largo, posicion + largo, strlen(posicion + largo) + 1);
            memcpy(posicion, reemplazo, remp_largo);

            posicion += remp_largo;
        }
    }
}

int main()
{
    int op;
    char nombre[100];
    char segundo_nombre[100];
    char apellido_paterno[100];
    char apellido_materno[100];
    int anio_nacimiento, mes_nacimiento, dia_nacimiento;
    char estado_nacimiento[100];

    char respuesta;
    do
    {
        nombre_completo(nombre, segundo_nombre, apellido_paterno, apellido_materno);

        fecha_nacimiento(dia_nacimiento, mes_nacimiento, anio_nacimiento);

        estados(estado_nacimiento);

        // Generar el CURP
        char curp[20]; // Suponemos una longitud fija para el CURP
        // Lógica para generar el CURP aquí

        // Censurar palabras inconvenientes en el CURP
        cens_curp(curp, palabras_inconvenientes, palabras_convertidas_normal, 78);

        // Imprimir el CURP
        printf("\nSu CURP es: %s\n", curp);
        printf("Ingrese 1 si desea ingresar otro curp\n");
        printf("Ingrese 0 para terminar el programa\n");
        op = validar_num("Ingrese la opcion deseada\n", 0, 1);

    } while (op != 0);
    printf("Saliendo del programa\n");

    return 0;
}

void nombre_completo(char nombre1[], char nombre2[], char ap_paterno[], char ap_materno[])
{
    int respuesta;
    printf("Ingrese su Nombre: ");
    validar_string(nombre1, 100);

    do
    {
        printf("Tiene un segundo nombre? (S/N): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S' || respuesta == 'n' || respuesta == 'N');

    if (respuesta == 'S' || respuesta == 's')
    {
        printf("Ingrese su Segundo Nombre: ");
        validar_string(nombre2, 100);
    }
    else
    {
        nombre2[0] = '\0'; 
    }

    printf("Ingrese su Apellido Paterno: ");
    validar_string(ap_paterno, 100);

    printf("Ingrese su Apellido Materno: ");
    validar_string(ap_materno, 100);
}

void estados(char* estado)
{
    int op;

    int i;

    printf("Estados de Mexico\n");

    for (i = 0; i < 32; i++)
    {
        printf("%d - %s", i + 1, estados);
    }
    printf("Ingresar su estado de nacimiento\n");
    op = validar_num("Ingrese su estado de nacimiento: ", 1, 33);
    strcpy(estado, estados_abr[op - 1]);
    printf("Estado de Nacimiento: \n", estado);
}

void fecha_nacimiento(int dia, int mes, int anio)
{
    anio = validar_num("Ingrese su anio de nacimiento: ", 1890, 2023);

    if (anio_bisiesto(anio))
    {
        mes = validar_num("Ingrese su mes de nacimiento: ", 1, 12);

        if (mes == 2)
        {
            dia = validar_num("Ingrese su dia de nacimiento: ", 1, 29);
        }

        else
        {
            if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
            {
                dia = validar_num("Ingrese su dia de nacimiento: ", 1, 31);
            }

            else
            {
                dia = validar_num("Ingrese su dia de nacimiento: ", 1, 30);
            }
        }
    }

    else
    {
        mes = validar_num("Ingrese su mes de nacimiento: ", 1, 12);

        if (mes == 2)
        {
            dia = validar_num("Ingrese su dia de nacimiento: ", 1, 28);
        }

        else
        {
            if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
            {
                dia = validar_num("Ingrese su dia de nacimiento: ", 1, 31);
            }

            else
            {
                dia = validar_num("Ingrese su dia de nacimiento: ", 1, 30);
            }
        }
    }
}

int sexo()
{
    int sexo;
    printf("1 - Hombre\n");
    printf("2 - Mujer\n");
    sexo = validar_num("Ingrese su sexo: ", 1, 2);

    return sexo;
}

int anio_bisiesto(int anio)
{
    {
        if (anio % 4 == 0)
        {
            if (anio % 100 == 0)
            {
                if (anio % 400 == 0)
                {
                    return 1;
                }

                else
                {
                    return 0;
                }
            }

            else
            {
                return 1;
            }
        }

        else
        {
            return 0;
        }
    }
}