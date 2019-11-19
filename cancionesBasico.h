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

void mostrarCancion(stCancion cancion); //MUESTRA UNA CANCION
void cargarArregloCanciones(stCancion * arreglo); //CARGA UN ARREGLO CON CANCIONES DESDE EL ARCHIVO
int cantidadCancionesArch(); //CANTIDAD DE CANCIONES NO ELIMINADAS DENTRO DEL ARCHIVO
int cantidadCancionesCompleto(); //CANTIDAD DE CANCIONES COMPLETO DENTRO DEL ARCHIVO
int buscaUltimoIdCancion(); //BUSCA EL ULTIMO ID UTILIZADO EN UNA CANCION
void guardarCancion(stCancion a); //GUARDA UNA CANCION DENTRO DEL ARCHIVO
void eliminarCancionArch(int id); //ELIMINA UNA CANCION DEL ARCHIVO
void datosCancion(stCancion a); //MUESTRA UNA CANCION PARA EL ADMINISTRADOR
stCancion modificarCancion(stCancion a); //MODIFICA UNA CANCION Y LA RETORNA
void modificarCancionArch(stCancion cancion); //MODIFICA UNA CANCION DENTRO DEL ARCHIVO
stCancion buscarCancion(int id); //BUSCA UNA CANCION POR ID DENTRO DEL ARCHIVO
int archivo2ArregloCompleto(stCancion * array); //CARGA UN ARREGLO CON CANCIONES DESDE EL ARCHIVO CON LAS ELIMINADAS INCLUIDAS
void listarPorGenero(); //LISTA LAS CANCIONES POR GENERO
void ordenaArregloGenero(stCancion * array,int v); //ORDENA UN ARREGLO POR GENERO
void insertaGenero(stCancion * array, int v, stCancion dato); //INSERTA UNA CANCION DENTRO DE UN ARREGLO POR GENERO
void muestraArregloGenero(stCancion * array, int v); //MUESTRA UN ARREGLO POR GENERO
void listarPorTitulo(); //LISTA LAS CANCIONES POR TITULO
void ordenaArregloTitulo(stCancion * a, int v); //ORDENA UN ARREGLO POR TITULO
int seleccionaTitulo(stCancion * a, int v, int inicio); //INSERTA UNA CANCION DENTRO DE UN ARREGLO POR TITULO
void muestraArregloTitulo(stCancion * array, int v); //MUESTRA UN ARREGLO POR TITULO
#endif // CANCIONESBASICO_H_INCLUDED
