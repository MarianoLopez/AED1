/*Modo 	Significado
r 		Abre un archivo de texto para lectura
w 		Crea un archivo de texto para escritura
a 		Abre un archivo de texto para a�adir
rb 		Abre un archivo binario para lectura
wb 		Crea un archivo binario para escritura
ab 		Abre un archivo binario para a�adir*/
#include <stdio.h>
int main(){
 	FILE* fichero; /*puntero del tipo FILE*/
 	
	fichero = fopen("prueba.txt", "w"); /*apertura/creaci�n del archivo en modo escritura*/
	
	fputs("Esta es una l�nea\n", fichero);/*La funci�n fputs() escribe la cadena a un archivo especifico*/
	fputs("Esta es otra linea\n", fichero);
	fputs("y esta es continuaci�n de la anterior\n", fichero);
	
	fclose(fichero);/*cierre de archivo*/
	
	printf("Archivo prueba.txt creado");
	return 0;
}

