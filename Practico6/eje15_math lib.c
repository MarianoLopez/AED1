/*
Funciones predefinidas en C
15. Escribir un programa que permita obtener el resultado de las siguientes operaciones aplicadas a un valor real n:
	a) Redondear n hacia arriba.
	b) Redondear n hacia abajo.
	c) Obtener el valor absoluto de n
	d) Obtener la raíz cuadrada de n.
	e) Obtener n2.
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define CENTINELA 0

void aplicarOperaciones(double n);
void ingresarValor(double *n);

bool isPositivo(int n);

int main(){
	double n;
	
	ingresarValor(&n);
	while(n!=CENTINELA){
		aplicarOperaciones(n);
		ingresarValor(&n);	
	}
	return 0;
}
void aplicarOperaciones(double n){
	printf("\t %.2f round up: %.2lf\n",n,ceil(n));/*Returns the smallest integer value greater than or equal to x.*/
	printf("\t %.2f round down: %.2lf\n",n,floor(n));/*Returns the largest integer value less than or equal to x.*/
	if(isPositivo(n)){
		printf("\t %.2f square root: %.2lf\n",n,sqrt(n));/*Returns the square root of x.*/	
	}else{
		printf("\t %.2f absolute: %.2lf\n",n,fabs(n));/*Returns the absolute value of x.*/	
	}
	printf("\t %.2f raised 2: %.2lf\n",n,pow(n,2));/*Returns x raised to the power of y.*/
}
void ingresarValor(double *n){
	printf("Ingresar valor real (%d = fin): ",CENTINELA);
	scanf("%lf",n);
}
bool isPositivo(int n){
	return (n>0);
}
