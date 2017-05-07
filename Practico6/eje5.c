/*
Funciones con paso de parámetros / Funciones que no regresan valor
5. Escribir un programa que verifique si un número entero N introducido por teclado es par y muestre
en pantalla una leyenda indicándolo. Utilizar un subprograma que reciba N como parámetro.
*/
#include <stdio.h>
void isPar(int num);

int main(){
	int num;
	printf("Ingresar número (0 = fin): ");
	scanf("%d",&num);
	while(num!=0){
		isPar(num);
		printf("Ingresar número (0 = fin): ");
		scanf("%d",&num);
	}
	return 0;
}
void isPar(int num){
	/*la operación módulo "%" obtiene el resto de la división de un número por otro*/
	if(num%2 == 0){
		printf("\tNúmero Par!\n");
	}
}

