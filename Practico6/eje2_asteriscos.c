/*
Funciones sin paso de par�metros / Funciones que no regresan valor
2. Escribir una funci�n que imprima 5 asteriscos (*****). Luego utilizarla en la funci�n principal para
mostrar el siguiente mensaje: �*****Buenas tardes*****�
*/
#include <stdio.h>
void imprimirAsteriscos();
void imprimirSaludo();

int main(){
	imprimirSaludo();
	return 0;
}
void imprimirSaludo(){
	imprimirAsteriscos();
	printf("Buenas tardes");
	imprimirAsteriscos();
}
void imprimirAsteriscos(){
	/* variable local */
	int i;
	for(i=0;i<5;i++){
		printf("*");
	}
}
