/*
6.5. Para un campeonato regional de basquetbol, los organizadores utilizan una ficha de inscripción con los siguientes datos:
DNI, sexo (M/F), edad, categoría (N – niños, C – cadetes), provincia de origen (1-Chaco, 2- Formosa, 3-Corrientes).
Escriba un programa en C que ingrese los datos y:
- Muestre en pantalla el DNI de las mujeres cadetes de Corrientes o del Chaco.
- Calcule y muestre la cantidad de varones entre 10 y 12 años de Formosa.
*/
#include <stdio.h>
#define centinelaFIN 9999
int main(){
	int dni, edad, provinciaOrigen;
	char sexo,categoria;
	int contadorVaronesSolicitado = 0;
	
	printf("Ingrese el DNI (%d para finalizar): ",centinelaFIN);
	scanf("%d",&dni);
	while(dni != centinelaFIN){
		/*ingreso de datos*/
		printf("Ingrese el sexo (M/F): ");
		fflush(stdin);
		scanf("%c",&sexo);
		printf("Ingrese la edad: ");
		scanf("%d",&edad);
		printf("Ingrese la categoría (N-niños, C-cadetes): ");
		fflush(stdin);
		scanf("%c",&categoria);
		printf("Ingrese la provincia de origen (1-Chaco, 2- Formosa, 3-Corrientes): ");
		scanf("%d",&provinciaOrigen);
		
		/*Mujeres (F|f) cadetes (C|c) de Corrientes o Chaco(1|3)*/
		if((sexo=='F'||sexo=='f')&&(categoria=='C'||categoria=='c')&&(provinciaOrigen==1||provinciaOrigen==3)){
			printf("Mujer cadete de Chaco o Corrientes, DNI: %d\n",dni);
		}
		/*Varones (M|m) de Formosa (2) entre 10 y 12 años*/
		if((sexo=='M'||sexo=='m')&&provinciaOrigen==2&&(edad>=10 &&edad<=12)){
			contadorVaronesSolicitado++;
		}
		
		printf("Ingrese el DNI (%d para finalizar): ",centinelaFIN);
		scanf("%d",&dni);
	
	}
	/*totales*/
	printf("\nVarones entre 10 y 12 años de Formosa: %d\n",contadorVaronesSolicitado);
	return 0;
}
