/*
Funciones con paso de par�metros / Funciones que regresan valor
7. Escribir un programa que lea n�meros enteros e invoque una funci�n cuyo par�metro sea cada n�mero introducido y 
	devuelva el valor �Verdadero� en caso de que sea positivo o �Falso� en caso contrario.
Desde el programa principal (main) invocar a la funci�n y de acuerdo al valor que retorne,
informar con una leyenda si el n�mero introducido es positivo o no. (Incluir la librer�a <stdbool.h> para usar el tipo de datos booleano).
*/
#include <stdio.h>
#include <stdbool.h>
#define CENTINELA 0
bool isPositivo(int n);
void ingresarNumero(int *n);/*notar que el par�metro n es un puntero "*" del tipo int*/

int main(){
	int num;
	ingresarNumero(&num);/*notar el "&" para enviar como argumento la direcci�n de memoria*/
	while(num!=CENTINELA){
		if(isPositivo(num)){
			printf("\tN�mero positivo\n");
		}else{
			printf("\tN�mero negativo\n");	
		}
		ingresarNumero(&num);
	}
	return 0;
}
void ingresarNumero(int *n){
	printf("Ingresar n�mero (%d = fin): ",CENTINELA);
	scanf("%d",n);/*notar la falta de "&", dado que el par�metro n es una direcci�n de memoria*/
}
bool isPositivo(int n){
	return (n>0);
}
