/*
3.2 Con el objeto de conseguir fondos para su viaje de egresados, los alumnos de 6to. año organizaron un baile.
 	El precio de las entradas es de $100 con una consumición y de $80 sin consumición.
 	Si la venta es anticipada, se realiza un descuento del 20% al valor de la entrada. 
	Escriba un programa en C que solicite por teclado el tipo de entrada (1-con consumición, 2-sin consumición) 
	y un carácter que indique si la venta fue anticipada (“S”) o no (“N”) y muestre por pantalla el tipo de entrada y el importe a pagar.
Nota: prestar atención al ingreso de datos de tipo CHAR.
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
	
	printf("Ingrese el tipo de entrada (1-con consumición, 2-sin consumición):\n");
	scanf("%d",&tipoEntrada);
	printf("Indique si la venta es anticipada S/N:\n");
	/*limpiar buffer de entrada*/
	fflush(stdin);
	scanf("%c",&ventaAnticipada);
	
	if(tipoEntrada==1){
		/*con consumición*/
		importe = entradaConConsumicion;
		printf("Tipo de entrada: Con consumición ($%d)\n",entradaConConsumicion);
	}else{
		/*sin consumición*/
		importe = entradaSinConsumicion;
		printf("Tipo de entrada: Sin consumición ($%d)\n",entradaSinConsumicion);
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
