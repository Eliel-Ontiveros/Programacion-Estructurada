/*
Eliel Alfonso Ontiveros Ojeda_368746
26/11/2023 - 28/11/2023
INSTRUCCIONES: Programa que contenga el menú anterior, el programa utiliza un vector de índices de la siguiente estructura:  [ llave, índice] donde el campo llave es  noempleado. 
registros.dat   es el archivo con los registros a cargar en el vector de índices  archivo binario sera proporcionado,

CARGAR ARCHIVO : El programa deberá cargar al arrancar el programa, el archivo Binario generará el vector de índices (llave, indice) sólo con registros válidos (el tamaño del vector debera ser 25% mas grande que el la cantidad de registros que contenga el archivo binario ) utiliza un archivo externo para averiguar tamaño y retorne cantidad de registros.

1.- Agregar : 
El programa deberá ser capaz de agregar un registro al arreglo de índices y al final del archivo Binario.  (agregar forma automatica no repetido el campo llave)


2.- Eliminar :  
El programa deberá buscar una noempleado en el vector de índices por medio del método de búsqueda más óptimo. 
La función deberá retornar, el índice donde se encuentra la matrícula en el archivo Binario,  utilizar banderas para escoger el método más adecuado. 
Una vez obtenido el índice moverse dentro del archivo binario (usar fseek ) usando el índice del vector de índices. 
Leer el registro en la posición correcta, preguntar si se quiere eliminar registro. 
Cambiar el status del registro si la respuesta es afirmativa, volver a posición anterior y sobreescribir el registro. 


3.- Buscar :  
El programa deberá buscar un noempleado en el vector de índices por medio del método de búsqueda más óptimo. 
La función deberá retornar, el índice donde se encuentra la matrícula en el archivo Binario,  utilizar banderas para escoger el método más adecuado. 
Una vez obtenido el índice moverse dentro del archivo binario (usar fseek ) usando el índice del vector de índices. 
Leer el registro en la posición correcta, y desplegar el registro. 


 4.- Ordenar : 
El programa deberá ordenar el vector de índices por medio del método de ordenación más óptimo. Utilizar banderas para escoger el método más adecuado por el que se ordenará por el campo llave (noempleado) o no ordenarse si ya está ordenado.   (utilizar 3 metodos de ordenacion diferentes segun sea el caso que se necesite Justificar los metodos en el reporte)


5 Y 6.- Mostrar Todo: 
El programa deberá mostrar todos los registros del Archivo Binario, preguntar:  ordenado o normal.  Usar el vector de índices para imprimirlo ordenado, y directamente desde el archivo si es normal.


7.- GENERAR ARCHIVO TEXTO: 
El programa deberá generar un archivo de texto, el usuario debe proporcionar el nombre del archivo.

El programa deberá mostrar todos los registros del Archivo Binario, preguntar:  ordenado o normal.  Usar el vector de índices para imprimirlo ordenado, y directamente desde el archivo si es normal.

el programa podrá generar múltiples archivos para comprobar las salidas. 


8.- EMPAQUETAR : 
El programa deberá actualizar el Archivo Binario, a partir de solo registros válidos, y eliminarlos del archivo binario.  Crear copia y archivo de respaldo .bak del archivo de antes de eliminarlos. 
*/

#include "chntoky.h"
#include <direct.h>
#include "ListaNuevoUsuario.h"

typedef int Tkey;

// Definición de la estructura de un registro
typedef struct
{
    int status;
    Tkey enrollment;
    char name[30];
    char LastName1[50];
    char LastName2[50];
    char sex[15];
    char JobPstion[30];
    char state[30];
    int age;
    Tkey cellPhone;
} TWrkr;

typedef struct
{
    int indice;
    int llave;
    int status;
} indi;

#define MAX_REGISTROS 50

