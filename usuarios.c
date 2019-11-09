#include "usuarios.h"
#define arUsuarios "usuarios.dat"

stUsuario borrarUsuarioArchivo(int id){ //CAMBIA EL VALOR DEL USUARIO ELIMINADO DE 0 A 1
    int flag = 0;
    stUsuario a;
    FILE *pArchUsuarios = fopen(arUsuarios,"r+b");
    if(pArchUsuarios != NULL){
        while((flag==0)&&(fread(&a,sizeof(stUsuario),1,pArchUsuarios)>0)){
            if(a.idUsuario == id){
                flag = 1;
            }
        }
        if(flag==1){
        a.eliminado = 1;
        fseek(pArchUsuarios, sizeof(stUsuario)*-1, SEEK_CUR);
        fwrite(&a, sizeof(stUsuario), 1, pArchUsuarios);
        }
        else{
            a.idUsuario=-1;
        }
        fclose(pArchUsuarios);
    }

    return a;
}


void guardarUsuario(stUsuario a){ //GUARDA EL USUARIO REGISTRADO EN UN ARCHIVO
    FILE * pArchUsuarios = fopen(arUsuarios, "ab");
    if(pArchUsuarios!=NULL)
    {
        fwrite(&a, sizeof(stUsuario),1,pArchUsuarios);
        fclose(pArchUsuarios);
    }
}

int cantUsuarios(){
    FILE *pArch = fopen(arUsuarios, "rb");
    stUsuario a;
    int c = 0;
    if(pArch){
        while(fread(&a, sizeof(stUsuario), 1, pArch)>0){
        c++;
        }
        fclose(pArch);
    }
    return c;
}

void datosUsuario(stUsuario a){ //MUESTRA TODOS LOS DATOS DE UN USUARIO
   // stCancion c;
    printf("\n NOMBRE..............: %s", a.nombreUsuario);
    printf("\n ID..............: %d", a.idUsuario);
    printf("\n ELIMINADO..............: %d", a.eliminado);
    printf("\n GENERO..............: %c", a.genero);
    printf("\n PAIS..............: %s", a.pais);
    printf("\n CONTRASEÑA..............: %s", a.pass);
    printf("\n TIPO DE USUARIO..............: %d", a.tipoUsuario);
    printf("\n AÑO DE NACIMIENTO..............: %d", a.anioNacimiento);
  /*  printf("\n PLAYLIST PERSONAL..............:");
    printf("\n ID - CANCION");
    for(int i=0;i<a.cantidad;i++){
        imprimirCancionPorId(a.playlist[i]);
    }*/
}




