#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Categoria
{
    GEOGRAFIA,
    CIENCIAS_NATURALES,
    MATEMATICAS,
    HISTORIA_MEXICO
};

struct Pregunta
{
    char enunciado[200];
    char opciones[4][50];
    int respuestaCorrecta;
};

struct Pregunta preguntasGeografia[] = {
    {"¿Cuál es el río más largo del mundo?", {"Amazonas", "Nilo", "Yangtsé", "Misisipi"}, 0},
    {"¿En qué continente se encuentra la Torre Eiffel?", {"Europa", "Asia", "África", "América"}, 0},
    {"¿Cuál es la montaña más alta del mundo?", {"Kilimanjaro", "Everest", "Aconcagua", "Denali"}, 1},
    {"¿Cuál es el océano más grande?", {"Atlántico", "Índico", "Pacífico", "Ártico"}, 2},
    {"¿Cuál es el país más grande del mundo por territorio?", {"China", "Rusia", "Estados Unidos", "India"}, 1},
    {"¿En qué continente se encuentra Australia?", {"África", "Europa", "Oceanía", "Asia"}, 2},
    {"¿Cuál es la capital de Canadá?", {"Ottawa", "Toronto", "Vancouver", "Montreal"}, 0},
    {"¿Cuál es el desierto más grande del mundo?", {"Sahara", "Gobi", "Atacama", "Antártico"}, 0},
    {"¿En qué país se encuentra la Gran Muralla China?", {"Japón", "China", "Corea del Sur", "Mongolia"}, 1},
    {"¿Cuál es el canal que conecta el océano Atlántico con el océano Pacífico?", {"Canal de Suez", "Canal de Panamá", "Canal de la Mancha", "Canal de Gibraltar"}, 1},
    {"¿Cuál es la capital de Japón?", {"Pekín", "Tokio", "Seúl", "Bangkok"}, 1},
    {"¿En qué país se encuentra la ciudad de Machu Picchu?", {"Perú", "México", "Colombia", "Brasil"}, 0},
    {"¿Cuál es el lago más grande de África?", {"Lago Victoria", "Lago Tanganica", "Lago Malawi", "Lago Chad"}, 0},
    {"¿En qué continente se encuentra el Polo Norte?", {"Europa", "América del Norte", "Asia", "Antártida"}, 3},
    {"¿Cuál es la capital de Francia?", {"Berlín", "París", "Roma", "Madrid"}, 1},
    {"¿En qué país se encuentra la ciudad de Buenos Aires?", {"Argentina", "Brasil", "Chile", "Colombia"}, 0},
    {"¿Cuál es el país más poblado del mundo?", {"India", "China", "Estados Unidos", "Indonesia"}, 1},
    {"¿En qué continente se encuentra la selva amazónica?", {"África", "Asia", "América del Sur", "Oceanía"}, 2},
    {"¿Cuál es la capital de Sudáfrica?", {"Ciudad del Cabo", "Pretoria", "Johannesburgo", "Durban"}, 0},
    {"¿En qué país se encuentra el Kremlin?", {"Rusia", "China", "Ucrania", "Polonia"}, 0},
    {"¿Cuál es el río que atraviesa la ciudad de Nueva York?", {"Hudson", "Támesis", "Sena", "Danubio"}, 0},
    {"¿En qué océano se encuentra la Gran Barrera de Coral?", {"Atlántico", "Índico", "Pacífico", "Antártico"}, 2},
    {"¿Cuál es la capital de México?", {"Ciudad de México", "Guadalajara", "Monterrey", "Puebla"}, 0},
    {"¿En qué país se encuentra la ciudad de Roma?", {"España", "Italia", "Grecia", "Portugal"}, 1},
    {"¿Cuál es el punto más alto de la Tierra sobre el nivel del mar?", {"Mont Everest", "Kilimanjaro", "Aconcagua", "Denali"}, 0},
    {"¿En qué continente se encuentra el Polo Sur?", {"Antártida", "América del Sur", "Asia", "Oceanía"}, 0},
    {"¿Cuál es el país conocido como 'la tierra del sol naciente'?", {"China", "Japón", "Corea del Sur", "Tailandia"}, 1},
};

