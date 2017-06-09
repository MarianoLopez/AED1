/*
3. ALTERNATIVA DOBLE
3.1. Para otorgar un pr�stamo, un banco eval�a el sueldo del solicitante. Si el sueldo es mayor o igual a
$10.000, se autoriza un pr�stamo de hasta $30.000. 
Para sueldos inferiores, s�lo se autoriza un pr�stamo de hasta el 75% de sus ingresos.
Codifique en C un programa que ingrese el monto del sueldo del solicitante y muestre en pantalla una leyenda indicando el monto de pr�stamo autorizado.
*/
#include <stdio.h>
int main(){
	float sueldo;
	float prestamo = 0.0;
	printf("Ingrese importe del sueldo:\n");
	scanf("%f", &sueldo);
	if(sueldo >= 10000){
		prestamo = 30000;
	}else{
		prestamo = sueldo * 0.75;
	}
	printf("Prestamo otorgado: $ %4.2f\n", prestamo);
	return 0;
}

