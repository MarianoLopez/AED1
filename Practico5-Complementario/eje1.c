/*
1) En las �ltimas elecciones provinciales, se realiz� una encuesta de boca de urna, en la cual se preguntaba:
	 Sexo (F/M), Edad, Tuvo Inconvenientes para votar (S/N);Encontr� la boleta de su candidato (S/N).
Se solicita que escriba la expresi�n que permita obtener: Las mujeres, entre 30 y 50 a�os que tuvieron problemas para votar
y que el inconveniente fue No encontrar la boleta de su candidato
*/

#include <stdio.h>
int main(){
	/*C�digo para verificar la ejecuci�n de la expresi�n*/
	int edad;
	char sexo, inconvenientesAlVotar, encontroBoleta;
	/*de las mujeres, entre 30 y 50 a�os que tuvieron problemas para votar y que el inconveniente fue No encontrar la boleta de su candidato*/
	int contador = 0;
	/*a utilizar en while*/
	char cargaDeEncuestas;
	
	printf("Existen encuestas por procesar (S/N)?: ");
	scanf("%c",&cargaDeEncuestas);
	while(cargaDeEncuestas=='S'||cargaDeEncuestas=='s'){
		fflush(stdin);
		printf("Ingresar sexo (F/M): ");
		scanf("%c",&sexo);
		
		printf("Ingresar edad: ");
		scanf("%d",&edad);
		
		fflush(stdin);
		printf("Tuvo Inconvenientes para votar (S/N)?: ");
		scanf("%c",&inconvenientesAlVotar);
		
		fflush(stdin);
		printf("Encontr� la boleta de su candidato (S/N)?: ");
		scanf("%c",&encontroBoleta);
		
		/*expresi�n solicitada*/
		if((sexo=='F'||sexo=='f') /*mujeres*/
			&&(edad>=30 && edad<=50) /*entre 30 y 50 a�os*/
			&&(inconvenientesAlVotar=='S'||inconvenientesAlVotar=='s') /*que tuvieron problemas para votar*/
			&&(encontroBoleta=='N'||encontroBoleta=='n')){/*y que el inconveniente fue No encontrar la boleta de su candidato*/
			printf("\nMujer, entre 30 y 50 a�os que tuv� problemas para votar y que el inconveniente fue No encontrar la boleta de su candidato\n");
			contador++;
		}/*fin de la expresi�n solicitada*/
		
		fflush(stdin);
		printf("Existen encuestas por procesar (S/N)?: ");
		scanf("%c",&cargaDeEncuestas);
	}/*fin while*/
	
	printf("La cantidad de mujeres, entre 30 y 50 a�os que tuvieron problemas para votar y que el inconveniente fue No encontrar la boleta de su candidato es: %d",contador);
	return 0;
}
