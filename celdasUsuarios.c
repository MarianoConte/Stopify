#include "celdasUsuarios.h"
#define arUsuarios "usuarios.dat"

int buscaUltimoIdUsuario(stCelda * usuarios, int validos){ //REVISA EL ULTIMO ID REGISTRADO
    int idUsuario=-1;
    for(int i=0;i<validos;i++){
        if(usuarios[i].usr.idUsuario > idUsuario){
            idUsuario = usuarios[i].usr.idUsuario;
        }
    }
    return idUsuario;
}

int agregarUsuarioAArreglo(stCelda ** usuarios, int validos, stUsuario a){
    stCelda nueva;
    nueva.usr = a;
    validos++;
    (*usuarios) = realloc((*usuarios), validos * sizeof(stCelda));
    (*usuarios)[validos-1] = nueva;
    return validos;
}

void mostrarCeldaUsuario(stCelda usuario){
    datosUsuarioUsuario(usuario.usr);
    printf("\n <<<<<<< MIS CANCIONES >>>>>>>>>");
    mostrarPlaylist(usuario.listaCanciones);
}

stCelda * ordenarArregloDeUsuarios(stCelda * usuarios, int validos){
    stCelda aux;
    for(int i=0;i<validos;i++){
        for(int v=0;i<validos;i++){
            if(strcmp(usuarios[i].usr.nombreUsuario, usuarios[v].usr.nombreUsuario)>0){
                aux = usuarios[i];
                usuarios[i] = usuarios[v];
                usuarios[v] = aux;
            }
        }
    }
    return usuarios;
}


void mostrarUsuarios(stCelda * usuarios, int validos){
    for(int i=0;i<validos;i++){
        datosUsuario(usuarios[i].usr);
    }
}


int revisarNombreUsuario(stCelda * usuarios, int validos, char nombreUsuario[]){
    int c=0;
    int rta=0;
    while(c<validos && rta==0){
        if(strcmp(usuarios[c].usr.nombreUsuario, nombreUsuario)==0){
            rta=1;
        }
        c++;
    }
    return rta;
}

int borrarUsuarioEstructura(stCelda * usuarios, int validos, int id){
    int flag = 0;
    int i=0;
    while(i<validos && flag == 0){
        if(usuarios[i].usr.idUsuario == id){
            usuarios[i].usr.eliminado = 1;
            flag=1;
        }
        i++;
    }
    return flag;
}

stUsuario validarLogin(char usuario[], char password[], stCelda * usuarios, int validos){ //CHEQUEA QUE EL USUARIO Y LA CONTRASEÑA SEAN CORRECTOS
    int flagUsuario = 0;
    int flagPassword = 0;
    int c = 0;
    stUsuario a;
    while(c<validos && flagUsuario==0){
        a = usuarios[c].usr;
        if((strcmp(a.nombreUsuario, usuario) == 0)&&(a.eliminado==0)){
            flagUsuario = 1;
            if(strcmp(a.pass, password) == 0){
            flagPassword = 1;
            }
        }
        c++;
    }
    if((flagUsuario == 0)&&(flagPassword == 0)){
        a.idUsuario = -1;
    }
    else if((flagUsuario == 1)&&(flagPassword == 0)){
        a.idUsuario = -2;
    }

    return a;
}

int archivoUsuarios2Arreglo(stCelda * usuarios){
    FILE *pArch = fopen(arUsuarios, "rb");
    stUsuario a;
    stCelda celda;
    int v=0;
    if(pArch){
        while(fread(&a, sizeof(stUsuario), 1, pArch)>0){
            celda.usr = a;
            if(a.eliminado==0){
                celda.listaCanciones = inicLista();
                usuarios[v] = celda;
                v++;
            }
        }
        fclose(pArch);
    }
    return v;
}

stUsuario buscarUsuarioPorIdCeldas(stCelda * usuarios, int validos, int id){
    int i=0, flag=0;
    stUsuario rta;
    while(i<validos && flag == 0){
        if(usuarios[i].usr.idUsuario == id){
            rta = usuarios[i].usr;
            flag = 1;
        }
        i++;
    }
    if(flag==0){
        rta.idUsuario == -1;
    }
    return rta;
}

int buscarPosPorIdCeldas(stCelda * usuarios, int validos, int id){
    int i=0, flag=0;
    while(i<validos && flag == 0){
        if(usuarios[i].usr.idUsuario == id){
            flag = 1;
        }
        else{
            i++;
        }
    }
    return i;
}


stUsuario modificarUsuario(stCelda * usuarios, int validos, int id){ //MODIFICA AL USUARIO DENTRO DEL REGISTRO
    stUsuario a;
    int pos = -1;
    int rta=1;
    int opcion;
    a = buscarUsuarioPorIdCeldas(usuarios, validos, id);
    if(a.idUsuario!=-1){
        printf("<<<< USUARIO ENCONTRADO >>>> ");
            datosUsuario(a);
            printf("\n----------------------------------------------------");
            printf("\n Qué desea modificar?...");
            printf("\n 1) Nombre de usuario");
            printf("\n 2) Clave");
            printf("\n 3) Fecha de Nac.");
            printf("\n 4) Genero");
            printf("\n 5) Pais");
            printf("\n 6) Tipo de usuario");
            printf("\n----------------------------------------------------");
            scanf("%d", &opcion);
            switch(opcion){
                case 1:
                    printf("\n NUEVO NOMBRE DE USUARIO.......:  ");
                    while(rta==1){
                    fflush(stdin);
                    gets(a.nombreUsuario);
                    rta = revisarNombreUsuario(usuarios, validos, a.nombreUsuario);
                    if(rta==1){
                        printf("\n USUARIO YA EXISTENTE... ");
                        printf("\n INGRESE OTRO NOMBRE DE USUARIO... \n");
                        }
                    }
                    break;
                case 2:
                    printf("\n NUEVA CLAVE.......:  ");
                    fflush(stdin);
                    gets(a.pass);
                    break;
                case 3:
                    printf("\n NUEVA FECHA DE NACIMIENTO.......:  ");
                    scanf("%d", &a.anioNacimiento);
                    break;
                case 4:
                    printf("\n NUEVO GENERO.......:  ");
                    fflush(stdin);
                    scanf("%c", &a.genero);
                    break;
                case 5:
                    printf("\n NUEVO PAIS.......:  ");
                    fflush(stdin);
                    gets(a.pais);
                    break;
                case 6:
                    printf("\n NUEVO TIPO DE USUARIO.......:  ");
                    scanf("%d", &a.tipoUsuario);
                    break;
                default:
                    printf("\n OPCIÓN INVÁLIDA...");
                    system("pause");
                    return;
                }
            pos = buscarPosPorIdCeldas(usuarios, validos, id);
            usuarios[pos].usr = a;
            modificarUsuarioArchivo(a);
            printf("\n USUARIO MODIFICADO CORRECTAMENTE");
    }
    return a;
}



