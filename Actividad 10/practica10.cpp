#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include "chntoky.h"
using namespace std;

typedef struct _alumnos
{
    int status;
    int matricula;
    char ApPat[50];
    char ApMat[50];
    char Nombre[50];
    int Edad;
    char Sexo[10];
    int cant;
} talumnos;

talumnos CreacionPersona(set<int> matriculasUtilizadas)
{
    vector<string> nombres_hombre = {"Juan", "Jose", "Pepe", "Javier", "Jorge", "Natanael", "Lucas", "Luffy"};
    vector<string> nombres_mujer = {"Maria", "Guadalupe", "Miriam", "Daniela", "Karolina", "Adilene", "Judith"};
    vector<string> apellidos = {"Ontiveros", "Lopez", "Rodriguez", "Nuñez", "Ramos", "Robles", "Mendoza", "Ramirez", "Murillo", "Casas"};

    talumnos alumno;

    // Elegir género al azar
    bool es_hombre = numero_aleatorio(0, 1) == 0;

    // Elegir un nombre al azar según el género
    vector<string> &nombres = es_hombre ? nombres_hombre : nombres_mujer;
    string nombre_elegido = nombres[rand() % nombres.size()];

    // Elegir apellidos al azar
    string apellido_paterno = apellidos[rand() % apellidos.size()];
    string apellido_materno = apellidos[rand() % apellidos.size()];

    // Elegir un número de matrícula único
    int matricula;
    do
    {
        matricula = numero_aleatorio(300000, 399999);            // Genera un número aleatorio en el rango
    } while (matriculasUtilizadas.count(matricula) > 0); // Verifica si ya se utilizó

    matriculasUtilizadas.insert(matricula);

    // Almacenar los datos en el arreglo global de alumnos
    alumno.status = 1;
    strcpy(alumno.Nombre, nombre_elegido.c_str());
    strcpy(alumno.ApPat, apellido_paterno.c_str());
    strcpy(alumno.ApMat, apellido_materno.c_str());
    strcpy(alumno.Sexo, es_hombre ? "Hombre" : "Mujer");
    alumno.Edad = numero_aleatorio(18, 30);
    alumno.matricula = matricula;

    return alumno;
}

talumnos agregarManual(set<int> matriculasUtilizadas) {
    talumnos alumno;
    int sexo, status;
    string nombre, apellido_paterno, apellido_materno;

    status = validar_num("Ingrese 0 si el alumno está de baja o 1 si el alumno sigue estudiando: ", 0, 1);
    alumno.status = status;

    // Elegir un número de matrícula único
    int matricula;
    matricula = validar_num("Ingrese la matrícula del estudiante (300000-399999): ", 300000, 399999);

    if (matriculasUtilizadas.count(matricula) > 0) {
        printf("La matrícula ya ha sido utilizada. Ingrese una matrícula diferente.\n");
    } else {
        matriculasUtilizadas.insert(matricula); // Agregar la matrícula al conjunto para evitar duplicados
    }

    cin.ignore(); // Consume el carácter de nueva línea restante en el búfer

    sexo = validar_num("Ingrese 1 si es Hombre o 2 si es Mujer: ", 1, 2);

    cin.ignore(); // Agregar esta línea para consumir cualquier carácter de nueva línea restante

    // Ingresa el nombre del alumno
    do {
        printf("Ingrese el nombre del alumno: ");
        getline(cin, nombre);
    } while (!validar_string(nombre.c_str()));

    strcpy(alumno.Nombre, nombre.c_str());

    // Ingresa el apellido paterno del alumno
    do {
        printf("Ingrese el apellido paterno del alumno: ");
        getline(cin, apellido_paterno);
    } while (!validar_string(apellido_paterno.c_str()));

    strcpy(alumno.ApPat, apellido_paterno.c_str());

    // Ingresa el apellido materno del alumno
    do {
        printf("Ingrese el apellido materno del alumno: ");
        getline(cin, apellido_materno);
    } while (!validar_string(apellido_materno.c_str()));

    strcpy(alumno.ApMat, apellido_materno.c_str());

    // Almacena el sexo
    strcpy(alumno.Sexo, (sexo == 1) ? "Hombre" : "Mujer");

    // Genera una edad aleatoria entre 18 y 30 años
    alumno.Edad = numero_aleatorio(18, 30);

    // Almacena la matrícula ingresada
    alumno.matricula = matricula;

    return alumno;
}





void imprimir(talumnos alumnos[], int alumnos_creados)
{
    for (int i = 0; i < alumnos_creados; i++)
    {
        printf("Alumno %d:\n", i + 1);
        printf("Matricula: %d\n", alumnos[i].matricula);
        printf("Nombre: %s\n", alumnos[i].Nombre);
        printf("Apellido Paterno: %s\n", alumnos[i].ApPat);
        printf("Apellido Materno: %s\n", alumnos[i].ApMat);
        printf("Sexo: %s\n", alumnos[i].Sexo);
        printf("Edad: %d\n", alumnos[i].Edad);
        printf("Estatus: %d\n", alumnos[i].status);
        printf("----------------------------\n");
    }
}

int msgs()
{
    int op; // Declaramos la variable donde guardaremos la opcion de que operacion realizaremos
    // system("CLS"); // Sirve para limpiar la pantalla al momento de llamar nuestra funcion
    printf("-----M E N U-----\n");
    printf("1 - Crear gente\n");
    printf("2 - Imprimir\n");
    printf("0 - Salir\n");
    op = validar_num("Seleccione una de las opciones\n", 0, 6);

    return op;
}

void menu()
{
    int op, i;
    talumnos alumnos[500], alumnoTemp;
    set<int> matriculasUtilizadas;

    i = 0;
    do // Mientras op este entre los valor de 1 y 4 se seleccionara una opcion y saldra del bucle
    {
        op = msgs(); // Llamamos a nuestra funcion msgs para guardar el valor de op guardado en ella y guardarla en la funcion menu
        system("CLS");
        switch (op)
        {
        case 1:
            for (int j = 0; j < 10; j++)
            {
                if (i < 35)
                {
                    alumnoTemp = CreacionPersona(matriculasUtilizadas);
                    alumnos[i++] = alumnoTemp;
                }
                else
                {
                    printf("Se rebaso la cantidad de personas\n");
                    break;
                }
            }
            break;

        case 2:
            imprimir(alumnos, i);
            break;

        case 3:
            alumnoTemp = agregarManual(matriculasUtilizadas);
            alumnos[i++] = alumnoTemp;

        default:
            break;
        }

    } while (op != 0); // Si op es diferente a 0 la opcion saldra del bucle y continuara a la funcion seleccionada
}

int main()
{
    srand(time(NULL)); // Inicializa la semilla para números aleatorios
    menu();
    return 0;
}
