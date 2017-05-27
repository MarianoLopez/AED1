/*
4. Procesando datos con archivos binarios (.dat):
4.1. Dado un archivo de alumnos de FACENA cuyo diseño de registro es el del punto 3.1, se desea
obtener un listado de los inscriptos a la LSI, informar cuántos alumnos son y qué porcentaje
representan sobre el total de alumnos inscriptos de toda la Facultad.
*/
#include <stdio.h>
#include "Alumno.h"/*Archivo cabecera de eleboración propia, ver Alumno.h*/

#define ARCHIVO "alumnosIngresantes.dat"

void menu(int *respuesta);
void agregarAlumno();
void imprimirListado();
void eliminarArchivo();

int main(){
	int respuesta;
	menu(&respuesta);
	while(respuesta!=0){
		menu(&respuesta);	
	}	
	return 0;
}
void menu(int *respuesta){
	printf("************************************Menu************************************\n");
	printf("\t 1 - Crear/Agregar alumno ingresante al archivo\n");
	printf("\t 2 - Imprimir lista de alumnos ingresantes desde el archivo\n");
	printf("\t 3 - Eliminar el archivo de alumnos ingresantes\n");
	printf("\t 0 - Salir\n");
	printf("Ingresar opcion: ");
	scanf("%d",respuesta);
	switch(*respuesta){
		case 1:
			agregarAlumno();
			break;
		case 2:
			imprimirListado();
			break;
		case 3:
			eliminarArchivo();
			break;	
	}
}
void agregarAlumno(){
	FILE *fichero = fopen(ARCHIVO, "ab");/*a = modo adjuntar, posiciona el puntero del archivo al final, en caso de no exitir el archivo, lo creará*/
	if(fichero != NULL){/*verificar si el archivo existe*/
		Alumno alumno = getAlumno();
		fwrite(&alumno, sizeof(alumno), 1, fichero);
		fclose(fichero);
	}else{
		printf("Error al abrir archivo: %s\n",ARCHIVO);
	}
}

void imprimirListado(){
	FILE *fichero = fopen(ARCHIVO, "rb");
	if(fichero != NULL){/*verificar si el archivo existe*/
		printf("****Listado de alumnos ingresantes de FaCENA****\n");
		Alumno alumno;
		fread(&alumno,sizeof(alumno), 1, fichero);
		while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
			imprimirAlumno(&alumno);
			fread(&alumno,sizeof(alumno), 1, fichero);
		}
		fclose(fichero);
	}else{
		printf("Error al abrir archivo: %s\n",ARCHIVO);
	}
}

void eliminarArchivo(){
   /*int remove(const char *filename)*/
   if(!remove(ARCHIVO)){
      printf("Archivo %s eliminado correctamente\n",ARCHIVO);
   }else {
      printf("Error al intentar eliminar el archivo %s\n",ARCHIVO);
   }
}
