#ifndef CELDASUSUARIOS_H_INCLUDED
#define CELDASUSUARIOS_H_INCLUDED
#include "usuarios.h"
#include "cancionesLista.h"

typedef struct
{
    stUsuario usr;
    nodoListaCancion * listaCanciones;
}stCelda;


int buscaUltimoIdUsuario(stCelda * usuarios, int validos); //BUSCA EL ULTIMO ID USADO
int agregarUsuarioAArreglo(stCelda ** usuarios, int validos, stUsuario a); //AGREGA UN USUARIO AL ARREGLO DE USUARIOS
void mostrarCeldaUsuario(stCelda usuario); //MUESTRA EL CONTENIDO DE UNA CELDA
stCelda * ordenarArregloDeUsuarios(stCelda * usuarios, int validos); //ORDENA EL ARREGLO DE USUARIOS
int revisarNombreUsuario(stCelda * usuarios, int validos, char nombreUsuario[]); //REVISA SI EL NOMBRE DE USUARIO ESTA DISPONIBLE
int borrarUsuarioEstructura(stCelda * usuarios, int validos, int id); //BORRA EL USUARIO DEL ARREGLO
stUsuario validarLogin(char usuario[], char password[], stCelda * usuarios, int validos); //VALIDA EL LOGIN
int archivoUsuarios2Arreglo(stCelda * usuarios); //PASA LOS USUARIOS DEL ARCHIVO AL ARREGLO
stUsuario modificarUsuario(stCelda * usuarios, int validos, int id); //MODIFICA UN USUARIO DENTRO DEL ARREGLO
stUsuario buscarUsuarioPorIdCeldas(stCelda * usuarios, int validos, int id); //BUSCA UN USUARIO POR ID DENTRO DEL ARREGLO
int buscarPosPorIdCeldas(stCelda * usuarios, int validos, int id); //BUSCA UNA POSICION POR ID DENTRO DEL ARREGLO
void mostrarUsuarios(stCelda * usuarios, int validos); //MUESTRA UNICAMENTE LOS USUARIOS DE UN ARREGLO

#endif // CELDASUSUARIOS_H_INCLUDED
