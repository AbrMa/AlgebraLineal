//El siguiente programa permite conecer dado un sistema de m x n si : i)Tiene solución. ii)Tiene infinidad de soluciones. iii)No tiene.
//Librerias.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Prototipos de funciones.
typedef struct fraccion{
    float numerador;
    float denominador;
}
FRACCION;

void llenaMatriz(float **M,int fil, int col);
void muestraMatriz(float **M,int fil, int col);
void muestraMatrizFracciones(FRACCION **Mf,int fil, int col);
void diagonal(float **M,int fil, int col, FRACCION **mI);
void diagonalArriba(float **M,int fil, int col,FRACCION **mI);
void elimina(float **M,int fil, int col, int x, int y,FRACCION **mI);
void eliminaArriba(float **M,int fil, int col, int x, int y,FRACCION **mI);
void rango(float **M,int fil, int col);
void divisor(float **M, FRACCION **Mf, int fil, int col,FRACCION **mI);
void reglasFracciones(FRACCION **Mf, int fil, int col);
void llenaMatrizIdentidad(FRACCION **mI,int fil, int col);
void muestraMatrizIdentidad(FRACCION **mIdentidad,int fil, int col);
void muestraMatrizFlotante(float **M,int fil, int col);
int main()
{
    //Declaración de variables: matriz, n = filas, m = columnas, i = contador.
    int n,m,i,cont=1, confirma,j,lamatflot=0;
    float **matriz;
    FRACCION **matrizFracciones, **mIdentidad;
    while (cont == 1) {
        //Descripción del programa.
        system("clear");
        printf("\nEste programa Hace de todo :\n\n");
        printf("Por favor ingrese n : el número de filas\n");
        scanf("%d",&n);
        printf("Por favor ingresa m : el número de columnas\n");
        scanf("%d",&m);
        printf("¿Su matriz es flotante? 1 si \n");
        scanf("%d",&lamatflot);
        printf("Los valores ingresados para las filas y columnas son %d y %d respectivamente. \n", n,m);
        //Creación de la matriz usando memoria dinámica.
        matriz = (float **)malloc (n*sizeof(float *));
        for (i=0;i<n;i++){
            matriz[i] = (float *) malloc (m*sizeof(float));
        }
        matrizFracciones = (FRACCION **)malloc (n*sizeof(FRACCION *));
        for (i=0;i<n;i++){
            matrizFracciones[i] = (FRACCION *) malloc (m*sizeof(FRACCION));
        }
        mIdentidad = (FRACCION **)malloc (n*sizeof(FRACCION *));
        for (i=0;i<n;i++){
            mIdentidad[i] = (FRACCION *) malloc (m*sizeof(FRACCION));
        }
        llenaMatriz(matriz,n,m);
        llenaMatrizIdentidad(mIdentidad,n,m);
        printf("\nLa matriz ingresada fue la siguiente:\n");
        if(lamatflot == 1){
            printf("\n");
            muestraMatrizFlotante(matriz,n,m);
            printf("\n");
        }
        muestraMatriz(matriz,n,m);
        printf("\n");
        diagonal(matriz,n,m,mIdentidad);
        printf("\nLa matriz diagonalizada es la siguiente:\n");
        muestraMatriz(matriz,n,m);
        if(lamatflot == 1){
            printf("\n");
            muestraMatrizFlotante(matriz,n,m);
        }
        rango(matriz,n,m);
        printf("\n");
        diagonalArriba(matriz,n,m,mIdentidad);
        printf("\nLa matriz diagonalizada hacia arriba es la siguiente:\n");
        muestraMatriz(matriz,n,m);
        if(lamatflot == 1){
            printf("\n");
            muestraMatrizFlotante(matriz,n,m);
        }
        printf("\n");
        divisor(matriz,matrizFracciones,n,m,mIdentidad);
        printf("\n");
        reglasFracciones(matrizFracciones, n,m);
        reglasFracciones(mIdentidad, n,m);
        
        confirma = 1;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(mIdentidad[i][j].denominador == 0){
                    confirma = 0;
                    break;
                }
            }
        }
        
        if(confirma == 1){
            printf("\nLa matriz inversa de la anterior es la siguiente: ya que (A)(inversaA) = I \n");
            muestraMatrizFracciones(mIdentidad,n,m);
            printf("\n");
        }
        if(confirma == 0){
            printf("\nLa matriz inversa de dicha función no existe\n");
        }
        confirma = 0;
        printf("\n¿Desea continuar?Presione 1.\n");
        scanf("%d",&cont);
    }
    return 0;
}

