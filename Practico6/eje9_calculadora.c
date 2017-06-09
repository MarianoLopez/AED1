/*
9. Escribir un programa que emule una calculadora de operaciones básicas. Para ello implemente una
función para cada operación (suma, resta, multiplicación y división) que retorne el resultado. 
*/
#include <stdio.h>
#define CENTINELA 0
void ingresarDatos(int *, int *);
void procesarEimprimir(int, int);
int suma(int,int);
int resta(int,int);
float division(int,int);
int multiplicacion(int,int);

int main(){
	int a,b;
	ingresarDatos(&a,&b);	
	while(a!=CENTINELA||b!=CENTINELA){
		procesarEimprimir(a,b);
		ingresarDatos(&a,&b);	
	}
	return 0;
}
void procesarEimprimir(int a, int b){
	printf("\t%d + %d = %d\n",a,b,suma(a,b));
	printf("\t%d - %d = %d\n",a,b,resta(a,b));
	printf("\t%d / %d = %.2f\n",a,b,division(a,b));
	printf("\t%d * %d = %d\n\n",a,b,multiplicacion(a,b));
}
void ingresarDatos(int *a, int *b){
	printf("Ingresar 2 números enteros, separados por coma (%d,%d = fin): ",CENTINELA,CENTINELA);
	scanf("%d,%d",a,b);
}

int suma(int a, int b){
	return a+b;
}
int resta(int a, int b){
	return a-b;
}
float division(int a, int b){
	return a/(float)b;
}
int multiplicacion(int a, int b){
	return a*b;
}
