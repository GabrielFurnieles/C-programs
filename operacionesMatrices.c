/* Desarrollar una aplicación que sea capaz de realizar una serie de operaciones con una y dos matrices de datos numéricos (dichas matrices
deberán ser introducidas por el usuario). Operaciones a realizar:
a)Con una sola matriz:
    - Determinante de la matriz
    - Matriz transpuesta
    - Matriz inversa

b)Con dos matrices
    - Suma de las dos matrices
    - Multiplicación de las dos matrices
    - División de una matriz entre otra
*/

#include<stdio.h>
#include<math.h>

int Pivote(int n,int Matriz);

int main(){
    int n,i,j,m,w,q;

    printf("\nEste programa realiza operaciones con matrices.");
    printf("\nIntroduzca el orden de la matriz: ");
    scanf("%d",&n);
    float Matriz[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Valor[%d][%d]: ",i+1,j+1);
            scanf("%f",&Matriz[i][j]);
        }
    }
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%8.0f",Matriz[i][j]);
        }
    }
    printf("\n\n");

/*TRASPUESTA*/
    printf("\nTRASPUESTA:");
    for(j=0;j<n;j++){
        printf("\n");
        for(i=0;i<n;i++){
            printf("%8.0f",Matriz[i][j]);
        }
    }
    printf("\n\n");

/*DETERMINANTE*/
    float pivote,aux,det,correccion;
    float Cambio_filas[n],Cambio_filas_I[n];
    w=-1;
    correccion=1;

    float Determinante[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            Determinante[i][j]=Matriz[i][j];
        }
    }

    for(q=0;q<n-1;q++){
        /*Selección pivote y división fila entre pivote*/
        pivote=Determinante[q][q];
        while(pivote==0){       /*pivote no puede ser 0*/
            for(j=0+q;j<n;j++){
                if(Determinante[j][q]!=0){        /*desplazarse por columna en búsqueda pivote distinto de 0*/
                    for(i=0;i<n;i++){
                        Cambio_filas[i]=Determinante[q][i];
                        Determinante[q][i]=Determinante[j][i];          /*Intercambiar filas (tanto en Determinante como en Identidad)*/
                        Determinante[j][i]=Cambio_filas[i];
                    }
                    correccion=correccion*(-1); /*Cada cambio de filas modifica el signo del determinnate*/
                    j=n; /*Detener bucle*/
                }
            }
            pivote=Determinante[q][q];
        }
        correccion=correccion*pivote;
        for(j=0;j<n;j++){
                Determinante[q][j]=Determinante[q][j]/pivote;
            }
        /*Operaciones elementales*/
        w++;
        for(i=1+w;i<n;i++){
            aux=Determinante[i][w];
            for(j=0;j<n;j++){
                Determinante[i][j]=Determinante[i][j]-Determinante[w][j]*aux;
            }
        }
    }
    /*Cálculo determinante*/
    det=1;
    for(i=0;i<n;i++){
        det=det*Determinante[i][i];
    }
    printf("DETERMINANTE = %.2f",det*correccion);
    printf("\n\n");

/*INVERSA*/
    if(det*correccion!=0){
        float Inversa[n][n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                Inversa[i][j]=Matriz[i][j];
            }
        }
        /*1-Construcción matriz identidad*/
        float Identidad[n][n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                Identidad[i][j]=0;
                if(i==j){
                    Identidad[i][j]=1;
                }
            }
        }
        /*2-Reducción por filas Inversa a matriz Identidad*/
        w=-1;

        for(q=0;q<n;q++){
            /*2.1-Selección de pivote*/
            pivote=Inversa[q][q];
            /*Pivote no puede ser 0*/
            while(pivote==0){
                for(j=0+q;j<n;j++){
                    if(Inversa[j][q]!=0){        /*desplazarse por columna en búsqueda pivote distinto de 0*/
                        for(i=0;i<n;i++){
                            Cambio_filas[i]=Inversa[q][i];
                            Cambio_filas_I[i]=Identidad[q][i];
                            Inversa[q][i]=Inversa[j][i];          /*Intercambiar filas (tanto en Inversa como en Identidad)*/
                            Identidad[q][i]=Identidad[j][i];
                            Inversa[j][i]=Cambio_filas[i];
                            Identidad[j][i]=Cambio_filas_I[i];
                        }
                        pivote=Inversa[q][q];
                        j=n; /*Detener bucle*/
                    }
                }
            }
            /*2.2-División fila entre pivote*/
            for(j=0;j<n;j++){
                Inversa[q][j]=Inversa[q][j]/pivote;
                Identidad[q][j]=Identidad[q][j]/pivote;
            }
            /*2.3-Hacer 0 por debajo y por encima del pivote (w=-1)*/
            w++;
            for(i=0;i<n;i++){
                if(w!=i){
                    aux=Inversa[i][w];
                    for(j=0;j<n;j++){
                        Inversa[i][j]=Inversa[i][j]-Inversa[q][j]*aux;
                        Identidad[i][j]=Identidad[i][j]-Identidad[q][j]*aux;
                    }
                }
            }
        }
        /*3-Imprimir solución (la matriz Identidad)*/
        printf("\nINVERSA:");
        for(i=0;i<n;i++){
            printf("\n");
            for(j=0;j<n;j++){
                printf("%8.2f",Identidad[i][j]);
            }
        }
        printf("\n\n");
    }
    else{
        printf("\nNo existe INVERSA");
    }

/*SUMA*/
    float Suma[n][n];
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                Suma[i][j]=Matriz[i][j];
            }
        }
    /*Pedir matriz a sumar*/
    float Sumando[n][n];
    float Sol[n][n];
    printf("SUMA:\n");
    printf("Introduzca la matriz a sumar (recuerda que debe ser del mismo orden que la introducida al principio del programa): %d\n",n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Sumando[%d][%d]: ",i+1,j+1);
            scanf("%f",&Sumando[i][j]);
        }
    }
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%8.0f",Sumando[i][j]);
        }
    }
    /*Operaciones*/
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                Sol[i][j]=Suma[i][j]+Sumando[i][j];
            }
    }
    printf("\nSolucion:");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%8.2f",Sol[i][j]);
        }
    }
    printf("\n\n");

/*MULTIPLICACIÓN*/
    printf("MULTIPLICACION:");
    float mult;
    float Multiplicacion[n][n];
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                Multiplicacion[i][j]=Matriz[i][j];
            }
        }
    /*Pedir matriz a multiplicar*/
    printf("\nIntroduzca la matriz a multiplicar (recuerda que debe tener %d filas)",n);
    printf("\nIntroduzca numero de columnas: ");
    scanf("%d",&m);
    float Factor[n][m];
    float Solucion[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Factor[%d][%d]: ",i+1,j+1);
            scanf("%f",&Factor[i][j]);
        }
    }
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("%8.2f",Factor[i][j]);
        }
    }
    printf("\n\n");
    /*Operaciones*/
    for(i=0;i<n;i++){
        for(w=0;w<m;w++){
            mult=0;
            for(j=0;j<n;j++){
                mult=mult+Multiplicacion[i][j]*Factor[j][w];
            }
            Solucion[i][w]=mult;
        }
    }
    /*Solución*/
    printf("\Solucion:");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("%8.2f",Solucion[i][j]);
        }
    }

    printf("\n\n\n");
    printf("Fin del programa\n");
    return 0;
    }
