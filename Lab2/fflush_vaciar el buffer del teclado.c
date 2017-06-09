/*
Funci�n fflush() -> Se utiliza para vaciar (limpiar) el buffer del teclado cuando se ingresan datos de tipo car�cter o cadena. 

Cuando se ejecuta scanf, por ejemplo:  scanf( "%c", &a ) 
el programa se detiene para que el usuario teclee el dato requerido que se almacena temporalmente en el buffer (memoria intermedia) de la entrada est�ndar.
Al pulsar la tecla ENTER, se le asigna a la variable a el valor introducido, por ejemplo 50, 
y se genera un salto de l�nea autom�tico para continuar el ingreso de otros datos.  
El salto de l�nea se indica con la secuencia de escape �\n�. 
Este car�cter de control est� representado en ASCII por LF, equivalente al decimal 10.
Si el car�cter de control LF queda en el buffer, ser� tomado como dato por el siguiente scanf ("%d", &b),
haciendo que no sea correcto el ingreso de los datos. 
*/
#include <stdio.h>
int main(){
	char a, b,c;
	printf("Sin fflush()\n");
	printf("Ingresar el primer caracter: ");
	scanf("%c",&a);
	printf("Ingresar el segundo caracter: ");
	scanf("%c",&b);
	printf("Ingresar el tercer caracter: ");
	scanf("%c",&c);
	printf("Valores ingresados: %c, %c, %c\n",a,b,c);
	
	/*
	 Puede haber problemas para que la instrucci�n de la l�nea 19: scanf ("%c", &b) se ejecute de forma correcta �Por qu�?:
	 Cuando se ejecuta la primera instrucci�n de entrada: scanf ( "%c", &a );
	 despu�s de asignar un car�cter por ejemplo �t� a la variable �a�, se produce un salto de l�nea autom�tico, pero,
	 en el buffer del teclado tambi�n se ha quedado almacenada la secuencia de escape (\n), que es, precisamente, un car�cter.
	 En consecuencia, cuando se ejecuta la instrucci�n scanf ( "%c", &b ); a la variable b se le asigna el salto de l�nea almacenado en el buffer de la entrada
	 est�ndar, y la ejecuci�n del programa continua con la siguiente instrucci�n. Ahora, el buffer vuelve a estar vac�o y,
	 por tanto, la entrada de la variable c s� se ejecuta correctamente. 
	*/
	printf("Con fflush()\n");
	fflush(stdin);
	printf("Ingresar el primer caracter: ");
	scanf("%c",&a);
	printf("Ingresar el segundo caracter: ");
	fflush(stdin);
	scanf("%c",&b);
	printf("Ingresar el tercer caracter: ");
	fflush(stdin);
	scanf("%c",&c);
	printf("Valores ingresados: %c, %c, %c",a,b,c);
	return 0;
}

