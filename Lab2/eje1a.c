/*
1. Tipos de datos – Visualización con printf() 
	a) Escribir en C un programa que inicialice 3 variables char, int y float.
	Para cada una de las variables, utilizando la función printf(),
	visualizar en pantalla el valor de las variables en su formato original,
	y además representarlas en al menos otros 2 formatos más.
*/

#include <stdio.h>
int main(){
	char a = 'z';
	float b = 52.33;
	int c = 2;
	
	printf("Imprimir variable a(char):\n");
	printf("\tComo char: %c\n",a);
	printf("\tComo entero|decimal(ASCII): %d\n",a);
	printf("\tComo hexadecimal: %x\n",a);
	printf("\tComo octal: %o\n",a);
	
	printf("Imprimir variable b(float):\n");
	printf("\tComo float: %.2f\n",b);
	printf("\tParte entera como hexadecimal: %x\n",(int)b);
	printf("\tParte entera como octal: %o\n",(int)b);
	
	
	printf("Imprimir variable c(int):\n");
	printf("\tComo int: %d\n",c);
	printf("\tComo entero|decimal(ASCII): %d\n",c);
	printf("\tComo hexadecimal: %x\n",c);
	printf("\tComo octal: %o\n",c);
	
	return 0;
}
