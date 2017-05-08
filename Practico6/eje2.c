/*
Funciones sin paso de parámetros / Funciones que no regresan valor
2. Escribir una función que imprima 5 asteriscos (*****). Luego utilizarla en la función principal para
mostrar el siguiente mensaje: “*****Buenas tardes*****”
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
