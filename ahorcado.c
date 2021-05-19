/*Se trata de crear un programa en C que simule el juego del ahorcado, teniendo en cuenta únicamente que el jugador tras introducir cada letra de la palabra a adivinar tenga al menos información de:

    ---> Las letras que ha acertado hasta el momento, y en qué posiciones  (p.ej.: A _ _ A)

   ----> El número de ocasiones que le quedan de introducir letras

   ----> Los fallos, es decir, las letras que ya ha introducido y no están en la palabra

El resto de la dinámica del juego, opciones, posibilidades, etc... serán de diseño propio. Se valorará muy especialmente la originalidad en la solución y la interfaz de comunicación con el usuario.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>


void LINEA(){
    int i,ancho;
    ancho=60;
    for(i=0;i<ancho;i++){
        printf(" *");
    }
}

/*Lista palabras (tema programacion)*/
void LISTA_PALABRAS(char *Lista[25]){
    Lista[0]="ventilador";
    Lista[1]="programa";
    Lista[2]="compilar";
    Lista[3]="teclado";
    Lista[4]="funcion";
    Lista[5]="memoria";
    Lista[6]="codigo";
    Lista[7]="lenguaje";
    Lista[8]="algoritmo";
    Lista[9]="diagrama";
    Lista[10]="pantalla";
    Lista[12]="transistor";
    Lista[13]="codificar";
    Lista[14]="procesador";
    Lista[15]="hacker";
    Lista[16]="tecnologia";
    Lista[17]="variable";
    Lista[18]="operador";
    Lista[19]="binario";
    Lista[20]="datos";
    Lista[21]="printf";
    Lista[22]="scanf";
    Lista[23]="matriz";
    Lista[24]="vector";

}

/*Play: Función de juego*/
void PLAY(char *palabra,int longitud){
    const char *const cyan = "\033[0;0;36m";
    const char *const rojo = "\033[0;0;31m";
    const char *const normal = "\033[0m";
    const char *const verde = "\033[0;0;32m";

    int i,j,contador,vidas,acertadas,falladas;
    vidas=7;
    acertadas=0;
    falladas=0;
    char letra;
    char letras_acertadas[longitud];
    char letras_falladas[7];

    //Rellenar palabra_acertada con "_"
    char palabra_acertada[longitud];
    for(i=0;i<longitud;i++){
        palabra_acertada[i]='_';
    }

    /*Interfaz*/
    LINEA();
    printf("\nVidas:7\n\n");
    for(i=0;i<longitud;i++){
        printf("%6c",palabra_acertada[i]);
    }

    printf("\n");
    printf("\n%sLetras acertadas:%s",cyan,normal);
    printf("\n%sLetras falladas:%s",rojo,normal);

    do{
        printf("\n\n");
        scanf(" %c",&letra);
        printf("\n");
        LINEA();

        //Solución: Añadir contador de manera que si acierta una letra este será >0 y sino será =0
        contador=0;
        for(i=0;i<longitud;i++){
            for(j=0;j<longitud;j++){                                                  /*Comprobar si la letra ya la ha introducido antes y es repetida*/
                if(letra==palabra[i]&&letra!=letras_acertadas[j]){
                    contador++;
                    palabra_acertada[i]=letra;
                }
                else if(letra==palabra[i]&&letra==letras_acertadas[j]){
                    printf("\nLetra repetida");
                    contador=-longitud;                                                /*contador=-longitud pues al recorrer array letras_acertadas en muchos casos se cumplirá la opción "if(letra!=letras_acertadas)" y se realizará contador++, de esta forma me aseguro que contador sera menor o igual a 0*/
                }
            }
        }
        //Caso ACIERTO
        if(contador>0){
            //Letras acertadas
            letras_acertadas[acertadas]=letra;      //Al principio acertadas es 0
            acertadas++;
        }
        //Caso FALLO
        else{
            vidas--;
            //Letras falladas
            letras_falladas[falladas]=letra;        //Al principio falladas = 0
            falladas++;
        }

        //INTERFAZ (de nuevo)
        //Imprimir vidas
        if(vidas>0){
            printf("\nVidas: %d\n\n",vidas);
            //Imprimir palabra acertada(lo que lleva acertado de la palabra)
            for(i=0;i<longitud;i++){
                printf("%6c",palabra_acertada[i]);
            }
            printf("\n");
            //Imprimir Letras acertadas
            printf("\n%sLetras acertadas: %s",cyan,normal);
            for(i=0;i<acertadas;i++){
                printf("%c, ",letras_acertadas[i]);
            }
            //Imprimir Letras falladas
            printf("\n%sLetras falladas:%s ",rojo,normal);
            for(i=0;i<falladas;i++){
                printf("%c,",letras_falladas[i]);
            }
        }

        /*VICTORIA*/
        int victoria=0;
        for(i=0;i<longitud;i++){
            if(palabra_acertada[i]==palabra[i]){
                victoria++;
            }
        }
        if(victoria==longitud){
            printf("\n\n\n\n");
            LINEA();
            printf("\n%sENHORABUENA, has ganado!%s\n",verde,normal);
            LINEA();
            return;
        }

    }while(vidas>0);

    printf("\n\n\nVidas: 0");
    printf("\n\n\n%sOh no, te has quedado sin vidas!%s",rojo,normal);
    printf("\nLa solucion era: ");
    puts(palabra);

    return;
}



