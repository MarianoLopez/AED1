/*
3.- Ingresar dos números reales, que corresponden al peso de la ración diaria de comida de un animal en cautiverio. 
	Calcular la suma e informar el resultado. 
	Si el total de comida supera los 12 kg, emitir un mensaje indicando que está fuera del rango permitido. 
*/

#include <stdio.h>

int main(){
	float racion1,racion2,total;
	printf("Ingresar el peso de la ración 1 y 2, separados por coma \n");
	/*& = referencia a la variable*/
	scanf("%f,%f",&racion1,&racion2);
	total = racion1 + racion2;
	printf("Ración diaria: %.2f\n",total);
	if(total>12){
		printf("Ración fuera del rango permitido");
	}
	return 0;
}
