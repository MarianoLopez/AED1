/*Funciones con paso de par�metros / Funciones que no regresan valor
5. Escribir un programa que verifique si un n�mero entero N introducido por teclado es par y muestre
en pantalla una leyenda indic�ndolo. Utilizar un subprograma que reciba N como par�metro.*/
#include <stdio.h>
#define CENTINELA 0 /*constante*/
void isPar(int num);
void ingresarNumero(int *n);/*notar que el par�metro n es un puntero "*" del tipo int*/
int main(){
	int num;/*local*/
	ingresarNumero(&num);/*notar el "&" para enviar como argumento la direcci�n de memoria*/
	while(num!=CENTINELA){
		isPar(num);
		ingresarNumero(&num);
	}
	return 0;
}
void ingresarNumero(int *n){
	printf("Ingresar n�mero (%d = fin): ",CENTINELA);
	scanf("%d",n);/*notar la falta de "&", dado que el par�metro n es una direcci�n de memoria*/
}
void isPar(int num){
	/*la operaci�n m�dulo "%" obtiene el resto de la divisi�n de un n�mero por otro*/
	if(num%2 == 0){
		printf("\tN�mero Par!\n");
	}
}

