/*
3.2 Con el objeto de conseguir fondos para su viaje de egresados, los alumnos de 6to. a�o organizaron un baile.
 	El precio de las entradas es de $100 con una consumici�n y de $80 sin consumici�n.
 	Si la venta es anticipada, se realiza un descuento del 20% al valor de la entrada. 
	Escriba un programa en C que solicite por teclado el tipo de entrada (1-con consumici�n, 2-sin consumici�n) 
	y un car�cter que indique si la venta fue anticipada (�S�) o no (�N�) y muestre por pantalla el tipo de entrada y el importe a pagar.
Nota: prestar atenci�n al ingreso de datos de tipo CHAR.
*/
#include <stdio.h>
/*constantes*/
#define entradaConConsumicion 100
#define entradaSinConsumicion 80
#define descuentoAnticipada 0.20
int main(){
	int tipoEntrada;
	char ventaAnticipada;
	int importe;
	
	printf("Ingrese el tipo de entrada (1-con consumici�n, 2-sin consumici�n):\n");
	scanf("%d",&tipoEntrada);
	printf("Indique si la venta es anticipada S/N:\n");
	/*limpiar buffer de entrada*/
	fflush(stdin);
	scanf("%c",&ventaAnticipada);
	
	if(tipoEntrada==1){
		/*con consumici�n*/
		importe = entradaConConsumicion;
		printf("Tipo de entrada: Con consumici�n ($%d)\n",entradaConConsumicion);
	}else{
		/*sin consumici�n*/
		importe = entradaSinConsumicion;
		printf("Tipo de entrada: Sin consumici�n ($%d)\n",entradaSinConsumicion);
	}
	
	if(ventaAnticipada=='S'||ventaAnticipada=='s'){
		/*equivalente a importe = importe - (importe * descuentoAnticipada)*/
		importe -= (importe*descuentoAnticipada);
		/*(descuentoAnticipada*100) = 0.20*100 = (int)20.00 --> 20*/
		printf("Venta anticipada (descuento del %d%%)\n",(int)(descuentoAnticipada*100));
	}
	
	printf("Total a pagar: $%d",importe);
	return 0;
}
