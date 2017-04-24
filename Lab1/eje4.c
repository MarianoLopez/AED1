#include <stdio.h>

/*
4.- Ingresar tres números enteros que representan horas, minutos y segundos, convertir todo a segundos, e informar el resultado
*/

int main() {
	int horas,minutos,segundos,totalEnSegundos;
	printf("Ingresar la cantidad de horas\n");
	scanf("%d",&horas);
	printf("Ingresar la cantidad de minutos\n");
	scanf("%d",&minutos);
	printf("Ingresar la cantidad de segundos\n");
	scanf("%d",&segundos);
	/*1hr = 60min y 1min = 60sec*/
	totalEnSegundos = segundos + (minutos*60) + (horas*60*60);
	printf("El total en segundos es: %d",totalEnSegundos);
	return 0;
}
