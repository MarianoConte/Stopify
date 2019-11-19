#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include "cancionesArbol.h"
#include "cancionesLista.h"
#include "celdasUsuarios.h"

typedef struct
{
    int idPlaylist;
    int idUsuario;
    int idCancion;
} stPlaylist;

void pasarDeArchivoPlaylistToADL(stCelda * usuarios, int validos, nodoArbolCancion * arbolCancion); //
void mostrarPlaylist(nodoListaCancion * lista);
void guardarPlaylist(int idCancion, int idUsuario);
int buscaUltimoIdPlaylist();
#endif // PLAYLIST_H_INCLUDED
