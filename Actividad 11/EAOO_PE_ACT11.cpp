#include "chntoky.h"
#define MAXIMO 2000

typedef struct _nombres
{
    char ap_pat[30];
    char ap_mat[30];
    char nombre[30];
    char nombre2[30];
} Tnombres;

typedef struct _fechaNacimiento
{
    int anio;
    int mes;
    int dia;
} Tnacimiento;

typedef struct _alumno
{
    int status;
    int matricula;
    Tnombres nom_comp;
    int op_apellido1;
    int op_apellido2;
    Tnacimiento fech_nacim;
    int edad;
    int sexo;
    char estd_nacim[2];
    char curp[19];
} Talum;

int msges();
void menu();
Talum auto_reg();
Talum manual_reg();
void curp(Talum student);
int linearSearch(Talum array[], int size, int searchNumber);
int binarySearch(Talum array[], int left, int right, int number);
int ordenar(Talum array[], int size);
void swap(Talum array[], int i, int j);
int partition(Talum array[], int low, int high);
void quicksort(Talum array[], int low, int high);
void imprimir_reg(Talum array[], int size);
void archivo_text(Talum array[], int size);

int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

int msges()
{
    int opcion;
    system("cls");
    printf("--------------------------------\n");
    printf("              Menu\n");
    printf("--------------------------------\n");
    printf("|| 1. Agregar                 ||\n");
    printf("|| 2. Eliminar                ||\n");
    printf("|| 3. Buscar                  ||\n");
    printf("|| 4. Ordenar                 ||\n");
    printf("|| 5. Imprimir                ||\n");
    printf("|| 6. Crear archivo txt       ||\n");
    printf("|| 0.Salir                    ||\n");
    opcion = validar_num("|| Selecciona una opcion:    ", 0, 6);
    return opcion;
}

int msges2()
{
    int op;
    printf("--------------------------------\n");
    printf("              Menu\n");
    printf("--------------------------------\n");
    printf("|| 1. Registros Auto (100)    ||\n");
    printf("|| 2. Registro Manual (1)     ||\n");
    printf("|| 3. Regresar                ||\n");
    op = validar_num("|| Selecciona una opcion:    ", 1, 3);
    return op;
}

void menu()
{
    int opcion, orden, i, eliminar, buscar, found;
    Talum studentArray[MAXIMO], temp;
    i = 0;

    do
    {
        opcion = msges();
        system("CLS");

        switch (opcion)
        {
        case 1:
            int op;

            do
            {
                op = msges2();
                switch (op)
                {
                case 1:
                    orden = 0;

                    for (int j = 0; j < 100; j++)
                    {
                        temp = auto_reg();
                        while (linearSearch(studentArray, i, temp.matricula) != -1)
                        {
                            temp.matricula = numero_aleatorio(300000, 399999);
                        }
                        studentArray[i++] = temp;
                    }
                    printf("Se han creado 100 registros\n");

                    break;

                case 2:
                    if (i >= MAXIMO)
                    {
                        printf("\nSe ha excedido el limite de registros\n");
                    }
                    else
                    {
                        orden = 0;

                        temp = manual_reg();
                        while (linearSearch(studentArray, i, temp.matricula) != -1)
                        {
                            printf("Matricula existente\n");
                            printf("Ingrese otra matricula\n");
                            temp.matricula = validar_num("", 300000, 399999);
                        }
                        studentArray[i++] = temp;
                        printf("Se ha creado el registro");

                        break;
                    }
                }
                system("PAUSE");
                system("CLS");
            } while (op != 3);
            break;

        case 2:
            eliminar = validar_num("Matricula que desea eliminar: ", 300000, 399999);
            buscar = linearSearch(studentArray, i, eliminar);

            if (buscar != -1)
            {
                if (studentArray[buscar].status == 1)
                {
                    // Marcar el registro como eliminado
                    studentArray[buscar].status = 0;
                    printf("Matricula eliminada\n");
                }
                else
                {
                    printf("El registro ya está eliminado\n");
                }
            }
            else
            {
                printf("No existe la matricula ingresada\n");
            }
            system("PAUSE");
            break;

        case 3:
            buscar = validar_num("Matricula que desea buscar: ", 300000, 399999);

            if (orden == 0)
            {
                found = linearSearch(studentArray, i, buscar);
            }
            else
            {
                found = binarySearch(studentArray, 0, i - 1, buscar);
            }

            if (found != -1)
            {
                printf("Se ha encontrado la matricula, esta en el registro %i\n", found + 1);
                imprimir_reg(&studentArray[found], 1);
            }
            else
            {
                printf("No se ha encontrado la matricula\n");
            }

            system("PAUSE");
            break;

        case 4:
            if (orden == 0)
            {
                if (i <= 500)
                {
                    orden = ordenar(studentArray, i);
                    printf("Se han ordenado los registros\n");
                }
            }
            else
            {
                printf("Los registros ya estan ordenados\n");
            }
            system("PAUSE");
            break;

        case 5:
            imprimir_reg(studentArray, i);
            system("PAUSE");
            break;

        case 6:
            printf("Se ha creado el archivo txt\n");
            archivo_text(studentArray, i);
            system("PAUSE");
            break;

        case 0:
            return;
            break;

        default:
            printf("Opcion invalida. Seleccione una opcion valida\n");
            break;
        }

    } while (opcion != 0);
}

