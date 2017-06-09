/*
Función fflush() -> Se utiliza para vaciar (limpiar) el buffer del teclado cuando se ingresan datos de tipo carácter o cadena. 

Cuando se ejecuta scanf, por ejemplo:  scanf( "%c", &a ) 
el programa se detiene para que el usuario teclee el dato requerido que se almacena temporalmente en el buffer (memoria intermedia) de la entrada estándar.
Al pulsar la tecla ENTER, se le asigna a la variable a el valor introducido, por ejemplo 50, 
y se genera un salto de línea automático para continuar el ingreso de otros datos.  
El salto de línea se indica con la secuencia de escape “\n”. 
Este carácter de control está representado en ASCII por LF, equivalente al decimal 10.
Si el carácter de control LF queda en el buffer, será tomado como dato por el siguiente scanf ("%d", &b),
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
	 Puede haber problemas para que la instrucción de la línea 19: scanf ("%c", &b) se ejecute de forma correcta ¿Por qué?:
	 Cuando se ejecuta la primera instrucción de entrada: scanf ( "%c", &a );
	 después de asignar un carácter por ejemplo “t” a la variable “a”, se produce un salto de línea automático, pero,
	 en el buffer del teclado también se ha quedado almacenada la secuencia de escape (\n), que es, precisamente, un carácter.
	 En consecuencia, cuando se ejecuta la instrucción scanf ( "%c", &b ); a la variable b se le asigna el salto de línea almacenado en el buffer de la entrada
	 estándar, y la ejecución del programa continua con la siguiente instrucción. Ahora, el buffer vuelve a estar vacío y,
	 por tanto, la entrada de la variable c sí se ejecuta correctamente. 
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