/*Esqueleto de las funciones*/
void agregarRegistro(FILE *archivoBinario, Tkey **indiceVector, int *numRegistros);
void cargarArchivo(Tkey **indiceVector, TWrkr **registros, int *numRegistros);
int buscarMatricula(const Tkey *indiceVector, int numRegistros, Tkey matricula);
void eliminarRegistro(FILE *archivoBinario, Tkey *indiceVector, int numRegistros);
void buscarRegistro(FILE *archivoBinario, const Tkey *indiceVector, int numRegistros, Tkey matricula);
void ordenarIndices(Tkey *indiceVector, int numRegistros);
void imprimirRegistro(const TWrkr *registro);
void mostrarTodo(FILE *archivoBinario, const Tkey *indiceVector, int numRegistros);
void imprimirRegistroEnTexto(FILE *archivoTexto, const TWrkr *registro);
void generarArchivoTexto(FILE *archivoBinario, const Tkey *indiceVector, int numRegistros);
void empaquetarArchivo(FILE *archivoBinario);
void crear_index(int p, indi *indice);
void importarDatos(TWrkr reg);
int Ordenar(indi array[], int size);

/*Esqueleto de Menu y Mensaje*/
void menu(void);
void ImprimirMenu(void);

/*Funcion Main*/
int main()
{
    srand(time(NULL));

    menu();

    return 0;
}

void menu(void)
{
    Tkey *indiceVector = NULL;
    TWrkr *registros = NULL;
    int numRegistros = 0;
    FILE *archivoBinario;

    cargarArchivo(&indiceVector, &registros, &numRegistros);

    char currentPath[FILENAME_MAX];
    if (!_getcwd(currentPath, sizeof(currentPath)))
    {
        perror("Error getting current directory");
    }
    else
    {
        printf("Current working directory: %s\n", currentPath);
    }

    int opcion;
    archivoBinario = fopen("datos.dat", "rb+");
    if (!archivoBinario)
    {
        perror("Error al abrir el archivo binario");
        exit(EXIT_FAILURE);
    }

    do
    {
        system("CLS");
        ImprimirMenu();
        printf("\nSeleccione una opcion: ");
        opcion = val_num(0, 8);

        switch (opcion)
        {
        case 1:
            agregarRegistro(archivoBinario, &indiceVector, &numRegistros);

            break;

        case 2:
            eliminarRegistro(archivoBinario, indiceVector, numRegistros);

            break;

        case 3:
        {
            Tkey matriculaBuscar;
            printf("Ingrese el numero de empleado a buscar: ");
            matriculaBuscar = val_num(300000, 399999);

            int indiceEncontrado = buscarMatricula(indiceVector, numRegistros, matriculaBuscar);

            if (indiceEncontrado != -1)
            {

                fseek(archivoBinario, indiceEncontrado * sizeof(TWrkr), SEEK_SET);

                TWrkr registroEncontrado;
                fread(&registroEncontrado, sizeof(TWrkr), 1, archivoBinario);

                printf("Registro encontrado:\n");
                imprimirRegistro(&registroEncontrado);
            }
            else
            {
                printf("Numero de empleado no encontrado.\n");
            }
            system("PAUSE");
            break;
        }

        case 4:
            ordenarIndices(indiceVector, numRegistros);

            break;

        case 5:
            mostrarTodo(archivoBinario, indiceVector, numRegistros);

            break;

        case 6:
            generarArchivoTexto(archivoBinario, indiceVector, numRegistros);

            break;

        case 7:
            empaquetarArchivo(archivoBinario);

            break;
        }

    } while (opcion != 0);

    fclose(archivoBinario);

    printf("Saliendo del Programa\n");

    free(indiceVector);
    free(registros);
}

void ImprimirMenu(void)
{
    system("cls");
    printf("-------------------------------------\n");
    printf("                 Menu\n");
    printf("-------------------------------------\n");
    printf("||  1 - Agregar                    ||\n");
    printf("||  2 - Eliminar                   ||\n");
    printf("||  3 - Buscar                     ||\n");
    printf("||  4 - Ordenar                    ||\n");
    printf("||  5 - Imprimir Archivo Original  ||\n");
    printf("||  6 - Generar Archivo Texto      ||\n");
    printf("||  7 - Empaquetar                 ||\n");
    printf("||  0 - Salir                      ||\n");
    printf("-------------------------------------\n");
    printf("-------------------------------------");
}

Tkey generarMatriculaUnica(const Tkey *indiceVector, int numRegistros)
{
    Tkey nuevaMatricula;

    bool matriculaExistente;

    do
    {
        nuevaMatricula = numero_aleatorio(300000, 399999);

        matriculaExistente = false;

        for (int i = 0; i < numRegistros; i++)
        {
            if (indiceVector[i] == nuevaMatricula)
            {
                matriculaExistente = true;
                break;
            }
        }

    } while (matriculaExistente);

    return nuevaMatricula;
}

