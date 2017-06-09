/*Funciones con paso de parámetros / Funciones que no regresan valor
5. Escribir un programa que verifique si un número entero N introducido por teclado es par y muestre
en pantalla una leyenda indicándolo. Utilizar un subprograma que reciba N como parámetro.*/
#include <stdio.h>
#define CENTINELA 0 /*constante*/
void isPar(int num);
void ingresarNumero(int *n);/*notar que el parámetro n es un puntero "*" del tipo int*/
int main(){
	int num;/*local*/
	ingresarNumero(&num);/*notar el "&" para enviar como argumento la dirección de memoria*/
	while(num!=CENTINELA){
		isPar(num);
		ingresarNumero(&num);
	}
	return 0;
}
void ingresarNumero(int *n){
	printf("Ingresar número (%d = fin): ",CENTINELA);
	scanf("%d",n);/*notar la falta de "&", dado que el parámetro n es una dirección de memoria*/
}
void isPar(int num){
	/*la operación módulo "%" obtiene el resto de la división de un número por otro*/
	if(num%2 == 0){
		printf("\tNúmero Par!\n");
	}
}

