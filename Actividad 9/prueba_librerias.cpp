#include "chnoop.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int vect[n];

    printf("Ingrese la cantidad de elementos quiere agregar en el vector\n");
    scanf("%d", &n);
    printf("Se generara un vector con %d elementos\n", n);

    random_vect(n, vect, 0, 20);

    imp_vector(n, vect);

    return 0;
}
