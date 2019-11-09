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

nodoArbolCancion* inicArbol();
nodoArbolCancion* crearNodoArbol (stCancion cancion);
nodoArbolCancion* insertarNodoArbol (nodoArbolCancion* arbol, nodoArbolCancion* nuevoNodo);
void mostrarArbolPre(nodoArbolCancion* arbol);
void mostrarArbolIn(nodoArbolCancion* arbol);
void mostrarArbolPost(nodoArbolCancion* arbol);  // modularizar
nodoArbolCancion* borrarUnNodoArbol (nodoArbolCancion* arbol, int idCancion);
//nodoArbolCancion* buscarCancion (nodoArbolCancion* arbol, int idCancion);
nodoArbolCancion * cargarArbol();
stCancion buscarNodoPorId(nodoArbolCancion * arbolCancion, int id);
nodoArbolCancion * pasarArreglo2Arbol(stCancion * arreglo, int posMin, int posMax);
#endif // CANCIONESARBOL_H_INCLUDED
