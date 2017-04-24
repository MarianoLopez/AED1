/*
Modificar el programa del ejercicio 6.2, utilizando como indicador de finalización un valor
“centinela”, es decir, un valor ficticio y no probable del dato que se procesa. (si la escala es de 0 a 10).
*/
#include <stdio.h>
int main(){
	float nota, promedioAprobados;
	int contadorAlumnosAprobados = 0;
	float acumuladorAprobados = 0.0;
	
	printf("Ingrese la nota (valor fuera de la escala 1-10 para finalizar):\n");
	scanf("%f",&nota);
	/*mayor a 0 y menor a 11*/
	while(nota>0 && nota <11){
		if(nota>=6){
			contadorAlumnosAprobados++;
			acumuladorAprobados+=nota;
		}
		printf("Ingrese la nota (valor fuera de la escala 1-10 para finalizar):\n");
		scanf("%f",&nota);
	}
	
	promedioAprobados = acumuladorAprobados/contadorAlumnosAprobados;
	printf("\nPromedio de notas del primer parcial de AEDI (aprobados): %.2f\n",promedioAprobados);
	printf("Cantidad de alumnos aprobados: %d",contadorAlumnosAprobados);
	return 0;
}
