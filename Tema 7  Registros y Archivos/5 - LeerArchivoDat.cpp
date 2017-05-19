#include <stdio.h>
#include <stdbool.h>
/* declara prototipo de las funciones */
bool abrirArchivo();
void leerDatos();
void finDatos();

/* registro de alumno */
struct registro {
	int dni,codCar,codSex,edad;
} regalum;

FILE *fichero;/*puntero del tipo FILE*/
int cantLeidos;/*contador*/

int main(){
	cantLeidos=0;
	if(abrirArchivo()){
		leerDatos();
		finDatos();	
		return 0;
	}else{
		printf("Error abriendo archivo");
		return -1;
	}
	
	
}

bool abrirArchivo() {
	fichero = fopen("Alumnos.dat", "rb");/* Abre un archivo binario para lectura */
	return (fichero != NULL);/*verificar si Alumnos.dat existe*/
}

void leerDatos() {
	/*fread (puntero, longitud, numelem, fich);
		Dónde:
			puntero es un puntero a la zona de memoria donde se va a iniciar la transferencia.
			longitud es el tamaño N en bytes de cada elemento a transferir.
			numelem es el número k de elementos a transferir
			fich es el puntero al archivo que se utiliza para la transferencia.
		Para transferir registros de un archivo, la longitud se determina aplicando el operador sizeof a la estructura 
		que devuelve el número de bytes que la compone, y en numelem el valor 1 dado que se desea transferir una estructura*/
	fread(&regalum, sizeof(struct registro), 1, fichero);/* lee primer registro del archivo alumnos */
	printf("Documento\tCarrera\tSexo\tEdad");
	while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
		printf( "\n%d" "\t%i" "\t%i" "\t%i\n", regalum.dni, regalum.codCar,regalum.codSex, regalum.edad);
		fread(&regalum,sizeof(struct registro), 1, fichero);
		cantLeidos=cantLeidos + 1;
	}
}

void finDatos(){
	printf("\nLa cantidad de registros leidos fue: %i", cantLeidos);
	fclose(fichero);/*cerrar archivo*/
}
