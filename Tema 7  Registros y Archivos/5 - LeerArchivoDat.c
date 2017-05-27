#include <stdio.h>
/* declara prototipo de las funciones */
void leerDatos(FILE *fichero,int *cantLeidos);
void finDatos(FILE *fichero,int *cantLeidos);

/* registro de alumno */
struct registro {
	int dni,codCar,codSex,edad;
};

typedef struct registro Alumno;/*definir la estructura registro como un nuevo tipo de datos "Alumno"*/



int main(){
	FILE *fichero = fopen("Alumnos.dat", "rb");/*puntero del tipo FILE*/
	int cantLeidos = 0;/*contador*/
	
	if(fichero != NULL){/*verificar que exista el archivo Alumnos.dat. NULL es valor especial aplicado a un puntero (o referencia) usado para indicar que no se apunta a un objeto o dato válidos*/
		leerDatos(fichero,&cantLeidos);
		finDatos(fichero,&cantLeidos);
		return 0;
	}else{
		printf("Error abriendo archivo");
		return -1;
	}
}

void leerDatos(FILE *fichero,int *cantLeidos) {
	Alumno alumno; /*variable local del tipo Alumno, ver typedef*/
	/*fread (puntero, longitud, numelem, fich);
		Dónde:
			puntero es un puntero a la zona de memoria donde se va a iniciar la transferencia.
			longitud es el tamaño N en bytes de cada elemento a transferir.
			numelem es el número k de elementos a transferir
			fich es el puntero al archivo que se utiliza para la transferencia.
		Para transferir registros de un archivo, la longitud se determina aplicando el operador sizeof a la estructura 
		que devuelve el número de bytes que la compone, y en numelem el valor 1 dado que se desea transferir una estructura*/
	fread(&alumno, sizeof(alumno), 1, fichero);/* lee primer registro del archivo alumnos */
	printf("Documento\tCarrera\tSexo\tEdad");
	while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
		printf( "\n%d" "\t\t%i" "\t%i" "\t%i\n", alumno.dni, alumno.codCar,alumno.codSex, alumno.edad);
		fread(&alumno,sizeof(alumno), 1, fichero);
		*cantLeidos+=1;
	}
}

void finDatos(FILE *fichero,int *cantLeidos){
	printf("\nLa cantidad de registros leidos fue: %i", *cantLeidos);
	fclose(fichero);/*cerrar archivo*/
}
