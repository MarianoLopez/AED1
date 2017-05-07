/*
Funciones con paso de parámetros / Funciones que regresan valor
7. Escribir un programa que lea números enteros e invoque una función cuyo parámetro sea cada número introducido y 
	devuelva el valor “Verdadero” en caso de que sea positivo o “Falso” en caso contrario.
Desde el programa principal (main) invocar a la función y de acuerdo al valor que retorne,
informar con una leyenda si el número introducido es positivo o no. (Incluir la librería <stdbool.h> para usar el tipo de datos booleano).
*/
#include <stdio.h>
#include <stdbool.h>
bool isPositivo(int n);

int main(){
	int num;
	printf("Ingresar número (0 = fin): ");
	scanf("%d",&num);
	while(num!=0){
		if(isPositivo(num)){
			printf("\tNúmero positivo\n");
		}else{
			printf("\tNúmero negativo\n");	
		}
		printf("Ingresar número (0 = fin): ");
		scanf("%d",&num);
	}
	return 0;
}

bool isPositivo(int n){
	return (n>0);
}
