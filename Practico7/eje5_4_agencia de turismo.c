/*
5.4. Procesar los datos de la agencia de turismo, utilizando el registro definido en el punto 5.3, para obtener la siguiente información:
a. Datos de los pasajeros que viajaron a destinos extranjeros y pagaron con tarjeta.
b. Total, de importe facturado en concepto de viajes al extranjero y porcentaje de esta
recaudación con respecto al total de importes recaudados por la agencia.
*/
#include <stdio.h>
#include "Pasajero.h"/*eje5_3*/

#define ARRAYSIZE 3 /*tamño del arreglo*/
/*prototipos*/
Pasajero *inicializarArreglo();/*C no permite retornar arreglos, pero si punteros*/
void recorrerArrayOpcionA(Pasajero *);
void recorrerArrayOpcionB(Pasajero *);
void detectarViajeExtranjeroConTarjeta(Pasajero *,float *);/*imprimir datos en caso de ser viaje al extranjero abonado con tarjeta y acomular el total abonado*/
void imprimirTotal(float *,float *);

int main(){
	Pasajero *pasajeros = inicializarArreglo();
	printf("****Opcion A***\n");
	recorrerArrayOpcionA(pasajeros);
	printf("\n\n***Opcion B***\n");
	recorrerArrayOpcionB(pasajeros);
	return 0;
}
void detectarViajeExtranjeroConTarjeta(Pasajero *p, float *acumulador){
	if(p->destino==2&&p->formaPago==2){/*extranjero y tarjeta*/
		*acumulador+=p->precioViaje;/*acomular valor del viaje para conocer el total*/
		printf("Viaje al extranjero pagado con tarjeta:");
		imprimirPasajero(p);/*ver Pasajero.h*/
	}
}
void imprimirTotal(float *total,float *extranjero){
	printf("Importe total facturado en concepto de viajes: $%.2f\n",*total);
	printf("Importe total facturado en concepto de viajes al extranjero abonados con tarjeta: $%.2f\n",*extranjero);
	printf("Porcentaje de esta recaudación con respecto al total: %.2f%%\n",(*extranjero/ *total)*100);
}

/*Opción más optima, utiliza en su totalidad el puntero sin generar más variables*/
void recorrerArrayOpcionA(Pasajero *pasajeros){
	int indice;
	float acomuladorTotal = 0;
	float acomuladorExtranjeroTarjeta = 0;
	for(indice=0;indice<ARRAYSIZE;indice++){
		acomuladorTotal+=(pasajeros+indice)->precioViaje;/*acomular el valor de todos los viajes*/
		detectarViajeExtranjeroConTarjeta((pasajeros+indice),&acomuladorExtranjeroTarjeta);
	}
	imprimirTotal(&acomuladorTotal,&acomuladorExtranjeroTarjeta);
}

/*Creación de una variable local del tipo Pasajero para almacenar el contenido el puntero*/
void recorrerArrayOpcionB(Pasajero *pasajeros){
	int indice;
	Pasajero p;
	float acomuladorTotal = 0;
	float acomuladorExtranjeroTarjeta = 0;
	for(indice=0;indice<ARRAYSIZE;indice++){
		p = *(pasajeros + indice);/*Copiar el contenido del puntero a la variable local "p"*/
		acomuladorTotal+=p.precioViaje;/*notar el "." en lugar de "->" por no ser puntero*/
		detectarViajeExtranjeroConTarjeta(&p,&acomuladorExtranjeroTarjeta);
	}
	imprimirTotal(&acomuladorTotal,&acomuladorExtranjeroTarjeta);
}

Pasajero *inicializarArreglo(){
/*El siguiente problema es que C, no permite devolver direcciones de memoria de variables locales fuera de la función,
por ende necesitamos utilizar una variable estática. https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm*/
/*una variable estática es una variable que ha sido ubicada estáticamente y cuyo tiempo de vida se extiende durante toda la ejecución del programa.
Normalmente una variable estática tiene un ámbito más amplio que otras variables. 
Los valores de variables estáticas se pueden establecer una vez (durante el tiempo de ejecución) o se pueden cambiar en múltiples ocasiones durante la ejecución del programa*/
	static Pasajero pasajeros[ARRAYSIZE]= {
		/*{dni,apeynom,destino(1-nacional,2-extranjero),precio,formaPago(1-efectivo, 2-tarjeta)} -> inicialización de 1 Pasajero dentro del arreglo*/
		{36194445,"Lopez,Mariano",2,1000.33,2},
		{34693548,"Villa,Emanuel",2,2000.99,2},
		{12345678,"Lopez,Alejandro",1,500.50,1}
	};/*arreglo estático del tipo Pasajero, con longitud (ARRAYSIZE) = 3*/
	return pasajeros;
}
