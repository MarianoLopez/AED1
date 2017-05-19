#include<stdio.h>
main(){
	FILE *file; /* Puntero del tipo FILE */
	char _char; /*variable para almacenar el car�cter leido del archivo*/
	
	file = fopen("prueba.txt","r");/*Abre el archivo en modo lectura */
	
	if(file == NULL){/*null resulta ser un valor especial aplicado a un puntero (o referencia) usado para indicar que no se apunta a un objeto o dato v�lidos*/
	   printf("Error abriendo el archivo");
	   return -1;
	}else{
		printf("Contenidos del archivo:\n-----------------------\n" );
		_char = fgetc(file);/*leer 1 car�cter del archivo*/
		
		/*La funci�n feof() se utiliza para detectar cuando no quedan m�s elementos en un archivo, devolviendo un valor distinto de cero en este caso. */
		while (feof(file) == 0) { /* mientras no sea fin de archivo*/
			printf( "%c",_char); /*imprmir car�cter leido*/
			_char = fgetc(file);
		}
		
		fclose(file); /*Cierra el archivo*/
		return 0;
	}

}

