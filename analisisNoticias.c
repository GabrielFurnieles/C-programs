/*Una empresa de marketing digital está realizando un estudio sobre la irrupción de las tecnologías disruptivas en los medios de comunicación no especializados (prensa, radio, televisión, redes sociales).
Las tecnologías disruptivas que se han seleccionado para su estudio son: blockchain, realidad virtual, ciberseguridad, inteligencia artificial, robótica y bigdata.

1)Total de noticias en cada semana y media.
2)Tecnologías que más aparecen por semana.
3)Mayor incremento.
4)Tendencias. (se considera tendencia aquellas noticias que cumplan)
    a- Nunca ha sido la que menor número de apariciones ha tenido en una semana
    b- Ha sido la tecnología que mayor número de noticias ha tenido en el total de las ocho semanas, o bien no es la tecnología que mayor número de noticias
    ha tenido en el total de las ocho semanas, pero si ha sido la tecnología que mayor número de noticias ha tenido al menos en tres de las ocho semanas.
*/

#include<stdio.h>

main(){
    int i,j,s;
    char Tipos[6][20]={"Blockchain","VR","Ciberseguridad","IA","Robotica","Big Data"};

    printf("\n\nEste programa almacena las noticias tecnológicas que han sido publicadas en 'x' semanas y extrae patrones");
    printf("\nEspecifique el numero de semanas a evaluar (tenga en cuenta que debera introducir los datos manualmente a continuacion):");
    scanf("%d",&s);

    float Noticias[6][s+2];

/*Pedir matriz*/
    printf("\nIntroduzca los datos:\n");
    for(j=0;j<s+2;j++){
        for(i=0;i<6;i++){
            if(j<s){
                do{
                    if (i==0){
                        printf("\nBlockchain[S%d]: ",j+1);
                    }
                    if (i==1){
                        printf("\nVR[S%d]: ",j+1);
                    }
                    if (i==2){
                        printf("\nCiberseguridad[S%d]: ",j+1);
                    }
                    if (i==3){
                        printf("\nIA[S%d]: ",j+1);
                    }
                    if (i==4){
                        printf("\nRobotica[S%d]: ",j+1);
                    }
                    if (i==5)
                    printf("\nBig Data:[S%d]: ",j+1);

                    scanf("%f",&Noticias[i][j]);
                }while(Noticias[i][j]<0);
            }
            else{
                Noticias[i][j]=0;
            }
        }
    }

    printf("\n\n\n");
/*Imprimir matriz*/
    for(i=0;i<6;i++){
        printf("\n");
        printf(" %20s",Tipos[i]);
        for(j=0;j<s;j++){
            printf("%6.0f",Noticias[i][j]);
        }
    }

/*Suma por filas y media*/
    float sum;
    float media;
    for(i=0;i<6;i++){
        sum=0;
        for(j=0;j<s;j++){
            sum=sum+Noticias[i][j];
        }
        media=sum/s;
        Noticias[i][s]=sum;
        Noticias[i][s+1]=media;
    }

    printf("\n\n\nSUMA y MEDIA de las tecnologias a lo largo de las semanas");
    for(i=0;i<6;i++){
        printf("\n");
        printf(" %20s",Tipos[i]);
        for(j=0;j<(s+2);j++){
            if(j<s){
                printf("%6.0f",Noticias[i][j]);
            }
            else if(j==s){
                printf("%6.0f|",Noticias[i][j]);
            }
            else{
                printf("%6.2f|",Noticias[i][j]);
            }
        }
    }

    printf("\n\n\n");

/*Tecnologías que más aparecen por semana*/
    char Semana[8][15]={"Semana 1","Semana 2","Semana 3","Semana 4","Semana 5","Semana 6","Semana 7","Semana 8"};
    float mayorsemana;
    printf("\nNoticias que han aparecido mas en CADA SEMANA");
    for(j=0;j<s;j++){
            mayorsemana=Noticias[0][j];
        for(i=0;i<6;i++){
            if(Noticias[i][j]>mayorsemana){
                mayorsemana=Noticias[i][j];
            }
        }
        printf("\n%15s: ",Semana[j]);
        for(i=0;i<6;i++){
            if(Noticias[i][j]==mayorsemana){
                printf(" %s (%.2f)",Tipos[i],Noticias[i][j]);
            }
        }
    }

    printf("\n\n\n");
/*Mayor incremento*/
    float inc,mayorInc;
    float Inc[6];
    int pos;
    for(i=0;i<6;i++){
        inc=0;
        inc=Noticias[i][s-1]-Noticias[i][0];
        if(Noticias[i][0]!=0){
            inc=inc/Noticias[i][0];
        }
        inc=inc*100.0;
        Inc[i]=inc;
    }

/*Matriz con incrementos*/
    printf("Porcentajes de INCREMENTO");
    mayorInc=Inc[0];
    pos=0;
    for(i=0;i<6;i++){
        printf("\n");
        printf(" %20s",Tipos[i]);
        printf("%10.2f",Inc[i]);
        if(Inc[i]>=mayorInc){
            mayorInc=Inc[i];
            pos=i;
        }
    }

    printf("\n\nMayor incremento: %.2f -> %s",mayorInc,Tipos[pos]);


/*Tendencia*/
    char *Tendencias[6]={"Blockchain","VR","Ciberseguridad","IA","Robotica","Big Data"};
    float menor;
    //Descartar los menores por semana
    for(j=0;j<s;j++){
        menor=Noticias[0][j];
        for(i=0;i<6;i++){
            if(Noticias[i][j]<=menor){
                menor=Noticias[i][j];
            }
        }
        for(i=0;i<6;i++){               //Como puede haber más de un menor, hay que volver a recorrer toda la columna para descartarlos.
            if(Noticias[i][j]==menor){
                Tendencias[i]='no';
            }
        }
    }

    //Tecnología que más aparece en 8 semanas o al menos en 3 de las 8
    //Creamos MatrizTend que almacenará en la primera col las sumas 3 a 3 y en la segunda la suma total por fila
    float MatrizTend[6][2];
    for(i=0;i<6;i++){
            MatrizTend[i][0]=0;
            MatrizTend[i][1]=Noticias[i][s];
    }
            //1-Suma mayor 3 a 3
    //Matriz copia Noticias
    float Suma3a3[6][8];
    for(i=0;i<6;i++){
        for(j=0;j<s;j++){
            Suma3a3[i][j]=Noticias[i][j];
        }
    }

    //Mayor suma 3 a 3 por fila
    int q;
    float mayor,suma;
    for(i=0;i<6;i++){
        suma=0;
        for(q=0;q<3;q++){
            mayor=0;
            for(j=0;j<s;j++){
                if(Suma3a3[i][j]>=mayor){       //Encontramos el mayor
                    mayor=Suma3a3[i][j];
                }
            }
            for(j=0;j<s;j++){                   //Anulamos el mayor (para repetir el proceso y encontrar el 2º mayor)
                if(Suma3a3[i][j]==mayor){
                    Suma3a3[i][j]=0;
                    j=s;
                }
            }
            suma=suma+mayor;
        }
        MatrizTend[i][0]=suma;                  //Almacenamos la suma en la MatrizTend para luego comparar
    }

            //2-Encontrar la mayor de las sumas totales y de las sumas 3 a 3
    float suma3a3Mayor,sumaTotalMayor;
    suma3a3Mayor=MatrizTend[0][0];
    sumaTotalMayor=MatrizTend[0][1];
    for(i=0;i<6;i++){
        if(MatrizTend[i][0]>=suma3a3Mayor){
            suma3a3Mayor=MatrizTend[i][0];
        }
        if(MatrizTend[i][1]>=sumaTotalMayor){
            sumaTotalMayor=MatrizTend[i][1];
        }
    }

            //3-Comparar
    printf("\n\n\nTENDENCIAS:");
    for(i=0;i<6;i++){
        if(MatrizTend[i][1]==sumaTotalMayor && Tendencias[i]!='no'){
            printf("\n- %s -> Mayor numero de apariciones (%.0f)",Tendencias[i],MatrizTend[i][1]);
        }
        if(MatrizTend[i][0]==suma3a3Mayor && Tendencias[i]!='no'){
            printf("\n- %s -> Tecnologia con mayor numero de noticias en 3 de las %d semanas (%.0f)",Tendencias[i],s,MatrizTend[i][0]);
        }
    }


    printf("\n\n\n\n");
    printf("\nFin del programa");
    return 0;
}
