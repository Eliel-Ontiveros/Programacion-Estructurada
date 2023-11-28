/*
Eliel Alfonso Ontiveros Ojeda_368746
14-Nov-2023 /
EAOO_PE_ACT13.cpp

MENÚ

1.- AGREGAR (AUTOM 100 REGISTROS)

2.- EDITAR REGISTRO

3.- ELIMINAR REGISTRO (lógico)

4.- BUSCAR

5.- ORDENAR

6- IMPRIMIR

7.- GENERAR ARCHIVO TEXTO

8.- VER ARCHIVO TEXTO

9.- CREAR ARCH BINARIO

10.- CARGAR ARCH BINARIO

 0.- SALIR
*/
#include "Funciones.h"
#include "chntoky.h"

#define N 5000
#define FALSE 0
#define TRUE 1
#define ACTIVO 1
#define INACTIVO 0

void Menu(void);
void ImprimirMenu(void);
void GenArchivoT(tdato vect[], int n);
void LeerArchivoT(void);
int LeerRegistroArchivoT(tdato vect[], int n);
void GenArchivoB(tdato vect[], int n);
int LeerArchivoB(tdato vect[], int n);
void EditarRegistroEnArchivoT(char nombreArchivo[], long matriculaBuscada);

int main()
{
    srand(time(NULL));
    Menu();

    return 0;
}

