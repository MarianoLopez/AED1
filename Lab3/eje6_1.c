/*
6. ESTRUCTURA WHILE
6.1. Agregar al ejercicio 1.1 las instrucciones necesarias para que calcule el valor de la compra cuando se
compran varios productos distintos. El cajero ingresará -1 como valor de cantidad para indicar que no
hay más productos comprados.
*/
#include <stdio.h>
int main(){
	int cantidad;
	float precio;
	float total = 0.0;
	printf("ingrese la cantidad del producto (-1 = fin): \n");
	scanf("%d", &cantidad);
	/*Mientras la cantidad "leida anteriormente por teclado" sea disinta de -1 hacer....*/
	while(cantidad != -1){
		printf("ingrese el precio del producto: \n");
		scanf("%f", &precio);
		total += cantidad * precio;
		printf("ingrese la cantidad del producto (-1 = fin): \n");
		scanf("%d", &cantidad);
		/*se volverá a evaluar la condición (cantidad != -1)*/
	}

	printf("\nTotal: $ %4.2f\n", total);
	return 0;
}
