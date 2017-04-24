/*
1. ESTRUCTURA SECUENCIAL
1.1. Escribir un programa en C que emita el ticket con el importe a pagar en un supermercado considerando
los datos: cantidad y precio del producto. Imprimir el importe con la leyenda “Total”.
*/
#include <stdio.h>
int main(){
	int cantidad;
	float precio;
	float total = 0.0;
	printf("ingrese la cantidad del producto: \n");
	scanf("%d", &cantidad);
	printf("ingrese el precio del producto: \n");
	scanf("%f", &precio);
	total = cantidad * precio;
	printf("Total: $ %4.2f\n", total);
	return 0;
}

