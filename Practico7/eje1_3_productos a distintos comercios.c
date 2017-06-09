/*
1.3. Una compañía distribuye los productos a distintos comercios de la ciudad. Para ello almacena
en un archivo de 2.000 registros toda la información relacionada a su mercadería:
	Código sucursal
	Código del producto.
	Descripción del producto
	Stock: cantidad que se mantiene del producto.
	Stock mínimo: cantidad mínima de los productos a mantener en bodega.
a) Determinar el tipo de dato para cada caso y el tamaño.
b)Proponer campo clave simple, campos claves compuestos. Justificar en cada caso.
c) Calcular la longitud del registro.
d)Teniendo en cuenta que el medio donde se almacenará este archivo posee sectores
de 512 bytes, calcular el factor de bloqueo.*/

#include <stdio.h>

struct producto{
	int codSucursal,codProducto,stock,stockMinimo;
};
/*(int 4bytes)*4variables =  16 bytes.
	Clave primaria simple = codProducto (el mismo producto tendrá códigos diferentes para cada sucursal),
	Clave primaria compuesta codSucursal+codProducto (mismo código de producto para las diferentes sucursales)*/
			  
typedef struct producto Producto; /*declarar la estructura producto, como un tipo de dato "Producto"*/

/*c)
Se denomina “factor de bloqueo” a la cantidad de registros lógicos que se pueden guardar en un registro físico. Se calcula de la siguiente manera:
Factor de bloqueo = Tamaño del sector / Longitud del registro lógico
El factor de bloqueo es el resultado truncado (sin decimales) de la división. Por ejemplo, si el
registro físico es de 512 y la longitud del registro es 50 bytes, del resultado 10,24 se toma
solamente 10.

FB = 512bytes/16bytes = 32 registros en cada bloque
accesos a disco = registros/factor de bloqueo -> 2.000/32 = 62,5 = 63 accesos a disco para leer el archivo.
Considerando que una PC puede tener un tiempo medio de accesos de 90 milisegundos.
	90ms*63accesos = 5670ms = 5,67segundos. 
*/
void ejemploEscrituraBinaria();/*Escribir 10 registros aleatorios*/
void ejemploLecturaBinaria();/*Leer los 10 registros*/
FILE *CrearArchivoMercaderias();
FILE *abrirArchivoMercaderias();
void cerrarArchivo(FILE *);
void grabarProducto(Producto *p,FILE *f);/*grabar producto en archivo*/
void leerProducto(Producto *p,FILE *f);/*leer producto desde archivo*/
void imprimirProducto(Producto *p);

int main(){
	ejemploEscrituraBinaria();
	ejemploLecturaBinaria();
	return 0;
}
FILE *CrearArchivoMercaderias(){
	return fopen("mercaderia.dat", "wb");/* crea/abre archivo binario para escritura*/
}
FILE *abrirArchivoMercaderias(){
	return fopen("mercaderia.dat", "rb");/* Abre un archivo binario para lectura */
}
void cerrarArchivo(FILE *fichero){
	fclose(fichero);
}

void grabarProducto(Producto *p,FILE *fichero){
	fwrite(p, sizeof(*p), 1, fichero);/*puntero del tipo Producto, sizeof(producto"* contenido"), elementos a transferir, puntero del tipo FILE*/
}

void leerProducto(Producto *p,FILE *fichero){
	fread(p,sizeof(*p), 1, fichero);/*puntero del tipo Producto, sizeof(producto"* contenido"), elementos a transferir, puntero del tipo FILE*/
}

void imprimirProducto(Producto *producto){
	printf( "\n%d" "\t\t%i" "\t\t%i" "\t\t%i\n",
	  producto->codSucursal,/*el operador "->"flecha/arrow es utilizado para acceder a miembros de una estructura a través de un puntero*/
	  producto->codProducto,
	  producto->stock,
	  producto->stockMinimo);
}

void ejemploEscrituraBinaria(){
	Producto producto;
	FILE *fichero = CrearArchivoMercaderias();
	int i;
	/*grabar 10 registros aleatorios*/
	for(i=1;i<=10;i++){
		if(i<=5){
			producto.codSucursal=1;
		}else{
			producto.codSucursal=2;
		}
		producto.codProducto=i;
		producto.stock=5*i;
		producto.stockMinimo=2*i;
		grabarProducto(&producto,fichero);
	}
	cerrarArchivo(fichero);
}

void ejemploLecturaBinaria(){
	Producto producto;
	FILE *fichero = abrirArchivoMercaderias();
	if(fichero != NULL){/*verificar si mercaderia.dat existe*/
		printf("codSucursal\tcodProducto\tstock\tstockMinimo");
		leerProducto(&producto,fichero);
		while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
			imprimirProducto(&producto);
			leerProducto(&producto,fichero);
		}
		cerrarArchivo(fichero);
	}else{
		printf("Error al abrir archivo");
	}
}
