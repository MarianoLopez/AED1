/*
Alcance de Variables
14. Analizar el c�digo para responder lo siguiente:
	a) Identifique cu�les son las variables globales y locales
	b) Analice el c�digo y explique el resultado
*/
#include <stdio.h>
int local();

int a, b;
int main (){
	a = 5;
	b = a + 15;
	local();
	printf("\na en main = %d b = %d\n", a, b);
	return 0;
}

int local(){
	int a;
	a = b * 5;
	printf("a en local = %d", a);
	return 0;
}
