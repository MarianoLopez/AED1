/*
1.1. Definir los campos necesarios para conformar un registro de: alumnos de la FaCENA (Facultad
de Ciencias Exactas y Naturales y Agrimensura), y otro de películas de un video club.
1.2. Para cada registro del punto anterior:
	Determinar el tipo y el tamaño de cada campo
	Calcular la longitud del registro.
*/
#include<stdio.h>

/*definicion de registros*/
struct alumno { /* Define el registro alumno*/
	int dni; /*int 4 bytes*/
	int libreta;/*int 4 bytes*/
};/*total 8 bytes*/

typedef struct alumno Alumno;/*declarar la estructura alumno, como un tipo de dato "Alumno"*/

struct pelicula { /* Define el registro película*/
	int codPelicula;/*int 4 bytes*/
	float precio;/*float 4 bytes*/
	int stock;/*int 4 bytes*/
};/*total 12 bytes*/

typedef struct pelicula Pelicula;/*declarar la estructura pelicula, como un tipo de dato "Pelicula"*/

/*prototipos*/
void cargarAlumnoPorReferencia(Alumno *a);/*puntero del tipo Alumno, notar la necesidad del typedef previo*/
void cargarAlumnoPorValor(Alumno a);
void imprimirAlumno(Alumno *a);
void cargarPelicula(Pelicula *p);/*puntero del tipo Pelicula, notar la necesidad del typedef previo*/
void imprimirPelicula(Pelicula *p);

int main(){	
	/*declarar variables locales*/
	Alumno alum1,alum2;
	Pelicula pelicula;
	
	printf("Struct ByRef:\n");
	cargarAlumnoPorReferencia(&alum1);
	imprimirAlumno(&alum1);
	
	printf("\nStruct ByVal:\n");
	/*Notar como las modificaciones solo afecta al objeto creado dentro de la función y luego el objeto es destruido por ser local a la función*/
	cargarAlumnoPorValor(alum2);
	imprimirAlumno(&alum2);
	
	cargarPelicula(&pelicula);
	imprimirPelicula(&pelicula);
	return 0;
}

void cargarAlumnoPorReferencia(Alumno *a){
	a->dni = 36194445;/*el operador "->"flecha/arrow es utilizado para acceder a miembros de una estructura a través de un puntero*/
	a->libreta = 45842;
	printf("**Dentro de cargarAlumnoPorReferencia()**\n");
	imprimirAlumno(a);
	printf("**Fuera de cargarAlumnoPorReferencia()**\n");
}

void cargarAlumnoPorValor(Alumno a){
	a.dni = 36194446;
	a.libreta = 45846;
	printf("**Dentro de cargarAlumnoPorValor()**\n");
	imprimirAlumno(&a);
	printf("**Fuera de cargarAlumnoPorValor()**\n");
}

void imprimirAlumno(Alumno *a){
	printf("\tDni: %d\n",a->dni);
	printf("\tLibreta: %d\n",a->libreta);
}

void cargarPelicula(Pelicula *p){
	p->codPelicula = 55;
	p->precio = 75.88;
	p->stock = 25;
}
void imprimirPelicula(Pelicula *p){
	printf("\n**Imprimir Pelicula**\n");
	printf("\tPelicula codigo: %d\n",p->codPelicula);
	printf("\tPrecio: %.2f\n",p->precio);
	printf("\tStock: %d\n",p->stock);
}
