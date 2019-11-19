#include "playlist.h"
#define arPlaylists "playlists.dat"

void pasarDeArchivoPlaylistToADL(stCelda * usuarios, int validos, nodoArbolCancion * arbolCancion){
    stPlaylist a;
    stCancion cancion;
    stUsuario usuario;
    int pos;
    FILE *pArch = fopen(arPlaylists, "rb");
    if(pArch){
        while(fread(&a, sizeof(stPlaylist), 1, pArch)>0){
            nodoListaCancion * aux;
            cancion = buscarNodoPorId(arbolCancion, a.idCancion);
            usuario = buscarUsuarioPorIdCeldas(usuarios, validos, a.idUsuario);
            if(!cancion.eliminado && !usuario.eliminado){
                aux = crearNodoLista(cancion);
                pos = buscarPosPorIdCeldas(usuarios, validos, usuario.idUsuario);
                usuarios[pos].listaCanciones = agregarNodoListaCancion(usuarios[pos].listaCanciones, aux);
            }
        }
        fclose(pArch);
    }
}

void mostrarPlaylist(nodoListaCancion * lista){
    if(lista){
        mostrarCancion(lista->c);
        mostrarPlaylist(lista->sig);
    }
}

void actualizarCancionesEscuchadas(int idCancion, int idUsuario){
    stPlaylist a;
    a.idPlaylist=buscaUltimoIdPlaylist();
    a.idCancion = idCancion;
    a.idUsuario = idUsuario;
    FILE *pArch = fopen(arPlaylists,"ab");
    if(pArch != NULL){
        fwrite(&a, sizeof(stPlaylist),1,pArch);
        fclose(pArch);
    }
}

int buscaUltimoIdPlaylist(){ //REVISA EL ULTIMO ID REGISTRADO
    int idPlaylist=-1;
    stPlaylist a;
    FILE *pArch = fopen(arPlaylists,"rb");
    if(pArch != NULL){
        fseek(pArch,sizeof(stPlaylist)*(-1),SEEK_END);
        if(fread(&a,sizeof(stPlaylist),1,pArch)>0){
            idPlaylist=a.idPlaylist;
        }
        fclose(pArch);
    }

    return idPlaylist;
}