void agregarRegistro(FILE *archivoBinario, Tkey **indiceVector, int *numRegistros)
{
    TWrkr nuevoUsuario;
    indi indice[MAX_REGISTROS];
    char temp[30];
    int c, i;

    c = rand() % (2 - 1 + 1) + 1;

    nuevoUsuario.status = 1;

    genNombre(temp, c);
    strcpy(nuevoUsuario.name, temp);

    genApellido(temp);
    strcpy(nuevoUsuario.LastName1, temp);

    genApellido(temp);
    strcpy(nuevoUsuario.LastName2, temp);

    genSexo(temp);
    strcpy(nuevoUsuario.sex, temp);

    genPuesto(temp);
    strcpy(nuevoUsuario.JobPstion, temp);

    genEstado(temp);
    strcpy(nuevoUsuario.state, temp);

    nuevoUsuario.age = numero_aleatorio(18, 60);
    nuevoUsuario.cellPhone = numero_aleatorio(1000000, 1999999);

    nuevoUsuario.enrollment = generarMatriculaUnica(*indiceVector, *numRegistros);

    fseek(archivoBinario, 0, SEEK_END);

    fwrite(&nuevoUsuario, sizeof(TWrkr), 1, archivoBinario);
    (*numRegistros)++;

    *indiceVector = (Tkey *)realloc(*indiceVector, (*numRegistros + *numRegistros / 4) * sizeof(Tkey));

    if (*indiceVector == NULL)
    {
        perror("Error reallocating memory for indiceVector");
        exit(EXIT_FAILURE);
    }

    (*indiceVector)[*numRegistros - 1] = nuevoUsuario.enrollment;

    indi *indiceArray = (indi *)malloc(*numRegistros * sizeof(indi));

    if (indiceArray == NULL)
    {
        perror("Error allocating memory for indiceArray");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *numRegistros; i++)
    {
        indiceArray[i].indice = i;
        indiceArray[i].llave = (*indiceVector)[i];
    }

    crear_index(*numRegistros, indiceArray);

    free(indiceArray);

    printf("Registro Creado\n");
    system("PAUSE");
}

void cargarArchivo(Tkey **indiceVector, TWrkr **registros, int *numRegistros)
{
    FILE *archivoBinario = fopen("datos.dat", "rb+");

    if (!archivoBinario)
    {
        perror("Error al abrir el archivo binario");
        exit(EXIT_FAILURE);
    }

    fseek(archivoBinario, 0, SEEK_END);
    int tamanoArchivo = ftell(archivoBinario);
    *numRegistros = tamanoArchivo / sizeof(TWrkr);

    *indiceVector = (Tkey *)malloc((*numRegistros + *numRegistros / 4) * sizeof(Tkey));

    fseek(archivoBinario, 0, SEEK_SET);

    *registros = (TWrkr *)malloc(*numRegistros * sizeof(TWrkr));
    for (int i = 0; i < *numRegistros; ++i)
    {
        fread(&(*registros)[i], sizeof(TWrkr), 1, archivoBinario);

        (*indiceVector)[i] = (*registros)[i].enrollment;
    }

    fclose(archivoBinario);
}

int buscarMatricula(const Tkey *indiceVector, int numRegistros, Tkey matricula)
{
    for (int i = 0; i < numRegistros; ++i)
    {
        if (indiceVector[i] == matricula)
        {
            return i;
        }
    }
    return -1;
}

void eliminarRegistro(FILE *archivoBinario, Tkey *indiceVector, int numRegistros)
{
    Tkey matricula;
    int indiceEncontrado;

    printf("Ingrese el numero de empleado a eliminar: ");
    matricula = val_num(300000, 399999);

    indiceEncontrado = buscarMatricula(indiceVector, numRegistros, matricula);

    if (indiceEncontrado != -1)
    {
        fseek(archivoBinario, indiceEncontrado * sizeof(TWrkr), SEEK_SET);

        TWrkr registroEncontrado;
        fread(&registroEncontrado, sizeof(TWrkr), 1, archivoBinario);

        printf("Registro encontrado:\n");
        imprimirRegistro(&registroEncontrado);

        char respuesta;
        printf("Desea eliminar el registro? (1 = Si, 2 = No): ");
        respuesta = val_num(0, 1);

        if (respuesta == 1)
        {
            registroEncontrado.status = 0;

            fseek(archivoBinario, -sizeof(TWrkr), SEEK_CUR);
            fwrite(&registroEncontrado, sizeof(TWrkr), 1, archivoBinario);

            printf("Registro eliminado exitosamente.\n");
        }
        else
        {
            printf("Eliminacion cancelada.\n");
        }
    }
    else
    {
        printf("Numero de empleado no encontrado.\n");
    }

    system("PAUSE");
}

