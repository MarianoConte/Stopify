#ifndef CELDASUSUARIOS_H_INCLUDED
#define CELDASUSUARIOS_H_INCLUDED
#include "usuarios.h"
#include "cancionesLista.h"

typedef struct
{
    stUsuario usr;
    nodoListaCancion * listaCanciones;
}stCelda;


int buscaUltimoIdUsuario(stCelda * usuarios, int validos);
int agregarUsuarioAArreglo(stCelda ** usuarios, int validos, stUsuario a);
void ordenarArregloDeUsuarios(stCelda * usuarios, int validos);
int revisarNombreUsuario(stCelda * usuarios, int validos, char nombreUsuario[]);
int borrarUsuarioEstructura(stCelda * usuarios, int validos, int id);
stUsuario validarLogin(char usuario[], char password[], stCelda * usuarios, int validos);
int archivoUsuarios2Arreglo(stCelda * usuarios);
stUsuario modificarUsuario(stCelda * usuarios, int validos, int id);
#endif // CELDASUSUARIOS_H_INCLUDED
