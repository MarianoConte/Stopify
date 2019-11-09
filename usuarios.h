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

stUsuario borrarUsuarioArchivo(int id);
void guardarUsuario(stUsuario a);
int cantUsuarios();
void datosUsuario(stUsuario a);


#endif // USUARIOS_H_INCLUDED
