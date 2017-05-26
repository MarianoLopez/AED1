#include<stdio.h>
main(){
	FILE *file; /* Puntero del tipo FILE */
	char _char; /*variable para almacenar el carácter leido del archivo*/
	
	file = fopen("prueba.txt","r");/*Abre el archivo en modo lectura */
	
	if(file == NULL){/*null resulta ser un valor especial aplicado a un puntero (o referencia) usado para indicar que no se apunta a un objeto o dato válidos*/
	   printf("Error abriendo el archivo");
	   return -1;
	}else{
		printf("Contenidos del archivo:\n-----------------------\n" );
		_char = fgetc(file);/*leer 1 carácter del archivo*/
		
		/*La función feof() se utiliza para detectar cuando no quedan más elementos en un archivo, devolviendo un valor distinto de cero en este caso. */
		while (feof(file) == 0) { /* mientras no sea fin de archivo*/
			printf( "%c",_char); /*imprmir carácter leido*/
			_char = fgetc(file);
		}
		
		fclose(file); /*Cierra el archivo*/
		return 0;
	}

}

