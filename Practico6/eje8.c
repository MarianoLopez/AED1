/*
8. Escribir un subprograma que retorne la conversión de la temperatura en grados Fahrenheit a
Celsius. Considere que la fórmula de conversión de grados Fahrenheit a Celsius es:
Celsius = 5/9 (Fahrenheit- 32)
*/
#include <stdio.h>
float fahrenheitToCelsius(float f);

int main(){
	float fahrenheit;
	printf("Ingresar temperatura Fahrenheit (99999 = fin): ");
	scanf("%f",&fahrenheit);
	while(fahrenheit!=99999){
		printf("\tCelsius: %.2f\n",fahrenheitToCelsius(fahrenheit));
		printf("Ingresar temperatura Fahrenheit (99999 = fin): ");
		scanf("%f",&fahrenheit);
	}
	return 0;
}

float fahrenheitToCelsius(float f){
	return 5/(float)9 *(f- 32);
}
