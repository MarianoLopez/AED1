/*
6.2. Se dispone de las notas obtenidas por los alumnos de la asignatura Algoritmos y Estructuras de Datos I en el primer parcial.
Escriba un programa en C para ingresar las notas y calcular el promedio general, considerando s�lo los parciales aprobados.
Como no se conoce la cantidad de alumnos, para finalizar, el bucle DEBE utilizar un contador de alumnos.
*/
#include <stdio.h>
#define maximoDeAlumnos 10
int main(){
	float nota, promedioAprobados;
	int contadorAlumnosAprobados = 0;
	float acumuladorAprobados = 0.0;
	int indice;
	/*
		El bucle for o ciclo for es una estructura de control en programaci�n en la que se puede indicar de antemano el n�mero m�nimo de iteraciones 
		que la instrucci�n realizar�. Sintaxis:
		for ( inicializaci�n; condici�n; incremento ) {
		   declaraciones;
		}
		La inicializaci�n es ejecutada primero y solo una vez.
		Luego se evalua la condici�n, si es verdadera ejecutar� el cuerpo del bucle, si es falsa el bucle termina.
		Si la condici�n fue verdadera y se termin� la ejecuci�n del cuerpo, se produce un incremento "positivo o negativo" para actualizar la variable de control/indice 

		indice = 0
		MIENTRAS indice < maximoDeAlumnos HACER
			.....
			indice = indice + 1
		FIN MIENTRAS
		
		Es esquivalente a:
		
		PARA/DESDE indice = 0 HASTA maximoDeAlumnos HACER
			.....
			indice = indice + 1
		FIN PARA/DESDE
	*/
	for(indice=0;indice<maximoDeAlumnos;indice++){
		printf("Ingrese la nota:\n");
		scanf("%f",&nota);
		if(nota>=6){
			contadorAlumnosAprobados++;
			acumuladorAprobados+=nota;
		}
	}
	promedioAprobados = acumuladorAprobados/contadorAlumnosAprobados;
	printf("\nPromedio de notas del primer parcial de AEDI (aprobados): %.2f\n",promedioAprobados);
	printf("Cantidad de alumnos aprobados: %d",contadorAlumnosAprobados);
	return 0;
}
