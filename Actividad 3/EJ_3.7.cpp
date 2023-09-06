// Eliel Alfonso Ontiveros Ojeda_368746
// 05-Sep-2023 / 06-Sep-2023
//Funcion que pida el mes y dia, y el programa le despliega su signo zodiacal y su horoscopo del dia
//OOEA_Act3_7_932

#include <stdio.h>

void calcularHoroscopo() 
{
    int mes, dia;

    printf("Ingrese el numero del mes de nacimiento (1-12)\n");
    scanf("%d", &mes);

    printf("Ingrese el dia de nacimiento (1-31)\n");
    scanf("%d", &dia);

    if (mes < 1 || mes > 12 || dia < 1 || dia > 31) 
    {
        printf("Entrada no valida. Asegurese de ingresar un mes entre 1 y 12 y un día entre 1 y 31.\n");
        return; 
    }

    char *signo = "";
    if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19))
    {
        signo = "Aries";
    }

    else
    {
        if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20))
        {
            signo = "Tauro";
        }

        else
        {
            if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20))
            {
                signo = "Geminis";
            }

            else
            {
                if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22))
                {
                    signo = "Cancer";
                }

                else
                {
                    if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22))
                    {
                        signo = "Leo";
                    }

                    else
                    {
                        if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22))
                        {
                            signo = "Virgo";
                        }

                        else
                        {
                            if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22))
                            {
                                signo = "Libra";
                            }

                            else
                            {
                                if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21))
                                {
                                    signo = "Escorpio";
                                }

                                else
                                {
                                    if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21))
                                    {
                                        signo = "Sagitario";
                                    }

                                    else
                                    {
                                        if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19))
                                        {
                                            signo = "Capricornio";
                                        }

                                        else
                                        {
                                            if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18))
                                            {
                                                signo = "Acuario";
                                            }

                                            else
                                            {
                                                signo = "Piscis";
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
        
    }
    

    printf("Tu signo del zodiaco es: %s\n", signo);

    if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19)) //Aries
    {
        printf("SALUD: Ese cambio de imagen te ha sentado muy bien, porque te hace sentirte más guapa. Sigue cuidándote. Por lo demás, esta semana no vas a tener problemas, aunque deberías tomar un poco más de vitamina C, te vendrá bien para prevenir\n");
        printf("AMOR: Esa persona que llegó hace poco a tu vida, te está soltando indirectas. Debes poner más atención y ser receptiva. Según me indican los astros, esta persona ha llegado para quedarse y te va a hacer muy feliz. Déjate llevar y olvida el pasado de una vez por todas. ¡Enhorabuena!\n");
        printf("FORTUNA: Aunque tu economía está en un buen momento, es necesario que no te de por gastar a lo loco. Deberías empezar a ahorrar porque tienes planes de futuro y debes empezar a hacerlos realidad. Esta semana el número siete y el color azul te van a dar mucha suerte\n");
    }

    else
    {
        if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20)) //Tauro
        {
            printf("SALUD: Vas a sufrir pequeños mareos estos días por las altas temperaturas. No es nada grave según puedo ver en las cartas, pero es necesario que te hagas un chequeo cuanto antes. El médico podrá ayudarte, pero debes seguir a raja tabla sus recomendaciones\n");
            printf("AMOR: Te has dado cuenta que extrañas a esa persona por la que te enganchaste hace unos meses, pero en aquel momento vuestra relación no podía ser. No debes tener miedo en ponerte en contacto con el, porque se siente como tú\n");
            printf("FORTUNA: Las estrellas de tu constelación forman esta semana una V. Esto significa que tu economía va a ser muy afortunada. Puedes empezar a ahorrar para darte un capricho dentro de poco");
        }

        else
        {
            if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20)) //Geminis
            {
                printf("SALUD: El chocolate es tu gran debilidad. Y esta es la razón por la que empiezas a tener problemas en la piel. Además de tener algo de ansiedad. Procura calmarte y eliminar el chocolate de la lista de tu compra\n");
                printf("AMOR: Te has empeñado en que la relación que empezaste hace unas semanas salga adelante. Pero ha llegado el momento del final, porque ninguno de los dos estáis enamorados. No tengas miedo a estar sola un tiempo, porque tarde o temprano harás realidad la historia de amor con la que siempre has soñado\n");
                printf("FORTUNA: Te caracterizas por tener un carácter fuerte e impulsivo. Esto muchas veces puede ser negativo, pero esta semana va a ser muy beneficioso en tu puesto de trabajo. El número seis y el color amarillo te van a dar suerte");
            }

            else
            {
                if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22)) //Cancer
                {
                    printf("SALUD: Ha llegado la hora de plantearte seriamente que tienes que moderarte en las comidas. Has abandonado por completo el ejercicio y cada vez visitas más la cocina entre horas. Debes empezar a tener una dieta equilibrada y hacer las cenas sanas\n");
                    printf("AMOR: La influencia negativa de Marte en el signo de Cáncer va a hacer que no estés nada pasional esta semana. No vas a tener apetito sexual y esto puede afectar a tu relación. Si no la tienes, es una cosa positiva porque vas a querer estar solo con tus amistades y no pensar en coquetear\n");
                    printf("FORTUNA: Según me indica la carta del Tres de Espadas te estás empezando a dormir en los laureles y eso a tus jefes no les está gustando. Siempre te has caracterizado por ser un trabajador ejemplar. El color verde y el número cinco te van a dar suerte");
                }

                else
                {
                    if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22)) //Leo
                    {
                        printf("SALUD: Tu pelo te trae por la calle de la margina cada vez que te miras al espejo y ves que se te está cayendo. Deberías consultar con un especialista para que te aconseje un producto para remediarlo. Tu estado de ánimo será bastante bueno\n");
                        printf("AMOR: la influencia positiva de Saturno hace que tu pareja te haga sentirte como una reina. Pero te digo que eso son etapas en las relaciones. Tienes que tener en cuenta que esto irá pasando. Si hace tiempo que tu corazón no está ocupado, vas a seguir así una larga temporada, esto no quiere decir que no tengas pretendientes\n");
                        printf("FORTUNA: Hace un año que te ofrecieron el trabajo donde estás. No te has equivocado y según me indica la carta del Dos de Oros ha llegado la hora de recoger los frutos de tanto esfuerzo. El número cinco y el color rojo té van a dar mucha suerte");
                    }

                    else
                    {
                        if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22)) //Virgo
                        {
                            printf("SALUD: Has decidido dejar de fumar, y le vas a hacer caso a tu médico que lleva tiempo aconsejándotelo. Creías que no ibas a poder hacerlo, pero no está siendo difícil. No vas a tener ninguna tentación cuando te encuentres baja de ánimo\n");
                            printf("AMOR: Si no tienes pareja, gracias a las influencias positivas de Venus y de la Luna, esta semana va a aparecer alguien muy especial en tu vida. En un principio puede que no te lo tomes muy en serio, pero según pasen los días vas a entablar una relación que va a durar en el tiempo\n");
                            printf("FORTUNA: Un familiar te pidió hace poco una cantidad importante de dinero y no sabes muy bien si te lo va a devolver. No te agobies, porque según me indica la carta del Seis de Oros te lo va a devolver dentro de unos meses. No sufras porque has hecho bien");
                        }

                        else
                        {
                            if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)) //Libra
                            {
                                printf("SALUD: La razón por la que tienes problemas de estómago y tus nervios están fatal, se debe al dese control que tienes a tu alimentación y la falta de sueño. Tienes que empezar a pensar en cuidarte más\n");
                                printf("AMOR: Según me indica la carta del Cuatro de Espadas esta semana vas a comprobar que tu egoísmo no es un buen aliado en tu relación. Estaría muy bien que empezaras a no pensar tanto en ti, porque tu pareja también tiene voz y voto. Como sigues así vas a quedarte sola y la culpa solamente la tienes tú. Si no tienes pareja, olvídate de conquistar a nadie\n");
                                printf("FORTUNA: Eres una persona muy directa y no te gusta callarte las cosas. Esto no es bueno porque hay veces que deberías cerrar la boca. Tus compañeros se están empezando a cansar de tus comentarios y esto te va a causar más de un problema");
                            }

                            else
                            {
                                if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21)) //Escorpio
                                {
                                    printf("SALUD: Tienes un gran problema porque no sabes qué hacer con tu tiempo libre. Sería bueno que te mimaras un poquito y aprovechar para ponerte a punto. Retoma los rituales de belleza que te sientan tan bien\n");
                                    printf("AMOR: Estas un poco ciega de amor. Debes enfrentarte a la realidad y si ese hombre no te merece, ha llegado la hora de cerrar la puerta. Ya no tienes que perdonarle más. Eso sí, no te de miedo a estar sola, porque según veo en los astros, la palabra amor está escrita en tu futuro\n");
                                    printf("FORTUNA: Te voy a dar un consejo para que tu economía vaya mejor de lo que ya está, o por lo menos continúe como hasta ahora. Debes poner debajo de tu almohada una bolsita de tela con cinco monedas y una hoja de laurel");
                                }

                                else
                                {
                                    if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21)) //Sagitario
                                    {
                                        printf("SALUD: Empezaste el mes con mucha fuerza y energía. No debes malgastarla. Te has marcado unos horarios y no te lo saltas por nada del mundo. Eso te está viniendo muy bien tanto para tu salud como para tu ánimo\n");
                                        printf("AMOR: Hace un tiempo te destrozaron el corazón. Pues según me indica la carta del Cuatro de Espadas, esa persona que lo hizo se va a querer poner en contacto contigo. No te creas que ha cambiado, por mucho que te lo prometa. Mi consejo es que continúes con tu vida, ya que eres una mujer cada vez más fuerte y la suerte te alumbra\n");
                                        printf("FORTUNA: En el terreno laboral, las cosas no te van a ir tan bien. La influencia negativa de Marte en tu signo hará que a finales de semana tengas una situación bastante tensa con tus superiores o con algún compañero de trabajo. El número ocho y el color blanco te darán suerte");
                                    }

                                    else
                                    {
                                        if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19)) //Capricornio
                                        {
                                            printf("SALUD: Tu ánimo ha cambiado porque estás viendo las cosas de una forma positiva. Respecto a tu salud, siento decirte que vas a tener una gran dolencia estomacal, quizás sea por consumir algún alimento en mal estado\n");
                                            printf("AMOR: Sabes que llorando no se solucionan los problemas. Tu relación de pareja está viviendo un momento muy tenso y la culpa solamente es tuya. Siento decirte que según me indican las cartas esa relación ya está muerta. Así que no te empeñes en continuar con algo que no va a ningún sitio\n");
                                            printf("FORTUNA: Vas a vivir una situación un tanto incomoda, ya que un antiguo jefe se va a poner en contacto contigo, pero no pienses que es para que vuelvas a trabajar con el. Solo quiere saber cómo te va. El número nueve y el color verde te darán suerte");
                                        }

                                        else
                                        {
                                            if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18)) //Acuario
                                            {
                                                printf("SALUD: Después de pasar unas semanas baja de ánimo, has sabido recuperarte, sabiendo desconectar de los problemas que te rodeaban. Entras en una etapa donde te vas a sentir muy bien contigo misma. Es hora de que cada días te mimes más\n");
                                                printf("AMOR: Aunque parezca que eres una persona con mucha fuerza, eres muy sensible y necesitas estar arropada por tu amor. No debes preocuparte porque estás bajo la protección de la Luna, y durante este mes vas a vivir momentos muy románticos y sobre todos llenos de pasión. Es una buena oportunidad para dar un paso más en vuestra relación\n");
                                                printf("FORTUNA: Los cambios que puedan venir en el trabajo van a ser muy beneficiosos, aunque tampoco te puedes acomodar, que es una cosa que te suele pasar. Según me indican las cartas, tu economía va a estar muy saneada y te vas a poder permitir cambiar de casa. El número tres y el color rojo te darán mucha suerte");
                                            }

                                            else
                                            {
                                                printf("SALUD: Desde hace días tenías una pequeña dolencia, pero esta semana te vas a recuperar. Tienes que tomarte un descanso y no estar tan activa. Esto te vendría bien para todo lo relacionado con tu salud\n");
                                                printf("AMOR: Te has dado cuenta de que no puedes vivir sin tu pareja. Estás muy enamorada, y sabes que tu vida no tiene sentido sin el. Según me indica la carta del Tres de Copas tu chico siente lo mismo, así que todo funciona perfectamente. Por fin has encontrado a alguien que encaja perfectamente en tu corazón. No lo dejes escapar\n");
                                                printf("FORTUNA: La idea de comprarte una segunda vivienda para pasar tus días de descanso se va a hacer realidad, según me indica la carta del Dos de Oros. De todas formas, tienes que tener mucho cuidado las ofertas que te hagan. El número cuatro y el color azul te darán suerte");
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
        
    }
    

}

int main() 
{
    calcularHoroscopo();
    return 0;
}
