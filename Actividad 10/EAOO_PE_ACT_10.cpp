#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CAPACIDAD 500

typedef struct
{
    int estado;
    int matricula;
    char apellidoPaterno[30];
    char apellidoMaterno[30];
    char nombre[50];
    int edad;
    int sexo;
} Estudiante;

void menu();
int mostrarMenu();
void llenarRegistros(Estudiante estudiantes[], int *posicion);
Estudiante nuevoEstudiante(Estudiante estudiantes[], int *posicion);
void eliminarEstudiante(Estudiante estudiantes[], int posicion);
void buscarEstudiante(Estudiante estudiantes[], int posicion, int flag);
void ordenarEstudiantes(Estudiante estudiantes[], int n);
void mostrarRegistrosActivos(Estudiante estudiantes[], int posicion);
void mostrarRegistros(Estudiante estudiantes[], int n);
Estudiante generarDatosRegistro(Estudiante estudiantes[], int posicion);
int existeElemento(Estudiante estudiantes[], int n, int elemento);
int alfaEspacio(const char *cadena);
void mostrarRegistro(Estudiante estudiante, int numero);
int busquedaBinaria(Estudiante estudiantes[], int n, int matricula);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}


void menu()
{
    int opcion, posicion = 0, flag = 1;
    Estudiante estudiantes[CAPACIDAD];
    do
    {
        opcion = mostrarMenu();
        system("clear"); // Cambiar a "cls" en Windows

        switch (opcion)
        {
        case 1:
            if (posicion + 10 >= CAPACIDAD)
            {
                printf("Has alcanzado el límite de registros permitidos.\n");
            }
            else
            {
                llenarRegistros(estudiantes, &posicion);
                posicion += 10;
                flag = 0;
                printf("\t\t\t¡Se crearon 10 registros correctamente!\n");
            }
            system("pause"); // Cambiar a "PAUSE" en Windows
            break;
        case 2:
            if (posicion + 1 >= CAPACIDAD)
            {
                printf("Has alcanzado el límite de registros permitidos.\n");
            }
            else
            {
                estudiantes[posicion] = nuevoEstudiante(estudiantes, &posicion);
                flag = 0;
                posicion += 1;
            }
            system("pause"); // Cambiar a "PAUSE" en Windows
            break;
        case 3:
            eliminarEstudiante(estudiantes, posicion);
            flag = 0;
            system("pause"); // Cambiar a "PAUSE" en Windows
            break;
        case 4:
            buscarEstudiante(estudiantes, posicion, flag);
            system("pause"); // Cambiar a "PAUSE" en Windows
            break;
        case 5:
            if (flag == 0)
            {
                ordenarEstudiantes(estudiantes, posicion);
                flag = 1;
                printf("Los registros se han ordenado correctamente por matrícula de menor a mayor.\n");
            }
            else
            {
                printf("Los registros ya se habían ordenado anteriormente.\n");
            }
            system("pause"); // Cambiar a "PAUSE" en Windows
            break;
        case 6:
            mostrarRegistrosActivos(estudiantes, posicion);
            system("pause"); // Cambiar a "PAUSE" en Windows
            break;
        }
    } while (opcion != 0);
    printf("Saliendo del programa.\n");
}

