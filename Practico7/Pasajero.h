/*ARCHIVO CABECERA*/
/*
Una agencia de turismo registra los siguientes datos de los pasajeros: DNI, Apellido y Nombre,
Destino (1-Nacionales, 2-Extranjeros), Precio del viaje, Forma de pago (1-Efectivo, 2-Tarjeta).
Determinar el tipo de dato para cada campo y su longitud, luego realizar la declaración del registro
y crear una variable de este tipo
*/
struct pasajero{
	int dni; /*4bytes*/
	char apeynom[50]; /*char = 1byte -> array de 50 chars = 50bytes*/
	int destino;/*4bytes*/
	float precioViaje;/*4bytes*/
	int formaPago;/*4bytes*/
};/*total: 66bytes.*/
/*Pero en realidad si hacemos sizeof(Pasajero) = 68bytes.
Esto se debe a los ajustes de  alineación , el compilador intenta encajar los datos en celdas de 4, 8 o 16 bytes de tu procesador 
(suponiendo arquitectura de 32 bits) para que los accesos sean más óptimos 
(de otro modo para leer una variable harían falta dos o más accesos a memoria en vez de uno).
Para ello mete espacios vacíos entre las variables para lograr direcciones de memoria múltiplos de 4, 8 o 16 bytes.
Más información en: 
	http://etsiitforos.ugr.es/apps/foro/index.php?idhebra=9729
	https://social.msdn.microsoft.com/Forums/es-ES/12af5638-c9d4-440d-a1c9-9bfb446cd3f7/tamao-en-byes-del-unsigned-char?forum=vcppes
	https://en.wikipedia.org/wiki/Data_structure_alignment
*/
typedef struct pasajero Pasajero;/*definir Pasajero como nuevo tipo de datos, a partir de la estructura pasajero*/

void imprimirPasajero(Pasajero *);/*prototipo*/

void imprimirPasajero(Pasajero *p){
	printf("\n\tDNI: %d\n\tApellido y Nombre: %s\n\tDestino: %d\n\tPrecio: %.2f\n\tForma de pago: %d\n",
			p->dni,p->apeynom,p->destino,p->precioViaje,p->formaPago);
}
