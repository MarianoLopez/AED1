/*
2) Se dispone de los siguientes datos de las películas en cartelera en los cines durante la semana pasada: 
	nombre, género (1-Comedia 2-Ciencia ficción 3-Terror),cantidad de espectadores,
	categoría (1-Apta para todo público 2-Apta para mayores de 18 años).
Escribir la expresión que permita obtener:
	a) las películas de ciencia ficción con más de 500 espectadores aptas para todo público.
	b) las películas de terror con menos de 450 espectadores aptas para mayores de 18 años.
*/
#include <stdio.h>
int main(){
	/*Código para verificar la ejecución de la expresión*/
	int genero, cantidadEspectadores, categoria;
	int contadorA = 0;/*las películas de ciencia ficción con más de 500 espectadores aptas para todo público.*/
	int contadorB = 0;/*las películas de terror con menos de 450 espectadores aptas para mayores de 18 años.*/
	
	char cargaPeliculas;
	
	printf("Existen películas por procesar (S/N)?: ");
	scanf("%c",&cargaPeliculas);
	while(cargaPeliculas=='S'||cargaPeliculas=='s'){
		
		printf("Ingresar género (1-Comedia 2-Ciencia ficción 3-Terror): ");
		scanf("%d",&genero);
		
		printf("Ingresar la cantidad de espectadores: ");
		scanf("%d",&cantidadEspectadores);
		
		printf("Ingresar la categoría (1-Apta para todo público 2-Apta para mayores de 18 años): ");
		scanf("%d",&categoria);
		
		/*Expresiones solicitadas:
			a) las películas de ciencia ficción con más de 500 espectadores aptas para todo público.
		*/
		if(genero==2 /*ciencia ficción*/
			&&cantidadEspectadores>500 /*con más de 500 espectadores*/	
			&&categoria==1){/*aptas para todo público*/
			printf("\nPelícula de ciencia ficción con más de 500 espectadores aptas para todo público.\n");
			contadorA++;
		}
		/*b) las películas de terror con menos de 450 espectadores aptas para mayores de 18 años.*/
		if(genero==3 /*terror*/
			&&cantidadEspectadores<450 /*con menos de 450 espectadores*/
			&&categoria==2){ /*aptas para mayores de 18 años*/
			printf("\nPelícula de terror con menos de 450 espectadores aptas para mayores de 18 años.\n");
			contadorB++;
		}/*fin expresiones solicitadas*/
		
		fflush(stdin);
		printf("Existen películas por procesar (S/N)?: ");
		scanf("%c",&cargaPeliculas);
	}/*fin while*/
	printf("\nPelículas de ciencia ficción con más de 500 espectadores aptas para todo público: %d\n",contadorA);
	printf("\nPelículas de terror con menos de 450 espectadores aptas para mayores de 18 años: %d\n",contadorB);
	return 0;
}
