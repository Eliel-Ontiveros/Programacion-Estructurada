/*
Eliel Alfonso Ontiveros Ojeda_368746
15-Oct-2023 / 22-Oct-2023
Realiza un programa que sirva para generar el CURP de una persona. 

El programa debe pedir los datos al usuario, generar, almacenar en una cadena y desplegar el CURP. 

El programa deberá repetirse cuantas veces desee el usuario 

Nota: el programa deberá estar 100% validado, de datos entrada así como las reglas que e deben cuplir al generar el curp
*/

#include <stdio.h>
#include <string.h>
#include "palabras_inconvenientes.h"
#include "chntoky.h"

void nombre_completo(char curp[], char nombre1[], char nombre2[], char ap_paterno[], char ap_materno[]);
void estd_nacimiento(char curp[], char *estado);
void fecha_nacimiento(char curp[], int dia, int mes, int anio);
void sex_usuario(char curp[]);
int anio_bisiesto(int anio);
char primera_vocal(const char *str);
bool esVocal(const char str);
char primera_consonante(const char *str);
char primera_consonante_sin_inicial(const char *str);
int compara_arreglo(char curp[]);
char *compuestos(char str[]);
void replaceNWithX(char *str);

int main()
{
    srand(time(NULL));
    int op;
    char nombre[100];
    char segundo_nombre[100];
    char apellido_paterno[100];
    char apellido_materno[100];
    int anio_nacimiento, mes_nacimiento, dia_nacimiento;
    int sexo;
    char estado_nacimiento[100];
    char curp[19];
    curp[19] = '\0'; // Agregar un carácter nulo al final de la cadena CURP
    curp[18] = numero_aleatorio(0, 9);

    char respuesta;
    do
    {
        nombre_completo(curp, nombre, segundo_nombre, apellido_paterno, apellido_materno);
        compara_arreglo(curp);

        fecha_nacimiento(curp, dia_nacimiento, mes_nacimiento, anio_nacimiento);

        estd_nacimiento(curp, estado_nacimiento);

        sex_usuario(curp);

        printf("Tu curp es la siguiente\n");
        for (int i = 0; i < 20; i++)
        {
            printf("%c", curp[i]);
        }

        printf("\nIngrese 1 si desea ingresar otro curp\n");
        printf("Ingrese 0 para terminar el programa\n");
        op = validar_num("Ingrese la opcion deseada: ", 0, 1);

    } while (op != 0);
    printf("Saliendo del programa\n");

    return 0;
}

void nombre_completo(char curp[], char nombre1[], char nombre2[], char ap_paterno[], char ap_materno[])
{
    system("CLS");
    int op;
    printf("Ingrese su Nombre: ");
    validar_string(nombre1, 100);
    replaceNWithX(nombre1);

    const char *ultimoNombre = compuestos(nombre1); // Llama a la función compuestos y almacena el resultado

    if (ultimoNombre != NULL)
    {
        strcpy(nombre1, ultimoNombre); // Sobrescribe nombre1 con el último nombre completo
    }

    printf("1 - Tengo un segundo nombre\n");
    printf("2 - No tengo un segundo nombre\n");
    op = validar_num("Ingrese una opcion: ", 1, 2);

    if (op == 1)
    {
        printf("Ingrese su Segundo Nombre: ");
        validar_string(nombre2, 100);
        replaceNWithX(nombre2);
    }
    else
    {
        nombre2[0] = '\0';
    }

    printf("Ingrese su Apellido Paterno: ");
    validar_string(ap_paterno, 100);
    replaceNWithX(ap_paterno);

    const char *ultimoApellidoPaterno = compuestos(ap_paterno);

    if (ultimoApellidoPaterno != NULL)
    {
        strcpy(ap_paterno, ultimoApellidoPaterno);
    }

    printf("Ingrese su Apellido Materno: ");
    validar_string(ap_materno, 100);
    replaceNWithX(ap_materno);

    const char *ultimoApellidoMaterno = compuestos(ap_materno);

    if (ultimoApellidoMaterno != NULL)
    {
        strcpy(ap_materno, ultimoApellidoMaterno);
    }

    curp[0] = ap_paterno[0];
    for (int i = 1; ap_paterno[i] != '\0'; i++)
    {
        if (esVocal(ap_paterno[i]))
        {
            curp[1] = ap_paterno[i];
            break;
        }
    }
    for (int i = 1; ap_paterno[i] != '\0'; i++)
    {
        if (!esVocal(ap_paterno[i]))
        {
            curp[13] = ap_paterno[i];
            break;
        }
    }
    for (int i = 1; ap_materno[i] != '\0'; i++)
    {
        if (!esVocal(ap_materno[i]))
        {
            curp[14] = ap_materno[i];
            break;
        }
    }

    curp[2] = ap_materno[0];

    curp[3] = nombre1[0];

    curp[16] = primera_consonante(nombre1);
}

