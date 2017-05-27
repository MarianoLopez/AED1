#include <stdio.h>

/* declara prototipo de las funciones */
/*Utilización de punteros para evitar las variables globales*/
void ingresaRespuesta(int *respuesta);/*asigna en el puntero la respuesta del usuario para el ingreso de datos*/
void grabarDatos(FILE *fichero,int *respuesta, int *contador);/*Verifica la respuesta del usuario, en caso afirmativo procede a solicitar los datos del alumnos, incrementar el contador y grabar el archivo*/
void finDatos(FILE *fichero, int *contador);/*Cierra el archivo "puntero" e imprime el contador*/

/* declara el registro con datos del alumno */
struct registro {
	int dni,codCar,codSex,edad;
};

typedef struct registro Alumno;/*declara la estructura registro, como un nuevo tipo de datos "Alumno"*/



int main(){
	/*variables locales*/
	FILE *fichero; /*puntero del tipo FILE*/
	int respuestaUsuario;
	int cantGrabados=0;	/*contador*/
	
	fichero = fopen("Alumnos.dat", "wb");/* crea/abre archivo binario para escritura*/
	
	ingresaRespuesta(&respuestaUsuario);/*& = dirección de memoria*/
	grabarDatos(fichero,&respuestaUsuario,&cantGrabados);
	finDatos(fichero,&cantGrabados);
	
	return 0;
}
void ingresaRespuesta(int *respuestaUsuario){
	printf("Desea ingresar datos al archivo? Si=1 No=0: ");
	scanf("%i", respuestaUsuario);/*dado que respuestaUsuario ya es una dirección de memoria, no necesita &*/
}
void grabarDatos(FILE *fichero,int *respuestaUsuario, int *cantGrabados){
	while(*respuestaUsuario){/* int *respuestaUsuario = puntero del tipo int, *respuestaUsuario = contenido del puntero*/
		Alumno alumno; /*variable local del tipo Alumno,"notar la necesitad del typedef previo"*/
		printf("Ingrese dni del alumno: ");
		scanf("%i",&alumno.dni);
		printf("Ingrese Codigo de carrera: ");
		scanf("%i",&alumno.codCar);
		printf("Digite el Codigo de sexo: ");
		scanf("%i",&alumno.codSex);
		printf("Ingrese la edad: ");
		scanf("%i",&alumno.edad);
		
		/*fwrite (puntero, longitud, numelem, fich);
		Dónde:
			puntero es un puntero a la zona de memoria donde se va a iniciar la transferencia.
			longitud es el tamaño N en bytes de cada elemento a transferir.
			numelem es el número k de elementos a transferir
			fich es el puntero al archivo que se utiliza para la transferencia.
		Para transferir registros de un archivo, la longitud se determina aplicando el operador sizeof a la estructura 
		que devuelve el número de bytes que la compone, y en numelem el valor 1 dado que se desea transferir una estructura*/
		
		fwrite(&alumno, sizeof(alumno), 1, fichero);/* graba el registro (del tipo Alumno) en el archivo indicado */
		
		*cantGrabados+=1;/* incrementa en 1 contador de registros grabados */
		ingresaRespuesta(respuestaUsuario);
	}/*fin while*/
}

void finDatos(FILE *fichero, int *cantGrabados){
	printf("Cantidad de registros grabados: %i\n", *cantGrabados);
	fclose(fichero);/*cerrar archivo*/
}
