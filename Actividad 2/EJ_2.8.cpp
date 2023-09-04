//Eliel Alfonso Ontiveros Ojeda_368746
//03-Ago-2023 / 
//Programa para jugar Piedra, Papel o tijera (Condicion anidada)
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int op,comp;

    printf("Ingrese la opcion con la que jugara\n");
    printf("1 - Piedra\n");
    printf("2 - Papel\n");
    printf("3 - Tijera\n");
    scanf("%d", &op);
    srand(time(NULL));
    comp = 1 + rand()%3;

    if (op == 1 && comp == 2)
    {
        printf("Elegiste Piedra\n");
        printf("La maquina eligio Papel\n");
        printf("Perdiste");
    }

    else
    {
        if (op == 1 && comp == 3)
        {
            printf("Elegiste Piedra\n");
            printf("La maquina eligio Tijera\n");
            printf("Ganaste");
        }

        else
        {
            if (op == comp)
            {
                printf("Elegiste Piedra\n");
                printf("La maquina eligio Piedra\n");
                printf("Empate");
            }

            else
            {
                if (op == 2 && comp == 1)
                {
                    printf("Elegiste Papel\n");
                    printf("La maquina eligio Piedra\n");
                    printf("Ganaste");
                }

                else
                {
                    if (op == 2 && comp == 3)
                    {
                        printf("Elegiste Papel\n");
                        printf("La maquina eligio Tijera\n");
                        printf("Perdiste");
                    }

                    else
                    {
                        if (op == comp)
                        {
                            printf("Elegiste Papel\n");
                            printf("La maquina eligio Papel\n");
                            printf("Empate");
                        }

                        else
                        {
                            if (op == 3 && comp == 1)
                            {
                                printf("Elegiste Tijera\n");
                                printf("La maquina eligio Piedra\n");
                                printf("Perdiste");
                            }

                            else
                            {
                                if (op == 3 && comp == 2)
                                {
                                    printf("Elegiste Tijera\n");
                                    printf("La maquina eligio Papel\n");
                                    printf("Ganaste");
                                }

                                else
                                {
                                    if (op == comp)
                                    {
                                    printf("Elegiste Tijera\n");
                                    printf("La maquina eligio Tijera\n");
                                    printf("Empate");
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
}