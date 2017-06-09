/*
4. Expresiones l�gicas Operadores l�gicos:   && (AND), || (OR), !(NOT) 
	a) Escribir un programa que Inicialice 2 variables �a� y �b� de tipo entero, y verifique si a>b y a>0,
	   utilizando la sentencia condicional �if� y el operador l�gico apropiado.
	   Visualizar por pantalla si se cumplen o no ambas condiciones 
*/

#include <stdio.h>
main(){
	int a = 5;
	int b = 17;
	
	printf("a)\n");
	if((a>b) && (a>0)){
		printf("%d>%d Y %d>0 es VERDADERO\n",a,b,a);
	}else{
		printf("%d>%d Y %d>0 es FALSO\n",a,b,a);
	}
	
	/*
		b) Cambiar los valores de las variables, ejecutar y explicar el funcionamiento del operador l�gico �&&�. 
	*/
	a = 17;
	b = 5;
	printf("b)\n");
	if((a>b) && (a>0)){
		printf("%d>%d Y %d>0 es VERDADERO\n",a,b,a);
	}else{
		printf("%d>%d Y %d>0 es FALSO\n",a,b,a);
	}
	
	/*
		c) De manera an�loga, agregar una nueva sentencia condicional que eval�e que a>b o a>0.
		Visualizar por pantalla si se cumplen las condiciones:
	*/
	printf("c)\n");
	a = 5;
	b = 17;
	if((a>b) || (a>0)){
		printf("%d>%d O %d>0 es VERDADERO\n",a,b,a);
	}else{
		printf("%d>%d O %d>0 es FALSO\n",a,b,a);
	}
	
	/*
		d) Cambiar los valores de las variables, ejecutar y explicar el funcionamiento del operador l�gico �||�. 
	*/
	
	printf("d)\n");
	a = 17;
	b = 5;
	if((a>b) || (a>0)){
		printf("%d>%d O %d>0 es VERDADERO\n",a,b,a);
	}else{
		printf("%d>%d O %d>0 es FALSO\n",a,b,a);
	}
	
	/*
		e) Modificar las expresiones booleanas de cada if encerr�ndolas entre par�ntesis �( )� 
		y agregando al comienzo de este el operador l�gico de negaci�n  �!�. Ejecute y explique los cambios que produce
	*/
	a = 5;
	b = 17;
	printf("e)\n");
	if(!((a>b) && (a>0))){
		printf("!(%d>%d Y %d>0) es VERDADERO\n",a,b,a);
	}else{
		printf("!(%d>%d Y %d>0) es FALSO\n",a,b,a);
	}
	
	return 0;
}

