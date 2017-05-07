#include <stdio.h>
/*prototipo de la función, void = sin retorno*/
void ingresoDeDatos(int *, int *);

int main(){
	int libreta,edad;
	/*notar los "&", los argumentos son direcciones de memoria*/
	ingresoDeDatos(&libreta,&edad);
	while(libreta!=0||edad!=0){ /*0,0 = fin*/
		printf("Datos ingresados:\n\tLibreta: %d\n\tEdad: %d\n\n",libreta,edad);	
		ingresoDeDatos(&libreta,&edad);
	}
	return 0;
}

void ingresoDeDatos(int *libreta, int *edad){
	printf("Ingresar libreta y edad, separados por coma (0,0 = fin): ");
	/*notar la falta de "&", dado que los parámetros son direcciones de memoria*/
	scanf("%d,%d",libreta,edad);
}
