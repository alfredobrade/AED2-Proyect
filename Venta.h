/*
Entidad venta
*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

#include "VentaPersistencia.h"
#include "VentaArticuloPersistencia.h"
#include "ArticuloPersistencia.h"



//--declaracion de tipos de datos personalizados
typedef char String[255];

typedef struct {
	String id_Articulo;
	int cantidad;
}ItemListaArticulos;
typedef ItemListaArticulos ListaArticulos[20]; //esto debe ser una lista o vector

typedef struct Venta{
	//int id_Venta
	String fecha;
	//tring id_Cliente
	//ListaArticulos id_Articulo; //esto lo sacamos de aca 
	/* sacamos la lista de articulos puesto que aca solo cargamos el costo y monto total
	y usamos la lista para cargar en la tabla intermedia VentaArticulo */
	float costo;
	float monto;
}tVenta;


//--prototipos de funciones
void ingresarVenta();
void guardarVenta();
//tArticulo buscarArticulo(String);

//String ingresarFecha(); //no me deja retornar un string
void cargarArticulos();
void ingresarArticulo(int);
void listarArticulos();

//--declaracion de variables globales

tVenta Venta;
FILE * Ventas;

//--**funcion principal**--



//--declaracion de funciones

void menu(){
	/*
	int opcion;
	printf("\t***Menu Inicial***\n");
	printf("\n1 - Cargar Datos de Stock\n2 - Ver Stock\n3 - Ventas\n4 - Imprimir Ticket\n0 - Salir\n\n");
	scanf("%d", &opcion);
	
	switch(opcion){
	case 1: 
		break;
	case 2: 
			
		break;
	case 3:
		break;
	case 4:
		break;
	}	
	*/
}

//despliega un menu de ingreso de articulos y los almacena en db
void ingresarVenta(){
	abrirVentasLectura();
	//buscar el ultimo ID para ingresar uno nuevo
	//Venta.fecha = ingresarFecha(); //llevar� strcat?
	cargarArticulos();
	
	
	
	
}
/*
String ingresarFecha(){
	String fecha, aux;
	printf("ingrese d�a");
	scanf("%s",&fecha);
	printf("ingrese mes");
	scanf("%s",&aux);
	strcat(fecha,aux);
	printf("ingrese a�o");
	scanf("%s",&aux);
	strcat(fecha,aux);
	
	return fecha;
}*/

void cargarArticulos(){
	//primero imprimimos una lista para elegir que articulo agregar
	listarArticulos();
	int opcion = 1;
	int i = 0;
	while (opcion == 1){
		ingresarArticulo(i);
		
	}
}

void ingresarArticulo(int i){
	printf("ingrese un Articulo por su id\n");
	scanf("%s",ListaArticulos.id_Articulo[i]);
	
}

void listarArticulos(){
	abrirArticulosLectura();
	imprimirListaArticulos();
}


/* retorna el articulo buscado para extraer stock, costo y precio -
se podria hacer metodos donde traiga directamente esos datos
tArticulo buscarArticulo(String idArticulo){
	
	
	return tArticulo;
}
*/


