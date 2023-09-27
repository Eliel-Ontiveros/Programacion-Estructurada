/*




*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void manual(void);
void random(void);
void vect1_vect2(void);
void imp_vectores(void);
void matriz_4x4(void);
void imp_matriz(void);
int msgs();
void menu();

int main()
{
    menu();

    return 0;
}

int msgs()
{
    int op;
    system("CLS");
    printf("------MENU-------\n");
    printf("1 - Llenar Vector 1 (Manualmente)\n");
    printf("2 - Llenar Vector 2 (Aleatoriamente)\n");
    printf("3 - Llenar Vector 3 (Con Vector 1 y Vector 2)\n");
    printf("4 - Imprimir Verctores\n");
    printf("5 - Llenar Matriz 4 x 4\n");
    printf("6 - Imprimir Matriz\n");
    printf("0 - Salir\n");
    scanf("%d", &op);

    return op;
}

void menu()
{
    int op;
    system("CLS");

    do
    {
        op = msgs();

        switch (op)
        {
        case 1:
            manual();
            break;

        case 2:
            random();
            break;

        case 3:
            vect1_vect2();
            break;

        case 4:
            imp_vectores();
            break;

        case 5:
            matriz_4x4();
            break;

        case 6:
            imp_matriz();
            break;

        default:
            break;
        }

    } while (op != 0);

    printf("Saliendo del Programa");
}

void manual()
{
    int vect1[10];

    for (int i = 1; i < 11; i++)
    {
        printf("Introduce un valor entre 30 y 70 para el elemento %d: ", i);
        scanf("%d", &vect1[i]);
    }

    system("PAUSE");
}

void random()
{
    int vect2[10];
    srand(time(NULL));

    for (int i = 1; i < 11; i++)
    {
        vect2[i] = rand() % 20 + 1;
    }

    for (int i = 1; i < 11; i++)
    {
        printf("El valor del elemento %d es: %d\n", i, vect2[i]);
    }

    system("PAUSE");
}

void vect1_vect2()
{
    int vect3[20];

    system("PAUSE");
}

void imp_vectores()
{
    system("PAUSE");
}

void matriz_4x4()
{
    system("PAUSE");
}

void imp_matriz()
{
    system("PAUSE");
}