//Funciones.
//La siguiente función permite ingresar los coeficientes a la matriz.
void llenaMatriz(float **M,int fil, int col){
    int i,j;
    //Limpia basura.
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            M[i][j] = 0;
        }
    }
    //Ingresa datos.
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            printf("Ingrese el coeficiente %d de la ecuación %d\n", j+1,i+1);
            scanf("%f",&M[i][j]);
        }
    }
}

void llenaMatrizIdentidad(FRACCION **mI,int fil, int col){
    int i,j;
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            if(i==j){
                mI[i][j].numerador = 1;
                mI[i][j].denominador =1;
            }
            else{
                mI[i][j].numerador = 0;
                mI[i][j].denominador =1;

            }
        }
    }
}

//La siguiente función muestra la matriz.
void muestraMatriz(float **M,int fil, int col){
    int i,j;
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            //Formato para mostrar la diagonalización.
            if(i==j){
                printf("\033[0;32m%d\033[0m\t",(int)M[i][j]);
            }
            else{
                printf("%d\t", (int)M[i][j]);
            }
        }
        printf("\n");
    }
}

void muestraMatrizFlotante(float **M,int fil, int col){
    int i,j;
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            //Formato para mostrar la diagonalización.
            if(i==j){
                printf("\033[0;32m%f\033[0m\t",M[i][j]);
            }
            else{
                printf("%f\t", M[i][j]);
            }
        }
        printf("\n");
    }
}

void reglasFracciones(FRACCION **Mf, int fil, int col){
    int i,j;
    float a,b;
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            a = Mf[i][j].numerador;
            b = Mf[i][j].denominador;
            if(a==b){
                Mf[i][j].numerador = 1;
                Mf[i][j].denominador = 1;
            }
//            if(a==-b){
//                Mf[i][j].numerador = -1;
//                Mf[i][j].denominador = 1;
//            }
            if(fmodf(a,b) == 0){
                if(a/b >= 0){
                    Mf[i][j].numerador = a/b;
                    Mf[i][j].denominador = 1;
                }
                if(a/b <= 0){
                    Mf[i][j].numerador = (a/b);
                    Mf[i][j].denominador = 1;
                }
            }
            
            if(fmodf(a,b) < 0 || fmodf(a,b) > 0){
                float n1=a, n2=b;
                n1 = ( n1 > 0) ? n1 : -n1;
                n2 = ( n2 > 0) ? n2 : -n2;
                while(n1!=n2)
                {
                    if(n1 > n2)
                        n1 -= n2;
                    else
                        n2 -= n1;
                }
                Mf[i][j].numerador = a/n1;
                Mf[i][j].denominador = b/n1;
            }
        }
    }
}

