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
#include <stdlib.h>/*gesti�n de memoria din�mica https://es.wikipedia.org/wiki/Stdlib.h*/
#include <stdbool.h>/*Boolean*/
#include "Libro.h"/*eje 3_2*/

#define ARCHIVO "libros.dat"/*Archivo a utilizar*/
#define ARRAYSIZE 4 /*tama�o del arreglo de ejemplo*/

/*prototipos*/
bool grabarLibro(Libro*);/*Graba libro al final del archivo, devuelve true al efectuar la escritura*/
void agregarLibro();/*Solicitar libro al usuario y grabarlo al final del archivo*/
Libro *leerLibros();/*Devuelve un puntero de libros leidos desde el archivo*/
int getLibrosSize();/*Devuelve la cantidad de libros que contiene el archivo*/
void imprimirTotales(Libro *libros, int size);/*Calcula e imprime totales solicitados por el enunciado*/
void eliminarArchivo();/*Eliminar archivo .dat*/
Libro *inicializarArreglo();/*C no permite retornar arreglos, pero si punteros. Ejemplo*/

int main(){
	int respuesta = 1;
	while(respuesta!=0){
		printf("************************************Menu************************************\n");
		printf("\t 1 - Crear/Agregar libro\n");
		printf("\t 2 - Imprimir listado de libros\n");
		printf("\t 3 - Ejemplo estatico\n");
		printf("\t 4 - Eliminar archivo\n");
		printf("\t 0 - Salir\n");
		printf("Ingresar opcion: ");
		scanf("%d",&respuesta);
		Libro *libros;/*puntero auxiliar para poder utilizar la funci�n free en el caso 2*/
		switch(respuesta){
			case 1:
				agregarLibro();
				break;
			case 2:
				libros = leerLibros();
				imprimirTotales(libros,getLibrosSize());
				free(libros);/*libera el bloque de memoria especificada de nuevo al sistema*/
				break;
			case 3:
				imprimirTotales(inicializarArreglo(),ARRAYSIZE);
				
				break;
			case 4:
				eliminarArchivo();
				break;
		}
	}
	return 0;
}

void agregarLibro(){
	Libro libro = solicitarLibro();
	if(grabarLibro(&libro)){
		printf("Libro: %s, aniadido con exito\n",libro.titulo);	
	}else{
		printf("Error al grabar en el archivo: %s\n",ARCHIVO);
	}
	printf("Precionar tecla para continuar\n");
	getch();
}

void imprimirTotales(Libro *libros, int size){
	int indice; /*para el bucle for*/
	int antiguedad; /*del libro*/
	/*contadores*/
	int contadorRecientes = 0;
	int contadorEntre2y5 = 0;
	int contador5mayor = 0;
	printf("Listado de libros:");
	for(indice=0;indice<size;indice++){
		imprimirLibro((libros+indice));
		antiguedad = getAntiguedad((libros+indice)->anioEdicion);
		printf("\tAntiguedad: %d anios\n",antiguedad);
		/*decidir contador a incrementar*/
		if(antiguedad<=2){
			contadorRecientes++;/*equivalente a contadorRecientes+=1*/
		}else if(antiguedad > 2 && antiguedad <5){
			contadorEntre2y5++;
		}else{
			contador5mayor++;
		}
	}
	printf("\nLibros: %d\n",size);
	printf("Libros recientes (hasta 2 anios inclusive): %d\n",contadorRecientes);
	printf("Libros con antiguedad mayor a 2 y menor a 5: %d\n",contadorEntre2y5);
	printf("Libros con 5 o mas anios de antiguedad: %d\n",contador5mayor);
	printf("Precionar tecla para continuar\n");
	getch();
}

int getLibrosSize(){
	FILE *fichero = fopen(ARCHIVO,"rb");
	int librosSize = 0;
	if(fichero!=NULL){
		fseek(fichero, 0, SEEK_END); /* fseek sets the file position of the stream to the given offset. SEEK_SET	Beginning of file;SEEK_CUR	Current position of the file pointer;SEEK_END	End of file*/
		librosSize = ftell(fichero)/sizeof(Libro);/*ftell returns the current file position of the given stream.*/
		fclose(fichero);
	}
	return librosSize;
}

Libro *leerLibros(){
	int size = getLibrosSize();/*cantidad de libros en el archivo*/
	static Libro *libros;
	libros = malloc(size * sizeof(Libro));/*asigna el n�mero especificado de bytes https://es.wikipedia.org/wiki/Malloc*/
	int index = 0;
	FILE *fichero = fopen(ARCHIVO,"rb");
	if(fichero!=NULL){
		fread((libros+index),sizeof(Libro),1,fichero);/*(libros+index) = mover puntero*/
		while(!feof(fichero)){
			index++;
			fread((libros+index),sizeof(Libro),1,fichero);
		}
		fclose(fichero);
	}else{
		printf("Error al intentar abrir el archivo %s\n",ARCHIVO);
	}
	return libros;
}

bool grabarLibro(Libro *libro){
	bool guardado = false;
	FILE *fichero = fopen(ARCHIVO,"ab");/*append*/
	if(fichero!=NULL){
		fwrite(libro,sizeof(*libro),1,fichero);
		fclose(fichero);	
		guardado = true;
	}
	return guardado;
}

void eliminarArchivo(){
   /*int remove(const char *filename)*/
   if(!remove(ARCHIVO)){
      printf("Archivo %s eliminado correctamente\n",ARCHIVO);
   }else {
      printf("Error al intentar eliminar el archivo %s\n",ARCHIVO);
   }
}

/*Ejemplo*/
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
		{"XXXXXXXXX","A Dance with Dragons","George R. R. Martin",2014,"Bantam Spectra"},
		{"XXXXXXXXX","The Winds of Winter","George R. R. Martin",2017,"Bantam Spectra"}
	};/*arreglo est�tico del tipo Libro, con longitud (ARRAYSIZE) = 4*/
	return libros;
}