main(){
    //Colores
    const char *const cyan = "\033[0;0;36m";
    const char *const rojo = "\033[0;0;31m";
    const char *const titulo = "\033[7;1;37m";
    const char *const normas="\033[7;1;35m";
    const char *const normal = "\033[0m";



    char *lista_palabras[25];
    char *palabra_seleccionada;
    int modo,num,i,longitud;

    system("cls");
    LINEA();
    printf("%sBIENVENIDO/A AL JUEGO DEL AHORCADO!%s \n",titulo,normal);
    LINEA();

    printf("\n");
    printf("\n%sNORMAS:%s\n1-Tienes 7 vidas, por cada fallo o letra repetida que ya hayas dicho se te descontara una vida.",normas,normal);
    printf("\n2-En caso de saber la palabra o las letras restantes puedes escribirlas de forma seguida en el mismo nivel,\npero ten cuidado de introducir cada letra solo una vez, pues de lo contrario te contara como repetida.");
    printf("\nEj: d _ _ g r _ m _  Input:ia -> Sol: diagrama");
    printf("\n\n\nSeleccione un modo de juego: 1 JUGADOR: Maquina vs Humano (1) o 2 JUGADORES: Humano vs Humano (2): \n");
    scanf("%d",&modo);

    if(modo==1){
        RANDOM_NUM(&num);
        LISTA_PALABRAS(lista_palabras);
        /*Comprobación
        printf("\n%d",num);
        printf("\n%s",lista_palabras[num]);*/

        //Se escoge palabra random de la lista de palabras
        palabra_seleccionada=lista_palabras[num];
        /*Comprobación
        printf("\n%s\n\n",palabra_seleccionada);*/

        //Se indica la longitud de la palabra
        longitud=strlen(palabra_seleccionada);
        printf("\n%d LETRAS\n",longitud);


        PLAY(palabra_seleccionada,longitud);
    }

    if(modo==2){
        palabra_seleccionada=PEDIR_PALABRA();
        /*Comprobación
        printf("%s",palabra_seleccionada);*/

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        longitud=strlen(palabra_seleccionada);
        printf("\n%d LETRAS\n",longitud);

        PLAY(palabra_seleccionada,longitud);
    }



    printf("\n\n\n");
    return 0;
}

/*Genera numero random*/
int RANDOM_NUM(int *random_num){
    int n;
    srand(time(NULL));
    *random_num=rand()%24;
    return;
}

int PEDIR_PALABRA(){
    const char *const rojo = "\033[0;0;31m";
    const char *const normal = "\033[0m";
    const char *const oculto="\033[8;1;37m";
    char *pal = malloc(20);
    printf("\nIntroduzca la palabra (asegurese de que la otra persona no puede verla):\n");
    printf("%sINDICACION:%s No utilice mayusculas ni tildes.\n",rojo,normal);
    scanf("%s",pal); //Aquí debería ir un & después de la coma pero al ponerlo da error y sin él el programa funciona bien ¿?

    return pal;
}


