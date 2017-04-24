/*
5. ESTRUCTURAS ANIDADAS
5.1. Al ejercicio 3.1, para otorgar un cr�dito, agregue la condici�n de mayor�a de edad (21 a�os). Se deber�
ingresar la edad del solicitante. Mostrar un mensaje en caso de no otorgar el cr�dito por ser menor de
edad. Resolver utilizando estructuras anidadas
*/
#include <stdio.h>
int main(){
	float sueldo;
	float prestamo = 0.0;
	int edad;
	printf("Ingrese importe del sueldo:\n");
	scanf("%f", &sueldo);
	printf("Ingrese la edad:\n");
	scanf("%d", &edad);
	if(edad>=21){
		if(sueldo >= 10000){
			prestamo = 30000;
		}else{
			prestamo = sueldo * 0.75;
		}
		printf("Prestamo otorgado: $ %4.2f\n", prestamo);	
	}else{
		/*menor de edad*/
		printf("Prestamo NO otorgado por ser menor de edad");
	}
	
	return 0;
}
