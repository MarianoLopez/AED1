/*
Funciones con paso de par�metros / Funciones que no regresan valor
4. Modifique el ejercicio 2, para que el subprograma dibuje n asteriscos que recibe como par�metro.
*/
#include <stdio.h>
#define asteriscos 20
void imprimirAsteriscos(int cantidad);

int main(){
	imprimirAsteriscos(asteriscos);
	printf("Buenas tardes");
	imprimirAsteriscos(asteriscos);
	return 0;
}

void imprimirAsteriscos(int cantidad){
	int i;
	for(i=0;i<cantidad;i++){
		printf("*");	
	}
}
