#include "funcionesPantalla.h"


void menuInicio(stCelda * usuarios, int validos, nodoArbolCancion * canciones){// MENU DEL INICIO DEL PROGRAMA, MUESTRA OPCIONES Y REALIZA FUNCIONES SEGUN LO SELECCIONADO
    int respuesta = 0;
    do{
        system("cls");
        printf("Bienvenido a Stopify!!! Seleccione una opción...\n");
        printf("1) Iniciar sesion\n");
        printf("2) Registrarse\n");
        printf("3) Salir\n");
        scanf("%d", &respuesta);
        if((respuesta<1)&&(respuesta>4)){
            printf("\nOpción inválida... Intente otra vez");
        }
    }while((respuesta<1)&&(respuesta>3));
    switch(respuesta){
        case 1:
            login(usuarios, validos, canciones);
            break;
        case 2:
            registroUsuario(usuarios, validos);
            break;
        default:
            return;
    }
}


void login(stCelda * usuarios, int validos, nodoArbolCancion * canciones){ //MUESTRA POR PANTALLA EL LOGIN Y MANDA LO OBTENIDO A VALIDAR LOGIN
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
    controlDeVistas(a, usuarios, validos, canciones);
}

void controlDeVistas(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones){ //MUESTRA UNA VISTA U OTRA DEPENDIENDO DE SI EL USUARIO ES ADMIN O USUARIO COMUN
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
            vistaAdmin(a, usuarios, validos, canciones);
            break;
        case 1:
            vistaUsuario(a, usuarios, validos, canciones);
            break;
        default:
            return;
        }
    }
}

void vistaUsuario(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones){ //MUESTRA LAS OPCIONES A UN USUARIO COMUN (NO ADMINISTRADOR) Y EJECUTA FUNCIONES SEGUN LO SELECCIONADO
    int opcion = 0;
    do{
        system("cls");
        printf("\n----------------------------------------------------");
        printf("\n Bienvenido %s", a.nombreUsuario);
        printf("\n Seleccione una opcion...");
        printf("\n 1) Ver mi perfil");
        printf("\n 2) Mostrar catalogo de canciones");
        printf("\n 3) Escuchar cancion");
        printf("\n 4) Canciones recomendadas");
        printf("\n 5) Salir");
        printf("\n----------------------------------------------------");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                menuVerMiPerfil(usuarios, validos, a);
                break;
            case 2:
                menuMostrarCatalogoCanciones(canciones);
                break;
            case 3:
                menuEscucharCancion(a, usuarios, validos, canciones);
                break;
            case 4:
                menuCancionesRecomendadas(a, usuarios, validos, canciones);
                break;
            case 5:
                break;
            default:
                return;
        }
    }while(opcion<5);
}

void menuMostrarCatalogoCanciones(nodoArbolCancion * canciones){//MUESTRA LOS DATOS DEL USUARIO COMUN LOGEADO
    system("cls");
    stCancion * arreglo;
    arreglo = (stCancion*) malloc(cantidadCancionesArch()*sizeof(stCancion));
    int validos = 0;
    printf("\n <<<<<<< CANCIONES >>>>>>>>>");
    pasarArbol2Arreglo(arreglo, canciones, &validos);
    int opcion = 0;
    system("cls");
    printf("Seleccione una opcion...\n");
    printf("1) Listar por titulo...\n");
    printf("2) Listar por genero...\n");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
                ordenaArregloTitulo(arreglo, validos);
                system("cls");
                muestraArregloTitulo(arreglo, validos);
            break;
        case 2:
                ordenaArregloGenero(arreglo, validos);
                system("cls");
                muestraArregloGenero(arreglo, validos);
            break;
        default:
            return;
    }

    printf("\n");
    system("pause");
}

void menuVerMiPerfil(stCelda * usuarios, int validos, stUsuario a){//MUESTRA LOS DATOS DEL USUARIO COMUN LOGEADO
    system("cls");
    printf("\n <<<<<<< MI PERFIL >>>>>>>>>");
    int pos = buscarPosPorIdCeldas(usuarios, validos, a.idUsuario);
    mostrarCeldaUsuario(usuarios[pos]);
    printf("\n");
    system("pause");
}

