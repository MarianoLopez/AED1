/*
8.2. Generar y mostrar la tabla de multiplicar de un n�mero introducido por el teclado
*/
#include <stdio.h>
int main(){
	int num;
	int multiplicacion;
	printf("Ingrese un n�mero entero: ");
	scanf("%d",&num);
	int i;
	for(i=1;i<=10;i++){
		multiplicacion = num * i;
		printf("%d * %d = %d\n",num,i,multiplicacion);
	}
	return 0;
}
