/*
5) Una empresa de turismo organiza un tour para vacaciones de julio y ofrece una bonificación del precio del servicio,
   de acuerdo a la categoría del cliente:
   	 30% para jubilados y 20 % para estudiantes.
   Se desea conocer el monto a pagar por cada cliente, para ello dispone de los siguientes datos:
   	 DNI, Precio del servicio, Categoría(1- Jubilado, 2-Estudiante, 3- Otros).
 Realice un algoritmo que efectúe 
 	la bonificación del precio según la categoría 
	y luego visualice en pantalla el DNI del cliente, Categoría y el precio bonificado.
	Al final, mostrar el porcentaje de las ventas a estudiantes sobre el total.
*/
#include <stdio.h>
#define bonificacionJubilados 0.30
#define bonificacionEstudiantes 0.20
int main(){
	/*Código para verificar la ejecución del algoritmo*/
	int dni,categoria;
	float precioServicio;
	
	int contadorVentas = 0;
	int contadorVentasEstudiantes = 0;
	
	float beneficio;
	
	printf("Ingresar DNI (99999 para finalizar): ");
	scanf("%d",&dni);
	while(dni!=99999){
		
		printf("Ingresar precio del servicio: ");
		scanf("%f",&precioServicio);
		
		printf("Ingresar Categoría(1- Jubilado, 2-Estudiante, 3- Otros): ");
		scanf("%d",&categoria);
		
		contadorVentas++;
		
		/*bonificación del precio según la categoría */
		switch(categoria){
			case 1: /*jubilado*/
				beneficio = precioServicio * bonificacionJubilados;
				break;
			case 2: /*estudiante*/
				beneficio = precioServicio * bonificacionEstudiantes;
				contadorVentasEstudiantes++;
				break;
			default: /*otros*/
				beneficio = 0;
				break;
		}
		/*visualice en pantalla el DNI del cliente, Categoría y el precio bonificado.*/
		printf("Dni: %d, categoría: %d, precio del servicio: $%.2f\n",dni,categoria,precioServicio);
		printf("Importe bonificado: $%.2f\n",beneficio);
		precioServicio-= beneficio;
		printf("Total a pagar: $%.2f\n",precioServicio);
		
		printf("Ingresar DNI (99999 para finalizar): ");
		scanf("%d",&dni);
	}/*fin while*/
	
	/*mostrar el porcentaje de las ventas a estudiantes sobre el total.*/
	printf("\nCantidad de ventas: %d\n",contadorVentas);
	printf("\nCantidad de ventas a estudiantes: %d\n",contadorVentasEstudiantes);
	printf("\nPorcentaje de las ventas a estudiantes sobre el total: %%%.2f\n",(contadorVentasEstudiantes/(float)contadorVentas)*100);
	return 0;
}
