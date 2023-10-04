#ifdef chntoky.h
#define chntoky.h 

void menu(); // Función para navegar por el menú

int msgs(); // Función para imprimir el menú y obtener la opción del usuario

int validar_num(char mensaje[], int ri, int rf); // Función que valida que el usuario ingrese un numero

void num_aleatorio(int n); // Función para generar un numero aleatorio 

void manual_vect(int n, int vect[]); // Función para llenar manualmente un vector 

void random_vect(int n, int vect[], int ri, int rf);  // Función para llenar aleatoriamente un vector

void vect1_vect2(int n, int vect[]); // Función que genera un vector utilizando como referencia otros 2 vectores existentes

void imp_vector(int n, int vect[]); // Función que imprime vectores

void matriz_4x4(int n, int matrix[30][30], int vect1[], int vect2[]);

void imp_matriz(int matrix[30][30]);

#endif