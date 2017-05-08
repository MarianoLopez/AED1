/*A partir de los siguientes datos ingresados por teclado: 
	número de libreta universitaria, nota del 1er parcial y nota del 2do parcial,
escriba un programa que invoque una función que devuelva una leyenda asociada a la condición del alumno: “Promocionó”, “Regularizó”, o “Libre”).
Condiciones para determinar la condición del alumno:
	Para la promoción: es necesario aprobar los 2(dos) parciales y que el promedio de ambos sea mayor o igual a 7(siete).
	Para regularizar: es necesario aprobar los 2(dos) parciales.
	Libre: si desaprueba al menos un parcial.
Recordar que el parcial se aprueba con nota >= 6.
El fin de datos está dado con libreta universitaria igual a cero.
El programa deberá contemplar las siguientes funciones:
	Una función que devuelva true en el caso que el parcial esté aprobado y false en caso contrario.
	Una función que retorne el promedio de 2 notas que se reciben como parámetro.
*/
#include <stdio.h>
#include <stdbool.h>
#define CENTINELA 0

bool isAprobado(float nota);
float getPromedio(float p1, float p2);

void ingresarLibreta(int *libreta);
void ingresarNotas(float *p1, float *p2);
void imprimirCondicion(float p1, float p2);

int main(){
	int libreta;
	float p1,p2;
	
	ingresarLibreta(&libreta);
	while(libreta!=CENTINELA){
		ingresarNotas(&p1,&p2);
		imprimirCondicion(p1,p2);
		ingresarLibreta(&libreta);
	}
	return 0;
}

bool isAprobado(float nota){
	return (nota >= 6);
}
float getPromedio(float p1, float p2){
	return (p1+p2)/2;
}

void imprimirCondicion(float p1, float p2){
	float promedio = getPromedio(p1,p2);
	if(isAprobado(p1)&&isAprobado(p2)&&promedio>=7){
		printf("\tPromocionó!\n");
	}else if(isAprobado(p1)&&isAprobado(p2)){
		printf("\tRegularizó!\n");
	}else{
		printf("\tLibre!\n");
	}
}

void ingresarLibreta(int *libreta){
	printf("Ingresar libreta del alumno (%d = fin): ",CENTINELA);
	scanf("%d",libreta);
}
void ingresarNotas(float *p1, float *p2){
	printf("Ingresar las notas de los 2 parciales, separadas por coma: ");
	scanf("%f,%f",p1,p2);
}

