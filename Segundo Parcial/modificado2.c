	
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

void llenaTodo(int A[10], int B[10][10], int C[10][11]);
void componentesOmega(int A[10], int num);
void imprimeOmega(int A[10], int num);
void componentesElemento(int B[10][10], int num, int numEle);
void imprimeElemento(int B[10][10], int num, int numElementos);
void vaciaFinal(int A[10], int B[10][10], int C[10][11], int num, int numEle);
void imprimeFinal(int C[10][11], int num, int numEle);
void imprimeFinalChido(int C[10][11], int num, int numEle);
void diagonal(int C[10][11],int num, int numEle);
void rango(int C[10][11],int num, int numEle, int A[10], int B[10][10]);
void rangoGenera(int C[10][11],int num, int numEle, int A[10], int B[10][10]);
void elimina(int C[10][11],int num, int numEle, int x, int y);
void diagonalArriba(int C[10][11],int num, int numEle);
void eliminaArriba(int C[10][11],int num, int numEle, int x, int y);
void solUnica(int C[10][11],int num, int numEle);
void imprimeconEscalar(int A[10], int B[10][10], int C[10][11],int num, int numEle);
void infinidad(int A[10], int B[10][10], int C[10][11],int num, int numEle, int ran);

int main(int argc, char const *argv[])
{
	int omega[10],elementos[10][10],final[10][11];
	int n,i,numElementos;
	llenaTodo(omega,elementos,final);
	system("clear");
	printf("INDEPENDECIA LINEAL Y BASES.\n");
	printf("Este programa determina dado un conjunto finito de vectores {");
	printf("\e[1mV\e[0m");printf("₁, "); printf("\e[1mV\e[0m");printf("₂, "); printf("\e[1mV\e[0m");printf("₃,...,"); printf("\e[1mV\e[0m");printf("n} si");
	printf("son base para un espacio ");
	printf("\e[1mV\e[0m .\n");
	printf("V ∈ Rⁿ\nIngrese n, 2<n<10\n");
	scanf("%d",&n);
	printf("Usted ingreso n = %d\n",n);
	//printf("El vector \e[1mV\e[0m ingresado fue\n");
	//imprimeOmega(omega,n);
	printf("\nIngrese el número de elementos ");
	printf("\e[1mV\e[0m");printf("₁, "); printf("\e[1mV\e[0m");printf("₂, "); printf("\e[1mV\e[0m");printf("₃,...,"); printf("\e[1mV\e[0m");printf("n \n");
	scanf("%d",&numElementos);
	printf("El número de elementos que usted ingresó es %d\n",numElementos);
	componentesElemento(elementos,n,numElementos);
	printf("Los elementos ingresados son\n");
	imprimeElemento(elementos,n,numElementos);
	vaciaFinal(omega,elementos,final,n,numElementos);
	printf("Para verificar si el conjunto dado es una base primero verificaremos si el conjunto es linealmente independiente, generamos a partir de los datos anteriores la siguiente matriz\n");
	imprimeFinalChido(final,n,numElementos);
	diagonal(final,n,numElementos);
	//printf("La matriz diagonalizada es la siguiente (0 bajo la diagonal)\n");
	//imprimeFinalChido(final,n,numElementos);
	//diagonalArriba(final,n,numElementos);
	//imprimeFinal(final,n,numElementos);
	rango(final,n, numElementos,omega,elementos);
	return 0;
}

void llenaTodo(int A[10], int B[10][10], int C[10][11])
{
	int i,j;
	for (i = 0; i < 10; ++i)
	{
		A[i]=0;	
		for (j = 0; j < 10; ++j)
		{
			B[i][j]=0;
		}
		for (j = 0; j < 11; ++j)
		{
			C[i][j]=0;
		}
	}

}

void componentesOmega(int A[10], int num)
{
	int i;
	for (i = 0; i < num; ++i)
	{
		A[i]=(i+1);
	}
}

void imprimeOmega(int A[10], int num)
{
	int i;
	printf(rojito);
	printf("\e[1mV\e[0m");
	printf(rojito);
	printf(" = <");
	for (i=0; i < num; ++i)
	{
		printf(rojito);
		if (i==(num-1))
			printf("%d",A[i]);
		else
			printf("%d,",A[i]);
	}
	printf(rojito);
	printf(">");
	printf(NORMAL);
}