Talum auto_reg()
{
    Talum student;
    int op_nom2;
    student.status = 1;

    student.matricula = numero_aleatorio(300000, 399999);

    student.op_apellido1 = 1;
    student.op_apellido2 = 1;
    student.sexo = numero_aleatorio(1, 2);

    strcpy(student.nom_comp.ap_pat, apellidos[numero_aleatorio(0, 20)]);
    strcpy(student.nom_comp.ap_mat, apellidos[numero_aleatorio(0, 20)]);

    if (student.sexo == 1)
    {
        strcpy(student.nom_comp.nombre, nombre_hombre[numero_aleatorio(0, 20)]);
        op_nom2 = numero_aleatorio(1, 2);

        if (op_nom2 == 1)
        {
            strcpy(student.nom_comp.nombre2, nombre_hombre2[numero_aleatorio(0, 20)]);
        }

        else
        {
            student.nom_comp.nombre2[0] = '\0';
        }

        student.sexo = 1;
    }

    else
    {
        strcpy(student.nom_comp.nombre, nombre_mujer[numero_aleatorio(0, 20)]);
        op_nom2 = numero_aleatorio(1, 2);

        if (op_nom2 == 1)
        {
            strcpy(student.nom_comp.nombre2, nombre_mujer2[numero_aleatorio(0, 20)]);
        }

        else
        {
            student.nom_comp.nombre2[0] = '\0';
        }
        student.sexo = 2;
    }

    student.fech_nacim.anio = numero_aleatorio(1970, 2023);
    student.fech_nacim.mes = numero_aleatorio(1, 12);

    if (student.fech_nacim.mes == 2 && anio_bisiesto(student.fech_nacim.anio) == 1)
    {
        student.fech_nacim.dia = numero_aleatorio(1, 29);
    }
    else
    {
        if (student.fech_nacim.mes == 2 && anio_bisiesto(student.fech_nacim.anio) == 0)
        {
            student.fech_nacim.dia = numero_aleatorio(1, 28);
        }
        else
        {
            if (student.fech_nacim.mes == 1 || student.fech_nacim.mes == 3 || student.fech_nacim.mes == 5 || student.fech_nacim.mes == 7 || student.fech_nacim.mes == 8 || student.fech_nacim.mes == 10 || student.fech_nacim.mes == 12)
            {
                student.fech_nacim.dia = numero_aleatorio(1, 31);
            }
            else
            {
                if (student.fech_nacim.mes == 4 || student.fech_nacim.mes == 6 || student.fech_nacim.mes == 9 || student.fech_nacim.mes == 11)
                {
                    student.fech_nacim.dia = numero_aleatorio(1, 30);
                }
            }
        }
    }

    student.edad = 2023 - student.fech_nacim.anio;

    strcpy(student.estd_nacim, estados_abr[numero_aleatorio(0, 32)]);

    return student;
}