struct Pregunta preguntasCienciasNaturales[] = {
    {"¿Que animal es conocido como el 'Rey de la Selva'?", {"Elefante", "Leon", "Tigre", "Oso"}, 1},
    {"¿Cuantas patas tiene una araña?", {"4", "6", "8", "10"}, 2},
    {"¿Cuál de los siguientes es un planeta del sistema solar?", {"Luna", "Júpiter", "Marte", "Saturno"}, 1},
    {"¿Qué parte de la planta absorbe agua y nutrientes del suelo?", {"Hojas", "Raíces", "Tallo", "Flores"}, 1},
    {"¿Cuál es la unidad básica de la vida?", {"Átomo", "Molécula", "Célula", "Organismo"}, 2},
    {"¿Qué gas necesitan las plantas para realizar la fotosíntesis?", {"Oxígeno", "Dióxido de carbono", "Nitrógeno", "Hidrógeno"}, 1},
    {"¿Cuál de los siguientes animales es un mamífero?", {"Pato", "Tiburón", "Elefante", "Rana"}, 2},
    {"¿Qué hace que el arco iris tenga diferentes colores?", {"La reflexión de la luz", "La refracción de la luz", "La absorción de la luz", "La difusión de la luz"}, 1},
    {"¿Cuál es la capa más externa de la Tierra?", {"Núcleo", "Manto", "Corteza", "Núcleo externo"}, 2},
    {"¿Qué animal realiza la metamorfosis completa durante su desarrollo?", {"Mariposa", "Abeja", "Caracol", "Saltamontes"}, 0},
    {"¿Cuál es el órgano responsable de bombear sangre en nuestro cuerpo?", {"Pulmón", "Corazón", "Riñón", "Hígado"}, 1},
    {"¿Cuál es la fuerza que mantiene a los objetos en la Tierra?", {"Gravedad", "Magnetismo", "Fricción", "Elasticidad"}, 0},
    {"¿Cuál de los siguientes no es un tipo de roca?", {"Granito", "Mercurio", "Pizarra", "Mármol"}, 1},
    {"¿Qué gas es esencial para la respiración de los seres humanos?", {"Dióxido de carbono", "Oxígeno", "Nitrógeno", "Hidrógeno"}, 1},
    {"¿Cuál es el proceso por el cual las plantas convierten la luz en energía?", {"Respiración", "Fotosíntesis", "Transpiración", "Germinación"}, 1},
    {"¿Cuál es el nombre de la primera fase de la luna?", {"Luna llena", "Cuarto creciente", "Luna nueva", "Cuarto menguante"}, 2},
    {"¿Qué tipo de energía se obtiene del sol?", {"Energía eólica", "Energía solar", "Energía hidroeléctrica", "Energía geotérmica"}, 1},
    {"¿Cuál es el componente más abundante en la atmósfera de la Tierra?", {"Nitrógeno", "Oxígeno", "Dióxido de carbono", "Argón"}, 0},
    {"¿Cuál es la función principal de la clorofila en las plantas?", {"Absorber agua", "Realizar la fotosíntesis", "Transportar nutrientes", "Producir esporas"}, 1},
    {"¿Cuál de las siguientes no es una característica de los mamíferos?", {"Ponen huevos", "Tienen glándulas mamarias", "Tienen pelo o pelaje", "Tienen escamas"}, 0},
    {"¿Cuál es la capa más interna de la Tierra?", {"Núcleo", "Manto", "Corteza", "Núcleo interno"}, 3},
    {"¿Cuál es el proceso por el cual el agua se convierte en vapor?", {"Evaporación", "Condensación", "Precipitación", "Sublimación"}, 0},
    {"¿Cuál es la función principal de los pulmones en el sistema respiratorio?", {"Bombeo de sangre", "Intercambio de gases", "Digestión de alimentos", "Filtración de desechos"}, 1},
    {"¿Qué tipo de energía se obtiene de la corriente de agua en movimiento?", {"Energía solar", "Energía eólica", "Energía hidroeléctrica", "Energía geotérmica"}, 2},
    {"¿Cuál es el proceso por el cual los líquidos se convierten en gas?", {"Fusión", "Vaporización", "Solidificación", "Sublimación"}, 1},
    {"¿Cuál es el animal más grande del planeta Tierra?", {"Elefante", "Ballena azul", "Jirafa", "Rinoceronte"}, 1},
    {"¿Qué parte del sistema solar es conocida como 'el planeta rojo'?", {"Marte", "Venus", "Júpiter", "Saturno"}, 0},
};

