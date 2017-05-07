/*
6. Escribir un programa que calcule y visualice en pantalla el cubo de los números comprendidos entre 1 y 5.
Utilice una función que devuelva el valor del cubo para cada número.
*/
#include <stdio.h>
#include <math.h>
int getCubo(int n);
int getCuboMath(int n);

int main(){
	int i;
	printf("Sin usar libreria math\n");
	for(i=1;i<=5;i++){
		printf("%d al cubo = %d\n",i,getCubo(i));
	}
	printf("\nUsando math\n");
	for(i=1;i<=5;i++){
		printf("%d al cubo = %d\n",i,getCuboMath(i));
	}
	return 0;
}
int getCuboMath(int n){
	return (int)pow(n,3);
}
int getCubo(int n){
	return n*n*n;
}


