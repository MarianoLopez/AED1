/*
5.5. Procesar los datos de los libros de una biblioteca, utilizando el registro definido en el punto 3.2,
para obtener la siguiente información:
a. Los datos de cada libro: ISBN, Título, Autor/es, Año de edición, Antigüedad del libro
(Año actual – Año de edición).
b. El total de libros de la biblioteca, el total de libros recientes (hasta 2 años (inclusive)
de antigüedad), el total de libros de más de 2 y menos de 5 años de antigüedad y el
total de libros con 5 o más años de antigüedad.
*/

#include <stdio.h>
#include <time.h>/*necesario para recuperar año actual, otra opción sería declarar una constante (#define ANIOACTUAL 2017)*/
#include "Libro.h"/*eje 3_2*/

#define ARRAYSIZE 4 /*tamño del arreglo*/

/*prototipos*/
Libro *inicializarArreglo();/*C no permite retornar arreglos, pero si punteros*/
int getAntiguedad(int anio);

int main(){
	Libro *libros = inicializarArreglo();
	
	int indice;
	int antiguedad;
	int contadorRecientes = 0;
	int contadorEntre2y5 = 0;
	int contador5mayor = 0;
	printf("Listado de libros:");
	for(indice=0;indice<ARRAYSIZE;indice++){
		imprimirLibro((libros+indice));
		antiguedad = getAntiguedad((libros+indice)->anioEdicion);
		printf("\tAntiguedad: %d anios\n",antiguedad);
		/*decidir cual contador incrementar*/
		if(antiguedad<=2){
			contadorRecientes++;/*equivalente a contadorRecientes+=1*/
		}else if(antiguedad > 2 && antiguedad <5){
			contadorEntre2y5++;
		}else{
			contador5mayor++;
		}
	}
	printf("\nLibros: %d\n",ARRAYSIZE);
	printf("Libros recientes (hasta 2 anios inclusive): %d\n",contadorRecientes);
	printf("Libros con antiguedad mayor a 2 y menor a 5: %d\n",contadorEntre2y5);
	printf("Libros con 5 o mas anios de antiguedad: %d\n",contador5mayor);
	return 0;
}

int getAntiguedad(int anio){
	time_t t = time(NULL);/*time.h*/
	struct tm tm = *localtime(&t);/*time.h*/
	return (tm.tm_year + 1900)-anio;/*año actual - anio "parametro"*/
}
Libro *inicializarArreglo(){
/*El siguiente problema es que C, no permite devolver direcciones de memoria de variables locales fuera de la función,
por ende necesitamos utilizar una variable estática. https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm*/
/*una variable estática es una variable que ha sido ubicada estáticamente y cuyo tiempo de vida se extiende durante toda la ejecución del programa.
Normalmente una variable estática tiene un ámbito más amplio que otras variables. 
Los valores de variables estáticas se pueden establecer una vez (durante el tiempo de ejecución) o se pueden cambiar en múltiples ocasiones durante la ejecución del programa*/
	static Libro libros[ARRAYSIZE]= {
		/*{ISBN (identificación del libro),Título de la obra, Autor/es, Año de edición, Editorial} -> inicialización de 1 Libro dentro del arreglo*/
		{"8471664577","Don Quijote De La Mancha","Miguel de Cervantes Saavedra",1980,"Edaf"},
		{"XXXXXXXXX","A Clash of Kings","George R. R. Martin",1998,"Bantam Spectra"},
		{"XXXXXXXXX","A Dance with Dragons","George R. R. Martin",2011,"Bantam Spectra"},
		{"XXXXXXXXX","The Winds of Winter","George R. R. Martin",2017,"Bantam Spectra"}
	};/*arreglo estático del tipo Libro, con longitud (ARRAYSIZE) = 4*/
	return libros;
}