struct Pregunta preguntasMatematicas[] = {
    {"¿Cuanto es 7 + 9?", {"12", "14", "16", "18"}, 2},
    {"¿Cuantos lados tiene un triangulo?", {"3", "4", "5", "6"}, 0},
    {"Si tienes 8 chocolates y comes 3, ¿Cuantos chocolates te quedan?", {"3", "6", "5", "4"}, 2},
    {"¿Cuanto es 9 x 7?", {"63", "70", "56", "59"}, 0},
    {"Si divides 18 entre 3, ¿Cuanto es?", {"8", "15", "6", "11"}, 2},
    {"¿Cuanto es la tercera parte de 27?", {"8", "10", "12", "9"}, 3},
    {"¿Cuanto es la mitad de 16?", {"7", "5", "8", "32"}, 2},
    {"Si el cuadrado de un numero es 25, ¿Cual es el numero?", {"4", "5", "6", "7"}, 1},
    {"¿Cuantos lados tiene un hexagono?", {"5", "7", "8", "6"}, 3},
    {"Si tienes 3 docenas de huevos, ¿Cuantos huevos tienes en total?", {"34", "38", "36", "30"}, 2},
    {"Si un rectangulo tiene lados de 5 cm y 8 cm, ¿Cuanto mide su perimetro?", {"26", "30", "24", "36"}, 0},
    {"¿Cuantos dias hay en dos semanas?", {"7", "14", "15", "8"}, 1},
    {"¿Cuanto es 6 x 9?", {"60", "46", "54", "56"}, 2},
    {"¿Cuantas caras tiene un cubo?", {"9", "8", "6", "4"}, 2},
    {"¿Como se llama el triangulo que tiene un angulo de 90 grados?", {"Triangulo rectangulo", "Triangulo escaleno", "Triangulo equilatero", "Triangulo isoceles"}, 0},
    {"¿Como se llama un poligono de 8 lados?", {"Hexagono", "Heptagono", "Octagono", "Pentagono"}, 2},
    {"¿Cuantas diagonales tiene un cuadrado?", {"1", "2", "3", "4"}, 1},
    {"Si un tren viaja a 60 km/h, ¿Cuantos km recorre en 3 horas?", {"160", "170", "145", "180"}, 3},
    {"¿Cuantos kilometros hay en una milla?", {"2.347", "1.862", "1.604", "1.504"}, 2},
    {"Si un triangulo tiene un lado de 9 cm, ¿Cuanto mide su area?", {"82", "91", "100", "97"}, 1},
    {"¿Cuantos minutos hay en una hora?", {"60", "100", "59", "70"}, 0},
    {"Si un rectangulo tiene lados de 7 cm y 10 cm, ¿Cuanto mide su area?", {"63", "77", "70", "73"}, 2},
    {"¿Cuantas semanas hay en un año?", {"54", "47", "52", "55"}, 2},
    {"¿Cuantos meses hay en una año", {"12", "13", "10", "11"}, 0},
    {"¿Cual es el numero primo mas pequeño?", {"1", "3", "0", "2"}, 3},
    {"¿Cuantos grados tiene un circulo completo?", {"180", "270", "360", "450"}, 2},
};

