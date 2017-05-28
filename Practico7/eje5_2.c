/*
5.2. Realizar un algoritmo (en seudo o en C), que lea un archivo de texto que contiene, en cada l�nea,
los siguientes datos de clientes de un banco, separados por �,�: N�mero de cuenta, nombre del
cliente. Grabar un nuevo archivo de texto que almacene la misma informaci�n. Iterar la entrada
de datos hasta que el operador indique que no existen m�s datos. Visualizar al final la cantidad
de registros grabados.*/
#include <stdio.h>
#include <string.h>
/*prototipos*/
void cargarClientesEnArchivo();
void solicitarCliente(int *nroCuenta, char(*nombreCliente)[]);
void grabarCliente(int *nroCuenta, char(*nombreCliente)[],FILE *fichero);
void leerYgrabarNuevoArchivo();
void escribirNuevoArchivo();
/*constantes*/
#define ARCHIVO "clientesBanco.txt"
#define ARCHIVONUEVO "clientesBancoNuevo.txt"

int main(){
	/*cargarClientesEnArchivo();*/ /*Ejecutar la primera vez para generar el archivo de clientes*/
	leerYgrabarNuevoArchivo();
	return 0;
}
void leerYgrabarNuevoArchivo(){
	FILE *fichero = fopen(ARCHIVO,"r");
	if(fichero!=NULL){
		FILE *ficheroNuevo = fopen(ARCHIVONUEVO,"w");
		char respuestaUsuario;
		char _char; /*variable para almacenar el car�cter leido del archivo*/
		printf("Desea leer una linea del archivo? s/n: ");
		scanf("%c",&respuestaUsuario);
		while(respuestaUsuario!='n'&&respuestaUsuario!='N'){
			char linea[50];/*String auxiliar para almacenar l�nea le�da*/
			int indice = 0;
			_char = fgetc(fichero);/*leer 1 car�cter del archivo*/
			/*La funci�n feof() se utiliza para detectar cuando no quedan m�s elementos en un archivo, devolviendo un valor distinto de cero en este caso. */
			if(!feof(fichero)) { /* si no es el fin de archivo*/
				while(_char!='\n'){/*detectamos nueva l�nea con \n*/
					linea[indice]=_char;/*a�adir char al string*/
					indice+=1;/*incrementar indice*/
					_char = fgetc(fichero);
				}
				linea[indice]='\0';/*finalizador*/
				printf("Contenido: %s\n",linea);
				strcat(linea,"\n");/*concatenar*/
				fputs(linea,ficheroNuevo);
				fflush(stdin);
				printf("Desea leer una linea del archivo? s/n: ");
				scanf("%c",&respuestaUsuario);
			}else{
				respuestaUsuario='n';
				printf("EOF");
			}
		}/*fin while*/
		fclose(fichero);
		fclose(ficheroNuevo);
	}else{
		printf("Error abriendo archivo");
	}
}
void cargarClientesEnArchivo(){
	FILE *file = fopen(ARCHIVO,"a");
	if(file!=NULL){
		char respuestaUsuario;
		int nroCuenta;
		char nombreCliente[50];
		printf("Desea cargar un nuevo cliente? s/n: ");
		scanf("%c",&respuestaUsuario);
		while(respuestaUsuario!='n'&&respuestaUsuario!='N'){
			solicitarCliente(&nroCuenta, &nombreCliente);
			grabarCliente(&nroCuenta, &nombreCliente,file);
			printf("Desea cargar un nuevo cliente? s/n: ");
			scanf("%c",&respuestaUsuario);
		}	
	}else{
		printf("Error abriendo archivo");
	}
}

void solicitarCliente(int *nroCuenta, char(*nombreCliente)[]){
	printf("Ingresar numero de cuenta: ");
	scanf("%d",nroCuenta);
	fflush(stdin);/*necesario al ingresar multiples nombres separados por espacio*/
	printf("Ingresar Nombre: ");
	/*[] = expresi�n regular (https://es.wikipedia.org/wiki/Expresi%C3%B3n_regular), ^ = representa el inicio de la cadena, \ = Se utiliza para escapar el siguiente car�cter de la expresi�n de b�squeda */
	scanf("%[^\n]s",nombreCliente);/*[^\n] acepta cualquier String omitiendo \n, de esta forma "nombre" admite espacios en blanco "omitidos por defecto"*/
	fflush(stdin);/*necesario al ingresar multiples nombres separados por espacio*/
}

void grabarCliente(int *nroCuenta, char(*nombreCliente)[], FILE *fichero){
	char stringCompleto[50];
	sprintf(stringCompleto,"%d", *nroCuenta);/*convertir (cast) entero a String (array de chars)*/
	strcat(stringCompleto,", ");/*concatenar nombre a stringCompleto. Ej: stringCompleto = 36194445, ", " -> resultado stringCompleto=36194445, */
	strcat(stringCompleto,*nombreCliente);
	strcat(stringCompleto,"\n");
	fputs(stringCompleto, fichero);/*La funci�n fputs() escribe la cadena a un archivo especifico*/	
}


