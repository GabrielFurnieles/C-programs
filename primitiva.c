/*Escribir un programa en C que simule un sorteo de la primitiva.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    int NumeroGanador[6],NumeroUser[6],premio;
    printf("Este programa simula el sorteo de la primitiva");

    LECTURA_NUMS(NumeroUser);

    printf("\n\nNumeros ganadores:\n");
    RANDOM_NUM(NumeroGanador);

    printf("\n\n");
    COMPROBAR_PREMIO(&premio,NumeroGanador,NumeroUser);

    printf("\n\nSu premio es: \n");
    switch(premio){
        case 6:
            printf("\nENHORABUENA, HAS GANADO EL GORDO!");
            break;
        case 5:
            printf("\nFelicidades! Premio de Categoria 2 y 3 (5 aciertos)");
            break;
        case 4:
            printf("\nFelicidades! Premio de Categoria 4 (4 aciertos)");
            break;
        case 3:
            printf("\nFelicidades! Premio de Categoria 5 (3 aciertos)");
            break;
        default:
            printf("Lo siento, no ha ganado ningun premio. Intentelo de nuevo!");
    }


    printf("\n\n\n");
    return 0;
}




int RANDOM_NUM(int Vector[6]){
    srand(time(NULL));
    for(int i=0;i<6;i++){
        Vector[i]=rand()%49+1;
        for(int j=0;j<6;j++){
            if(j!=i&&Vector[i]==Vector[j]){
                Vector[i]=(rand()%49+1)+1;
            }
        }
        printf("%6d",Vector[i]);
    }
    return Vector;
}

int LECTURA_NUMS(int User[6]){
    int i;
    char rep;
    printf("\n\nIntroduzca sus numeros (Presione ENTER cada vez que quiera introducir un nuevo numero, recuerde que solo puede introducir 6 nums): \n");
    do{
        //Limpiar Array
        for(i=0;i<6;i++){
            User[i]=0;
        }
        //Pedir elementos
        for(i=0;i<6;i++){
            printf("Num[%d]: ",i+1);
            scanf("%d",&User[i]);
            rep='limon';
            //Numero introducido entre 1 y 49
            if(User[i]<1||User[i]>49){
                i=6;
                printf("\nError, numero introducido no valido, desea volver a introducir sus numeros? SI(s),NO(n)\n");
                scanf(" %c",&rep);
            }
            //Numero introducido no puede ser repetido
            for(int j=0;j<6;j++){
                if(j!=i&&User[i]==User[j]){             //j!=i porque sino siempre coincidirían los valores
                    i=6;
                    printf("\nError, numero introducido no valido, desea volver a introducir sus numeros? SI(s),NO(n)\n");
                    scanf(" %c",&rep);
                }
            }
        }
    }while(rep=='S'||rep=='s');
    if(rep=='N'||rep=='n'){
        return;
    }

    return User;
}

int COMPROBAR_PREMIO(int* premio,int Vector[6],int User[6]){
    int i,j,p;
    p=0;
    printf("Coincidencias: \n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(User[i]==Vector[j]){
                printf("%6d",User[i]);
                p++;
            }
        }
    }
    *premio=p;
    return;
}

