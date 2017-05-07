/*
Funciones con paso de par�metros / Funciones que regresan valor
7. Escribir un programa que lea n�meros enteros e invoque una funci�n cuyo par�metro sea cada n�mero introducido y 
	devuelva el valor �Verdadero� en caso de que sea positivo o �Falso� en caso contrario.
Desde el programa principal (main) invocar a la funci�n y de acuerdo al valor que retorne,
informar con una leyenda si el n�mero introducido es positivo o no. (Incluir la librer�a <stdbool.h> para usar el tipo de datos booleano).
*/
#include <stdio.h>
#include <stdbool.h>
bool isPositivo(int n);

int main(){
	int num;
	printf("Ingresar n�mero (0 = fin): ");
	scanf("%d",&num);
	while(num!=0){
		if(isPositivo(num)){
			printf("\tN�mero positivo\n");
		}else{
			printf("\tN�mero negativo\n");	
		}
		printf("Ingresar n�mero (0 = fin): ");
		scanf("%d",&num);
	}
	return 0;
}

bool isPositivo(int n){
	return (n>0);
}
