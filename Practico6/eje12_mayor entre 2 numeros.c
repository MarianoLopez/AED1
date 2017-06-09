/*
12. Escribir un programa que ingrese 2 números enteros e invoque una función que determine el mayor
valor entre ellos. Utilizar otro subprograma para informar el resultado con una leyenda adecuada.
*/
#include <stdio.h>
#define CENTINELA 0
int getMayor(int a, int b);
void print(int mayor);

void ingresarDatos(int *a, int *b);

int main(){
	int a,b;
	ingresarDatos(&a,&b);
	while(a!=CENTINELA||b!=CENTINELA){
		print(getMayor(a,b));
		ingresarDatos(&a,&b);
	}
	return 0;
}

void print(int mayor){
	printf("\tEl mayor valor es: %d\n",mayor);
}
int getMayor(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

void ingresarDatos(int *a, int *b){
	printf("Ingresar 2 números enteros, separados por coma (%d,%d = fin): ",CENTINELA,CENTINELA);
	scanf("%d,%d",a,b);
}
