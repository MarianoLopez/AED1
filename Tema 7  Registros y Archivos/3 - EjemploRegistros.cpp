#include<stdio.h>
main(){
	struct alumno { /* Define el registro alumnos */
		int dni;
		float parcial1;
		float parcial2;
		float promedio;
	} regalumno;
	
	/* completa datos del registro */
	printf("dni alumno: ");
	scanf("%i", &(regalumno.dni));
	printf("nota parcial 1: ");
	scanf("%f", &(regalumno.parcial1));
	printf("nota parcial 2: ");
	scanf("%f", &(regalumno.parcial2));
	printf("\n");
	
	/* Calcula el promedio de notas */
	regalumno.promedio=(regalumno.parcial1+regalumno.parcial2)/2;
	printf("Promedio de %i: es %.2f", regalumno.dni, regalumno.promedio);
	return 0;
}
