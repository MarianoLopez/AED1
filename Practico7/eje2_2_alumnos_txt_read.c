/*2.2. Realizar un algoritmo (en seudo o en C), que lea el archivo de texto generado en el ejercicio anterior y visualice por pantalla cada registro del archivo. */
#include<stdio.h>
void imprimirArchivo(FILE *file,int *registrosLeidos);

int main(){
	FILE *file = fopen("Alumnos_eje1_5.txt","r");/*Abre el archivo en modo lectura */
	int registrosLeidos = 0;
	
	imprimirArchivo(file,&registrosLeidos);
	printf("\nLa cantidad de registros leidos es: %d",registrosLeidos);
	return 0;
	
}
void imprimirArchivo(FILE *file,int *registrosLeidos){
	if(file == NULL){/*null resulta ser un valor especial aplicado a un puntero (o referencia) usado para indicar que no se apunta a un objeto o dato válidos*/
	   printf("Error abriendo el archivo");
	}else{
		printf("Contenido del archivo:\n-----------------------\n" );
		char _char; /*variable para almacenar el carácter leido del archivo*/
		/*La función feof() se utiliza para detectar cuando no quedan más elementos en un archivo, devolviendo un valor distinto de cero en este caso. */
		while (!feof(file)) { /* mientras no sea fin de archivo*/
			_char = fgetc(file);/*leer 1 carácter del archivo y mueve el puntero interno al siguiente carácter del archivo*/
			printf( "%c",_char); /*imprmir carácter leido*/
			if(_char == ';'){/*el fin de cada línea era ";"*/
				*registrosLeidos+=1;
			}
		}
		fclose(file); /*Cierra el archivo*/
	}
}
