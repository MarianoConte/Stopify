#ifndef CANCIONESLISTA_H_INCLUDED
#define CANCIONESLISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "cancionesBasico.h"

typedef struct
{
    stCancion c;
    struct nodoListaCancion * sig;
} nodoListaCancion;

nodoListaCancion* inicLista();
nodoListaCancion* crearNodoLista(stCancion cancion);
nodoListaCancion * agregarNodoListaCancion(nodoListaCancion * lista, nodoListaCancion * nuevo);
nodoListaCancion* agregarAlFinal(nodoListaCancion* lista, nodoListaCancion* nuevoNodo);
nodoListaCancion* agregarEnOrdenPoridDeCancion(nodoListaCancion* lista, nodoListaCancion* nuevoNodo);
nodoListaCancion* archAlista(char nombreArchivoCanciones[], nodoListaCancion* lista);
void listaAarch(char nombreArchCanciones[], nodoListaCancion* lista);
void mostrarLista(nodoListaCancion* lista, nodoListaCancion* nuevoNodo); // modularizar
void mostrarListaCancionesPorGenero(nodoListaCancion* lista, char genero[]);
nodoListaCancion* borrarNodoPorIdCancion(nodoListaCancion* lista, int idBorrada);
nodoListaCancion* buscarUltimaCancion(nodoListaCancion* lista);

#endif // CANCIONESLISTA_H_INCLUDED
