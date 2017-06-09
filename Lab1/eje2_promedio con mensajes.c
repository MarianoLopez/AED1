/*
	2.- Modifique el algoritmo del punto anterior para que, además de mostrar el promedio, 
	muestre el mensaje “Destacado” si éste es mayor o igual que 8. 
	En otro caso, mostrar el mensaje “Bueno”.
*/
#include <stdio.h>

int main() {
	/*variables*/
	float nota1,nota2,promedio;
	/*imprimir por consola, \n = nueva línea*/
	printf("Ingresar la primer nota\n");
	/*leer desde consola y almacenar en variable (formato, variable)*/
	scanf("%f",&nota1);
	printf("Ingresar la segunda nota\n");
	scanf("%f",&nota2);
	promedio = (nota1+nota2)/2;
	/*%.2f = float con 2 decimales*/
	printf("El promedio del alumno es: %.2f\n",promedio);	
	if(promedio >=8){
		printf("Destacado");
	}else{
		printf("Bueno");
	}
	/*0 = EXIT_SUCCESS, 1 = EXIT_FAILURE */
	return 0;
}