int mostrarMenu()
{
    int opcion;
    system("clear"); // Cambiar a "cls" en Windows
    printf("MANEJO Y CONTROL DE ESTUDIANTES\n");
    printf("1.- Agregar 10 registros automáticamente\n");
    printf("2.- Agregar manualmente\n");
    printf("3.- Eliminar registro\n");
    printf("4.- Buscar\n");
    printf("5.- Ordenar\n");
    printf("6.- Imprimir\n");
    printf("0.- Salir\n");
    printf("Selecciona una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

void llenarRegistros(Estudiante estudiantes[], int *posicion)
{
    for (int i = *posicion; i < *posicion + 10; i++)
    {
        estudiantes[i] = generarDatosRegistro(estudiantes, *posicion);
    }
    mostrarRegistros(estudiantes, *posicion + 10);
}

Estudiante nuevoEstudiante(Estudiante estudiantes[], int *posicion)
{
    Estudiante nuevoEstudiante;

    char temp[30];

    nuevoEstudiante.estado = 1;

    do
    {
        printf("Por favor, ingresa la matrícula del estudiante: ");
        scanf("%d", &nuevoEstudiante.matricula);
    } while (existeElemento(estudiantes, *posicion, nuevoEstudiante.matricula) != -1);

    do
    {
        printf("Ingresa el apellido paterno del estudiante (en mayúsculas): ");
        scanf("%s", temp);
    } while (alfaEspacio(temp) == -1);

    strcpy(nuevoEstudiante.apellidoPaterno, temp);

    do
    {
        printf("Ingresa el apellido materno del estudiante (en mayúsculas): ");
        scanf("%s", temp);
    } while (alfaEspacio(temp) == -1);

    strcpy(nuevoEstudiante.apellidoMaterno, temp);

    do
    {
        printf("Ingresa el nombre del estudiante (en mayúsculas): ");
        scanf("%s", temp);
    } while (alfaEspacio(temp) == -1);

    strcpy(nuevoEstudiante.nombre, temp);

    printf("0.- Mujer\t 1.- Hombre\n");
    do
    {
        printf("Ingresa el sexo del estudiante (0 para mujer, 1 para hombre): ");
        scanf("%d", &nuevoEstudiante.sexo);
    } while (nuevoEstudiante.sexo < 0 || nuevoEstudiante.sexo > 1);

    return nuevoEstudiante;
}

void eliminarEstudiante(Estudiante estudiantes[], int posicion)
{
    int numero, indice;
    printf("Ingresa la matrícula del estudiante que deseas eliminar: ");
    scanf("%d", &numero);
    indice = existeElemento(estudiantes, posicion, numero);
    if (indice != -1)
    {
        if (estudiantes[indice].estado != 0)
        {
            estudiantes[indice].estado = 0;
            printf("El estudiante ha sido dado de baja correctamente.\n");
        }
        else
        {
            printf("El estudiante ya estaba dado de baja anteriormente.\n");
        }
    }
    else
    {
        printf("La matrícula ingresada no pertenece a ningún estudiante.\n");
    }
}

void buscarEstudiante(Estudiante estudiantes[], int posicion, int flag)
{
    int numero, indice;
    printf("Ingresa la matrícula del estudiante que deseas buscar: ");
    scanf("%d", &numero);
    if (flag == 0)
    {
        indice = existeElemento(estudiantes, posicion, numero);
    }
    else
    {
        indice = busquedaBinaria(estudiantes, posicion, numero);
    }
    if (indice != -1)
    {
        printf("El estudiante ha sido encontrado con éxito.\n");
        printf("No.\tMatrícula\tEstado\tApellido Paterno\tApellido Materno\tNombre\tEdad\tSexo\n");
        mostrarRegistro(estudiantes[indice], indice);
    }
    else
    {
        printf("La matrícula ingresada no pertenece a ningún estudiante.\n");
    }
}

void ordenarEstudiantes(Estudiante estudiantes[], int n)
{
    Estudiante temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (estudiantes[j].matricula > estudiantes[j + 1].matricula)
            {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
    mostrarRegistros(estudiantes, n);
}

void mostrarRegistrosActivos(Estudiante estudiantes[], int posicion)
{
    printf("No.\tMatrícula\tEstado\tApellido Paterno\tApellido Materno\tNombre\tEdad\tSexo\n");
    for (int i = 0; i < posicion; i++)
    {
        if (estudiantes[i].estado == 1)
        {
            mostrarRegistro(estudiantes[i], i);
        }
    }
}

void mostrarRegistros(Estudiante estudiantes[], int n)
{
    printf("No.\tMatrícula\tEstado\tApellido Paterno\tApellido Materno\tNombre\tEdad\tSexo\n");
    for (int i = 0; i < n; i++)
    {
        mostrarRegistro(estudiantes[i], i);
    }
}

Estudiante generarDatosRegistro(Estudiante estudiantes[], int posicion)
{
    Estudiante nuevoEstudiante;

    nuevoEstudiante.estado = 1;
    nuevoEstudiante.matricula = rand() % 100000; // Matrícula aleatoria de 0 a 99999

    strcpy(nuevoEstudiante.apellidoPaterno, "ApellidoPaterno" + (posicion % 10));
    strcpy(nuevoEstudiante.apellidoMaterno, "ApellidoMaterno" + (posicion % 10));
    strcpy(nuevoEstudiante.nombre, "Nombre" + (posicion % 10));

    nuevoEstudiante.edad = 18 + (rand() % 13); // Edad aleatoria de 18 a 30
    nuevoEstudiante.sexo = rand() % 2;         // 0 para mujer, 1 para hombre

    return nuevoEstudiante;
}

int existeElemento(Estudiante estudiantes[], int n, int elemento)
{
    for (int i = 0; i < n; i++)
    {
        if (estudiantes[i].matricula == elemento)
        {
            return i; // Devuelve el índice si se encuentra
        }
    }
    return -1; // Devuelve -1 si no se encuentra
}

int alfaEspacio(const char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (!(cadena[i] >= 'A' && cadena[i] <= 'Z') && cadena[i] != ' ')
        {
            return -1; // Contiene un carácter no alfabético o espacio
        }
    }
    return 0; // Todos los caracteres son alfabéticos o espacios
}

void mostrarRegistro(Estudiante estudiante, int numero)
{
    printf("%d\t%d\t%d\t%s\t%s\t%s\t%d\t%s\n", numero + 1, estudiante.matricula, estudiante.estado,
           estudiante.apellidoPaterno, estudiante.apellidoMaterno, estudiante.nombre, estudiante.edad,
           estudiante.sexo == 0 ? "Mujer" : "Hombre");
}

int busquedaBinaria(Estudiante estudiantes[], int n, int matricula)
{
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (estudiantes[medio].matricula == matricula)
        {
            return medio; // La matrícula se encontró
        }

        if (estudiantes[medio].matricula < matricula)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }

    return -1; // La matrícula no se encontró
}