void buscarRegistro(FILE *archivoBinario, const Tkey *indiceVector, int numRegistros, Tkey matricula)
{
    int indiceEncontrado = buscarMatricula(indiceVector, numRegistros, matricula);

    if (indiceEncontrado != -1)
    {
        fseek(archivoBinario, indiceEncontrado * sizeof(TWrkr), SEEK_SET);

        TWrkr registroEncontrado;
        fread(&registroEncontrado, sizeof(TWrkr), 1, archivoBinario);

        printf("Registro encontrado:\n");
        printf("Status: %d\n", registroEncontrado.status);
        printf("Noempleado: %d\n", registroEncontrado.enrollment);
        printf("Nombre: %s\n", registroEncontrado.name);
        printf("Apellido Paterno: %s\n", registroEncontrado.LastName1);
        printf("Apellido Materno: %s\n", registroEncontrado.LastName2);
        printf("Sexo: %s\n", registroEncontrado.sex);
        printf("Posicion: %s\n", registroEncontrado.JobPstion);
        printf("Estado: %s\n", registroEncontrado.state);
        printf("Edad: %d\n", registroEncontrado.age);
        printf("Num. Telefono: %d\n", registroEncontrado.cellPhone);
        printf("---------------------------------\n");
    }
    else
    {
        printf("Matrícula no encontrada.\n");
    }

    system("PAUSE");
}

int compararMatricula(const void *a, const void *b)
{
    return *((const Tkey *)a) - *((const Tkey *)b);
}

void ordenarIndices(Tkey *indiceVector, int numRegistros)
{
    qsort(indiceVector, numRegistros, sizeof(Tkey), compararMatricula);
}

void imprimirRegistro(const TWrkr *registro)
{
    printf("Status: %d\n", registro->status);
    printf("Noempleado: %d\n", registro->enrollment);
    printf("Nombre: %s\n", registro->name);
    printf("Apellido Paterno: %s\n", registro->LastName1);
    printf("Apellido Materno: %s\n", registro->LastName2);
    printf("Sexo: %s\n", registro->sex);
    printf("Posicion: %s\n", registro->JobPstion);
    printf("Estado: %s\n", registro->state);
    printf("Edad: %d\n", registro->age);
    printf("Num. Telefono: %d\n", registro->cellPhone);
    printf("------------------------\n");
}

int compararRegistrosPorMatricula(const void *a, const void *b)
{
    const TWrkr *registroA = (const TWrkr *)a;
    const TWrkr *registroB = (const TWrkr *)b;

    // Comparar por matrícula
    return registroA->enrollment - registroB->enrollment;
}

void mostrarTodo(FILE *archivoBinario, const Tkey *indiceVector, int numRegistros)
{
    int opcionOrden;

    printf("Seleccione la opcion:\n");
    printf("1. Imprimir ordenado por matricula\n");
    printf("2. Imprimir normal\n");
    opcionOrden = val_num(1, 2);

    if (opcionOrden == 1)
    {
        TWrkr *registros = (TWrkr *)malloc(numRegistros * sizeof(TWrkr));
        fseek(archivoBinario, 0, SEEK_SET);
        fread(registros, sizeof(TWrkr), numRegistros, archivoBinario);

        qsort(registros, numRegistros, sizeof(TWrkr), compararRegistrosPorMatricula);

        for (int i = 0; i < numRegistros; ++i)
        {
            imprimirRegistro(&registros[i]);
        }

        free(registros);
    }
    else if (opcionOrden == 2)
    {
        fseek(archivoBinario, 0, SEEK_SET);

        TWrkr registro;
        while (fread(&registro, sizeof(TWrkr), 1, archivoBinario) == 1)
        {
            imprimirRegistro(&registro);
        }
    }
    else
    {
        printf("Opcion no valida.\n");
    }

    system("PAUSE");
}

