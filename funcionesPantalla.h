#ifndef FUNCIONESPANTALLA_H_INCLUDED
#define FUNCIONESPANTALLA_H_INCLUDED
#include "celdasUsuarios.h"
#include "cancionesArbol.h"

void registroUsuario(stCelda * usuarios, int validos); //REGISTRO
stUsuario altaUsuario(stCelda * usuarios, int validos); //PANTALLA DE ALTA DE USUARIOS
int agregarUsuarios(stCelda * usuarios, int validos); //AGREGA UN USUARIO AL ARREGLO Y DEVUELVE LOS VALIDOS
stCancion altaCancion(); //PANTALLA DE ALTA DE CANCION
void menuListarCanciones(); //MUESTRA OPCIONES DE LISTAR
void menuBuscarCancion(nodoArbolCancion * canciones); //PANTALLA DE BUSCAR CANCION POR ID
nodoArbolCancion * menuModificarCancion(nodoArbolCancion * canciones); //PANTALLA DE MODIFICAR CANCION
nodoArbolCancion * menuBorrarCancion(nodoArbolCancion * canciones); //PANTALLA DE BORRAR CANCION
nodoArbolCancion * menuAltaCancion(nodoArbolCancion * canciones); //PANTALLA DE ALTA DE CANCION
nodoArbolCancion * gestionCanciones(nodoArbolCancion * canciones); //PANTALLA DE ADMINISTRADOR PARA GESTIONAR CANCIONES
void menuListarUsuarios(); //PANTALLA DE ADMINISTRADOR PARA LISTAR TODOS LOS USUARIOS
void menuBuscarUsuario(); //PANTALLA DE ADMINISTRADOR PARA BUSCAR USUARIO POR ID
void menuModificarUsuario(stCelda * usuarios, int validos); //PANTALLA DE ADMINISTRADOR PARA MODIFICAR USUARIO
int menuBorrarUsuario(stCelda * usuarios, int validos); //PANTALLA DE ADMINISTRADOR PARA BORRAR USUARIO
int gestionUsuarios(stUsuario a, stCelda * usuarios, int validos); //PANTALLA DE ADMINISTRADOR PARA GESTIONAR USUARIOS
void vistaAdmin(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones); //OPCIONES DE ADMINISTRADOR
void menuCancionesRecomendadas(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones); //PANTALLA DE CANCIONES RECOMENDADAS
void menuEscucharCancion(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones); //PANTALLA DE ESCUCHAR CANCION
void menuVerMiPerfil(stCelda * usuarios, int validos, stUsuario a); //PANTALLA DE PERFIL
void menuMostrarCatalogoCanciones(nodoArbolCancion * canciones); //PANTALLA DE MOSTRAR CATALOGO CANCIONES
void vistaUsuario(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones); //OPCIONES DEL USUARIO
void controlDeVistas(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones); //CONTROLA SI ES USUARIO O ADMIN Y MUESTRA UNA VISTA
void login(stCelda * usuarios, int validos, nodoArbolCancion * canciones); //PANTALLA DE LOGIN
void menuInicio(stCelda * usuarios, int validos, nodoArbolCancion * canciones); //MENU PRINCIPAL

#endif // FUNCIONESPANTALLA_H_INCLUDED
