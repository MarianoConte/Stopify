#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesPantalla.h"

int main()
{
    while(1){
    stCelda * usuarios;
    int dimension = cantUsuarios();
    usuarios = (stCelda *) malloc(dimension * (sizeof(stCelda)));
    int validos = archivoUsuarios2Arreglo(usuarios);
    //cargar arbol de canciones
    nodoArbolCancion * arbolCancion;
    arbolCancion = inicArbol();
    arbolCancion = cargarArbolDesdeArchivo();
    //llevar canciones a los usuarios mediante el archivo playlists
    pasarDeArchivoPlaylistToADL(usuarios, validos, arbolCancion);
    menuInicio(usuarios, validos, arbolCancion);
    }
}

