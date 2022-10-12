#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define rojito     "\x1b[31m"
#define verdesito  "\x1b[32m"
#define amarillito "\x1b[33m"
#define azulcito    "\x1b[34m"
#define magentabb "\x1b[35m"
#define cyanbb   "\x1b[36m"
#define NORMAL   "\x1b[0m"

void llenaTodo(int A[10][11]);
void imprimeFinalChido(int C[10][11], int num, int numEle);
void diagonal(int C[10][11],int num, int numEle);
void llenaMatriz(int M[10][11],int fil, int col);
void elimina(int C[10][11],int num, int numEle, int x, int y);
void rango(int C[10][11],int num, int numEle);
void daSol(int A[10][11],int num, int numEle, int ran);

int main(int argc, char const *argv[])
{
	int final[10][11];
	int n,m;
	llenaTodo(final);
	system("clear");
	printf("HALLAR BASES DE ESPACIOS NULOS.\n");
	printf("Por favor ingrese el número de ecuaciones.\n");
    scanf("%d",&n);
	printf("Este programa permite hallar la base de un espacio nulo dada una matriz Mnxn\n");
	printf("Por favor ingrese el número de incognitas.\n");
    scanf("%d",&m);
    printf("Los valores ingresados para las filas y columnas son %d y %d respectivamente. \n", n,m);
    llenaMatriz(final,n,m);
    printf("La matriz generada por los datos dados es la sig:\n");
	imprimeFinalChido(final,n,m);
	diagonal(final,n,m);
	printf("La matriz diagonalizada (0 debajo de la diagonal) es la siguiente:\n");
	imprimeFinalChido(final,n,m);
	rango(final,n,m);
	return 0;
}

void llenaMatriz(int M[10][11],int fil, int col)
{
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

void llenaTodo(int A[10][11])
{
	int i,j;
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 11; ++j)
		{
			A[i][j]=0;
		}
	}
}

void imprimeFinalChido(int C[10][11], int num, int numEle)
{
	int i,j;
	for(i=0; i<num; i++)
	{
		for(j=0; j<numEle; j++){
			printf(verdesito);
			printf("%d\t", C[i][j]);
		}
		printf(rojito);
		printf("%d", C[i][10]);
		printf(NORMAL);
		printf("\n");
	}
}

void diagonal(int C[10][11],int num, int numEle)
{
	int i,j;
    for(i=0; i<num; i++){
        for(j=0; j<numEle; j++){
            if(i==j){
                if(i<(num-1)){
                    elimina(C,num,numEle,i,j);
                }
            }
        }
    }
}

void elimina(int C[10][11],int num, int numEle, int x, int y){
    //Declaración de variables.
    int maAux[11], maAux2[11],a,b,i,j,k,detener=0;
    //maAux = (int *)malloc (numEle*sizeof(int));
    //maAux2 = (int *)malloc (numEle*sizeof(int));
    for(i=0; i<11; i++){
    	maAux[i]=0;
    	maAux2[i]=0;
    }
    //Verifica que el pivote sea distinto de 0, en caso de serlo la fila correspondiente es sustituida por una en dónde el nuevo pivote sea distinto de 0.
    while(C[x][y] == 0 && detener < num-1){
        for(i=x+1; i<num; i++){
            for(j=0; j<numEle; j++){
                maAux[i] =  C[x][i];
            }
        }
        for(j=0; j<numEle; j++){
            C[num-1][j] = maAux[j];
        }    
        detener++;
    }
    //Suma y resta.
    for (i=x; i<10; i++){
        if(i<(9)){
            if(C[i+1][y] != 0){
                a = C[x][y];
                b = C[i+1][y];
                for(k=0; k<11; k++){
                    maAux[k] = (b)*(C[x][k]);
                    maAux2[k] = (a)*(C[i+1][k]);
                    C[i+1][k] = maAux[k] - maAux2[k];
                }
            }
        }
    }
   // free(maAux);
   // free(maAux2);
}

void rango(int C[10][11],int num, int numEle)
{
	int i,j,ampliada=num,noampliada=num,nVariables=numEle,cont;
    //Para R(A*)
    for (i=0; i<num; i++) 
    {
        cont = 0;
        for (j=0; j<11; j++) {
            if(C[i][j] == 0){
                cont++;
                //printf("Entró\n");
            }
        }
        if(cont == 11){
            ampliada--;
            //printf("Entró 2\n");
        }
    }
    //Para R(A)
    for (i=0; i<num; i++) 
    {
        cont = 0;
        for (j=0; j<10; j++) {
            if(C[i][j] == 0){
                cont++;
                //printf("Entró normal\n");
            }
        }
        if(cont == (10)){
            noampliada--;
            //printf("Entró normal 2\n");
        }
    }
    
    if(ampliada == noampliada)
    {
        if(ampliada < nVariables){
            printf("\nii)El sistema tiene infinidad de soluciones. R(A*)=%d R(A)=%d n=%d\n", ampliada, noampliada,nVariables);
            daSol(C,num,numEle,noampliada);
        }
        else{
            printf("\nii)El sistema tiene solución única. R(A*)=%d R(A)=%d n=%d, su solución es:\n", ampliada, noampliada,nVariables);
            daSol(C,num,numEle,noampliada);
        }
    }
    else
    {
        printf("\niii)El sistema no tiene solucion. R(A*)=%d R(A)=%d n=%d\n", ampliada, noampliada,nVariables);
    }
}

void daSol(int A[10][11],int num, int numEle, int ran)
{
	/*para el primer caso siempre se tiene que  "0,0,0,...,a|b" */
	int i,j,k,m;
	float D[10][11],copia[10][11],auxiliar[11],alfa = 0;

	for(i=0; i<10; i++)
	{
		for(j=0; j<11; j++)
		{
			D[i][j]=0;
			copia[i][j]=0;
		}
		auxiliar[i]=0;
	}

	//la llenamos con los valores de c 
	for(i=0; i<10; i++)
	{
		for(j=0; j<11; j++)
		{
			D[i][j]=(float)A[i][j];
			copia[i][j]=(float)A[i][j];
		}
	}
	for(i=(ran-1); i>=0; i--)
	{
		//pa que no divida entre cero
		if(D[i][i] != 0)
		{
			// va pasando a la otra matriz copia
			for(j=i; j<10; j++)
			{
				//va a pasar todo menos el pishe dato del indice que estamos checando pa que luego lo divida 
				if(i != j)
				{
					copia[i][j] -= D[i][j];
				}
				copia[i][j] = copia[i][j] / D[i][i];
				copia[i][j] = copia[i][j] + auxiliar[j];
				auxiliar[j] = copia[i][j];
			}
		}
	}		
}
