#include <stdio.h>

/*
5.- Ingresar tres n�meros que representan metros, cent�metros y mil�metros, convertir todo a mil�metros e informar el resultado
*/

int main() {
	int metros,centimetros,milimetros,totalEnMilimetros;
	printf("Ingresar la cantidad de metros\n");
	scanf("%d",&metros);
	printf("Ingresar la cantidad de cent�metros\n");
	scanf("%d",&centimetros);
	printf("Ingresar la cantidad de mil�metros\n");
	scanf("%d",&milimetros);
	//1 metro = 100 cent�metros y 1 cent�metro = 10 mil�metros
	totalEnMilimetros = milimetros + (centimetros*10) + (metros*100*10);
	printf("El total en mil�metros es: %d",totalEnMilimetros);
	return 0;
}
