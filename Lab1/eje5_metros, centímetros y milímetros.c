#include <stdio.h>

/*
5.- Ingresar tres n˙meros que representan metros, centÝmetros y milÝmetros, convertir todo a milÝmetros e informar el resultado
*/

int main() {
	int metros,centimetros,milimetros,totalEnMilimetros;
	printf("Ingresar la cantidad de metros\n");
	scanf("%d",&metros);
	printf("Ingresar la cantidad de centÝmetros\n");
	scanf("%d",&centimetros);
	printf("Ingresar la cantidad de milÝmetros\n");
	scanf("%d",&milimetros);
	/*1 metro = 100 centÝmetros y 1 centÝmetro = 10 milÝmetros*/
	totalEnMilimetros = milimetros + (centimetros*10) + (metros*100*10);
	printf("El total en milÝmetros es: %d",totalEnMilimetros);
	return 0;
}
