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

nodoListaCancion* inicLista(); //INICIA UNA LISTA EN NULL
nodoListaCancion* crearNodoLista(stCancion cancion); //CREA UN NODO DE LISTA
nodoListaCancion * agregarNodoListaCancion(nodoListaCancion * lista, nodoListaCancion * nuevo); //AGREGA UN NODO A UNA LISTA
nodoListaCancion* agregarAlFinal(nodoListaCancion* lista, nodoListaCancion* nuevoNodo); //AGREGA UNA CANCION AL FINAL DE LA LISTA
nodoListaCancion* agregarEnOrdenPoridDeCancion(nodoListaCancion* lista, nodoListaCancion* nuevoNodo); //AGREGA UNA CANCION ORDENADA A UNA LISTA
//nodoListaCancion* archAlista(char nombreArchivoCanciones[], nodoListaCancion* lista);
//void listaAarch(char nombreArchCanciones[], nodoListaCancion* lista);
nodoListaCancion* borrarNodoPorIdCancion(nodoListaCancion* lista, int idBorrada);//BORRA UN NODO POR ID
nodoListaCancion* buscarUltimaCancion(nodoListaCancion* lista); //BUSCA LA ULTIMA CANCION
int cantidadCancionesPlaylist(nodoListaCancion * lista); //DEVUELVE LA CANTIDAD DE CANCIONES DE UNA PLAYLIST
stCancion buscarPorPosNodo(nodoListaCancion * lista, int pos); //BUSCA UNA CANCION POR POSICION DENTRO DE UNA PLAYLIST
#endif // CANCIONESLISTA_H_INCLUDED
