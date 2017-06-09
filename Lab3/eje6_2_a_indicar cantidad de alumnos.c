/*
a) Modificar el programa del ejercicio 6.2, utilizando como indicador de finalización una respuesta del
usuario que indique si existen más alumnos para procesar.
*/
#include <stdio.h>
int main(){
	float nota, promedioAprobados;
	int contadorAlumnosAprobados = 0;
	float acumuladorAprobados = 0.0;
	char respuestaUsuario;
	
	printf("Existen alumnos por procesar (S/N)?:\n");
	scanf("%c",&respuestaUsuario);
	while(respuestaUsuario=='S'||respuestaUsuario=='s'){
		printf("Ingrese la nota:\n");
		scanf("%f",&nota);
		if(nota>=6){
			contadorAlumnosAprobados++;
			acumuladorAprobados+=nota;
		}
	printf("Existen alumnos por procesar (S/N)?:\n");
	/*limpiar buffer*/
	fflush(stdin);
	scanf("%c",&respuestaUsuario);
	}

	promedioAprobados = acumuladorAprobados/contadorAlumnosAprobados;
	printf("\nPromedio de notas del primer parcial de AEDI (aprobados): %.2f\n",promedioAprobados);
	printf("Cantidad de alumnos aprobados: %d",contadorAlumnosAprobados);
	return 0;
}