void componentesElemento(int B[10][10], int num, int numEle)
{
	int i,j;
	for (i = 0; i < numEle; ++i)
	{
		for (j = 0; j < num; ++j)
		{
			printf("Ingrese la componente %d del elemento  V%d\n", (j+1),(i+1));
			scanf("%d", &B[i][j]);
		}
	}
}

void imprimeElemento(int B[10][10], int num, int numElementos)
{
	int i,j;
	for (i = 0; i < numElementos; ++i)
	{
		printf(verdesito);
		printf("\e[1mV\e[0m");
		printf(verdesito);
		printf("%d = <",(i+1));
		for (j = 0; j < num; ++j)
		{
			printf(verdesito);
			if(j==(num-1))
				printf("%d", B[i][j]);
			else
				printf("%d,", B[i][j]);
		}
		printf(verdesito);
		printf(">\n");
		printf(NORMAL);
	}
}

void vaciaFinal(int A[10], int B[10][10], int C[10][11], int num, int numEle)
{
	int i,j;
		for(i=0; i<10; i++)
		{
			for(j=0; j<10; j++)
			{
				C[i][j]=B[j][i];
			}
		}

		j = 10;
		for(i=0; i<10; i++)
		{
			C[i][j]=A[i];
		}
}

void imprimeFinal(int C[10][11], int num, int numEle)
{
	int i,j;
	for(i=0; i<10; i++)
	{
		for(j=0; j<11; j++){
			printf("%d\t", C[i][j]);
		}
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

void rango(int C[10][11],int num, int numEle, int A[10], int B[10][10])
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
            printf("\nii)El sistema generado por los vectores tiene infinidad de soluciones. R(A*)=%d R(A)=%d n=%d, por lo tanto podemos concluir que el conjunto dado de vectores no son linealmente independientes, y decir que no son base.\n", ampliada, noampliada,nVariables);
            //infinidad(A,B,C,num,numEle,noampliada);
        }
        else{
        	diagonalArriba(C,num,numEle);
        	//printf("La matriz diagonalizada es la siguiente (0 sobre la diagonal)\n");
			//imprimeFinalChido(C,num,numEle);
            //printf("\nii)El sistema generado por los vectores tiene solución única. R(A*)=%d R(A)=%d n=%d, su solución es:\n", ampliada, noampliada,nVariables);
            printf("\nii)El sistema generado por los vectores tiene solución única. R(A*)=%d R(A)=%d n=%d\n", ampliada, noampliada,nVariables);
            //imprimeOmega(A,num);
            //printf(" = ");
	        //imprimeconEscalar(A,B,C,num,numEle);
	        printf("Por lo tanto el conjunto de vectores dado son linealmente independientes\n");
	        componentesOmega(A,num);
	        vaciaFinal(A,B,C,num,numEle);
	        printf("Ahora veamos si el conjunto devectores genera al espacio vectorial V, para esto generamos la sig. matriz.\n");
	        imprimeFinalChido(C,num,numEle);
			diagonal(C,num,numEle);
			//printf("La matriz diagonalizada es la siguiente (0 bajo la diagonal)\n");
			//imprimeFinalChido(C,num,numEle);
			rangoGenera(C,num, numEle,A,B);
        }
    }
    else
    {
        printf("\niii)El sistema generado por los vectores no tiene solucion. R(A*)=%d R(A)=%d n=%d, por lo tanto podemos concluir que el conjunto dado de vectores no son linealmente independientes, y decir que no son base.\n", ampliada, noampliada,nVariables);
    }
}

void rangoGenera(int C[10][11],int num, int numEle, int A[10], int B[10][10])
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
            printf("\nii)El sistema generado por los vectores tiene infinidad de soluciones. R(A*)=%d R(A)=%d n=%d, por lo tanto el conjunto genera a V. De lo anterior podemos concluir que el conjunto es una base.\n", ampliada, noampliada,nVariables);
        }
        else{
        	diagonalArriba(C,num,numEle);
        	//(printf("La matriz diagonalizada es la siguiente (0 sobre la diagonal)\n");
			//imprimeFinalChido(C,num,numEle);
            printf("\nii)El sistema generado por los vectores tiene solución única. R(A*)=%d R(A)=%d n=%d, por lo tanto el conjunto genera a V. De lo anterior podemos concluir que el conjunto es una base.\n", ampliada, noampliada,nVariables);
        }
    }
    else
    {
        printf("\niii)El sistema generado por los vectores no tiene solucion. R(A*)=%d R(A)=%d n=%d, por lo tanto el conjunto no genera a V. De lo anterior podemos concluir que el conjunto es no es una base.\n", ampliada, noampliada,nVariables);
    }
}

