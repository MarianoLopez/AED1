/*
2. Tipos de datos � Rango de valores � tama�o en byte 
	a) Escribir un programa que inicialice las variables con los siguientes valores 
	(las variables num�ricas tienen el valor m�ximo positivo del rango de representaci�n): 
	char a = 'Z'; int b = 2147483647; short c = 32767; long d = 2147483647; float e = 3.4E+38; double f = 1.7E+308;
	
	b) Utilizando el operador sizeof() junto a la funci�n printf(), 
	imprimir por cada variable su longitud, su valor y su tipo de dato. 
*/

#include <stdio.h>
int main(){
	char a = 'Z';
	int b = 2147483647;
	short c = 32767;
	long d = 2147483647;
	float e = 3.4E+38;
	double f = 1.7E+308;
	printf("La longitud de la variable a es %d byte(s), su valor es %c y su tipo es %s\n", sizeof(a) ,a,"char");
	printf("La longitud de la variable b es %d byte(s), su valor es %d y su tipo es %s\n", sizeof(b) ,b,"int");
	printf("La longitud de la variable c es %d byte(s), su valor es %d y su tipo es %s\n", sizeof(c) ,c,"short");
	printf("La longitud de la variable d es %d byte(s), su valor es %d y su tipo es %s\n", sizeof(d) ,d,"long");
	printf("La longitud de la variable e es %d byte(s), su valor es %e y su tipo es %s\n", sizeof(e) ,e,"float");
	printf("La longitud de la variable f es %d byte(s), su valor es %e y su tipo es %s\n", sizeof(f) ,f,"double");
	
	/*
		c) Modifique los valores a cantidades que exceden el rango 
		(por ejemplo, asigne 40000 a la variable c).
		Explique, �qu� sucede con las variables num�ricas cuyo valor excede el rango permitido? 
	*/
	printf("\nc)\n");
	c = 40000;
	printf("La longitud de la variable c es %d byte(s), su valor es %d y su tipo es %s\n", sizeof(c) ,c,"short");
	b = 2147483648;
	printf("La longitud de la variable b es %d byte(s), su valor es %d y su tipo es %s\n", sizeof(b) ,b,"int");
	return 0;
}
