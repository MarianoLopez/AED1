/*
Una Empresa de servicio de Internet permite hacer reclamos v�a tel�fono, para ello solicita los siguientes datos al efectuar un reclamo:
 Nro.Usuario, DNI, Tipo de Reclamo (1-Falta de conexi�n 2-Reclamo sin atender 3-Baja potencia en la conexi�n).
Dise�e un algoritmo que permita:
	 Mostrar por pantalla los datos de los usuarios que reclaman por Baja potencia en la conexi�n y calcular el porcentaje de estos sobre el total de reclamos.
	 Informar la cantidad total de reclamos recibidos.
Se indicar� fin del programa ingresando 0 (cero) en Nro.Usuario.
*/
#include <stdio.h>
int main(){
	/*C�digo para verificar la ejecuci�n del algoritmo*/
	int nroUsuario,dni, tipoReclamo;
	
	int contadorReclamos = 0;
	int contadorReclamosBajaPotencia = 0;
	printf("Ingresar Nro.Usuario (0 para finalizar): ");
	scanf("%d",&nroUsuario);
	while(nroUsuario!=0){
		
		printf("Ingresar dni: ");
		scanf("%d",&dni);
		
		printf("Ingresar Tipo de Reclamo (1-Falta de conexi�n 2-Reclamo sin atender 3-Baja potencia en la conexi�n): ");
		scanf("%d",&tipoReclamo);
		
		contadorReclamos++;

		if(tipoReclamo==3){/*Baja potencia en la conexi�n*/
			printf("\nReclamo de Baja potencia en la conexi�n\n");
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
	printf("\nCantidad de reclamos por baja potencia en la conexi�n: %d\n",contadorReclamosBajaPotencia);
	printf("\nPorcentaje de reclamos por baja potencia en la conexi�n: %%%.2f\n",(contadorReclamosBajaPotencia/(float)contadorReclamos)*100);
	return 0;
}
