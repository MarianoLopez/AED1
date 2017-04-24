/*
6.- Dados 2 números enteros que representan la cantidad de alumnos aprobados y la cantidad total de alumnos,
	calcular e informar el porcentaje que representan los aprobados. 
*/
#include <stdio.h>

int main(){
	int alumnosAprobados,totalAlumnos,porcentajeAprobados;
	printf("Ingresa la cantidad de alumnos aprobados y el total de alumnos, separados por coma\n");
	scanf("%d , %d",&alumnosAprobados, &totalAlumnos);
	porcentajeAprobados = (alumnosAprobados*100)/totalAlumnos;
	/*%% = escapar al formateador */
	printf("El porcentaje de aprobados es de %d%%",porcentajeAprobados);
	return 0;
}
