#include <string.h>
#include <stdlib.h>
#include <time.h>

void genNombre(char vect[], int sexo)
{
    /*
        Hombre = 1
        Mujer = 2
    */
    int num;
    num = rand() % (20 - 1 + 1) + 1;

    char namesM[20][30] = {"MARIA", "SOFIA", "CARMEN", "ISABEL", "LAURA", "ANA", "JULIA", "PAULA", "ANAHI", "ROSA", "ELISA", "ELENA", "VANESA",
                           "ALICIA", "MONICA", "CLAUDIA", "DIANA", "SARA", "CAROLINA", "ANDREA"};

    char namesH[20][30] = {"ADAN", "JAVIER", "MIGUEL", "CARLOS", "LUIS", "ALEJANDRO", "DIEGO", "ANDRES", "JUAN", "PEDRO", "FERNANDO", "RAUL",
                           "JOSE", "RICARDO", "HUGO", "OSCAR", "PABLO", "EMILIO", "SERGIO", "FRANCISCO"};

    if (sexo == 1)
    {
        strcpy(vect, namesH[num - 1]);
    }
    else
    {
        if (sexo == 2)
        {
            strcpy(vect, namesM[num - 1]);
        }
    }
}

void genApellido(char vect[])
{
    int c;
    c = rand() % (49 - 1 + 1) + 1;
    char ap[50][30] = {"RODRIGUEZ", "GONZALEZ", "HERNANDEZ", "LOPEZ", "MARTINEZ", "PEREZ", "GARCIA", "SANCHEZ", "RAMIREZ", "TORRES", "FLORES",
                       "VAZQUEZ", "GOMEZ", "DIAZ", "REYES", "MORALES", "JIMENEZ", "ORTIZ", "CASTRO", "RUIZ", "ALVAREZ", "FERNANDEZ", "VARGAS", "RAMOS", "SUAREZ", "MENDOZA",
                       "CRUZ", "ALVAREZ", "RIVERA", "DOMINGUEZ", "MORENO", "BLANCO", "IGLESIAS", "ROMERO", "RUBIO", "NUNEZ", "SOSA", "GUTIERREZ", "MOLINA", "DELGADO", "AGUILAR",
                       "MEDINA", "GUERRERO", "SOTO", "SALAZAR", "ARIAS", "PAZ", "SOSA", "HERRERA"};
    strcpy(vect, ap[c - 1]);
}

void genSexo(char vect[])
{
    int c;
    c = rand() % (2 - 1 + 1) + 1;
    char generos[2][15] = {"HOMBRE", "MUJER"};
    strcpy(vect, generos[c - 1]);
}

void genPuesto(char vect[])
{
    int c;
    char puest[7][30] = {"INGENIERO EN COMPUTACION", "CONTABILIDAD", "SECRETARIO", "AUXILIAR", "LIMPIEZA", "INGENIERO EN SOFTWARE", "RECEPCION"};
    c = rand() % (7 - 1 + 1) + 1;
    strcpy(vect, puest[c - 1]);
}

void genEstado(char vect[])
{
    int c;
    const char *estados[] = {"AGU", "BC", "BCS", "CAM", "CHI", "CHH", "COA", "COL", "DUR", "GUA", "GRO", "HID",
                         "JAL", "MEX", "MIC", "MOR", "NAY", "NL", "OAX", "PUE", "QUE", "ROO", "SLP", "SIN", "SON", "TAB", "TAM",
                         "TLA", "VER", "YUC", "ZAC", "CDMX", "EXT"};

    c = rand() % (33 - 1 + 1) + 1;
    strcpy(vect, estados[c - 1]);
}