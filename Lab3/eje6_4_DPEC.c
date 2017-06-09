/*
6.4. De la facturación mensual por consumo de energía eléctrica, la DPEC necesita saber qué porcentaje de
la recaudación corresponde a los usuarios de tipo Residencial.
La empresa dispone de los siguientesdatos:
	 Nro. Usuario, categoría, importe facturado. Las categorías posibles son: 1-Residencial, 2-Comercial, 3-Industrial. 
Escriba un programa en C para obtener los resultados solicitados.
*/
#include <stdio.h>
#define centinelaFIN 9999
int main(){
	int nroUsuario, categoriaUsuario;
	float importeFacturado;
	
	int recaudaciones, recaudacionesResidenciales = 0;
	float acumuladorRecaudaciones, acumuladorResidenciales = 0.0;
	
	printf("Ingrese el número de usuario (%d para finalizar): ",centinelaFIN);
	scanf("%d",&nroUsuario);
	while(nroUsuario != centinelaFIN){
		/*incrementar contador de recaudaciones*/
		recaudaciones++;
		printf("Ingrese la categoria del usuario (1-Residencial, 2-Comercial, 3-Industrial): ");
		scanf("%d",&categoriaUsuario);
		printf("Ingrese el importe facturado: ");
		scanf("%f",&importeFacturado);
		/*acumular importe facturado*/
		acumuladorRecaudaciones+=importeFacturado;
		/*Residencial*/
		if(categoriaUsuario==1){
			/*incrementar contador de recaudaciones residenciales*/
			recaudacionesResidenciales++;
			/*acumular importe residencial facturado*/
			acumuladorResidenciales+=importeFacturado;
		}
		printf("Ingrese el número de usuario (%d para finalizar): ",centinelaFIN);
		scanf("%d",&nroUsuario);
	}
	/*totales*/
	printf("\nTotal de recaudaciones: %d\n",recaudaciones);
	printf("Importe de las recaudaciones: %.2f\n",acumuladorRecaudaciones);
	printf("Total de recaudaciones residenciales: %d\n",recaudacionesResidenciales);
	printf("Importe de las recaudaciones residenciales: %.2f\n",acumuladorResidenciales);
	printf("Recaudaciones residenciales sobre el total de recaudaciones: %d%%\n",(recaudacionesResidenciales*100)/recaudaciones);
	return 0;
}
