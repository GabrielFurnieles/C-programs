/*Escribir  un  programa  en  C  que  solicite una  contraseña  de  entrada  al programa. El usuario dispondrá de un máximo de 3 opciones
para introducirla correctamente. La lista de contraseñas válidas estará almacenada previamente en  una  matriz.  Si  logra  entrar  en  el  programa,
se  mostrará  un  mensaje  de  bienvenida.
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

void LISTA_CONTRASENAS(char *contras_valida[3]){
    contras_valida[0]="griselda72";
    contras_valida[1]="Griselda72";
    contras_valida[2]="GRISELDA72";
}

main(){
    //Colores
    const char *const rojo = "\033[0;0;31m";
    const char *const normal = "\033[0m";
    const char *const verde = "\033[0;0;32m";
    system("cls");

    char contrasena[12], *contras_valida[3];
    int resultado,i,intentos,cont;

    printf("Introduzca la contraseña para poder ingresar al programa.\nTiene 3 intentos:\n");
    intentos=3;

    while(intentos>0){
        printf("\nIntentos: %d\n",intentos);
        gets(contrasena);
        LISTA_CONTRASENAS(&contras_valida);

        cont=0;
        for(i=0;i<3;i++){
            resultado=strcmp(contrasena,contras_valida[i]);
            if(resultado==0){
                cont++;
                i=3;
            }
        }

        if(cont==1){
            printf("\n%sContrasena correcta!%s\n",verde,normal);
            intentos=-2;        //Sale del bucle while
        }

        else if(intentos>1){            //Así no aparece el mensaje de volver a introducir contraseña cunado no queden intentos
            printf("%sContrasena incorrecta, vuelva a intentarlo:%s\n",rojo,normal);
            intentos--;
        }

        else{
            intentos--;
        }
    }

    if(intentos==-2){
        printf("\n\nBIENVENIDO!");
    }

    else{
        printf("\n\nHas agotado tus intentos\nFin del programa.");
        return 0;
    }


    printf("\n\n\n\nFin del programa");
    return 0;
}
