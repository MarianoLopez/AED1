/*Archivo cabecera Alumno.h*/
struct alumno{int dni,codCarrera,sexo,edad;};/*definición de la estructura alumno*/
typedef struct alumno Alumno;/*declarar nuevo tipo de datos "Alumno" a partir de la estrucutra "alumno"*/

Alumno getAlumno();/*devuelve una variable del tipo Alumno a partir de los datos ingresados por teclado*/
void imprimirAlumno(Alumno *);
void verificarCodCarrera(int *codCarrera);/*verificar que el CodCarrera sea válido, caso contrario solicitar su nuevo ingreso*/
void verificarSexo(int *sexo);/*verificar que el sexo sea válido, caso contrario solicitar su nuevo ingreso*/


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
