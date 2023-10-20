#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int validar_num(char mensaje[], int ri, int rf);
int validar_string(const char *str);
int numero_aleatorio(int ri, int rf);
void llenar_vector(int *vector, int tam, int min, int max);
void llenar_matriz(int matriz[4][4], int min, int max);
void imprimir_vector(int *vector, int tam, char *nombre);
void imprimir_matriz(int matriz[4][4], char *nombre);
void ordenar_vector(int *vector, int tam);
int buscar_vector(int *vector, int tam, int valor);
int busq_sec_ord (int vect[], int n, int num);
int matricula(int n, int min, int max);

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

#include <ctype.h>

int validar_string(const char *str)
{
    if (str == NULL || str[0] == '\0')
    {
        return 0;
    }

    if (str[0] == ' ')
    {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            return 0;
        }

        if (isdigit((unsigned char)str[i]))
        {
            return 0;
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)str[i];
        if ((c >= 128 && c <= 165) || (c >= 192 && c <= 255))
        {
            return 0;
        }
    }

    return 1;
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
void ordenar_vector(int *vector, int tam)
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
int busq_sec_ord (int vect[], int n, int num)
{
    int i;
    i = 0;

    while (i <n)
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

    if(existe != -1)
    {
        printf("El numero existe dentro del vector, esta en la posicion: %d \n", existe);
    }

    else
    {
        printf("El numero ingresado no se encuentra dentro del vector\n");
    }

    system ("PAUSE");
    
}
