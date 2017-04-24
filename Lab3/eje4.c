/*
4. ALTERNATIVA M�LTIPLE
4.1. Una farmacia emite un ticket de compra en funci�n de la cantidad y precio del producto vendido, y el
tipo de producto: �P�, �F� o �L� (P �Perfumer�a, F-Farmacia y L-Limpieza).
Escriba un programa en C para calcular el valor de la compra, aplicando una bonificaci�n de acuerdo al tipo de producto: 
�P�:5%, �F�: 10%, �L�: 15%.
Imprimir el importe a pagar y el porcentaje de bonificaci�n, con la leyenda �%bonificado: XX�.
*/
#include <stdio.h>
/*constantes*/
#define bonificacionP 0.05
#define bonificacionF 0.1
#define bonificacionL 0.15
int main(){
	int cantidadProducto;
	float precioProducto,importe,bonificacion;
	char tipoProducto;
	
	printf("Ingrese la cantidad del producto:\n");
	scanf("%d",&cantidadProducto);
	printf("Ingrese el precio del producto:\n");
	scanf("%f",&precioProducto);
	importe = cantidadProducto * precioProducto;
	printf("Indique El tipo del producto (P �Perfumer�a, F-Farmacia y L-Limpieza):\n");
	/*limpiar buffer de entrada*/
	fflush(stdin);
	scanf("%c",&tipoProducto);
	
	printf("\nTotal sin bonificaci�n: $%.2f\n",importe);
	/*Aplicar bonificaci�n*/
	switch(tipoProducto){
		/*similar a if(tipoProducto=='P'||tipoProducto=='p')*/
		case 'P': case 'p':
			bonificacion=importe*bonificacionP;
			printf("Bonificaci�n del %.0f%% ($%.2f)\n",bonificacionP*100,bonificacion);
			/*break = terminar switch (continuaria en la l�nea 51)*/
			break;
		case 'F': case 'f':
			bonificacion=importe*bonificacionF;
			printf("Bonificaci�n del %.0f%% ($%.2f)\n",bonificacionF*100,bonificacion);
			break;
		case 'L': case 'l':
			bonificacion=importe*bonificacionL;
			printf("Bonificaci�n del %.0f%% ($%.2f)\n",bonificacionL*100,bonificacion);
			break;
		/*opcional, utilizado cuando ninguno de de los anteriores casos es verdadero*/	
		default:
			bonificacion = 0;
			break;
	}
	importe-=bonificacion;
	printf("\nTotal a pagar: $%.2f\n",importe);
	return 0;
}
