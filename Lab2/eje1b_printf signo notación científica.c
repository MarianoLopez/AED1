/*
b) Escribir en C un programa que inicialice una variable de tipo float o double,
	y formatee la salida para que el valor de la variable se visualice: 
		En su formato original.
		Indicando su signo (+ o -).
		En notación científica (Mantisa/Exponente).
		Como float utilizando 1 carácter para la parte decimal.
		Solo la parte entera.

*/
#include <stdio.h>

int main(){
	float b = 99.63;
	printf("Imprimir variable b(float):\n",b);
	printf("\tComo float: %f\n",b);
	printf("\tMostrando el signo: %+f\n",b);
	printf("\tNotacion cientifica (mantisa/exponente): %E\n",b);
	printf("\tCon solo 1(un) caracter para la parte decimal: %.1f\n",b);
	printf("\tComo entero: %d\n",(int)b);
	return 0;
}
