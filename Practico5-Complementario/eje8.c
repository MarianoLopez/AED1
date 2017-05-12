/*
8) La empresa DESPEGAR.COM, cuenta con la siguiente información:
	Nro de Venta,Código de Servicio (00-Hoteles, 01-Vuelos, 02-Paquetes, 03-Autos),
	Código Destino (A-Argentina, B-Brasil, P-Paraguay, P-Perú), Cantidad vendida.
Realice un algoritmo que permita:
	a) Mostrar por pantalla los servicios de Vuelos a Perú.
	b) Calcular la cantidad de servicios vendidos con destino Brasil y calcular que porcentaje representa sobre el total de servicios.
Se indicará el fin del programa ingresando ´X´ en Destino. 
*/
#include <stdio.h>
int main(){
	/*Código para verificar la ejecución del algoritmo*/
	int codigoServicio, cantidadVendida;
	char destino;
	int nroVenta = 0;
	
	int acumuladorServiciosBrasil = 0;
	int acumuladorServiciosVendidos = 0;
	
	printf("Ingresar Destino (A-Argentina, B-Brasil, U-Uruguay, P-Perú, X- fin del programa): ");
	scanf("%c",&destino);
	while(destino!='X'&&destino!='x'){
		
		printf("Ingresar Código de Servicio (0-Hoteles, 1-Vuelos, 2-Paquetes, 3-Autos): ");
		scanf("%d",&codigoServicio);
		
		printf("Ingresar cantidad vendida: ");
		scanf("%d",&cantidadVendida);
		
		nroVenta++;
		acumuladorServiciosVendidos+=cantidadVendida;
		if((destino=='P'||destino=='p')&&(codigoServicio==1)){/*Mostrar por pantalla los servicios de Vuelos a Perú.*/
			printf("\nVuelo a Perú, nro.venta: %d, cantidad vendida: %d\n\n",nroVenta,cantidadVendida);
		}
		
		if(destino=='B'||destino=='b'){/*Calcular la cantidad de servicios vendidos con destino Brasil*/
			acumuladorServiciosBrasil+=cantidadVendida;
		}
	
		fflush(stdin);
		printf("Ingresar Destino (A-Argentina, B-Brasil, U-Uruguay, P-Perú, X- fin del programa): ");
		scanf("%c",&destino);
	}/*fin while*/
	
	
	/*
		b) calcular que porcentaje representa sobre el total de servicios.
	*/
	printf("\nCantidad de servicios vendidos: %d\n",acumuladorServiciosVendidos);
	printf("\nCantidad de servicios vendidos con destino Brasil: %d\n",acumuladorServiciosBrasil);
	printf("\nPorcentaje de servicios vendidos con destino Brasil: %%%.2f\n",(acumuladorServiciosBrasil/(float)acumuladorServiciosVendidos)*100);
	return 0;
}
