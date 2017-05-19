#include <stdio.h>

/* declara prototipo de las funciones */
void ingresaRespuesta();
void grabarDatos();
void finDatos();

/* declara el registro con datos del alumno */
struct registro {
	int dni,codCar,codSex,edad;
} regalum;


FILE *fichero; /*puntero del tipo FILE*/

int cantGrabados;/*contador*/
int respuestaUsuario;
int main(){
cantGrabados=0;
	fichero = fopen("Alumnos.dat", "wb");/* crea/abre archivo binario para escritura*/
	ingresaRespuesta();
	grabarDatos();
	finDatos();
	return 0;
}
void ingresaRespuesta(){
	printf("Desea ingresar datos al archivo? Si=1 No=0: ");
	scanf("%i", &respuestaUsuario);
}
void grabarDatos(){
	while(respuestaUsuario){
		printf("Ingrese dni del alumno: ");
		scanf("%i",&regalum.dni);
		printf("Ingrese Codigo de carrera: ");
		scanf("%i",&regalum.codCar);
		printf("Digite el Codigo de sexo: ");
		scanf("%i",&regalum. codSex);
		printf("Ingrese la edad: ");
		scanf("%i",&regalum.edad);
		
		/*fwrite (puntero, longitud, numelem, fich);
		Dónde:
			puntero es un puntero a la zona de memoria donde se va a iniciar la transferencia.
			longitud es el tamaño N en bytes de cada elemento a transferir.
			numelem es el número k de elementos a transferir
			fich es el puntero al archivo que se utiliza para la transferencia.
		Para transferir registros de un archivo, la longitud se determina aplicando el operador sizeof a la estructura 
		que devuelve el número de bytes que la compone, y en numelem el valor 1 dado que se desea transferir una estructura*/
		
		fwrite(&regalum, sizeof(struct registro), 1, fichero);/* graba el registro en el archivo indicado */
		
		cantGrabados= cantGrabados + 1;/* incrementa en 1 contador de registros grabados */
		ingresaRespuesta();
	}/*fin while*/
}

void finDatos(){
	printf("Cantidad de registros grabados: %i\n", cantGrabados);
	fclose(fichero);/*cerrar archivo*/
}
