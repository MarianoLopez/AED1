/*
6.4. De la facturaci�n mensual por consumo de energ�a el�ctrica, la DPEC necesita saber qu� porcentaje de
la recaudaci�n corresponde a los usuarios de tipo Residencial.
La empresa dispone de los siguientesdatos:
	 Nro. Usuario, categor�a, importe facturado. Las categor�as posibles son: 1-Residencial, 2-Comercial, 3-Industrial. 
Escriba un programa en C para obtener los resultados solicitados.
*/
#include <stdio.h>
#define centinelaFIN 9999
int main(){
	int nroUsuario, categoriaUsuario;
	float importeFacturado;
	
	int recaudaciones, recaudacionesResidenciales = 0;
	float acumuladorRecaudaciones, acumuladorResidenciales = 0.0;
	
	printf("Ingrese el n�mero de usuario (%d para finalizar): ",centinelaFIN);
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
		printf("Ingrese el n�mero de usuario (%d para finalizar): ",centinelaFIN);
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
