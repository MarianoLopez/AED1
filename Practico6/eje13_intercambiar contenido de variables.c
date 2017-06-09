/*
Parámetros por referencia
13. Escribir un programa que contenga una función que intercambie el contenido de dos variables reales.
*/
#include <stdio.h>
#define CENTINELA 0
void intercambiarValores(double *,double *);
void ingresarDatos(double *a, double *b);
void print(double a, double b);

int main(){
	double a,b;
	ingresarDatos(&a,&b);
	while(a!=0||b!=0){
		print(a,b);
		intercambiarValores(&a,&b);
		print(a,b);
		ingresarDatos(&a,&b);
	}
	return 0;
}


void intercambiarValores(double *a, double *b){
	double auxiliar = *a; /* *a = contenido de a*/
	*a = *b;
	*b = auxiliar;
	printf("\t***intercambio***\n");
}
void print(double a, double b){
	printf("\tEl contenido de a es : %.2lf\n",a); /*%lf : Scan as a double floating-point number.*/
	printf("\tEl contenido de b es : %.2lf\n",b);
}
void ingresarDatos(double *a, double *b){
	printf("Ingresar 2 números reales (a,b), separados por coma (%d,%d = fin): ",CENTINELA,CENTINELA);
	scanf("%lf,%lf",a,b);
}
