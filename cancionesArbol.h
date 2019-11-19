#ifndef CANCIONESARBOL_H_INCLUDED
#define CANCIONESARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "cancionesBasico.h"

typedef struct
{
    stCancion c;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
} nodoArbolCancion;

nodoArbolCancion* inicArbol(); //INICIA EL ARBOL DE CANCIONES
nodoArbolCancion* crearNodoArbol (stCancion cancion); //CREA UN NODO DE ARBOL
nodoArbolCancion* insertarNodoArbol (nodoArbolCancion* arbol, nodoArbolCancion* nuevoNodo); //INSERTA UN NUEVO NODO EN UN ARBOL
void mostrarArbolPre(nodoArbolCancion* arbol); //MUESTRA EN PRE ORDER
void mostrarArbolIn(nodoArbolCancion* arbol); //MUESTRA EN ORDER
void mostrarArbolInGenero(nodoArbolCancion* arbol, char genero[]); //MUESTRA UNICAMENTE LOS NODOS CON EL GENERO INGRESADO
void mostrarArbolPost(nodoArbolCancion* arbol);  // MUESTRA EN POST ORDER
//nodoArbolCancion* buscarCancion (nodoArbolCancion* arbol, int idCancion);
int existeCancionPorId(nodoArbolCancion * arbolCancion, int id); //REVISA SI LA CANCION EXISTE POR ID Y RETORNA 1 SI EXISTE O 0 SINO
nodoArbolCancion * cargarArbolDesdeArchivo(); //CARGA EL ARBOL DE CANCIONES CON CANCIONES
stCancion buscarNodoPorId(nodoArbolCancion * arbolCancion, int id); //BUSCA UN NODO DENTRO DEL ARBOL POR ID
nodoArbolCancion * pasarArreglo2Arbol(stCancion * arreglo, int posMin, int posMax); //PASA LAS CANCIONES DE UN ARREGLO AL ARBOL PARA QUE ESTE QUEDE BALANCEADO
nodoArbolCancion* buscarMasIzqu(nodoArbolCancion* arbol); //BUSCA EL NODO MAS A LA IZQ
nodoArbolCancion* buscarMasDer (nodoArbolCancion* arbol); //BUSCA EL NODO MAS A LA DER
nodoArbolCancion* borrarNodoArbolPorIdCancion (nodoArbolCancion* arbol, int idCancion); //BORRA EL NODO DE UN ARBOL POR ID
nodoArbolCancion * borrarCancion(nodoArbolCancion * canciones, int id); //BORRA POR UNA CANCION ID Y LUEGO LA ELIMINA DENTRO DEL ARCHIVO
void modificarNodoDeCancion(nodoArbolCancion * canciones, stCancion cancion); //MODIFICA LA CANCION DENTRO DE UN NODO
void pasarArbol2Arreglo(stCancion * arreglo, nodoArbolCancion * canciones, int * validos); //PASA LAS CANCIONES DEL ARBOL A UN ARREGLO
#endif // CANCIONESARBOL_H_INCLUDED