struct Pregunta preguntasHistoriaMexico[] = {
    {"¿En qué año comenzó la Independencia de México?", {"1810", "1821", "1848", "1910"}, 0},
    {"¿Quién fue el líder de la lucha por la Independencia de México?", {"Benito Juárez", "Miguel Hidalgo", "Emiliano Zapata", "Pancho Villa"}, 1},
    {"¿En qué ciudad se encuentra la pirámide de Chichén Itzá?", {"Oaxaca", "Cancún", "Mérida", "México, D.F."}, 2},
    {"¿Qué civilización construyó la ciudad de Teotihuacán?", {"Aztecas", "Mayas", "Olmecas", "Toltecas"}, 0},
    {"¿Cuál fue la antigua capital de los aztecas?", {"Tenochtitlán", "Tulum", "Chichen Itzá", "Palenque"}, 0},
    {"¿Qué evento ocurrió el 5 de mayo de 1862?", {"Independencia de México", "Batalla de Puebla", "Revolución Mexicana", "Tratado de Guadalupe Hidalgo"}, 1},
    {"¿Quién fue el presidente de México durante la Revolución Mexicana?", {"Porfirio Díaz", "Benito Juárez", "Francisco Madero", "Venustiano Carranza"}, 2},
    {"¿En qué año se promulgó la Constitución Mexicana?", {"1810", "1824", "1857", "1917"}, 3},
    {"¿Quién fue conocido como 'El Libertador' en la Independencia de México?", {"José María Morelos", "Ignacio Allende", "Vicente Guerrero", "Miguel Hidalgo"}, 3},
    {"¿Cuál es el río más largo de México?", {"Río Bravo", "Río Grijalva", "Río Lerma", "Río Balsas"}, 0},
    {"¿Qué país invadió México en 1846, provocando la Guerra México-Estados Unidos?", {"España", "Francia", "Estados Unidos", "Inglaterra"}, 2},
    {"¿Qué famosa pintora mexicana es conocida por sus retratos de la cultura indígena?", {"Frida Kahlo", "Diego Rivera", "David Alfaro Siqueiros", "Rufino Tamayo"}, 0},
    {"¿Quién fue el último emperador azteca?", {"Moctezuma II", "Cuauhtémoc", "Montezuma I", "Itzcoatl"}, 1},
    {"¿En qué año México ganó su independencia de España?", {"1808", "1810", "1821", "1836"}, 2},
    {"¿Qué festividad mexicana conmemora a los muertos?", {"Día de la Independencia", "Día de Reyes", "Día de los Muertos", "Cinco de Mayo"}, 2},
    {"¿Cuál es el plato típico mexicano hecho a base de maíz?", {"Enchiladas", "Tacos", "Pozole", "Tamales"}, 2},
    {"¿En qué año se llevó a cabo la Revolución Mexicana?", {"1810", "1857", "1910", "1920"}, 2},
    {"¿Qué ciudad fue la primera capital de México después de su independencia?", {"Guadalajara", "Puebla", "Veracruz", "México, D.F."}, 3},
    {"¿Quién es conocido como el 'Padre de la Patria' en México?", {"Miguel Hidalgo", "Benito Juárez", "Emiliano Zapata", "Francisco Villa"}, 0},
    {"¿En qué año se llevó a cabo la conquista de México por parte de los españoles?", {"1492", "1519", "1600", "1821"}, 1},
    {"¿Qué civilización construyó las pirámides en la ciudad de Monte Albán?", {"Olmecas", "Zapotecas", "Toltecas", "Mixtecas"}, 1},
    {"¿Quién fue el líder militar que encabezó la resistencia contra la intervención francesa en México?", {"Benito Juárez", "Emiliano Zapata", "Ignacio Zaragoza", "Pancho Villa"}, 2},
    {"¿Cuál es el volcán más alto de México?", {"Popocatépetl", "Iztaccíhuatl", "Nevado de Toluca", "Citlaltépetl"}, 0},
    {"¿Qué grupo indígena fundó la ciudad de Tenochtitlán?", {"Aztecas", "Mayas", "Zapotecas", "Mixtecas"}, 0},
    {"¿Quién fue el presidente de México durante la Segunda Intervención Francesa?", {"Porfirio Díaz", "Benito Juárez", "Maximiliano de Habsburgo", "Ignacio Comonfort"}, 2},
    {"¿En qué año se proclamó la Independencia de México?", {"1808", "1810", "1821", "1910"}, 1},
    {"¿Cuál es el desierto más grande de México?", {"Desierto de Sonora", "Desierto de Chihuahua", "Desierto del Vizcaíno", "Desierto de Altar"}, 0},
};

