//El siguiente programa permite conecer dado un sistema de m x n si : i)Tiene solución. ii)Tiene infinidad de soluciones. iii)No tiene. 
//Librerias.
#include <stdio.h>
#include <stdlib.h>
//Prototipos de funciones.
void llenaMatriz(int **M,int fil, int col);
void muestraMatriz(int **M,int fil, int col);
void diagonal(int **M,int fil, int col);
void elimina(int **M,int fil, int col, int x, int y);
void rango(int **M,int fil, int col);
int main()
{
	//Declaración de variables: matriz, n = filas, m = columnas, i = contador.
	int **matriz,n,m,i,cont=1;
    while (cont == 1) {
        //Descripción del programa.
        printf("\nEste programa permite conocer dado un sistema 'm x n' si tiene :\n\n");
        printf("i) Solución única.\n");
        printf("ii) Infinidad de soluciones.\n");
        printf("iii) No tiene solución.\n\n");
        printf("Por favor ingrese el número de ecuaciones.\n");
        scanf("%d",&n);
        printf("Por favor ingrese el número de incognitas.\n");
        scanf("%d",&m);
        m++;
        printf("Los valores ingresados para las filas y columnas son %d y %d respectivamente. \n", n,m);
        //Creación de la matriz usando memoria dinámica.
        matriz = (int **)malloc (n*sizeof(int *));
        for (i=0;i<n;i++)
            matriz[i] = (int *) malloc (m*sizeof(int));
        llenaMatriz(matriz,n,m);
        printf("\nA*️ es la siguiente :\n");
        muestraMatriz(matriz,n,m);
        diagonal(matriz,n,m);
        printf("\nA*️ diagonalizada es la siguiente :\n");
        muestraMatriz(matriz,n,m);
        rango(matriz,n,m);
        printf("\n¿Desea continuar?Presione 1.\n");
        scanf("%d",&cont);
    }
	return 0;
}

//Funciones.
//La siguiente función permite ingresar los coeficientes a la matriz.
void llenaMatriz(int **M,int fil, int col){
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
			scanf("%d",&M[i][j]);
		}
	}
}
//La siguiente función muestra la matriz.
void muestraMatriz(int **M,int fil, int col){
	int i,j;
	for(i=0; i<fil; i++){
		for(j=0; j<col; j++){
			//Formato para mostrar la diagonalización.
			if(i==j){
				printf("\033[0;32m%d\033[0m\t", M[i][j]);
			}
			else{
				printf("%d\t", M[i][j]);
			}
		}
		printf("\n");
	}
}
//La siguiente función realiza el proceso de diagonalización.
void diagonal(int **M,int fil, int col){
	int i,j;
	for(i=0; i<fil; i++){
		for(j=0; j<col; j++){
			if(i==j){
				if(i<(fil-1)){
					elimina(M,fil,col,i,j);
				}
			}
		}
	}
}
//La siguiente función realiza operaciones para transformar a ceros los elementos bajo la diagonal.
void elimina(int **M,int fil, int col, int x, int y){
	//Declaración de variables.
	int *maAux,*maAux2,i,j,k,a,b,detener=0;
	maAux = (int *)malloc (col*sizeof(int));
	maAux2 = (int *)malloc (col*sizeof(int));
	//Verifica que el pivote sea distinto de 0, en caso de serlo la fila correspondiente es sustituida por una en dónde el
	//nuevo pivote sea distinto de 0.
	while(M[x][y] == 0 && detener < fil-1){
		//Matriz auxiliar.
		for(i=0; i<col; i++){
			maAux[i] =  M[x][i];
		}
		//Traslada filas.
		for(i=x; i<fil; i++){
			for(j=0; j<col; j++){
				if(i==(fil-1)){
					for(k=0; k<col; k++){
						M[i][k] = maAux[k];
					} 
				}
				else{
					M[i][j] = M[i+1][j];
				}
			}
            detener++;
		}
	}
	//Suma y resta.
	for (i=x; i<fil; ++i){
		if(i<(fil-1)){
			if(M[i+1][y] != 0){
				a = M[x][y];
				b = M[i+1][y];
				for(k=0; k<col; k++){
					maAux[k] = (b)*(M[x][k]);
					maAux2[k] = (a)*(M[i+1][k]);
					M[i+1][k] = maAux[k] - maAux2[k];
				}
			}
		}
		else{
			if(M[i][fil-1] != 0){
				a = M[x][y];
				b = M[i][fil-1];
				for(k=0; k<col; k++){
					maAux[k] = (b)*(M[x][k]);
					maAux2[k] = (a)*(M[i][k]);
				}
			}
		}
	}
}
//La siguiente función calcula el rango de A* y A, y nos da a conocer que caso se presenta para dicho sistema.
void rango(int **M,int fil, int col){
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
