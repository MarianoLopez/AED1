/*
Funciones sin paso de parámetros / Funciones que no regresan valor
1. Escribir un programa que ingrese los datos 
	Libreta universitaria y edad, indicando el fin de datos ingresando 0 en los datos de entrada.
Utilice una función para el ingreso de datos. Muestre en pantalla cada par de datos ingresados.
*/
#include <stdio.h>
#define CENTINELA 0
/*prototipo de la función, void = sin retorno*/
void ingresoDeDatos();
void imprimirDatos();
/*variables globales*/
int libreta,edad;

int main(){
	ingresoDeDatos();
	while(libreta!=CENTINELA||edad!=CENTINELA){ /*0,0 = fin*/
		imprimirDatos();
		ingresoDeDatos();
	}
	return 0;
}

void ingresoDeDatos(){
	printf("Ingresar libreta y edad, separados por coma (%d,%d = fin): ",CENTINELA,CENTINELA);
	scanf("%d,%d",&libreta,&edad);
}
void imprimirDatos(){
	printf("Datos ingresados:\n\tLibreta: %d\n\tEdad: %d\n\n",libreta,edad);	
}
