/*
Funciones sin paso de parámetros / Funciones que regresan valor
3. Se desea calcular el área y el perímetro de una superficie rectangular, 
	a partir de los datos base y altura.
Ingresar base y altura = 0 para indicar el fin de datos.
	Para una mayor legibilidad, definir una función principal que invoque a las siguientes funciones:
		Una función para el ingreso de datos (base y altura)
		Una función que retorne el área --> Area = base * altura
		Una función que retorne el perímetro --> Perímetro = 2 * (base + altura)
		Una función para visualizar los resultados.
*/
#include <stdio.h>
void ingresarDatos();
float getArea();
float getPerimetro();
void print();

/*global*/
float base, altura;

int main(){
	ingresarDatos();
	while(base!=0||altura!=0){
		print();
		ingresarDatos();
	}
	return 0;
}

void ingresarDatos(){
	printf("Ingresar base y altura, separados por coma (0,0 = fin): ");
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
	printf("\tÁrea: %.2f\n",getArea());
	printf("\tPerímetro: %.2f\n\n",getPerimetro());
}
