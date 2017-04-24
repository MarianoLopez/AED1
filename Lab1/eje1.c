/*
	1.-  Se ingresan por teclado 2 notas de exámenes aprobados (con decimales) de un alumno, calcular y mostrar su promedio. 
*/

/*
archivo de cabecera que contiene las definiciones de las macros, las constantes, 
las declaraciones de funciones de la biblioteca estándar del lenguaje de programación C 
para hacer operaciones, estándar, de entrada y salida
*/
#include <stdio.h>

int main() {
	//variables
	float nota1,nota2,promedio;
	//imprimir por consola, \n = nueva línea
	printf("Ingresar la primer nota\n");
	//leer desde consola y almacenar en variable (formato, variable)
	scanf("%f",&nota1);
	printf("Ingresar la segunda nota\n");
	scanf("%f",&nota2);
	promedio = (nota1+nota2)/2;
	//%.2f = float con 2 decimales
	printf("El promedio del alumno es: %.2f",promedio);
	//0 = EXIT_SUCCESS, 1 = EXIT_FAILURE 
	return 0;
}
