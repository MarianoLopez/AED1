/*4. Procesando datos con archivos binarios (.dat):
4.1. Dado un archivo de alumnos de FACENA cuyo diseño de registro es el del punto 3.1, se desea
obtener un listado de los inscriptos a la LSI, informar cuántos alumnos son y qué porcentaje
representan sobre el total de alumnos inscriptos de toda la Facultad.*/
#include <stdio.h>
#include "Alumno.h"/*Archivo cabecera de eleboración propia, ver Alumno.h*/

#define ARCHIVO "alumnosIngresantes.dat"
/*prototipos*/
void menu(int *respuesta);
void agregarAlumno();
void imprimirListado();
void eliminarArchivo();
void eje4_2();
void eje4_3();
void eje4_4();

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
	printf("\t 4 - Ejercicio 4.2\n");
	printf("\t 5 - Ejercicio 4.3\n");
	printf("\t 6 - Ejercicio 4.4\n");
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
		case 4:
			eje4_2();
			break;
		case 5:
			eje4_3();
			break;
		case 6:
			eje4_4();
			break;
	}
}
void agregarAlumno(){
	FILE *fichero = fopen(ARCHIVO, "ab");/*a = modo adjuntar, posiciona el puntero del archivo al final, en caso de no exitir el archivo, lo creará*/
	if(fichero != NULL){/*verificar si el archivo existe*/
		Alumno alumno = getAlumno();/*crear alumno a partir de datos ingresados por teclado, ver Alumno.h*/
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
		}/*fin while*/
		fclose(fichero);        
	}else{
		printf("Error al abrir archivo: %s\n",ARCHIVO);
	}
}
void eje4_4(){
	/*4.4. Con los mismos datos del ejercicio anterior, calcular el promedio de edades de los alumnos
	varones de la LSI. Informar el total de alumnos varones de la LSI y el promedio de edades*/
	FILE *fichero = fopen(ARCHIVO, "rb");
	int contadorVaronesLSI = 0;
	int acumuladorVaronesEdades= 0;
	if(fichero != NULL){/*verificar si el archivo existe*/		
		Alumno alumno;
		fread(&alumno,sizeof(alumno), 1, fichero);
		while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
			if(alumno.sexo==1&&alumno.codCarrera==18){
				contadorVaronesLSI+=1;
				acumuladorVaronesEdades+=alumno.edad;
			}
			fread(&alumno,sizeof(alumno), 1, fichero);
		}/*fin while*/
		fclose(fichero);
		printf("***4.4***\n\tTotal de alumnos varones en LSI: %d\n",contadorVaronesLSI);
		printf("\tPromedio de edades: %d\n",acumuladorVaronesEdades/contadorVaronesLSI);
	}else{
		printf("Error al abrir archivo: %s\n",ARCHIVO);
	}
}
void eje4_3(){
	/*4.3. Con los mismos datos del ejercicio anterior, contar la cantidad de alumnos inscriptos en las
	carreras Bioquímica, LSI y Agrimensura y determinar qué carrera tiene la mayor cantidad de
	alumnos. */
	FILE *fichero = fopen(ARCHIVO, "rb");
	int contadorBio = 0;
	int contadorLSI = 0;
	int contadorAgri= 0;
	if(fichero != NULL){/*verificar si el archivo existe*/		
		Alumno alumno;
		fread(&alumno,sizeof(alumno), 1, fichero);
		while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
			switch(alumno.codCarrera){
				case 18:
					contadorLSI+=1;
					break;
				case 28:
					contadorBio+=1;
					break;
				case 20:
					contadorAgri+=1;
					break;
			}
			fread(&alumno,sizeof(alumno), 1, fichero);
		}/*fin while*/
		fclose(fichero);
		printf("***4.3***\n\tTotal de alumnos Bioquimica: %d\n",contadorBio);
		printf("\tTotal de alumnos LSI: %d\n",contadorLSI);
		printf("\tTotal de alumnos Agrimensura: %d\n",contadorAgri);
		printf("\tla carrera con mayor cantidad de alumnos es: ");
		if(contadorBio>=contadorLSI && contadorBio>=contadorAgri){
			printf("Bioquimica\n");
		}else if (contadorLSI>=contadorBio && contadorLSI>=contadorAgri){
			printf("LSI\n");
		}else{
			printf("Agrimensura\n");
		}      
	}else{
		printf("Error al abrir archivo: %s\n",ARCHIVO);
	}
}

void eje4_2(){
	/*4.2. Con los mismos datos del ejercicio anterior, determinar cuántas mujeres menores de 25 años
	estudiarán la carrera de Ing. Electrónica. Informar el total y el porcentaje que representan sobre
	el total de mujeres de todas las carreras. Detectar la mujer con menor edad, mostrar al final DNI
	y edad.*/
	FILE *fichero = fopen(ARCHIVO, "rb");
	int contadorMujeres = 0;
	int cMujeresIngElectronicaM25 = 0;/*contador de mujeres menores a 25años que estudian Ing Electrónica*/
	/*variables para almacenar la mujer con menor edad*/
	int menorEdadm = 999;
	Alumno mujerMenorEdad;
	if(fichero != NULL){/*verificar si el archivo existe*/
		Alumno alumno;
		fread(&alumno,sizeof(alumno), 1, fichero);
		while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
			if(alumno.sexo==2){/*mujer*/
				contadorMujeres+=1;
				if(alumno.edad<menorEdadm){/*detectar menor*/
					menorEdadm=alumno.edad;
					mujerMenorEdad = alumno;
				}
				if(alumno.codCarrera==29 && alumno.edad<25){/*Ing.electrónica y menor a 25*/
					cMujeresIngElectronicaM25+=1;
				}
			}
			fread(&alumno,sizeof(alumno), 1, fichero);
		}/*fin while*/
		fclose(fichero);
		printf("***4.2***\n\tTotal de mujeres: %d\n",contadorMujeres);
		printf("\tTotal de mujeres menores de 25 años que estudiaran la carrera de Ing. Electronica: %d\n",cMujeresIngElectronicaM25);
		printf("\tPorcentaje sobre el total de mujeres: %%%.2f\n",(cMujeresIngElectronicaM25/(float)contadorMujeres)*100);
		printf("\tLa mujer con menor edad es:\n");
		imprimirAlumno(&mujerMenorEdad);
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
