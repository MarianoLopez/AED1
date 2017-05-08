/*
Funciones con paso de parámetros / Funciones que no regresan valor
4. Modifique el ejercicio 2, para que el subprograma dibuje n asteriscos que recibe como parámetro.
*/
#include <stdio.h>

void imprimirAsteriscos(int cantidad);
void imprimirSaludo();
int main(){
	imprimirSaludo();
	return 0;
}
void imprimirSaludo(){
	/* variable local */
	int cant; 
	printf("Ingresar cantidad de asteriscos: ");
	scanf("%d", &cant);
	imprimirAsteriscos(cant);
	printf("Buenas tardes");
	imprimirAsteriscos(cant);
}
void imprimirAsteriscos(int cantidad){
	int i;
	for(i=0;i<cantidad;i++){
		printf("*");	
	}
}
