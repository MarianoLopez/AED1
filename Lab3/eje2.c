/*
2. ALTERNATIVA SIMPLE
2.1. Modifique el ejercicio 1.1 para que calcule una bonificaci�n de 15% al total de la compra si �sta es
mayor o igual a $500 o se compran m�s de 5 productos. Utilice una sola expresi�n l�gica.
*/
#include <stdio.h>
int main(){
	int cantidad;
	float precio;
	float total = 0.0;
	float bonif;
	printf("ingrese la cantidad del producto: \n");
	scanf("%d", &cantidad);
	printf("ingrese el precio del producto: \n");
	scanf("%f", &precio);
	total = cantidad * precio;
	if (total >= 500 || cantidad > 5) {
		bonif = total * 0.15;
		total = total - bonif;
	}
	printf("Total: $ %4.2f\n", total);
	return 0;
}