void menuEscucharCancion(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones){
    system("cls");
    int id;
    int pos = buscarPosPorIdCeldas(usuarios, validos, a.idUsuario);
    stCancion cancion;
    char opcion;
    nodoListaCancion * aux;
    do{
    cancion.idCancion == -1;
    printf("\n <<<<<<< ESCUCHAR CANCION >>>>>>>>>");
    printf("\n Ingresa el id de la cancion que queres escuchar: ");
    scanf("%d", &id);
    cancion = buscarNodoPorId(canciones, id);
    if(!existeCancionPorId(canciones, id)){
        printf("\n Cancion no encontrada...");
    }
    else{
        aux = crearNodoLista(cancion);
        usuarios[pos].listaCanciones = agregarNodoListaCancion(usuarios[pos].listaCanciones, aux);
        actualizarCancionesEscuchadas(id, a.idUsuario);
        printf("\nCancion guardada con exito");
    }
    printf("\nPresiona cualquier tecla para agregar otra cancion o Esc para salir");
    opcion = getch();
    }while(opcion!=27);
}

void menuCancionesRecomendadas(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones){ //MUESTRA HASTA 5 CANCIONES AL AZAR
    system("cls");
    srand(time(NULL));
    printf(" <<<<<<<<<< CANCIONES RECOMENDADAS >>>>>>>>>>>");
    int pos = buscarPosPorIdCeldas(usuarios, validos, a.idUsuario);
    int cantidad = cantidadCancionesPlaylist(usuarios[pos].listaCanciones);
    int numNodo;
    stCancion cancion;
    if(cantidad>0){
        numNodo=rand()%cantidad;
        cancion = buscarPorPosNodo(usuarios[pos].listaCanciones, numNodo);
        printf("\nTe recomendamos...");
        printf("\nCanciones del genero... %s", cancion.genero);
        mostrarArbolInGenero(canciones, cancion.genero);
    }
    else{
        int id = rand()%cantidadCancionesArch();
        cancion = buscarNodoPorId(canciones, id);
        printf("\nTe recomendamos...");
        mostrarCancion(cancion);
    }
    printf("\n");
    system("pause");
}

void vistaAdmin(stUsuario a, stCelda * usuarios, int validos, nodoArbolCancion * canciones){ // MUESTRA LAS OPCIONES A UN ADMINISTRADOR Y EJECUTA FUNCIONES SEGUN LO SELECCIONADO
    int opcion = 0;
    do{
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
                validos = gestionUsuarios(a, usuarios, validos);
                break;
            case 2:
                canciones = gestionCanciones(canciones);
                break;
            default:
                return;
        }
    }while(opcion==1 || opcion==2);
}


int gestionUsuarios(stUsuario a, stCelda * usuarios, int validos){ // MUESTRA TODAS LAS OPCIONES PARA GESTIONAR USUARIOS Y REALIZA UNA FUNCION SEGUN LA SELECCION DEL ADMIN
    int opcion = 0;
    do{
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
                validos = menuBorrarUsuario(usuarios, validos);
                break;
            case 3:
                menuModificarUsuario(usuarios, validos);
                break;
            case 4:
                menuBuscarUsuario();
                break;
            case 5:
                menuListarUsuarios();
                break;
            case 6:
                break;
            default:
                return;
        }
    }while(opcion<6);
    return validos;
}

int menuBorrarUsuario(stCelda * usuarios, int validos){ //MUESTRA EL FORMULARIO PARA BORRAR UN USUARIO POR ID
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
            validos--;
        }
        datosUsuario(a);
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA INGRESAR UN NUEVO USUARIO...");
        opcion = getch();
    }while(opcion == '27');
    return validos;
}

void menuModificarUsuario(stCelda * usuarios, int validos){ //MUESTRA OPCIONES PARA MODIFICAR UN USUARIO
    char opcion;
    int id;
    stUsuario a;
    do{
        system("cls");
        printf("\n\n <<<< MODIFICAR USUARIO >>>> \n\n");
        printf("\n Ingrese el id del usuario que desea modificar...");
        scanf("%d", &id);
        a = modificarUsuario(usuarios, validos, id);
        if(a.idUsuario==-1 || a.eliminado == 1){
            printf("\n ERROR: El usuario no se encontro...");
        }else{
            system("cls");
        }
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA MODIFICAR UN NUEVO USUARIO...");
        opcion = getch();
    }while(opcion!=27);
}

