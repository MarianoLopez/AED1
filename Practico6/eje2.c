/*
Funciones sin paso de parámetros / Funciones que no regresan valor
2. Escribir una función que imprima 5 asteriscos (*****). Luego utilizarla en la función principal para
mostrar el siguiente mensaje: “*****Buenas tardes*****”
*/
#include <stdio.h>
void imprimirAsteriscos();

int main(){
	imprimirAsteriscos();
	printf("Buenas tardes");
	imprimirAsteriscos();
	return 0;
}

void imprimirAsteriscos(){
	printf("*****");
}
