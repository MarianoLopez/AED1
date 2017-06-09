/*
Funciones sin paso de par�metros / Funciones que regresan valor
3. Se desea calcular el �rea y el per�metro de una superficie rectangular, 
	a partir de los datos base y altura.
Ingresar base y altura = 0 para indicar el fin de datos.
	Para una mayor legibilidad, definir una funci�n principal que invoque a las siguientes funciones:
		Una funci�n para el ingreso de datos (base y altura)
		Una funci�n que retorne el �rea --> Area = base * altura
		Una funci�n que retorne el per�metro --> Per�metro = 2 * (base + altura)
		Una funci�n para visualizar los resultados.
*/
#include <stdio.h>
#define CENTINELA 0
void ingresarDatos();
float getArea();
float getPerimetro();
void print();

/*global*/
float base, altura;

int main(){
	ingresarDatos();
	while(base!=CENTINELA||altura!=CENTINELA){
		print();
		ingresarDatos();
	}
	return 0;
}

void ingresarDatos(){
	printf("Ingresar base y altura, separados por coma (%d,%d = fin): ",CENTINELA,CENTINELA);
	scanf("%f,%f",&base,&altura);
}

float getArea(){
	return base * altura;
}

float getPerimetro(){
	return 2 * (base + altura);
}

void print(){
	printf("Base: %.2f, Altura: %.2f\n",base,altura);
	printf("\t�rea: %.2f\n",getArea());
	printf("\tPer�metro: %.2f\n\n",getPerimetro());
}
