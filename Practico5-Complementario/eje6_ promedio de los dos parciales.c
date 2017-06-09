/*
6) Se ingresa por tecla los siguientes datos de alumnos del Algoritmo y Estructura de Datos I:
	 DNI, Nota 1� parcial, Nota 2� parcial y Porcentaje de Asistencia.
Realice un algoritmo que permita calcular el promedio de los dos parciales e informe con una leyenda las siguientes situaciones:
	a) si el promedio es menor que 6 �debe recuperar�,
	b) si el promedio es menor que 7 y mayor o igual a 6, informe �regulariz� y
	c) si el promedio es mayor o igual a 7 y la asistencia es superior al 80% informe �promocion�.
Adem�s, contar e informar cu�ntos alumnos deben recuperar.
Se indicar� fin del programa ingresando 0 (cero) en el DNI.
Al final, mostrar el porcentaje de alumnos que promocionaron.
*/
#include <stdio.h>
int main(){
	/*C�digo para verificar la ejecuci�n del algoritmo*/
	int dni,porcentajeAsistencia;
	float notaParcial1,notaParcial2;
	
	float promedioParcial;
	int contadorAlumnos = 0;
	int contadorPromociono = 0;
	int contadorDebeRecuperar = 0;

	printf("Ingresar DNI (0 para finalizar): ");
	scanf("%d",&dni);
	while(dni!=0){
		
		printf("Ingresar nota del primer parcial: ");
		scanf("%f",&notaParcial1);
		
		printf("Ingresar nota del segundo parcial: ");
		scanf("%f",&notaParcial2);
		
		printf("Ingresar porcentaje de asistencia: ");
		scanf("%d",&porcentajeAsistencia);
		
		contadorAlumnos++;

		promedioParcial = (notaParcial1+notaParcial2)/2;
		printf("Promedio del alumno: %.2f\n",promedioParcial);
		
		if(promedioParcial<6.0){/*si el promedio es menor que 6 �debe recuperar�,*/
			printf("debe recuperar\n");
			contadorDebeRecuperar++;
		}
		
		if(promedioParcial>=6.0 && promedioParcial<7.0){/*si el promedio es menor que 7 y mayor o igual a 6, informe �regulariz�*/
			printf("regulariz�\n");
		}
		
		if(promedioParcial>=7.0 && porcentajeAsistencia>80){ /*si el promedio es mayor o igual a 7 y la asistencia es superior al 80% informe �promocion�.*/
			printf("promocion�\n");	
			contadorPromociono++;
		}
	
		printf("Ingresar DNI (0 para finalizar): ");
		scanf("%d",&dni);
	}/*fin while*/
	
	
	/*informar cu�ntos alumnos deben recuperar.
	mostrar el porcentaje de alumnos que promocionaron.*/
	printf("\nCantidad de alumnos: %d\n",contadorAlumnos);
	printf("\nCantidad de alumnos que deben recuperdar: %d\n",contadorDebeRecuperar);
	printf("\nCantidad de alumnos que promocionaron: %d\n",contadorPromociono);
	printf("\nPorcentaje de alumnos que promocionaron: %%%.2f\n",(contadorPromociono/(float)contadorAlumnos)*100);
	return 0;
}

