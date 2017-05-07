/*
Funciones con paso de par�metros / Funciones que no regresan valor
5. Escribir un programa que verifique si un n�mero entero N introducido por teclado es par y muestre
en pantalla una leyenda indic�ndolo. Utilizar un subprograma que reciba N como par�metro.
*/
#include <stdio.h>
void isPar(int num);

int main(){
	int num;
	printf("Ingresar n�mero (0 = fin): ");
	scanf("%d",&num);
	while(num!=0){
		isPar(num);
		printf("Ingresar n�mero (0 = fin): ");
		scanf("%d",&num);
	}
	return 0;
}
void isPar(int num){
	/*la operaci�n m�dulo "%" obtiene el resto de la divisi�n de un n�mero por otro*/
	if(num%2 == 0){
		printf("\tN�mero Par!\n");
	}
}