void estd_nacimiento(char curp[], char *estado)
{
    int op;
    char estd_string[33][3];
    int i;

    printf("Estados de Mexico\n");

    for (i = 0; i < 33; i++)
    {
        printf("%d - %s\n", i + 1, estados[i]);
    }

    op = validar_num("Ingrese su estado de nacimiento: ", 1, 33);
    strcpy(estado, estados_abr[op - 1]);

    curp[11] = estado[0];
    curp[12] = estado[1];
}

void fecha_nacimiento(char curp[], int dia, int mes, int anio)
{
    char anio_string[5];
    char mes_string[4];
    char dia_string[4];
    anio = validar_num("Ingrese su anio de nacimiento: ", 1890, 2023);

    snprintf(anio_string, sizeof(anio_string), "%d", anio);

    curp[4] = anio_string[2];
    curp[5] = anio_string[3];

    if (anio_bisiesto(anio))
    {
        mes = validar_num("Ingrese su mes de nacimiento: ", 1, 12);

        snprintf(mes_string, sizeof(mes_string), "%02d", mes);
        curp[6] = mes_string[0];
        curp[7] = mes_string[1];

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
        // itoa(mes, mes_string, 10);
        snprintf(mes_string, sizeof(mes_string), "%02d", mes);
        curp[6] = mes_string[0];
        curp[7] = mes_string[1];

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

    snprintf(dia_string, sizeof(dia_string), "%02d", dia);
    curp[8] = dia_string[0];
    curp[9] = dia_string[1];

    if (anio < 1999)
    {
        curp[17] = '0';
    }

    else
    {
        curp[17] = 'A';
    }
}

void sex_usuario(char curp[])
{
    int sexo;
    printf("1 - Hombre\n");
    printf("2 - Mujer\n");
    sexo = validar_num("Ingrese su sexo: ", 1, 2);

    if (sexo == 1)
    {
        curp[10] = 'H';
    }

    else
    {
        curp[10] = 'M';
    }

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

char primera_vocal(const char *str)
{
    while (*str)
    {
        char ch = toupper(*str);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            return ch;
        }
        str++;
    }
    return '\0';
}

bool esVocal(const char str)
{

    char ch = toupper(str);
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return true;
    }

    return false;
}

char primera_consonante(const char *str)
{
    while (*str)
    {
        char ch = toupper(*str);
        if (ch >= 'A' && ch <= 'Z' && ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U')
        {
            return ch;
        }
        str++;
    }
    return '\0';
}

int compara_arreglo(char curp[])
{
    char nomfff[5];
    strcpy(nomfff, curp);

    for (int i = 0; i < 100; i++)
    {
        if (strcmp(nomfff, palabras_inconvenientes[i]) == 0)
        {
            curp[1] = 'X';
            return 1;
        }
    }

    return 0;
}

char *compuestos(char str[])
{
    char *lastMatch = NULL;

    char *token = strtok(str, " ");

    while (token != NULL)
    {
        for (int i = 0; i < 100; i++)
        {
            if (strcmp(token, lista_compuestos[i]) == 0)
            {
            }
            else
            {
                lastMatch = token;
            }
        }

        token = strtok(NULL, " ");
    }

    return lastMatch;
}

char primera_consonante_sin_inicial(const char *str)
{
    int found = 0;
    while (*str)
    {
        char ch = toupper(*str);
        if (ch >= 'A' && ch <= 'Z' && ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U')
        {
            if (found)
            {
                return ch;
            }
            found = 1;
        }
        str++;
    }
    return '\0';
}

void replaceNWithX(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'ñ')
        {
            str[i] = 'x';
        }
    }
}