/*
8. ESTRUCTURA PARA
8.1. Escribir un programa que permita calcular e informar el promedio de los n�meros impares
menores o iguales a un n�mero entero ingresado por teclado. Mostrar los impares.
*/
#include <stdio.h>
/*cabecera necesaria para utilizar la funci�n pow "potencia"*/
#include <math.h>
int main(){
	int numero;
	float promedio = 0.0;
	int acumulador = 0;
	int contador;
	
	printf("ingrese un numero entero: ");
	scanf("%d", &numero);
	/*
		i=5; // i vale 5 
		j=5 // j vale 5 
		a = i++ // a vale 5, i vale 6 (Asignaci�n, incremento)
		b = ++j // b vale 6, j vale 6  (Incremento, asignaci�n)
	*/
	int i;
	for (i = 1; i <= numero; ++i){
		/*
			pow(x,y) = x^y -> -1^i
			Las potencias de exponente impar tienen el mismo signo de la base.
		*/
 		if (pow(-1,i) == -1){
	 		acumulador +=i;
	 		contador++;
	 		printf("Impar %d \n", i);
	 	}
	 }
	 promedio = (float)acumulador/contador;
	 printf("Cantidad de numeros impares: %d\n", contador);
	 printf("El promedio es: %4.2f\n", promedio);
	 return 0;
}

