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

void cargarPlaylistsUsuarios(stCelda * usuarios, int validos, nodoArbolCancion * arbolCancion);

#endif // PLAYLIST_H_INCLUDED
