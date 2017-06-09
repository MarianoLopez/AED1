/*
3) En una vinoteca se desea realizar un relevamiento de las unidades en stock. De cada unidad se tienen los siguientes datos: 
	A�o de cosecha, Nombre del vino, Tipo de uva (M-Malbec, C-Cabernet, T-Merlot), Origen (A-argentino, F- franc�s, I-italiano).
Se solicita que escriba la expresi�n que permita obtener, de entre todos los vinos aquellos que: 
	Son de origen argentino o italiano, uva tipo Cabernet y a�o de cosecha menor que 2005.
*/
#include <stdio.h>
int main(){
	/*C�digo para verificar la ejecuci�n de la expresi�n*/
	char tipoUva,origen;
	int anioCosecha;
	
	int contador = 0;
	char cargarUnidad;
	
	printf("Existen unidades por procesar (S/N)?: ");
	scanf("%c",&cargarUnidad);
	while(cargarUnidad=='S'||cargarUnidad=='s'){
		
		printf("Ingresar el a�o de cosecha: ");
		scanf("%d",&anioCosecha);
		
		fflush(stdin);
		printf("Ingresar tipo de uva (M-Malbec, C-Cabernet, T-Merlot): ");
		scanf("%c",&tipoUva);
		
		fflush(stdin);
		printf("Ingresar el origen (A-argentino, F- franc�s, I-italiano): ");
		scanf("%c",&origen);

		/*Expresi�n solicitada:	*/
		if( ((origen=='A'||origen=='a')||(origen=='I'||origen=='i')) /*origen argentino o italiano*/
			&&(tipoUva=='C'||tipoUva=='c') /*uva tipo Cabernet*/
			&&(anioCosecha<2005)){ /*a�o de cosecha menor que 2005*/
			printf("\nVino de origen argentino o italiano, uva tipo Cabernet y a�o de cosecha menor que 2005\n");
			contador++;
		}/*fin expresi�n solicitada*/
		
		fflush(stdin);
		printf("\nExisten unidades por procesar (S/N)?: ");
		scanf("%c",&cargarUnidad);
	}/*fin while*/
	printf("\nVinos de origen argentino o italiano, uva tipo Cabernet y a�o de cosecha menor que 2005: %d\n",contador);
	return 0;
}
