/*
3. Expresiones aritméticas
	a) Escribir un programa que:
		Inicialice las siguientes variables:
			int a = 100;
			float b = 2.3;
		Declare las siguientes variables:
			int exp1;
			float exp2;
		Realice las siguientes asignaciones:
			exp1 = a / b;
			exp2 = a / b; 
			
	b) Utilizando la función printf() visualizar los valores de las variables exp1 y exp2,
		¿Son iguales?, explique qué sucede.
*/

#include <stdio.h>
int main(){
	int a = 100;
	float b = 2.3;
	
	int exp1;
	float exp2;
	
	exp1 = a/b;
	exp2 = a/b;
	printf("a) y b)\n");
	printf("El valor de la expresion 1(int) %d/%f es: %d\n",a,b,exp1);
	printf("El valor de la expresion 2(float) %d/%f es: %f\n\n",a,b,exp2);
	/*
		c) En el mismo código realice las siguientes asignaciones: exp1=3,347 + 5,2 + 10 / 2 + (-1); exp2=3,347+ 5,2 + 10 / 2 + (-1);  
		d) Visualizar nuevamente los valores de las variables exp1, exp2 y sacar conclusiones. 
	*/
	printf("c)\n");
	exp1=3.347+5.2+10/2+(-1);
	printf("El valor de la expresion 1(int) 3.347+5.2+10/2+(-1) es: %d\n",exp1);
	printf("d)\n");
	exp2=3.347+5.2+10/2+(-1);
	printf("El valor de la expresion 2(float) 3.347+5.2+10/2+(-1) es: %f\n\n",exp2);
	
	/*
		e) Realice la siguiente modificación a exp2 y explique los cambios que produce:exp2= (3,347 + 5,2 + 10) / 2 + (-1); 
	*/
	printf("e)\n");
	exp2=(3.347+5.2+10)/2+(-1);
	printf("El valor de la expresion 2(float) (3.347+5.2+10)/2+(-1) es: %f\n",exp2);
	
	return 0;
}
