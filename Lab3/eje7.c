/*
7. ESTRUCTURA HACER-MIENTRAS
7.1. Resolver el ejercicio 6.1 utilizando la estructura DO-WHILE.
*/
#include <stdio.h>
int main(){
	int cantidad;
	float precio;
	float total = 0.0;
	printf("ingrese la cantidad del producto: \n");
	scanf("%d", &cantidad);
	/*A diferencia del bucle mientras/while, hacer-mientras/do-while se ejecutará al menos 1 vez*/
	do{
		printf("ingrese el precio del producto: \n");
		scanf("%f", &precio);
		total += cantidad * precio;
		printf("ingrese la cantidad del producto (-1 = fin): \n");
		scanf("%d", &cantidad);
	}while(cantidad != -1);

	printf("\nTotal: $ %4.2f\n", total);
	return 0;
}
