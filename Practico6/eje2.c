/*
Funciones sin paso de par�metros / Funciones que no regresan valor
2. Escribir una funci�n que imprima 5 asteriscos (*****). Luego utilizarla en la funci�n principal para
mostrar el siguiente mensaje: �*****Buenas tardes*****�
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