void menuBuscarUsuario(){
    char opcion;
    int id;
    stUsuario a;
    do{
        system("cls");
        printf("\n\n <<<< BUSCAR USUARIO >>>> \n\n");
        printf("\n Ingrese el id del usuario que desea ver...");
        scanf("%d", &id);
        a = buscarUsuarioPorIdArchivo(id);
        if(a.idUsuario==-1){
            printf("\n ERROR: El usuario no se encontro...");
        }else{
            datosUsuario(a);
        }
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA BUSCAR UN NUEVO USUARIO...");
        opcion = getch();
    }while(opcion!=27);
}

void menuListarUsuarios(){
    printf("\n\n <<<< LISTA DE USUARIOS COMPLETA >>>> \n\n");
    listarUsuarios();
    printf("\n");
    system("pause");
}


nodoArbolCancion * gestionCanciones(nodoArbolCancion * canciones){//MUESTRA TODAS LAS OPCIONES PARA GESTIONAR CANCIONES Y REALIZA UNA FUNCION SEGUN LA SELECCION DEL ADMIN
    int opcion = 0;
    do{
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
                canciones = menuAltaCancion(canciones);
                break;
            case 2:
                canciones = menuBorrarCancion(canciones);
                break;
            case 3:
                canciones = menuModificarCancion(canciones);
                break;
            case 4:
                menuBuscarCancion(canciones);
                break;
            case 5:
                menuListarCanciones();
                break;
            case 6:
                break;
            default:
                return;
        }
    }while(opcion<6);
    return canciones;
}

nodoArbolCancion * menuAltaCancion(nodoArbolCancion * canciones){
    char opcion;
    stCancion a;
    nodoArbolCancion * nueva;
    do{
        a = altaCancion();
        nueva = crearNodoArbol(a);
        canciones = insertarNodoArbol(canciones, nueva);
        guardarCancion(a);
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA INGRESAR UNA NUEVA CANCION...");
        opcion = getch();
        }while(opcion!=27);
    return canciones;
}

nodoArbolCancion * menuBorrarCancion(nodoArbolCancion * canciones){ //PIDE UN ID Y BORRA UNA CANCION DENTRO DEL ARCHIVO
    char opcion;
    int id;
    stCancion a;
    do{
        system("cls");
        printf("\n\n <<<< ELIMINAR CANCION >>>> \n\n");
        printf("\n Ingrese el id de la cancion que desea eliminar...");
        scanf("%d", &id);
        canciones = borrarCancion(canciones, id);
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA INGRESAR UNA NUEVA CANCION...");
        opcion = getch();
    }while(opcion!=27);
    return canciones;
}

nodoArbolCancion * menuModificarCancion(nodoArbolCancion * canciones){
    char opcion;
    int id;
    stCancion a;
    do{
        a.idCancion = -1;
        system("cls");
        printf("\n\n <<<< MODIFICAR CANCION >>>> \n\n");
        printf("\n Ingrese el id de la cancion que desea modificar...");
        scanf("%d", &id);
        a = buscarNodoPorId(canciones, id);
        if(a.idCancion==-1 || a.idCancion == 1){
            printf("\n ERROR: La cancion no se encontro...");
        }else{
            datosCancion(a);
            a = modificarCancion(a);
            modificarNodoDeCancion(canciones, a);
            modificarCancionArch(a);
            printf("\n CANCION MODIFICADA CORRECTAMENTE");
        }
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA MODIFICAR UNA NUEVA CANCION...");
        opcion = getch();
    }while(opcion!=27);
}