void muestraMatrizFracciones(FRACCION **Mf,int fil, int col){
    int i,j;
    for(i=0; i<fil; i++)
    {
        for(j=0; j<col; j++)
        {
            //Formato para mostrar la diagonalización.
            if((int)Mf[i][j].denominador==1)
            {
                printf("%d\t",(int)Mf[i][j].numerador);
            }
            else
            {
                    if((int)Mf[i][j].numerador==0)
                    {
                        printf("%d\t",(int)Mf[i][j].numerador);
                    }
                    else
                    {
                        printf("%d/%d\t",(int)Mf[i][j].numerador,(int)Mf[i][j].denominador);
                    }
            }
        }
        printf("\n");
    }
}
//La siguiente función realiza el proceso de diagonalización.
void diagonal(float **M,int fil, int col, FRACCION **mI){
    int i,j;
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            if(i==j){
                if(i<(fil-1)){
                    elimina(M,fil,col,i,j, mI);
                }
            }
        }
    }
}
void diagonalArriba(float **M,int fil, int col,FRACCION **mI){
    int i,j;
    for(i=(fil-1); i>=0; i--){
        for(j=(col-1); j>=0; j--){
            if(i==j){
                if(i>0){
                    eliminaArriba(M,fil,col,i,j,mI);
                }
            }
        }
    }
}
//La siguiente función realiza operaciones para transformar a ceros los elementos bajo la diagonal.
void elimina(float **M,int fil, int col, int x, int y, FRACCION **mI){
    //Declaración de variables.
    FRACCION *auxIden, *auxIden2;
    float *maAux,*maAux2,a,b,c,d;
    int i,j,k,detener=0;
//    printf("\nlo que recibe de la identidad es\n");
//    muestraMatrizIdentidad(mI,fil,col);
//    printf("\n");
    maAux = (float *)malloc (col*sizeof(float));
    maAux2 = (float *)malloc (col*sizeof(float));
    auxIden = (FRACCION *)malloc (col*sizeof(FRACCION));
    auxIden2 = (FRACCION *)malloc (col*sizeof(FRACCION));
    //Verifica que el pivote sea distinto de 0, en caso de serlo la fila correspondiente es sustituida por una en dónde el nuevo pivote sea distinto de 0.
    while(M[x][y] == 0 && detener < fil-1){
        //Matriz auxiliar.
        for(i=0; i<col; i++){
            maAux[i] =  M[x][i];
//            printf("%d\t",(int)maAux[i]);
            auxIden[i].numerador = mI[x][i].numerador;
        }
        //Traslada filas.
//                    printf("\nlo que recibe de la normal en i:%d\n",i);
//                    muestraMatriz(M,fil,col);
//        for(i=x; i<fil; i++){

//            for(j=0; j<col; j++){
//                if(i==(fil-1)){
//                    for(k=0; k<col; k++){
//                        M[i][k] = maAux[k];
//                        mI[i][k].numerador = auxIden[k].numerador;
//                    }
//                }
//                else{
//                    M[i][j] = M[i+1][j];
//                    mI[i][j].numerador = mI[i+1][j].numerador;
////                    for(k=0; k<col; k++){
////                        M[i+1][k] = maAux[k];
////                    }
//
//                }
//            }
//            detener++;
//        }
        for(i=x+1; i<fil; i++){
            for(j=0; j<col; j++){
                M[i-1][j] = M[i][j];
                mI[i-1][j].numerador = mI[i][j].numerador;
            }
        }
        for(j=0; j<col; j++){
            M[fil-1][j] = maAux[j];
            mI[fil-1][j].numerador = auxIden[j].numerador;
        }
//        printf("\nlo que sale de la matriz normal es\n");
//        muestraMatriz(M,fil,col);
//        printf("\nlo que sale de la matriz identidad es\n");
//                    muestraMatrizIdentidad(mI,fil,col);
        
        
        detener++;
    }
    //Suma y resta.
    for (i=x; i<fil; i++){
        if(i<(fil-1)){
            if(M[i+1][y] != 0){
                a = M[x][y];
                b = M[i+1][y];
                for(k=0; k<col; k++){
                    maAux[k] = (b)*(M[x][k]);
                    maAux2[k] = (a)*(M[i+1][k]);
                    
                    auxIden[k].numerador = (b)*(mI[x][k].numerador);
                    auxIden2[k].numerador = (a)*(mI[i+1][k].numerador);
                    
                    M[i+1][k] = maAux[k] - maAux2[k];
                    mI[i+1][k].numerador = auxIden[k].numerador -auxIden2[k].numerador ;
                    

                }
            }
        }
    }
}
void eliminaArriba(float **M,int fil, int col, int x, int y,FRACCION **mI){
    //Declaración de variables.
    FRACCION *auxIden, *auxIden2;
    auxIden = (FRACCION *)malloc (col*sizeof(FRACCION));
    auxIden2 = (FRACCION *)malloc (col*sizeof(FRACCION));
    float *maAux,*maAux2,a,b,c,d;
    int i,j,k,detener=0;
    maAux = (float *)malloc (col*sizeof(float));
    maAux2 = (float *)malloc (col*sizeof(float));
    //Suma y resta.
    for (i=x; i>=0; i--){

        if(i>(0)){
            if(M[i-1][y] != 0){
                a = M[x][y];
                b = M[i-1][y];
//                printf("\na es : %f, b es %f\n",a,b);
                for(k=0; k<col; k++){
                    //borra
                    if(a != b){
                        maAux[k] = (b)*(M[x][k]);
                        maAux2[k] = (a)*(M[i-1][k]);
                        auxIden[k].numerador = (b)*(mI[x][k].numerador);
                        auxIden2[k].numerador = (a)*(mI[i-1][k].numerador);
                        
                        M[i-1][k] = maAux[k] - maAux2[k];
                        mI[i-1][k].numerador = auxIden[k].numerador - auxIden2[k].numerador;
                    }
                    else{
                        b = 1;
                        a = 1;
                        maAux[k] = (b)*(M[x][k]);
                        maAux2[k] = (a)*(M[i-1][k]);
                        auxIden[k].numerador = (b)*(mI[x][k].numerador);
                        auxIden2[k].numerador = (a)*(mI[i-1][k].numerador);
                        
                        M[i-1][k] = maAux[k] - maAux2[k];
                        mI[i-1][k].numerador = auxIden[k].numerador - auxIden2[k].numerador;
                    }
                    //borra
                    

                    

                }
            }
        }
    }
}
//La siguiente función calcula el rango de A* y A, y nos da a conocer que caso se presenta para dicho sistema.
void rango(float **M,int fil, int col){
    int i,j,ampliada=fil,noampliada=fil,nVariables=(col-1),cont;
    //Para R(A*)
    for (i=0; i<fil; i++) {
        cont = 0;
        for (j=0; j<col; j++) {
            if(M[i][j] == 0){
                cont++;
            }
        }
        if(cont == col){
            ampliada--;
        }
    }
    //Para R(A)
    for (i=0; i<fil; i++) {
        cont = 0;
        for (j=0; j<col-1; j++) {
            if(M[i][j] == 0){
                cont++;
            }
        }
        if(cont == (col-1)){
            noampliada--;
        }
    }
    
    if(ampliada == noampliada){
        if(ampliada < nVariables){
            printf("\nii)El sistema tiene infinidad de soluciones. R(A*)=%d R(A)=%d n=%d\n", ampliada, noampliada,nVariables);
        }
        else{
            printf("\nii)El sistema tiene solución única. R(A*)=%d R(A)=%d n=%d\n", ampliada, noampliada,nVariables);
        }
    }
    else{
        printf("\niii)El sistema no tiene solucion. R(A*)=%d R(A)=%d n=%d\n", ampliada, noampliada,nVariables);
    }
}

void divisor(float **M, FRACCION **Mf, int fil, int col,FRACCION **mI){
    int i,j,k;
    float div, divIdentidad;
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            Mf[i][j].numerador = M[i][j];
        }
    }
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            if(i==j){
                div = M[i][j];
                divIdentidad = div;
                for(k=0; k<col; k++){
                    Mf[i][k].denominador = div;
                    mI[i][k].denominador =  div;
                }
            }
        }
    }
}

void muestraMatrizIdentidad(FRACCION **mIdentidad,int fil, int col){
    int i,j;
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            printf("%d/%d\t",(int)mIdentidad[i][j].numerador,(int)mIdentidad[i][j].denominador);
        }
        printf("\n");
    }
}
