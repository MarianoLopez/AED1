/*
2. Procesando datos con archivos de texto (.txt):
2.1. Realizar un algoritmo (en seudo o en C) que permita grabar un archivo de texto con datos de
alumnos contenidos en una línea de texto que se ingresa por teclado. 
Cada línea contiene los siguientes datos: 
	DNI, nombre del alumno y finaliza con “;”.
Ingresar por teclado la cantidad de alumnos cuyos datos se registran.
Informar al final la cantidad de registros grabados.*/

#include <stdio.h>
#include <string.h>/*necesario para utilizar strcat,strcpy,strlen,strcmp,strchr y strstr*/

void setCantidad(int *cantidad);/*Solicita al usuario la cantidad de alumnos a registrar y lo almacena a través del puntero*/
void ingresarDatos(int *dni, char (*nombre)[]);/*Solicita al usuario dni y nombre; char (*)[] = puntero a un array de char, necesidad del operador de precedencia() para indicar que es un puntero. Más información en: http://unixwiz.net/techtips/reading-cdecl.html*/
void grabarLinea(FILE *fichero, int *dni, char (*nombre)[],int *contadorRegistrosGrabados);

int main(){
 	/*En programación se denomina vector-arreglo/array a una zona de almacenamiento contiguo que contiene una serie de elementos del mismo tipo. Más información en: https://www.tutorialspoint.com/cprogramming/c_arrays.htm*/
 	/*En C, el tipo de dato String no existe por defecto, son representados como un arreglo de caracteres, que terminan con un caracter  null '\0' para indicar su fin. Más información en : https://www.tutorialspoint.com/cprogramming/c_strings.htm*/
 	char nombre[30];/*Arreglo del tipo char de tamaño 30 "también conocido como String", sintaxis: tipo de dato nombre de la variable [tamaño]*/
 	
	int cantIngresar,i, dni;
	int contadorRegistrosGrabados = 0;
	FILE *fichero = fopen("Alumnos_eje1_5.txt", "w"); /*puntero del tipo FILE*/
 	
 	setCantidad(&cantIngresar);
 	
 	for(i=0;i<cantIngresar;i++){
 		ingresarDatos(&dni,&nombre);
 		grabarLinea(fichero,&dni,&nombre,&contadorRegistrosGrabados);
 	}
	
	fclose(fichero);/*cierre de archivo*/
	/*Notar que se podría utilizar la variable cantIngresar para saber la cantidad de registros grabados pero, si el programa no puede escribir la línea en el archivo "ej: se eliminó el archivo durante la ejecución del programa" ese número sería erróneo, por ende se utiliza un contador a parte el cual verifica la escritura antes de incrementarse.*/
	printf("La cantidad de registros grabados es: %d",contadorRegistrosGrabados);
	return 0;
}

void setCantidad(int *cantidad){
	printf("Ingresar la cantidad de alumnos a registrar: ");
 	scanf("%d",cantidad);
}

void ingresarDatos(int *dni, char (*nombre)[]){
	printf("Ingresar DNI: ");
	scanf("%d",dni);
	fflush(stdin);/*necesario al ingresar multiples nombres separados por espacio*/
	printf("Ingresar Nombre: ");
	/*[] = expresión regular (https://es.wikipedia.org/wiki/Expresi%C3%B3n_regular), ^ = representa el inicio de la cadena, \ = Se utiliza para escapar el siguiente carácter de la expresión de búsqueda */
	scanf("%[^\n]s",nombre);/*[^\n] acepta cualquier String omitiendo \n, de esta forma "nombre" admite espacios en blanco "omitidos por defecto"*/
	fflush(stdin);/*necesario al ingresar multiples nombres separados por espacio*/
}

void grabarLinea(FILE *fichero, int *dni, char (*nombre)[],int *contadorRegistrosGrabados){
	if(fichero!=NULL){
		char stringCompleto[50];
		sprintf(stringCompleto,"%d", *dni);/*convertir (cast) entero a String (array de chars)*/
		strcat(stringCompleto,", ");/*concatenar nombre a stringCompleto. Ej: stringCompleto = 36194445, ", " -> resultado stringCompleto=36194445, */
 		strcat(stringCompleto,*nombre);
 		strcat(stringCompleto,";\n");
 		fputs(stringCompleto, fichero);/*La función fputs() escribe la cadena a un archivo especifico*/	
 		*contadorRegistrosGrabados+=1;/*incrementar en 1 el contador*/
	}else{
		printf("Error abriendo archivo");
	}
}