struct Pregunta obtenerPreguntaAleatoria(enum Categoria categoria, int tamano)
{
    switch (categoria)
    {
    case GEOGRAFIA:
        return preguntasGeografia[rand() % tamano];
    case CIENCIAS_NATURALES:
        return preguntasCienciasNaturales[rand() % tamano];
    case MATEMATICAS:
        return preguntasMatematicas[rand() % tamano];
    case HISTORIA_MEXICO:
        return preguntasHistoriaMexico[rand() % tamano];
    }
}

int main()
{
    int op, op_cat;
    int salud_jugador = 20;
    int salud_oponente = 20;
    int  restar, daño;
    srand(time(NULL));

    do
    {
        system("CLS");
        printf("=== MENU ===\n");
        printf("1. JUGAR\n");
        printf("0. SALIR\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &op);

        if (op == 0)
        {
            break;
        }

        op_cat = rand() % 4;

        enum Categoria categoriaAleatoria = (enum Categoria)op_cat;
        int tamano;

        switch (categoriaAleatoria)
        {
        case GEOGRAFIA:
            tamano = sizeof(preguntasGeografia) / sizeof(preguntasGeografia[0]);
            break;
        case CIENCIAS_NATURALES:
            tamano = sizeof(preguntasCienciasNaturales) / sizeof(preguntasCienciasNaturales[0]);
            break;
        case MATEMATICAS:
            tamano = sizeof(preguntasMatematicas) / sizeof(preguntasMatematicas[0]);
            break;
        case HISTORIA_MEXICO:
            tamano = sizeof(preguntasHistoriaMexico) / sizeof(preguntasHistoriaMexico[0]);
            break;
        }

        struct Pregunta preguntaActual = obtenerPreguntaAleatoria(categoriaAleatoria, tamano);

        printf("\nCategoria: ");
        switch (categoriaAleatoria)
        {
        case GEOGRAFIA:
            printf("Geografia\n");
            break;
        case CIENCIAS_NATURALES:
            printf("Ciencias Naturales\n");
            break;
        case MATEMATICAS:
            printf("Matematicas\n");
            break;
        case HISTORIA_MEXICO:
            printf("Historia de Mexico\n");
            break;
        }

        printf("%s\n", preguntaActual.enunciado);
        for (int i = 0; i < 4; ++i)
        {
            printf("%d. %s\n", i + 1, preguntaActual.opciones[i]);
        }

        int respuestaCorrecta = preguntaActual.respuestaCorrecta + 1;

        int respuestaUsuario;
        printf("Ingrese el numero de la respuesta correcta: ");
        scanf("%d", &respuestaUsuario);

        if (respuestaUsuario == respuestaCorrecta)
        {
            printf("¡Respuesta Correcta! Eres genial.\n");
            restar = rand() % 5 + 1;
            salud_oponente -= restar;
            printf("\nSalud Jugador = %d\n", salud_jugador);
            printf("\nSalud Oponente = %d\n", salud_oponente);

            if(salud_oponente <= 0)
            {
                printf("\nHas vencido a tu oponente\n");
                printf("\n");
                break;
            }
            printf("\n");

            system("PAUSE");
        }
        else
        {
            printf("Respuesta incorrecta. La respuesta correcta era %d. %s.\n", respuestaCorrecta, preguntaActual.opciones[preguntaActual.respuestaCorrecta]);
            restar = rand() % 5 + 1;
            salud_jugador -= restar;
            printf("\nSalud Jugador = %d\n", salud_jugador);
            printf("\nSalud Oponente = %d\n", salud_oponente);

            if(salud_jugador <= 0)
            {
                printf("\nHas perdido toda tu vida\n");
                printf("\n");
                break;
            }
            printf("\n");
            system("PAUSE");
        }
    } while (op != 0);

    printf("Saliendo del Juego. ¡Esperamos que te hayas divertido!\n");

    return 0;
}
