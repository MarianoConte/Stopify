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
    arbolCancion = cargarArbol();
    //llevar canciones a los usuarios mediante el archivo playlists
    cargarPlaylistsUsuarios(usuarios, validos, arbolCancion);
    menuInicio(usuarios, validos);
    }
}


void menuInicio(stCelda * usuarios, int validos){// MENU DEL INICIO DEL PROGRAMA, MUESTRA OPCIONES Y REALIZA FUNCIONES SEGUN LO SELECCIONADO
    int respuesta = 0;
    do{
        system("cls");
        printf("Bienvenido a Stopify!!! Seleccione una opción...\n");
        printf("1) Ingresar como Administrador\n");
        printf("2) Ingresar como Usuario\n");
        printf("3) Registrarse\n");
        printf("4) Salir\n");
        scanf("%d", &respuesta);
        if((respuesta<1)&&(respuesta>4)){
            printf("\nOpción inválida... Intente otra vez");
        }
    }while((respuesta<1)&&(respuesta>4));
    switch(respuesta){
        case 1:
         //   login();
            break;
        case 2:
            login(usuarios, validos);
            break;
        case 3:
            registroUsuario(usuarios, validos);
            break;
        default:
            return;
    }
}


void login(stCelda * usuarios, int validos){ //MUESTRA POR PANTALLA EL LOGIN Y MANDA LO OBTENIDO A VALIDAR LOGIN
    stUsuario a;
    char usuario[30];
    char pass[20];
    system("cls");
    printf("\t<<<INICIO DE SESION>>>\n\n");
    printf("Ingrese sus datos...\n");
    printf("Usuario: ");
    fflush(stdin);
    gets(&usuario);
    printf("Clave: ");
    fflush(stdin);
    gets(&pass);
    a = validarLogin(usuario, pass, usuarios, validos);
    controlDeVistas(a, usuarios, validos);
}

void controlDeVistas(stUsuario a, stCelda * usuarios, int validos){ //MUESTRA UNA VISTA U OTRA DEPENDIENDO DE SI EL USUARIO ES ADMIN O USUARIO COMUN
    system("cls");
    if(a.idUsuario == -1){
        printf("Usuario no encontrado... \n");
        system("pause");
        }
    else if(a.idUsuario == -2){
        printf("Contraseña incorrecta... \n");
        system("pause");
        }
    else{
        switch(a.tipoUsuario){
        case 0:
            vistaAdmin(a, usuarios, validos);
            system("pause");
            break;
        case 1:
            printf("\nSoy un usuario...");
            system("pause");
            break;
        default:
            return;
        }
    }
}

void vistaAdmin(stUsuario a, stCelda * usuarios, int validos){ // MUESTRA LAS OPCIONES A UN ADMINISTRADOR Y EJECUTA FUNCIONES SEGUN LO SELECCIONADO
    int opcion = 0;
    system("cls");
    printf("\n----------------------------------------------------");
    printf("\n Bienvenido %s", a.nombreUsuario);
    printf("\n Seleccione una opcion...");
    printf("\n 1) Gestion de usuarios");
    printf("\n 2) Gestion de canciones");
    printf("\n 3) Salir");
    printf("\n----------------------------------------------------");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            gestionUsuarios(a, usuarios, validos);
            break;
        case 2:
           // gestionCanciones(a);
            break;
        case 3:
          //  menuInicio();
            break;
        default:
            return;
    }
}


int gestionUsuarios(stUsuario a, stCelda * usuarios, int validos){ // MUESTRA TODAS LAS OPCIONES PARA GESTIONAR USUARIOS Y REALIZA UNA FUNCION SEGUN LA SELECCION DEL ADMIN
    int opcion = 0;
    system("cls");
    printf("\n----------------------------------------------------");
    printf("\n Seleccione una opcion...");
    printf("\n 1) Agregar");
    printf("\n 2) Eliminar");
    printf("\n 3) Modificar");
    printf("\n 4) Buscar");
    printf("\n 5) Listar");
    printf("\n 6) Volver atras");
    printf("\n 7) Salir");
    printf("\n----------------------------------------------------");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            validos = agregarUsuarios(usuarios, validos);
            break;
        case 2:
            menuBorrarUsuario(usuarios, validos, a);
            break;
        case 3:
            menuModificarUsuario(a);
            break;
        case 4:
       //     menuBuscarUsuario(a);
            break;
        case 5:
        //    listarUsuarios(a);
            break;
        case 6:
      //      vistaAdmin(a);
            break;
        case 7:
    //        menuInicio();
        default:
            return;
    }
    return validos;
}

void menuBorrarUsuario(stCelda * usuarios, int validos, stUsuario admin){ //MUESTRA EL FORMULARIO PARA BORRAR UN USUARIO POR ID
    char opcion;
    int id=0;
    stUsuario a;
    int flag=0;
    do{
        system("cls");
        printf("\n\n <<<< ELIMINAR USUARIO >>>> \n\n");
        printf("\n Ingrese el id del usuario que desea eliminar...");
        scanf("%d", &id);
        flag = borrarUsuarioEstructura(usuarios, validos, id);
        if(flag == 0){
            printf("\n ERROR: El usuario no se encontro dentro de la estructura...");
        }
        a = borrarUsuarioArchivo(id);
        if(a.idUsuario==-1){
            printf("\n ERROR: El usuario no se encontro dentro del archivo...");
        }else{
            printf("\n USUARIO ELIMINADO CORRECTAMENTE");
        }
        datosUsuario(a);
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA INGRESAR UN NUEVO USUARIO...");
        opcion = getch();
    }while(opcion == '27');
}

void menuModificarUsuario(stUsuario admin){ //MUESTRA OPCIONES PARA MODIFICAR UN USUARIO
    char opcion;
    int id;
    stUsuario a;
    do{
        system("cls");
        printf("\n\n <<<< MODIFICAR USUARIO >>>> \n\n");
        printf("\n Ingrese el id del usuario que desea modificar...");
        scanf("%d", &id);
  //      a = modificarUsuario(id);
        if(a.idUsuario==-1){
            printf("\n ERROR: El usuario no se encontro...");
        }else{
            system("cls");
            printf("\n USUARIO MODIFICADO CORRECTAMENTE");
        }
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA MODIFICAR UN NUEVO USUARIO...");
        opcion = getch();
    }while(opcion!=27);
}



