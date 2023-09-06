// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 /
// Programa en C que sirva para el juego del CHINCHAMPU (Condicion anidada)
//OOEA_Act3_2_932

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int op, comp;

    printf("Ingrese la opcion con la que jugara\n");
    printf("1 - Piedra\n");
    printf("2 - Papel\n");
    printf("3 - Tijera\n");
    scanf("%d", &op);
    srand(time(NULL));
    comp = 1 + rand() %3;

    if (op == 1)
    {
        if (comp == 1)
        {
            printf("\nElegiste Piedra\n");
            printf("La computadora eligio Piedra\n");
            printf("Empate");
        }

        else
        {
            if (comp == 2)
            {
                printf("\nElegiste Piedra\n");
                printf("La computadora elegio Papel\n");
                printf("Perdiste");
            }

            else
            {
                if (comp == 3)
                {
                    printf("\nElegiste Piedra\n");
                    printf("La computadora eligio Tijera\n");
                    printf("Ganaste");
                }
                
            }
            
        }
        
    }

    else
    {
        if (op == 2)
        {
            if (comp == 1)
            {
                printf("\nElegiste Papel\n");
                printf("La computadora eligio Piedra\n");
                printf("Ganaste");
            }

            else
            {
                if (comp == 2)
                {
                    printf("\nElegiste papel\n");
                    printf("La computadora eligio Papel\n");
                    printf("Empate");
                }

                else
                {
                    if (comp == 3)
                    {
                        printf("\nElegiste papel\n");
                        printf("La computadora eligio Tijera\n");
                        printf("Perdiste");
                    }
                    
                }
                
            }
            
        }

        else
        {
            if (op == 3)
            {
                if (comp == 1)
                {
                    printf("\nElegiste Tijera\n");
                    printf("La computadora eligio Piedra\n");
                    printf("Perdiste");
                }

                else
                {
                    if (comp == 2)
                    {
                        printf("\nElegiste Tijera\n");
                        printf("La computadora eligio Papel\n");
                        printf("Ganaste");
                    }

                    else
                    {
                        if (comp == 3)
                        {
                            printf("\nElegiste Tijera\n");
                            printf("La computadora eligio Tijera\n");
                            printf("Empate");
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }

    return 0;
    
}