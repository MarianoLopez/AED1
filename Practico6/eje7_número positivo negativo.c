/*
Funciones con paso de parámetros / Funciones que regresan valor
7. Escribir un programa que lea números enteros e invoque una función cuyo parámetro sea cada número introducido y 
	devuelva el valor “Verdadero” en caso de que sea positivo o “Falso” en caso contrario.
Desde el programa principal (main) invocar a la función y de acuerdo al valor que retorne,
informar con una leyenda si el número introducido es positivo o no. (Incluir la librería <stdbool.h> para usar el tipo de datos booleano).
*/
#include <stdio.h>
#include <stdbool.h>
#define CENTINELA 0
bool isPositivo(int n);
void ingresarNumero(int *n);/*notar que el parámetro n es un puntero "*" del tipo int*/

int main(){
	int num;
	ingresarNumero(&num);/*notar el "&" para enviar como argumento la dirección de memoria*/
	while(num!=CENTINELA){
		if(isPositivo(num)){
			printf("\tNúmero positivo\n");
		}else{
			printf("\tNúmero negativo\n");	
		}
		ingresarNumero(&num);
	}
	return 0;
}
void ingresarNumero(int *n){
	printf("Ingresar número (%d = fin): ",CENTINELA);
	scanf("%d",n);/*notar la falta de "&", dado que el parámetro n es una dirección de memoria*/
}
bool isPositivo(int n){
	return (n>0);
}