Talum manual_reg()
{
    Talum student;
    int op;

    printf("Ingrese los siguientes datos:\n");

    student.matricula = 1;

    student.matricula = validar_num("\nMatricula: ", 300000, 399999);

    printf("Primer Nombre: ");
    validar_string(student.nom_comp.nombre, sizeof(student.nom_comp.nombre));
    replaceNWithX(student.nom_comp.nombre);

    const char *ultimoNombre = compuestos(student.nom_comp.nombre);
    if (ultimoNombre != NULL)
    {
        strcpy(student.nom_comp.nombre, ultimoNombre); // Sobrescribe nombre1 con el último nombre completo
    }

    printf("\n1 - Tengo un segundo nombre\n");
    printf("2 - No tengo un segundo nombre\n");
    op = validar_num("Ingrese una opcion: ", 1, 2);

    if (op == 1)
    {
        printf("\nIngrese su Segundo Nombre: ");
        validar_string(student.nom_comp.nombre2, sizeof(student.nom_comp.nombre2));
        replaceNWithX(student.nom_comp.nombre2);

        const char *ultimoNombre2 = compuestos(student.nom_comp.nombre2);
        if (ultimoNombre != NULL)
        {
            strcpy(student.nom_comp.nombre2, ultimoNombre2); // Sobrescribe nombre1 con el último nombre completo
        }
    }
    else
    {
        student.nom_comp.nombre2[0] = '\0';
    }

    system("CLS");

    printf("Tiene apellido paterno:\n");
    printf("[1] Si\n[2] No\nOpcion: ");
    student.op_apellido1 = val_num(1, 2);
    if (student.op_apellido1 == 1)
    {
        printf("Apellido Paterno: ");
        validar_string(student.nom_comp.ap_pat, sizeof(student.nom_comp.ap_pat));
        replaceNWithX(student.nom_comp.ap_pat);

        const char *ultimoApellidoPaterno = compuestos(student.nom_comp.ap_pat);
        if (ultimoNombre != NULL)
        {
            strcpy(student.nom_comp.ap_pat, ultimoApellidoPaterno); // Sobrescribe nombre1 con el último nombre completo
        }
    }

    system("CLS");

    printf("¿Tienes apellido materno?\n");
    printf("[1] Si\n[2] No\nOpcion: ");
    student.op_apellido2 = val_num(1, 2);
    if (student.op_apellido2 == 1)
    {
        printf("Apellido Materno: ");
        validar_string(student.nom_comp.ap_mat, sizeof(student.nom_comp.ap_mat));

        const char *ultimoApellidoMaterno = compuestos(student.nom_comp.ap_mat);

        if (ultimoApellidoMaterno != NULL)
        {
            strcpy(student.nom_comp.ap_mat, ultimoApellidoMaterno);
        }
    }
    system("CLS");

    printf("Anio de nacimiento (4 Digitos): ");
    student.fech_nacim.anio = val_num(1893, 2023);
    system("CLS");

    printf("Mes de nacimiento (1 Digito): ");
    student.fech_nacim.mes = val_num(1, 12);
    system("CLS");

    printf("Dia de nacimiento (1 Digito): ");
    if (student.fech_nacim.mes == 2 && anio_bisiesto(student.fech_nacim.anio) == 1)
    {
        student.fech_nacim.dia = val_num(1, 29);
    }
    else
    {
        if (student.fech_nacim.mes == 2 && anio_bisiesto(student.fech_nacim.anio) == 0)
        {
            student.fech_nacim.dia = val_num(1, 28);
        }
        else
        {
            if (student.fech_nacim.mes == 1 || student.fech_nacim.mes == 3 || student.fech_nacim.mes == 5 || student.fech_nacim.mes == 7 || student.fech_nacim.mes == 8 || student.fech_nacim.mes == 10 || student.fech_nacim.mes == 12)
            {
                student.fech_nacim.dia = val_num(1, 31);
            }
            else
            {
                if (student.fech_nacim.mes == 4 || student.fech_nacim.mes == 6 || student.fech_nacim.mes == 9 || student.fech_nacim.mes == 11)
                {
                    student.fech_nacim.dia = val_num(1, 30);
                }
            }
        }
    }
    system("CLS");

    student.edad = 2023 - student.fech_nacim.anio;

    printf("Sexo\n");
    printf("1. Hombre\n");
    printf("2. Mujer\n");

    student.sexo = val_num(1, 2);
    system("CLS");

    for (int i = 0; i < 33; i++)
    {
        printf("%s (%s)\n", lista_estados[i], estados_abr[i]);
    }

    printf("NOTA: USAR ABREVIACION DE DOS LETRAS.\n");
    printf("Entidad de Nacimiento: ");
    validar_string(student.estd_nacim, sizeof(student.estd_nacim));

    while (validarEntidad(student.estd_nacim, estados_abr, sizeof(estados_abr) / sizeof(estados_abr[0])) == 0)
    {
        printf("Entidad no válida. Ingresa una abreviatura válida.\n");
        printf("Entidad de Nacimiento: ");
        validar_string(student.estd_nacim, sizeof(student.estd_nacim));
    }
    system("CLS");

    return student;
}

