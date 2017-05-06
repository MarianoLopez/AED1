/*
Una Empresa de servicio de Internet permite hacer reclamos vía teléfono, para ello solicita los siguientes datos al efectuar un reclamo:
 Nro.Usuario, DNI, Tipo de Reclamo (1-Falta de conexión 2-Reclamo sin atender 3-Baja potencia en la conexión).
Diseñe un algoritmo que permita:
	 Mostrar por pantalla los datos de los usuarios que reclaman por Baja potencia en la conexión y calcular el porcentaje de estos sobre el total de reclamos.
	 Informar la cantidad total de reclamos recibidos.
Se indicará fin del programa ingresando 0 (cero) en Nro.Usuario.
*/
#include <stdio.h>
int main(){
	/*Código para verificar la ejecución del algoritmo*/
	int nroUsuario,dni, tipoReclamo;
	
	int contadorReclamos = 0;
	int contadorReclamosBajaPotencia = 0;
	printf("Ingresar Nro.Usuario (0 para finalizar): ");
	scanf("%d",&nroUsuario);
	while(nroUsuario!=0){
		
		printf("Ingresar dni: ");
		scanf("%d",&dni);
		
		printf("Ingresar Tipo de Reclamo (1-Falta de conexión 2-Reclamo sin atender 3-Baja potencia en la conexión): ");
		scanf("%d",&tipoReclamo);
		
		contadorReclamos++;

		if(tipoReclamo==3){/*Baja potencia en la conexión*/
			printf("\nReclamo de Baja potencia en la conexión\n");
			printf("Nro.usuario: %d, Dni: %d\n\n",nroUsuario,dni);
			contadorReclamosBajaPotencia++;
		}
	
		printf("Ingresar Nro.Usuario (0 para finalizar): ");
		scanf("%d",&nroUsuario);
	}/*fin while*/
	
	
	/*
	 calcular el porcentaje de estos sobre el total de reclamos.
	 Informar la cantidad total de reclamos recibidos.
	*/
	printf("\nCantidad de reclamos: %d\n",contadorReclamos);
	printf("\nCantidad de reclamos por baja potencia en la conexión: %d\n",contadorReclamosBajaPotencia);
	printf("\nPorcentaje de reclamos por baja potencia en la conexión: %%%.2f\n",(contadorReclamosBajaPotencia/(float)contadorReclamos)*100);
	return 0;
}
