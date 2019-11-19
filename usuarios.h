#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int idUsuario;
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero;
    char pais[20];
    int eliminado;   // indica 1 o 0 si el cliente fue eliminado
    int tipoUsuario; //0 es admin 1 es usuario comun
} stUsuario;

stUsuario borrarUsuarioArchivo(int id); //ELIMINA UN USUARIO DENTRO DEL ARCHIVO
void guardarUsuario(stUsuario a); //GUARDA UN USUARIO DENTRO DEL ARCHIVO
int cantUsuarios(); //DEVUELVE LA CANTIDAD DE USUARIOS NO ELIMINADOS
int cantUsuariosTotal(); //DEVUELVE LA CANTIDAD DE USUARIOS TOTALES
void datosUsuario(stUsuario a); //MUESTRA UN USUARIO PARA EL ADMIN
void datosUsuarioUsuario(stUsuario a); //MUESTRA EL PERFIL DEL USUARIO
void modificarUsuarioArchivo(stUsuario usuario); //MODIFICA UN USUARIO DENTRO DE UN ARCHIVO
void listarUsuarios(); //MUESTRA UN LISTADO DE TODOS LOS USUARIOS ORDENADOS POR NOMBRE DE USUARIO
void muestraArregloNombreUsuario(char array[][30], int v); //MUESTRA EL ARREGLO ORDENADO POR NOMBRES DE USUARIO
void insertaUsuario(char array[][30],int v, char dato[30]); //INSERTA UN USUARIO
void ordenaArregloNombreUsuario(char array[][30],int v); //ORDENA UN ARREGLO POR NOMBRE DE USUARIO
stUsuario buscarUsuarioPorIdArchivo(int id); //BUSCA UN USUARIO POR ID DENTRO DEL ARCHIVO
#endif // USUARIOS_H_INCLUDED
