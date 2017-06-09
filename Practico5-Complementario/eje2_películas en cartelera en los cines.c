/*
2) Se dispone de los siguientes datos de las pel�culas en cartelera en los cines durante la semana pasada: 
	nombre, g�nero (1-Comedia 2-Ciencia ficci�n 3-Terror),cantidad de espectadores,
	categor�a (1-Apta para todo p�blico 2-Apta para mayores de 18 a�os).
Escribir la expresi�n que permita obtener:
	a) las pel�culas de ciencia ficci�n con m�s de 500 espectadores aptas para todo p�blico.
	b) las pel�culas de terror con menos de 450 espectadores aptas para mayores de 18 a�os.
*/
#include <stdio.h>
int main(){
	/*C�digo para verificar la ejecuci�n de la expresi�n*/
	int genero, cantidadEspectadores, categoria;
	int contadorA = 0;/*las pel�culas de ciencia ficci�n con m�s de 500 espectadores aptas para todo p�blico.*/
	int contadorB = 0;/*las pel�culas de terror con menos de 450 espectadores aptas para mayores de 18 a�os.*/
	
	char cargaPeliculas;
	
	printf("Existen pel�culas por procesar (S/N)?: ");
	scanf("%c",&cargaPeliculas);
	while(cargaPeliculas=='S'||cargaPeliculas=='s'){
		
		printf("Ingresar g�nero (1-Comedia 2-Ciencia ficci�n 3-Terror): ");
		scanf("%d",&genero);
		
		printf("Ingresar la cantidad de espectadores: ");
		scanf("%d",&cantidadEspectadores);
		
		printf("Ingresar la categor�a (1-Apta para todo p�blico 2-Apta para mayores de 18 a�os): ");
		scanf("%d",&categoria);
		
		/*Expresiones solicitadas:
			a) las pel�culas de ciencia ficci�n con m�s de 500 espectadores aptas para todo p�blico.
		*/
		if(genero==2 /*ciencia ficci�n*/
			&&cantidadEspectadores>500 /*con m�s de 500 espectadores*/	
			&&categoria==1){/*aptas para todo p�blico*/
			printf("\nPel�cula de ciencia ficci�n con m�s de 500 espectadores aptas para todo p�blico.\n");
			contadorA++;
		}
		/*b) las pel�culas de terror con menos de 450 espectadores aptas para mayores de 18 a�os.*/
		if(genero==3 /*terror*/
			&&cantidadEspectadores<450 /*con menos de 450 espectadores*/
			&&categoria==2){ /*aptas para mayores de 18 a�os*/
			printf("\nPel�cula de terror con menos de 450 espectadores aptas para mayores de 18 a�os.\n");
			contadorB++;
		}/*fin expresiones solicitadas*/
		
		fflush(stdin);
		printf("Existen pel�culas por procesar (S/N)?: ");
		scanf("%c",&cargaPeliculas);
	}/*fin while*/
	printf("\nPel�culas de ciencia ficci�n con m�s de 500 espectadores aptas para todo p�blico: %d\n",contadorA);
	printf("\nPel�culas de terror con menos de 450 espectadores aptas para mayores de 18 a�os: %d\n",contadorB);
	return 0;
}
