/*
5. Instrucciones de asignación (entender los cambios en las posiciones de memoria) 
	a) Escribir un programa que: - Declare e inicialice 3 variables enteras a, b, c con los siguientes valores: a=10; b=-8; c = 36 
		 Visualice el contenido de las tres variables
		 Realice las siguientes operaciones de asignación: a=b; b=c; c = a;
		 Visualice nuevamente el contenido de las tres variables.
	b) Ejecute el programa  
	c) Explique los cambios en los valores de las variables.

*/
#include <stdio.h>
int main(){
	int a = 10;
	int b = -8;
	int c = 36;
	
	printf("Valores al inicio:\n");
	printf("Variable 'a' = %d\n",a);
	printf("Variable 'b' = %d\n",b);
	printf("Variable 'c' = %d\n",c);
	
	a=b;
	b=c; 
	c=a;
	printf("Luego de las asignaciones:\n");
	printf("Variable 'a' = %d\n",a);
	printf("Variable 'b' = %d\n",b);
	printf("Variable 'c' = %d\n",c);
	
	/*
		d) Modifique el programa para implementar la siguiente operación:  a = b + c 
	*/
	a = b+c;
	printf("\nLuego de hacer  a = b + c:\n");
	printf("Variable 'a' = %d\n",a);
	printf("Variable 'b' = %d\n",b);
	printf("Variable 'c' = %d\n",c);
	return 0;
}