void curp(Talum student)
{
    char cdia[3];
    char cmes[3];
    char canio[6];
    int ultimoDigito;
    char cultimoDigito;
    char curp[19];
    sprintf(cdia, "%d", student.fech_nacim.dia);
    sprintf(cmes, "%d", student.fech_nacim.mes);
    sprintf(canio, "%d", student.fech_nacim.anio);

    if (student.op_apellido1 == 1)
    {
        curp[0] = toupper(student.nom_comp.ap_pat[0]);
        curp[1] = obtenerPrimeraVocal(student.nom_comp.ap_pat);
    }
    else
    {
        if (student.op_apellido1 == 2)
        {
            curp[0] = 'X';
            curp[1] = 'X';
        }
    }
    if (student.op_apellido2 == 1)
    {
        curp[2] = toupper(student.nom_comp.ap_mat[0]);
    }
    else
    {
        if (student.op_apellido2 == 2)
        {
            curp[2] = 'X';
        }
    }

    curp[3] = toupper(student.nom_comp.nombre[0]);
    curp[4] = canio[2];
    curp[5] = canio[3];
    if (student.fech_nacim.mes < 10)
    {
        curp[6] = '0';
        curp[7] = cmes[0];
    }
    else
    {
        curp[6] = cmes[0];
        curp[7] = cmes[1];
    }
    if (student.fech_nacim.dia < 10)
    {
        curp[8] = '0';
        curp[9] = cdia[0];
    }
    else
    {
        curp[8] = cdia[0];
        curp[9] = cdia[1];
    }

    if (student.sexo == 1)
    {
        curp[10] = 'H';
    }
    else
    {
        curp[10] = 'M';
    }

    curp[11] = student.estd_nacim[0];
    curp[12] = student.estd_nacim[1];
    if (!obtenerSegundaConsonante(student.nom_comp.ap_pat) || student.op_apellido1 == 2)
    {
        curp[13] = 'X';
    }
    else
    {
        curp[13] = obtenerSegundaConsonante(student.nom_comp.ap_pat);
    }
    if (!obtenerSegundaConsonante(student.nom_comp.ap_mat) || student.op_apellido2 == 2)
    {
        curp[14] = 'X';
    }
    else
    {
        curp[14] = obtenerSegundaConsonante(student.nom_comp.ap_mat);
    }

    if (!obtenerSegundaConsonante(student.nom_comp.nombre))
    {
        curp[15] = 'X';
    }
    else
    {
        curp[15] = obtenerSegundaConsonante(student.nom_comp.nombre);
    }
    if (student.fech_nacim.anio < 2000)
    {
        curp[16] = '0';
    }
    else
    {
        if (student.fech_nacim.anio >= 2000 && student.fech_nacim.anio < 2010)
        {
            curp[16] = 'A';
        }
        else
        {
            if (student.fech_nacim.anio >= 2010)
            {
                curp[16] = 'B';
            }
        }
    }

    ultimoDigito = numero_aleatorio(0, 9);
    sprintf(&cultimoDigito, "%d", ultimoDigito);
    curp[17] = cultimoDigito;
    curp[18] = '\0';

    if (validarAntisonante(curp, palabras_inconvenientes, sizeof(palabras_inconvenientes) / sizeof(palabras_inconvenientes[0])))
    {
        curp[1] = 'X';
    }

    strcpy(student.curp, curp);
    printf("%s", student.curp);
}

