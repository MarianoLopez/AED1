/*
8. Escribir un subprograma que retorne la conversión de la temperatura en grados Fahrenheit a
Celsius. Considere que la fórmula de conversión de grados Fahrenheit a Celsius es:
Celsius = 5/9 (Fahrenheit- 32)
*/
#include <stdio.h>
#define CENTINELA 99999
float fahrenheitToCelsius(float f);
void ingresarFahrenheit(float *f);/*notar que el parámetro f es un puntero "*" del tipo float*/

int main(){
	float fahrenheit;
	
	ingresarFahrenheit(&fahrenheit);
	while(fahrenheit!=CENTINELA){
		printf("\tCelsius: %.2f\n",fahrenheitToCelsius(fahrenheit));
		ingresarFahrenheit(&fahrenheit);	
	}
	return 0;
}
void ingresarFahrenheit(float *f){
	printf("Ingresar temperatura Fahrenheit (%d = fin): ",CENTINELA);
	scanf("%f",f);
}
float fahrenheitToCelsius(float f){
	return 5/(float)9 *(f- 32);
}
