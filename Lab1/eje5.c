#include <stdio.h>

/*
5.- Ingresar tres números que representan metros, centímetros y milímetros, convertir todo a milímetros e informar el resultado
*/

int main() {
	int metros,centimetros,milimetros,totalEnMilimetros;
	printf("Ingresar la cantidad de metros\n");
	scanf("%d",&metros);
	printf("Ingresar la cantidad de centímetros\n");
	scanf("%d",&centimetros);
	printf("Ingresar la cantidad de milímetros\n");
	scanf("%d",&milimetros);
	//1 metro = 100 centímetros y 1 centímetro = 10 milímetros
	totalEnMilimetros = milimetros + (centimetros*10) + (metros*100*10);
	printf("El total en milímetros es: %d",totalEnMilimetros);
	return 0;
}
