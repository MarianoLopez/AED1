/* Archivo cabecera ".h"
3.2. Un registro de libros de una biblioteca posee los siguientes campos: ISBN (identificaci�n del libro),
T�tulo de la obra, Autor/es, A�o de edici�n, Editorial. Declarar este registro y luego realizar la
declaraci�n de una variable de este tipo.
*/

struct libro{
	char isbn[11];/*10+ \0*/
	char titulo[100];
	char autores[100];
	int anioEdicion;
	char editorial[30];
};
typedef struct libro Libro;/*declarar Libro como un nuevo tipo de datos, a partir de la estructura libro*/

void imprimirLibro(Libro *);

void imprimirLibro(Libro *l){
	
	printf("\n\tISBN: %s\n\tTitulo: %s\n\tAutores: %s\n\tAnio de edicion: %d\n\tEditorial: %s\n",
	l->isbn,l->titulo,l->autores,l->anioEdicion,l->editorial);
}
