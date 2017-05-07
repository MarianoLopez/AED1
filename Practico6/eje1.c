/*
Funciones sin paso de parámetros / Funciones que no regresan valor
1. Escribir un programa que ingrese los datos 
	Libreta universitaria y edad, indicando el fin de datos ingresando 0 en los datos de entrada.
Utilice una función para el ingreso de datos. Muestre en pantalla cada par de datos ingresados.
*/
#include <stdio.h>
/*prototipo de la función, void = sin retorno*/
void ingresoDeDatos();

int main(){
	ingresoDeDatos();
	return 0;
}

void ingresoDeDatos(){
	int libreta,edad;
	
	printf("Ingresar libreta y edad, separados por coma (0,0 = fin): ");
	scanf("%d,%d",&libreta,&edad);
	while(libreta!=0||edad!=0){ /*0,0 = fin*/
		printf("Datos ingresados:\n\tLibreta: %d\n\tEdad: %d\n\n",libreta,edad);	
		
		printf("Ingresar libreta y edad, separados por coma (0,0 = fin): ");
		scanf("%d,%d",&libreta,&edad);
	}
}
