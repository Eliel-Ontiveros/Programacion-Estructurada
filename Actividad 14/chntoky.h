#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int validar_num(char mensaje[], int ri, int rf);
int val_num(int ri, int rf);
bool validar_string(char vect[], int largo);
void mayus(char array[]);
int numero_aleatorio(int ri, int rf);
void llenar_vector(int *vector, int tam, int min, int max);
void llenar_matriz(int matriz[4][4], int min, int max);
void imprimir_vector(int *vector, int tam, char *nombre);
void imprimir_matriz(int matriz[4][4], char *nombre);
void ordenar_vector(int *vector, int tam);
int buscar_vector(int *vector, int tam, int valor);
int busq_sec_ord(int vect[], int n, int num);
void cens_curp(char *text, char cens_lista[][500], char remplazar_lista[][500], int n_palabras);
int anio_bisiesto(int anio);
char *compuestos(char str[]);
void replaceNWithX(char *str);

// VALIDAR NUMERO ENTERO
int validar_num(char mensaje[], int ri, int rf)
{
    int num;
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &num);
    } while (num < ri || num > rf);

    return num;
}


int val_num(int ri, int rf)
{
    char string[50];
    int num;

    do
    {
        fflush(stdin);
        gets(string);
        num = atoi(string);
        if (num < ri || num > rf)
        {
            printf("Please enter a valid number: ");
        }
    } while (num < ri || num > rf);

    return num;
}

#include <ctype.h>

bool validar_string(char vect[], int largo)
{
    int invalido = 0;
    int i;

    do
    {
        invalido = 0;
        fflush(stdin);
        gets(vect);
        mayus(vect);

        if (vect[0] == ' ')
        {
            invalido = 1;
        }

        for (i = 0; vect[i] != '\0'; i++)
            ;
        if (i > largo)
        {
            printf("El texto tiene mas de [%d] caracteres\n", largo);
            invalido = 1;
        }

        for (i = 0; vect[i] != '\0'; i++)
        {
            if (vect[i] > 90)
            {
                if (vect[i] >= 97)
                {
                    if (vect[i] > 122)
                    {
                        invalido = 1;
                        printf("No se pueden utilizar caracteres especiales\n");
                    }
                }
                else
                {
                    invalido = 1;
                    printf("No se pueden utilizar caracteres especiales\n");
                }
            }
            else
            {
                if (vect[i] == 32)
                {
                    if (vect[i + 1] == 32)
                    {
                        invalido = 1;
                        printf("No se pueden utilizar dobles espacios\n");
                    }
                }
                else
                {
                    if (vect[i] < 65)
                    {
                        invalido = 1;
                        printf("No se pueden utilizar caracteres especiales\n");
                    }
                }
            }
        }

        if (invalido == 1)
        {
            printf("Vuelva a ingresar su respuesta\n");
        }

    } while (invalido == 1);

    return true;
}

void mayus(char array[])
{
    int i;
    char word;
    for (i = 0; array[i] != '\0'; i++)
    {
        word = array[i];
        if (word >= 'a')
        {
            if (word <= 'z')
            {
                array[i] = array[i] - 32;
            }
        }
    }
}

int numero_aleatorio(int ri, int rf)
{
    int range = (rf - ri + 1);

    return rand() % range + ri;
}

// LLENAR VECTOR
void llenar_vector(int *vector, int tam, int min, int max)
{
    srand(time(0));
    for (int i = 0; i < tam; i++)
    {
        vector[i] = (rand() % (max - min + 1)) + min;
    }

    printf("Vector Llenado\n");

    system("PAUSE");
}

// LLENAR MATRIZ
void llenar_matriz(int matriz[4][4], int min, int max)
{
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = (rand() % (max - min + 1)) + min;
        }
    }

    printf("Matriz Llenada\n");

    system("PAUSE");
}

// IMPRIMIR VECTOR
void imprimir_vector(int *vector, int tam, char *nombre)
{
    printf("%s: ", nombre);
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");

    system("PAUSE");
}

// IMPRIMIR MATRIZ
void imprimir_matriz(int matriz[4][4], char *nombre)
{
    printf("%s:\n", nombre);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    system("PAUSE");
}

// ORDENAR VECTOR
void ordenar_vector(char *vector, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    printf("Vector Ordenado\n");

    system("PAUSE");
}

// BUSCAR VALOR EN VECTOR
int buscar_vector(int *vector, int tam, int valor)
{
    for (int i = 0; i < tam; i++)
    {
        if (vector[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

// BUSQUEDA SECUENCIAL DETENIENDO EL PROCESO SI NUM NO SE ENCUENTRA DENTRO DEL VECTOR
int busq_sec_ord(int vect[], int n, int num)
{
    int i;
    i = 0;

    while (i < n)
    {
        if (num >= vect[i])
        {
            if (num == vect[i])
            {
                return i;
            }
        }

        else
        {
            return -1;
        }

        i++;
    }

    return -1;
}

// BUSCA UN VALOR INGRESADO POR EL USUARIO
void valor_vector(int vect[], int tam)
{
    int valor;
    int existe;
    valor = validar_num("Ingrese el numero que desea buscar en el vector(Rango de 100 a 200)\n", 100, 200);
    existe = buscar_vector(vect, tam, valor);

    if (existe != -1)
    {
        printf("El numero existe dentro del vector, esta en la posicion: %d \n", existe);
    }

    else
    {
        printf("El numero ingresado no se encuentra dentro del vector\n");
    }

    system("PAUSE");
}

void cens_curp(char *text, char cens_lista[][500], char reemplazar_lista[][500], int n_palabras)
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


char obtenerPrimeraVocal(const char cadena[])
{
    char vocalEncontrada = 'X';

    for (int i = 1; cadena[i] != '\0'; i++)
    {
        char c = toupper(cadena[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vocalEncontrada = c;
            break;
        }
    }
    return vocalEncontrada;
}

char obtenerSegundaConsonante(char cadena[])
{
    int i = 1;

    while (cadena[i] != '\0')
    {
        char caracter = cadena[i];
        if (strchr("AEIOUaeiou", caracter) == NULL)
        {
            return caracter;
        }
        i++;
    }
    return '\0';
}

int validarAntisonante(char cadena[], char antisonantes[87][100], int numAntisonantes)
{
    char subcadena[5];

    strncpy(subcadena, cadena, 4);
    subcadena[4] = '\0';

    for (int i = 0; i < numAntisonantes; i++)
    {
        if (strcmp(subcadena, antisonantes[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}


int validarEntidad(char cadena[], char entidades[50][3], int numEntidades)
{
    for (int i = 0; i < numEntidades; i++)
    {
        if (strcmp(cadena, entidades[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}