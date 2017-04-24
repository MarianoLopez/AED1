/*
Una biblioteca tiene los siguientes datos de los préstamos de libros:
	 Nro. Socio, código de la obra, tipo de préstamo ( S - Lectura en Sala, D - Lectura en Domicilio).
Se desea visualizar en pantalla una lista con la identificación de los socios que llevaron libros a domicilio, incluyendo el código de la obra.
Además se desea conocer la cantidad de libros leídos en sala, y el porcentaje de los mismos sobre el total de préstamos.
El final de los datos estará dado con un 9999 en Nro. Socio.
*/
#include <stdio.h>
#define centinelaFIN 9999
int main(){
	int nroSocio, codObra;
	int prestamos, librosLeidosEnSala = 0;
	char tipoPrestamo;
	
	printf("Ingrese el número de socio (%d para finalizar): ",centinelaFIN);
	scanf("%d",&nroSocio);
	while(nroSocio != centinelaFIN){
		printf("Ingrese el código de la obra: ");
		scanf("%d",&codObra);
		printf("Ingrese el tipo de préstamo (S - Lectura en Sala, D - Lectura en Domicilio): ");
		/*limpiar buffer*/
		fflush(stdin);
		scanf("%c",&tipoPrestamo);
		prestamos++;
		switch(tipoPrestamo){
			/*domicilio*/
			case 'D': case 'd':
				printf("Socio: %d, código obra: %d\n",nroSocio,codObra);
				break;
			/*sala*/
			case 'S': case 's':
				librosLeidosEnSala++;
				break;
		}
		printf("Ingrese el número de socio (%d para finalizar): ",centinelaFIN);
		fflush(stdin);
		scanf("%d",&nroSocio);
	}
	printf("\nTotal de prestamos: %d\n",prestamos);
	printf("Libros leidos en sala: %d\n",librosLeidosEnSala);
	printf("Libros leidos en sala sobre el total de prestamos: %d%%\n",(librosLeidosEnSala*100)/prestamos);
	return 0;
}