void Menu(void)
{
    int i = 0, j, n, op, resul, buscar_num, ordenar;
    tdato vect[N], reg;
    long buscar_matriz;
    ordenar = FALSE;
    n = N - 1;
    do
    {
        system("cls");
        ImprimirMenu();
        op = val_num(0, 10);
        switch (op)
        {
        case 1:
            if (i <= N - 10)
            {
                for (j = 0; j < 100; j++)
                {
                    vect[i] = genRegistro();
                    i++;
                }
                printf("!!Registros Generados!!\n");
                system("pause");
            }
            else
            {
                printf("!!El vector ya esta lleno!!\n");
                printf("---------------------------\n");
                system("pause");
            }
            break;

        case 2:
        {
            printf("Cual ID quieres editar: ");
            buscar_matriz = val_num(100000, 199999);
            EditarRegistroEnArchivoT("nombre_del_archivo.txt", buscar_matriz);
            system("pause");
        }
        break;

        case 3:
        {
            printf("Cual es numero del registro que quieres borrar: ");
            buscar_num = val_num(100000, 199999);
            resul = EliminarLogico(vect, n, buscar_num);
            if (resul >= 0)
            {
                printf("!!Registro eliminado!!\n");
                printf("----------------------\n");
                system("pause");
            }
            else
            {
                printf("!!Este registro no existe!!\n");
                printf("---------------------------\n");
                system("pause");
            }
        }
        break;

        case 4:
        {
            printf("Cual es el ID que quieres buscar: ");
            buscar_matriz = val_num(100000, 199999);
            resul = BuscarSec(vect, i, buscar_matriz);
            if (resul >= 0)
            {
                system("cls");
                printf("------------------------------------------------------------------------\n");
                printf("||                 ID encontrada                    ||\n");
                printf("------------------------------------------------------------------------\n");
                printf("  No  ID  Nombre    apPat     apMat     Puesto        Edad Sexo  \n");
                printf("||%-4d %-9ld %-9s %-9s %-9s %-14s %-4d %-6s||\n", i + 1, vect[i].matricula, vect[i].nombre, vect[i].apPat, vect[i].apMat, vect[i].puesto, vect[i].edad, vect[i].sexo);
                printf("------------------------------------------------------------------------\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("-----------------------------------\n");
                printf("||  !!ID No encontrada!!  ||\n");
                printf("-----------------------------------\n");
                system("pause");
            }
        }
        break;

        case 5:
        {
            if (!ordenar)
            {
                Ordenar(vect, n);
                printf("!!Listo registros ordenados!!\n");
                printf("-----------------------------\n");
                ordenar = TRUE;
                system("pause");
            }
            else
            {
                printf("!!Los registros ya estan ordenados!!\n");
                printf("------------------------------------\n");
                system("pause");
            }
        }
        break;

        case 6:
        {
            ImprimirVect(vect, n);
        }
        break;

        case 7:
        {
            GenArchivoT(vect, n);
            printf("-------------------------\n");
            printf("|| !!Archivo Generado!! ||\n");
            printf("-------------------------\n");
            system("pause");
        }
        break;

        case 8:
        {
            n = LeerRegistroArchivoT(vect, n);
            printf("-------------------------\n");
            printf("|| !!Archivo Cargado!! ||\n");
            printf("-------------------------\n");
            system("pause");
        }
        break;

        case 9:
        {
            GenArchivoB(vect, n);
            printf("-------------------------\n");
            printf("|| !!Archivo Generado!! ||\n");
            printf("-------------------------\n");
            system("pause");
        }
        break;

        case 10:
        {
            n = LeerArchivoB(vect, n);
            printf("-------------------------\n");
            printf("|| !!Archivo Cargado!! ||\n");
            printf("-------------------------\n");
            system("pause");
        }
        break;
        }

    } while (op != 0);
}

void ImprimirMenu(void)
{
    system("cls");
    printf("-----------------------------------\n");
    printf("              Menu\n");
    printf("-----------------------------------\n");
    printf("||  1 - Agregar                  ||\n");
    printf("||  2 - Editar                   ||\n");
    printf("||  3 - Eliminar                 ||\n");
    printf("||  4 - Buscar                   ||\n");
    printf("||  5 - Ordenar                  ||\n");
    printf("||  6 - Imprimir                 ||\n");
    printf("||  7 - Generar Archivo Texto    ||\n");
    printf("||  8 - Cargar Archivo Texto     ||\n");
    printf("||  9 - Generar Archivo Binario  ||\n");
    printf("|| 10 - Cargar Archivo Binario   ||\n");
    printf("||  0 - Salir                    ||\n");
    printf("|| Selecciona una opcion:        ||\n");
    printf("-----------------------------------\n");
    printf("-----------------------------------");
}
/////////////
void GenArchivoT(tdato vect[], int n)
{
    FILE *fi;
    char nombre[30];
    int i;
    printf("Dame el nombre del archivo agrega .txt al final: ");
    fflush(stdin);
    validar_string(nombre, 20);
    fi = fopen(nombre, "w+");
    system("cls");
    for (i = 0; i <= n; i++)
    {
        if (vect[i].status == 1)
        {
            fprintf(fi, "%-4d %-9ld %-9s %-9s %-11s %-14s %-2d %-6s\n", i + 1, vect[i].matricula, vect[i].nombre, vect[i].apPat, vect[i].apMat, vect[i].puesto, vect[i].edad, vect[i].sexo);
        }
        else
        {
            fprintf(fi, "                  [Registro Inactivo]                    \n");
        }
    }
    fclose(fi);
}
///////////////
void LeerArchivoT(void)
{
    FILE *fi;
    char nombre[30], caracter;
    int i;
    printf("Dame el nombre del archivo agrega .txt al final: ");
    fflush(stdin);
    validar_string(nombre, 20);
    fi = fopen(nombre, "r");
    system("cls");
    if (fi)
    {
        while (!feof(fi))
        {
            caracter = fgetc(fi);
            printf("%c", caracter);
        }
        system("pause");
        fclose(fi);
    }
    else
    {
        printf("!!EL ARCHIVO NO EXISTE!!\n");
        system("pause");
    }
}

int LeerRegistroArchivoT(tdato vect[], int n)
{
    FILE *fi;
    char nombre[30];
    int i, j;
    system("cls");
    printf("Dame el nombre del archivo agrega .txt al final: ");
    fflush(stdin);
    validar_string(nombre, 20);
    fi = fopen(nombre, "r");
    system("cls");
    if (fi)
    {
        while (!feof(fi))
        {
            fscanf(fi, "%d%ld%s%s%s%d%s\n", &j, &vect[i].matricula, &vect[i].nombre, &vect[i].apPat, &vect[i].apMat, &vect[i].edad, &vect[i].sexo);
            printf("Cargando registros %ld\n", vect[i].matricula);
            vect[i].status = ACTIVO;
            i++;
        }
        system("pause");
        fclose(fi);
    }
    else
    {
        printf("!!EL ARCHIVO NO EXISTE!!\n");
        system("pause");
    }
    return i;
}

void GenArchivoB(tdato vect[], int n)
{
    int i;
    tdato reg;
    FILE *fi;
    system("cls");
    fi = fopen("Prueba.dat", "a+b");
    for (i = 0; i < n; i++)
    {
        reg = vect[i];
        fwrite(&reg, sizeof(tdato), 1, fi);
        printf("Escribiendo registro...\n");
    }
    fclose(fi);
    system("pause");
}

int LeerArchivoB(tdato vect[], int n)
{
    FILE *fi;
    int i = 0;
    tdato reg;
    system("cls");
    fi = fopen("Prueba.dat", "rb");
    printf("------------------------------------------------------------------------\n");
	printf("  No  ID  Nombre    apPat     apMat     Puesto        Edad Sexo  \n");
	printf("------------------------------------------------------------------------\n");
    if (fi)
    {
        while (fread(&reg, sizeof(tdato), 1, fi))
        {

            printf("||%-4d %-9ld %-9s %-9s %-9s %-14s %-4d %-6s||\n", i + 1, vect[i].matricula, vect[i].nombre, vect[i].apPat, vect[i].apMat, vect[i].puesto, vect[i].edad, vect[i].sexo);
            vect[n++] = reg;
        }
        fclose(fi);
    }
    else
    {
        printf("!!EL ARCHIVO NO EXISTE!!\n");
        system("pause");
    }
    return n;
}

void EditarRegistroEnArchivoT(char nombreArchivo[], long matriculaBuscada)
{
    FILE *fi, *temp;
    tdato reg;
    int encontrado = 0;

    fi = fopen(nombreArchivo, "r");
    temp = fopen("temp.txt", "w");

    if (fi == NULL || temp == NULL)
    {
        printf("Error al abrir archivos.\n");
        return;
    }

    char linea[256]; // Ajusta el tamaño según sea necesario

    while (fgets(linea, sizeof(linea), fi) != NULL)
    {
        sscanf(linea, "%d%ld%s%s%s%d%s", &reg.status, &reg.matricula, reg.nombre, reg.apPat, reg.apMat, &reg.edad, reg.sexo, reg.puesto);

        if (reg.matricula == matriculaBuscada && reg.status == 1)
        {
            printf("Registro actual:\n");
            printf("ID: %ld\n", reg.matricula);
            printf("Nombre: %s\n", reg.nombre);
            printf("Apellido Paterno: %s\n", reg.apPat);
            printf("Apellido Materno: %s\n", reg.apMat);
            printf("Edad: %d\n", reg.edad);
            printf("Sexo: %s\n", reg.sexo);
            printf("Puesto: %s\n", reg.puesto);

            printf("Ingresa la nueva información:\n");
            printf("Nombre: ");
            validar_string(reg.nombre, 20);
            printf("Apellido Paterno: ");
            validar_string(reg.apPat, 20);
            printf("Apellido Materno: ");
            validar_string(reg.apMat, 20);
            printf("Edad: ");
            scanf("%d", &reg.edad);
            printf("Sexo: ");
            validar_string(reg.sexo, 10);
            printf("Puesto: ");
            validar_string(reg.puesto, 20);

            fprintf(temp, "%d%ld%s%s%s%d%s%s\n", reg.status, reg.matricula, reg.nombre, reg.apPat, reg.apMat, reg.edad, reg.sexo, reg.puesto);
            encontrado = 1;
        }
        else
        {
            fprintf(temp, "%d%ld%s%s%s%d%s%s\n", reg.status, reg.matricula, reg.nombre, reg.apPat, reg.apMat, reg.edad, reg.sexo, reg.puesto);
        }
    }

    fclose(fi);
    fclose(temp);

    if (encontrado)
    {
        remove(nombreArchivo);
        rename("temp.txt", nombreArchivo);
        printf("Registro editado exitosamente.\n");
    }
    else
    {
        printf("Registro no encontrado.\n");
    }
}