void imprimirRegistroEnTexto(FILE *archivoTexto, const TWrkr *registro)
{
    fprintf(archivoTexto, "Status: %d\n", registro->status);
    fprintf(archivoTexto, "Noempleado: %d\n", registro->enrollment);
    fprintf(archivoTexto, "Nombre: %s\n", registro->name);
    fprintf(archivoTexto, "Apellido Paterno: %s\n", registro->LastName1);
    fprintf(archivoTexto, "Apellido Materno: %s\n", registro->LastName2);
    fprintf(archivoTexto, "Sexo: %s\n", registro->sex);
    fprintf(archivoTexto, "Posicion: %s\n", registro->JobPstion);
    fprintf(archivoTexto, "Estado: %s\n", registro->state);
    fprintf(archivoTexto, "Edad: %d\n", registro->age);
    fprintf(archivoTexto, "Num. Telefono: %d\n", registro->cellPhone);
    fprintf(archivoTexto, "------------------------\n");
}

void generarArchivoTexto(FILE *archivoBinario, const Tkey *indiceVector, int numRegistros)
{
    char nombreArchivoTexto[100];

    printf("Ingrese el nombre del archivo de texto: ");
    validar_string(nombreArchivoTexto, 40);

    FILE *archivoTexto = fopen(nombreArchivoTexto, "w");

    if (!archivoTexto)
    {
        perror("Error al abrir el archivo de texto");
        exit(EXIT_FAILURE);
    }

    int opcionOrden;

    printf("Seleccione la opcion:\n");
    printf("1. Imprimir ordenado\n");
    printf("2. Imprimir normal\n");
    opcionOrden = val_num(1, 2);

    if (opcionOrden == 1)
    {
        Tkey *copiaIndiceVector = (Tkey *)malloc(numRegistros * sizeof(Tkey));
        if (copiaIndiceVector == NULL)
        {
            perror("Error allocating memory for copiaIndiceVector");
            exit(EXIT_FAILURE);
        }

        memcpy(copiaIndiceVector, indiceVector, numRegistros * sizeof(Tkey));

        ordenarIndices(copiaIndiceVector, numRegistros);

        for (int i = 0; i < numRegistros; ++i)
        {
            int matriculaOrdenada = copiaIndiceVector[i];

            int indiceOrdenado = buscarMatricula(indiceVector, numRegistros, matriculaOrdenada);

            fseek(archivoBinario, indiceOrdenado * sizeof(TWrkr), SEEK_SET);

            TWrkr registro;
            fread(&registro, sizeof(TWrkr), 1, archivoBinario);

            imprimirRegistroEnTexto(archivoTexto, &registro);
        }

        free(copiaIndiceVector);
    }

    else if (opcionOrden == 2)
    {
        fseek(archivoBinario, 0, SEEK_SET);

        TWrkr registro;
        while (fread(&registro, sizeof(TWrkr), 1, archivoBinario) == 1)
        {
            imprimirRegistroEnTexto(archivoTexto, &registro);
        }
    }
    else
    {
        printf("Opcion no valida.\n");
    }

    fclose(archivoTexto);

    printf("Archivo de texto generado exitosamente: %s\n", nombreArchivoTexto);
}

void empaquetarArchivo(FILE *archivoBinario)
{
    FILE *doc = fopen("datos.dat", "rb");
    ;
    FILE *respaldo = fopen("datos.bak", "wb");

    TWrkr registros;

    if (doc)
    {
        while (fread(&registros, sizeof(TWrkr), 1, doc))
        {
            if (registros.status == 1)
            {
                fwrite(&registros, sizeof(TWrkr), 1, respaldo);
            }
        }
    }

    fclose(doc);
    fclose(respaldo);

    printf("Archivo Empaquetado\n");
    system("PAUSE");
}

void crear_index(int p, indi *indice)
{
    int i;
    FILE *doc = fopen("index.dat", "ab");

    if (doc == NULL)
    {
        perror("ERROR, Archivo no encontrado\n");
        system("PAUSE");
    }
    else
    {
        for (i = 0; i < p; i++)
        {
            indice[i].status = 1;
            fwrite(&indice[i], sizeof(indi), 1, doc);
        }
    }
    fclose(doc);
}

void importarDatos(TWrkr reg)
{
    FILE *doc = fopen("datos.dat", "ab");
    if (doc)
    {
        fwrite(&reg, sizeof(TWrkr), 1, doc);
    }
    fclose(doc);
}
