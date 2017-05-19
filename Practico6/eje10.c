/*
10. Escribir un programa para calcular el �rea de una circunferencia. (A = pi * r2)
El programa debe contener las siguientes funciones:
	Lectura de datos
	Una funci�n que reciba el radio como par�metro y retorne el valor del �rea de la circunferencia.
	Visualizaci�n de resultados obtenidos
*/
#include <stdio.h>
#include <math.h>
#define CENTINELA 0
/*#define M_PI 3.14159265358979323846264338327*//*M_PI is not defined in standard C ANSI*/
void ingresarRadio(float *);
float getArea(float radio);
void print(float radio, float area);

int main(){
	float radio;
	ingresarRadio(&radio);
	while(radio!=CENTINELA){
		print(radio,getArea(radio));
		ingresarRadio(&radio);
	}
	return 0;
}

void ingresarRadio(float *r){
	printf("Ingresar radio de la circunferencia (%d = fin): ",CENTINELA);
	scanf("%f",r);
}
float getArea(float radio){
	return M_PI * pow(radio,2);
}
void print(float radio, float area){
	printf("\tRadio: %.2f, �rea: %.2f\n",radio,area);
}
