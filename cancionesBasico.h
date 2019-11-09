#ifndef CANCIONESBASICO_H_INCLUDED
#define CANCIONESBASICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int idCancion;
   char titulo[30];
   char artista[20];
   int duracion;
   char album[20];
   int anio;
   char genero[20];
   char comentario[100];
   int eliminado;  // indica 1 o 0 si la canción fue eliminada
} stCancion;

void mostrarCancion(stCancion cancion);
void cargarArregloCanciones(stCancion * arreglo);
int cantidadCancionesArch();
#endif // CANCIONESBASICO_H_INCLUDED
