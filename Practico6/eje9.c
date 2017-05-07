/*
9. Escribir un programa que emule una calculadora de operaciones básicas. Para ello implemente una
función para cada operación (suma, resta, multiplicación y división) que retorne el resultado. 
*/
#include <stdio.h>

#define A 50
#define B 70

int suma(int,int);
int resta(int,int);
float division(int,int);
int multiplicacion(int,int);

int main(){
	printf("%d + %d = %d\n",A,B,suma(A,B));
	printf("%d - %d = %d\n",A,B,resta(A,B));
	printf("%d / %d = %.2f\n",A,B,division(A,B));
	printf("%d * %d = %d\n",A,B,multiplicacion(A,B));
	return 0;
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
