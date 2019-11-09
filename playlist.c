#include "playlist.h"
#define arPlaylists "playlists.dat"

void cargarPlaylistsUsuarios(stCelda * usuarios, int validos, nodoArbolCancion * arbolCancion){
    stPlaylist a;
    stCancion cancion;
    FILE *pArch = fopen(arPlaylists, "rb");
    if(pArch){
        while(fread(&a, sizeof(stPlaylist), 1, pArch)>0){
            nodoListaCancion * aux;
            cancion = buscarNodoPorId(arbolCancion, a.idCancion);
            aux = crearNodoLista(cancion);
            usuarios[a.idUsuario].listaCanciones = agregarNodoListaCancion(usuarios[a.idUsuario].listaCanciones, aux);
        }
        fclose(pArch);
    }
}


#define arPlaylists "playlists.dat"
