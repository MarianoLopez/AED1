/* Archivo cabecera ".h"
3.2. Un registro de libros de una biblioteca posee los siguientes campos: ISBN (identificaci�n del libro),
T�tulo de la obra, Autor/es, A�o de edici�n, Editorial. Declarar este registro y luego realizar la
declaraci�n de una variable de este tipo.
*/
#include <time.h>/*necesario para recuperar a�o actual, otra opci�n ser�a declarar una constante (#define ANIOACTUAL 2017)*/
struct libro{
	char isbn[11];/*10+ \0*/
	char titulo[100];
	char autores[100];
	int anioEdicion;
	char editorial[30];
};
typedef struct libro Libro;/*declarar Libro como un nuevo tipo de datos, a partir de la estructura libro*/

void imprimirLibro(Libro *);
Libro solicitarLibro();
int getAntiguedad(int anio);


int getAntiguedad(int anio){
	time_t t = time(NULL);/*time.h*/
	struct tm tm = *localtime(&t);/*time.h*/
	return (tm.tm_year + 1900)-anio;/*a�o actual - anio "parametro"*/
}

Libro solicitarLibro(){
	Libro libro;
	fflush(stdin);
	printf("Ingresar ISBN: ");
	scanf("%s",&libro.isbn);
	fflush(stdin);
	printf("Ingresar Titulo: ");
	scanf("%[^\n]s",&libro.titulo);
	fflush(stdin);
	printf("Ingresar Autor: ");
	scanf("%[^\n]s",&libro.autores);
	printf("Ingresar Anio de edicion: ");
	scanf("%d",&libro.anioEdicion);
	fflush(stdin);
	printf("Ingresar Editorial: ");
	scanf("%[^\n]s",&libro.editorial);
	return libro;
}

void imprimirLibro(Libro *l){
	
	printf("\n\tISBN: %s\n\tTitulo: %s\n\tAutores: %s\n\tAnio de edicion: %d\n\tEditorial: %s\n",
	l->isbn,l->titulo,l->autores,l->anioEdicion,l->editorial);
}
