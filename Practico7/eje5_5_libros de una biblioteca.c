/*
5.5. Procesar los datos de los libros de una biblioteca, utilizando el registro definido en el punto 3.2,
para obtener la siguiente informaci�n:
a. Los datos de cada libro: ISBN, T�tulo, Autor/es, A�o de edici�n, Antig�edad del libro
(A�o actual � A�o de edici�n).
b. El total de libros de la biblioteca, el total de libros recientes (hasta 2 a�os (inclusive)
de antig�edad), el total de libros de m�s de 2 y menos de 5 a�os de antig�edad y el
total de libros con 5 o m�s a�os de antig�edad.
*/

#include <stdio.h>
#include <time.h>/*necesario para recuperar a�o actual, otra opci�n ser�a declarar una constante (#define ANIOACTUAL 2017)*/
#include "Libro.h"/*eje 3_2*/

#define ARRAYSIZE 4 /*tam�o del arreglo*/

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
	return (tm.tm_year + 1900)-anio;/*a�o actual - anio "parametro"*/
}
Libro *inicializarArreglo(){
/*El siguiente problema es que C, no permite devolver direcciones de memoria de variables locales fuera de la funci�n,
por ende necesitamos utilizar una variable est�tica. https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm*/
/*una variable est�tica es una variable que ha sido ubicada est�ticamente y cuyo tiempo de vida se extiende durante toda la ejecuci�n del programa.
Normalmente una variable est�tica tiene un �mbito m�s amplio que otras variables. 
Los valores de variables est�ticas se pueden establecer una vez (durante el tiempo de ejecuci�n) o se pueden cambiar en m�ltiples ocasiones durante la ejecuci�n del programa*/
	static Libro libros[ARRAYSIZE]= {
		/*{ISBN (identificaci�n del libro),T�tulo de la obra, Autor/es, A�o de edici�n, Editorial} -> inicializaci�n de 1 Libro dentro del arreglo*/
		{"8471664577","Don Quijote De La Mancha","Miguel de Cervantes Saavedra",1980,"Edaf"},
		{"XXXXXXXXX","A Clash of Kings","George R. R. Martin",1998,"Bantam Spectra"},
		{"XXXXXXXXX","A Dance with Dragons","George R. R. Martin",2011,"Bantam Spectra"},
		{"XXXXXXXXX","The Winds of Winter","George R. R. Martin",2017,"Bantam Spectra"}
	};/*arreglo est�tico del tipo Libro, con longitud (ARRAYSIZE) = 4*/
	return libros;
}
