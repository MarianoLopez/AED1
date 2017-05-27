/*Modo 	Significado
r 		Abre un archivo de texto para lectura
w 		Crea un archivo de texto para escritura
a 		Abre un archivo de texto para añadir
rb 		Abre un archivo binario para lectura
wb 		Crea un archivo binario para escritura
ab 		Abre un archivo binario para añadir*/
#include <stdio.h>
int main(){
 	FILE* fichero; /*puntero del tipo FILE*/
 	
	fichero = fopen("prueba.txt", "w"); /*apertura/creación del archivo en modo escritura*/
	
	fputs("Esta es una línea\n", fichero);/*La función fputs() escribe la cadena a un archivo especifico*/
	fputs("Esta es otra linea\n", fichero);
	fputs("y esta es continuación de la anterior\n", fichero);
	
	fclose(fichero);/*cierre de archivo*/
	
	printf("Archivo prueba.txt creado");
	return 0;
}