void diagonalArriba(int C[10][11],int num, int numEle)
{
	int i,j;
    for(i=(num-1); i>=0; i--){
        for(j=(numEle-1); j>=0; j--){
            if(i==j){
                if(i>0){
                    eliminaArriba(C,num,numEle,i,j);
                }
            }
        }
    }
}

void eliminaArriba(int C[10][11],int num, int numEle, int x, int y)
{
	//Declaración de variables.
    int maAux[11], maAux2[11],a,b,i,j,k,detener=0;
    //maAux = (int *)malloc (numEle*sizeof(int));
    //maAux2 = (int *)malloc (numEle*sizeof(int));
    //Suma y resta.

    for(i=0; i<11; i++){
    	maAux[i]=0;
    	maAux2[i]=0;
    }

    for (i=x; i>=0; i--){

        if(i>(0)){
            if(C[i-1][y] != 0){
                a = C[x][y];
                b = C[i-1][y];
                for(k=0; k<11; k++){
                    //borra
                    if(a != b){
                        maAux[k] = (b)*(C[x][k]);
                        maAux2[k] = (a)*(C[i-1][k]);
                        C[i-1][k] = maAux[k] - maAux2[k];
                    }
                    else{
                        b = 1;
                        a = 1;
                        maAux[k] = (b)*(C[x][k]);
                        maAux2[k] = (a)*(C[i-1][k]);
                    
                        C[i-1][k] = maAux[k] - maAux2[k];
                    }
                }
            }
        }
    }
    //free(maAux);
    //free(maAux2);
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


void imprimeconEscalar(int A[10], int B[10][10], int C[10][11],int num, int numEle)
{
	float coef;
	int i=0,j=0;
	for (i = 0; i < num; i++)
	{
		coef = (float)C[i][10] / (float)C[i][i] ;
				if (coef >= 0)
		{
			printf(NORMAL);
			printf("+");
		}
		printf("%f",coef);
		printf(verdesito);
		printf("<");
		for (j = 0; j < numEle; j++)
		{
			printf(verdesito);
			if(j==(num-1))
				printf("%d", B[i][j]);
			else
				printf("%d,", B[i][j]);
		}
		printf(verdesito);
		printf(">");
		/*if ( i == numEle )
			printf(">\n");
		else
			printf("> + ");
		*/
		if( i == numEle-1 )
			printf("\n");
		printf(NORMAL);
	}
}

void infinidad(int A[10], int B[10][10], int C[10][11],int num, int numEle, int ran)
{
	int i,j,k,f=ran-1,cont;
	float coef,D[10][11];

	for(i=0; i<10; i++)
	{
		for(j=0; j<11; j++)
		{
			D[i][j] = 0 ;
		}
	}

	for(i=0; i<10; i++)
	{
		for(j=0; j<11; j++)
		{
			D[i][j] =(float)C[i][j];
			//printf("%f\t", D[i][j]);
		}
		//printf("\n");
	}

	imprimeOmega(A,num);
	printf(" = ");
	for(i= ran-1 ; i>=0; i--)
	{
		coef = D[i][10];
		for(j=0; j<numEle; j++)
		{
			if(i != j)
				coef -= D[i][j];
		}
		coef = coef / D[i][i];
		if( (i-1) >= 0)
		  D[i-1][i] *= coef;
		if( coef >= 0 )
		{
			printf("+");
		}
		printf("%f", coef);
		printf(verdesito);
		printf("<");
		for (int k = 0; k < num; k++)
		{
			printf(verdesito);
			if(k == k-1)
				printf("%d",B[f][k]);
			else
				printf("%d,",B[f][k]);
		}
		printf(verdesito);
		printf(">");
		printf(NORMAL);
		f--;
    }
    for(i=ran; i<numEle; i++)
    {
    	printf("+1");
    	printf(verdesito);
		printf("<");
		for(j=0; j<num; j++)
		{
		printf(verdesito);
			if(j == num-1)
				printf("%d",B[i][j]);
			else
				printf("%d,",B[i][j]);	
		}
		printf(verdesito);
		printf(">");
    }
    printf(NORMAL);
    printf("\n");
}