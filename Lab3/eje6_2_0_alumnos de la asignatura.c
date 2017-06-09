/*
6.2. Se dispone de las notas obtenidas por los alumnos de la asignatura Algoritmos y Estructuras de Datos I en el primer parcial.
Escriba un programa en C para ingresar las notas y calcular el promedio general, considerando sólo los parciales aprobados.
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
		El bucle for o ciclo for es una estructura de control en programación en la que se puede indicar de antemano el número mínimo de iteraciones 
		que la instrucción realizará. Sintaxis:
		for ( inicialización; condición; incremento ) {
		   declaraciones;
		}
		La inicialización es ejecutada primero y solo una vez.
		Luego se evalua la condición, si es verdadera ejecutará el cuerpo del bucle, si es falsa el bucle termina.
		Si la condición fue verdadera y se terminó la ejecución del cuerpo, se produce un incremento "positivo o negativo" para actualizar la variable de control/indice 

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