int linearSearch(Talum array[], int size, int searchNumber)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (array[i].matricula == searchNumber)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(Talum array[], int left, int right, int number)
{
    while (left <= right)
    {
        int medium = left + (right - left) / 2;

        if (array[medium].matricula == number)
        {
            return medium;
        }
        if (array[medium].matricula < number)
        {
            left = medium + 1;
        }
        else
        {
            right = medium - 1;
        }
    }

    return -1;
}

int ordenar(Talum array[], int size)
{
    Talum temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].matricula < array[i].matricula)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 1;
}

void imprimir_reg(Talum array[], int i)
{
    int status = 0;
    int tam = 0;
    int j;
    char temp[100];
    int pedad = 0; // Asegúrate de que pedad comience en 0

    while (tam < i)
    {
        system("CLS");

        printf("NO. REGISTER || MATRICULA || APELLIDO PATERNO || APELLIDO MATERNO ||        NOMBRE       ||  EDAD  ||  SEXO  || LUGAR DE NACIMIENTO ||    CURP\n");
        printf("=========================================================================================================================================================\n");

        for (j = pedad * 40; j < (pedad + 1) * 40; j++)
        {
            if (j < i)
            {
                if (array[j].status == 1)
                {
                    printf("%12d || %9d || %16s || %16s || %9s %9s || %6d || ", j + 1, array[j].matricula, array[j].nom_comp.ap_pat, array[j].nom_comp.ap_mat, array[j].nom_comp.nombre, array[j].nom_comp.nombre2, array[j].edad);

                    if (array[j].sexo == 1)
                    {
                        printf("HOMBRE  || ");
                    }
                    else
                    {
                        if (array[j].sexo == 2)
                        {
                            printf("MUJER  || ");
                        }
                    }

                    int estadoIndex = -1;
                    for (int k = 0; k < 33; k++)
                    {
                        if (strcmp(array[j].estd_nacim, estados_abr[k]) == 0)
                        {
                            estadoIndex = k;
                            break;
                        }
                    }

                    if (estadoIndex != -1)
                    {
                        strcpy(temp, lista_estados[estadoIndex]);
                    }

                    printf(" %19s ||", temp);

                    curp(array[j]);
                    printf("\n");

                    status++;
                    tam++;
                }
            }
        }
        pedad++;

        if (tam < i)
        {
            printf("PRESS ENTER TO SEE MORE REGISTERS\n");
            system("PAUSE");
        }
    }
}

void archivo_text(Talum array[], int size)
{
    char temp[100];
    FILE *outputFile = freopen("C:\\Users\\Eliel\\OneDrive\\Documentos\\Universidad\\Programación Estructurada\\Actividad 11\\Actividad_11.txt", "w", stdout);

    printf("NO. REGISTER || MATRICULA || APELLIDO PATERNO || APELLIDO MATERNO ||        NOMBRE       ||  EDAD  ||  SEXO  || LUGAR DE NACIMIENTO ||    CURP\n");
    printf("=========================================================================================================================================================\n");

    for (int i = 0; i < size; i++)
    {
        if (array[i].status == 1)
        {
            printf("%12d || %9d || %16s || %16s || %9s %9s || %6d || ", i + 1, array[i].matricula, array[i].nom_comp.ap_pat, array[i].nom_comp.ap_mat, array[i].nom_comp.nombre, array[i].nom_comp.nombre2, array[i].edad);

            if (array[i].sexo == 1)
            {
                printf("HOMBRE || ");
            }
            else
            {
                if (array[i].sexo == 2)
                {
                    printf("MUJER  ||");
                }
            }

            int estadoIndex = -1;
            for (int j = 0; j < 33; j++)
            {
                if (strcmp(array[i].estd_nacim, estados_abr[j]) == 0)
                {
                    estadoIndex = j;
                    break;
                }
            }

            if (estadoIndex != -1)
            {
                strcpy(temp, lista_estados[estadoIndex]);
            }

            printf(" %19s ||", temp);

            curp(array[i]);
            printf("\n");
        }
    }

    fclose(outputFile);
    printf("\nArchivo creado con exito\n");
}
