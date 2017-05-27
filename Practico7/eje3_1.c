/*
Declaración de datos tipo REGISTRO
3.1. Declarar un registro de alumnos Ingresantes de FACENA que contenga los siguientes campos:
DNI, Cod de Carrera, Cod. Sexo, Edad. Luego crear una variable de este tipo Alumno. Los códigos
de los campos son:
Carreras:
	18. Lic. en Sistemas de Información (LSI)
	19. Lic. en Cs. Biológicas
	20. Agrimensura
	28. Bioquímica
	29. Ing. Electrónica
Sexo:
	1. Varón
	2. Muj
*/
#include <stdio.h>

struct alumno{int dni,codCarrera,sexo,edad;};/*definición de la estructura alumno*/
typedef struct alumno Alumno;/*declarar nuevo tipo de datos "Alumno" a partir de la estrucutra "alumno"*/

Alumno getAlumno();/*devuelve una variable del tipo Alumno a partir de los datos ingresados por teclado*/
void imprimirAlumno(Alumno *);
void verificarCodCarrera(int *codCarrera);/*verificar que el CodCarrera sea válido, caso contrario solicitar su nuevo ingreso*/
void verificarSexo(int *sexo);/*verificar que el sexo sea válido, caso contrario solicitar su nuevo ingreso*/

int main(){
	Alumno alumno = getAlumno();
	imprimirAlumno(&alumno);
	return 0;
}

void imprimirAlumno(Alumno *alumno){
	printf("Alumno:\n\tDNI: %d\n\tCarrera: %d\n\tSexo: %d\n\tEdad: %d\n",
		alumno->dni,/*el operador "->"flecha/arrow es utilizado para acceder a miembros de una estructura a través de un puntero*/
		alumno->codCarrera,
		alumno->sexo,
		alumno->edad);
}
Alumno getAlumno(){
	Alumno alumno;/*variable local del tipo Alumno*/
	printf("Ingresar DNI: ");
	scanf("%d",&alumno.dni);
	printf("Ingresar Codigo de Carrera: ");
	scanf("%d",&alumno.codCarrera);
	verificarCodCarrera(&alumno.codCarrera);
	printf("Ingresar sexo (1. Varon 2. Muj): ");
	scanf("%d",&alumno.sexo);
	verificarSexo(&alumno.sexo);
	printf("Ingresar edad: ");
	scanf("%d",&alumno.edad);
	return alumno;
}
void verificarCodCarrera(int *codCarrera){
	/*Mientras el codCarrera sea distinto a 18,19,20,28 o 29 hacer..*/
	while(*codCarrera!=18&&*codCarrera!=19&&*codCarrera!=20&&*codCarrera!=28&&*codCarrera!=29){
		printf("Carrera no valida\n");
		printf("\tIngresar Codigo de Carrera: ");
		scanf("%d",codCarrera);
	}
}

void verificarSexo(int *sexo){
	/*Mientras el sexo sea distinto a 1 o 2 hacer..*/
	while(*sexo!=1&&*sexo!=2){
		printf("Sexo no valido\n");
		printf("\tIngresar sexo (1. Varon 2. Muj): ");
		scanf("%d",sexo);
	}
}

