/*
4) Un colegio privado necesita procesar información de sus alumnos, para ello solicita los siguientes datos: 
	DNI del Alumno, Nivel escolar (1–Inicial, 2-Primaria, 3-Secundaria), 
    Importe de la cuota, tiene hermanos (S-SÍ, N-NO).
Diseñe un algoritmo que procese los datos de todos los alumnos y permita:
	a. Bonificar el importe de la cuota con un 10% a los alumnos que tengan hermanos, mostrar en pantalla sus datos y el importe bonificado.
	b. Informar la cantidad de alumnos que hay en el nivel inicial.
El proceso finalizará cuando el DNI sea igual 0.
*/
#include <stdio.h>
#define bonificacion 0.10
int main(){
	/*Código para verificar la ejecución del algoritmo*/
	int dni,nivelEscolar;
	float cuotaImporte;
	char tieneHermanos;
	
	float beneficioPorHermanos;
	int contadorAlumnosNivelInicial = 0;
	
	printf("Ingresar DNI del alumno (0 para finalizar): ");
	scanf("%d",&dni);
	while(dni!=0){
		
		printf("Ingresar Nivel escolar (1–Inicial, 2-Primaria, 3-Secundaria): ");
		scanf("%d",&nivelEscolar);
		
		printf("Ingresar importe de la cuota: ");
		scanf("%f",&cuotaImporte);
		
		fflush(stdin);
		printf("Tiene hermanos (S-SI, N-NO)?: ");
		scanf("%c",&tieneHermanos);

		/*a. Bonificar el importe de la cuota con un 10% a los alumnos que tengan hermanos, mostrar en pantalla sus datos y el importe bonificado.*/
		if(tieneHermanos=='S'||tieneHermanos=='s'){
			beneficioPorHermanos = cuotaImporte * bonificacion;
			printf("Dni: %d, Nivel escolar: %d, cuota: $%.2f, hermanos: %c\n",dni,nivelEscolar,cuotaImporte,tieneHermanos);
			printf("Importe bonificado: $%.2f\n",beneficioPorHermanos);
			cuotaImporte-= beneficioPorHermanos;
			printf("Total a pagar: $%.2f\n",cuotaImporte);
		}
		
		/*b. Cantidad de alumnos que hay en el nivel inicial.*/
		if(nivelEscolar == 1){
			contadorAlumnosNivelInicial++;
		}
		
		printf("Ingresar DNI del alumno (0 para finalizar): ");
		scanf("%d",&dni);
	}/*fin while*/
	/*b. Informar la cantidad de alumnos que hay en el nivel inicial.*/
	printf("\nCantidad de alumnos en nivel inicial: %d\n",contadorAlumnosNivelInicial);
	return 0;
}