void menuBuscarCancion(nodoArbolCancion * canciones){ //PIDE UN ID PARA BUSCAR DENTRO DEL ARCHIVO DE CANCIONES
    char opcion;
    int id;
    stCancion a;
    do{
        a.idCancion = -1;
        system("cls");
        printf("\n\n <<<< BUSCAR CANCION >>>> \n\n");
        printf("\n Ingrese el id de la cancion que desea modificar...");
        scanf("%d", &id);
        a = buscarCancion(id);
        if(a.idCancion==-1){
            printf("\n ERROR: La cancion no se encontro...");
        }
        printf("\n\n\n ESC PARA VOLVER AL MENU...");
        printf("\n\n\n CUALQUIER OTRA TECLA PARA BUSCAR UNA NUEVA CANCION...");
        opcion = getch();
    }while(opcion!=27);
}

void menuListarCanciones(){ //MUESTRA OPCIONES PARA LISTAR TODAS LAS CANCIONES POR TITULO O POR GENERO
    int opcion = 0;
    system("cls");
    printf("Seleccione una opcion...\n");
    printf("1) Listar por titulo...\n");
    printf("2) Listar por genero...\n");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            listarPorTitulo();
            break;
        case 2:
            listarPorGenero();
            break;
        default:
            return;
    }
    printf("\n");
    system("pause");
}


stUsuario altaUsuario(stCelda * usuarios, int validos){
        stUsuario a;
        int usuarioYaRegistrado = 0;
        a.idUsuario = buscaUltimoIdUsuario(usuarios, validos);
        a.idUsuario++;
        do{
            system("cls");
            printf("\n\n <<<< REGISTRO >>>> \n\n");
            printf("\n NOMBRE DE USUARIO.......:  ");
            fflush(stdin);
            gets(a.nombreUsuario);
            usuarioYaRegistrado = revisarNombreUsuario(usuarios, validos, a.nombreUsuario);
            if(usuarioYaRegistrado == 1){
                printf("\nESE NOMBRE DE USUARIO NO ESTA DISPONIBLE... ELIJA OTRO...\n");
                system("pause");
            }
        }while(usuarioYaRegistrado == 1);
        printf("\n CLAVE.......:  ");
        fflush(stdin);
        gets(a.pass);
        printf("\n FECHA DE NACIMIENTO.......:  ");
        scanf("%d", &a.anioNacimiento);
        printf("\n GENERO.......:  ");
        fflush(stdin);
        scanf("%c", &a.genero);
        printf("\n PAIS.......:  ");
        fflush(stdin);
        gets(a.pais);
        a.tipoUsuario = 1;
        a.eliminado = 0;
        return a;
}

void registroUsuario(stCelda * usuarios, int validos){ //VISTA DE REGISTRO
        stUsuario a = altaUsuario(usuarios, validos);
        guardarUsuario(a);
        printf("\n USUARIO REGISTRADO CORRECTAMENTE...\n");
        system("pause");
}


int agregarUsuarios(stCelda * usuarios, int validos){
    char opcion;
    do{
    stUsuario a = altaUsuario(usuarios, validos);
    validos = agregarUsuarioAArreglo(&usuarios, validos, a);
    guardarUsuario(a);
    printf("\n USUARIO REGISTRADO CORRECTAMENTE...\n");
    printf("\nDESEA INGRESAR OTRO USUARIO? S/n");
    opcion = getch();
    }while(opcion=='s');
    return validos;
}

stCancion altaCancion(){
    stCancion a;
    a.idCancion = buscaUltimoIdCancion();
    a.idCancion++;
    system("cls");
    printf("\n\n <<<< ALTA CANCION >>>> \n\n");
    printf("\n TITULO.......:  ");
    fflush(stdin);
    gets(a.titulo);
    printf("\n ARTISTA.......:  ");
    fflush(stdin);
    gets(a.artista);
    printf("\n DURACION.......:  ");
    scanf("%d", &a.duracion);
    printf("\n ALBUM.......:  ");
    fflush(stdin);
    gets(a.album);
    printf("\n AÑO.......:  ");
    scanf("%d", &a.anio);
    printf("\n GENERO.......:  ");
    fflush(stdin);
    gets(a.genero);
    printf("\n COMENTARIO.......:  ");
    fflush(stdin);
    gets(a.comentario);
    a.eliminado = 0;
    return a;
}


