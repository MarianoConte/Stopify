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
        if(a.eliminado==0){
            c++;
            }
        }
        fclose(pArch);
    }
    return c;
}

int cantUsuariosTotal(){
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
    printf("\n ID..............: %d", a.idUsuario);
    printf("\n NOMBRE..............: %s", a.nombreUsuario);
    printf("\n ELIMINADO..............: %d", a.eliminado);
    printf("\n GENERO..............: %c", a.genero);
    printf("\n PAIS..............: %s", a.pais);
    printf("\n CONTRASEÑA..............: %s", a.pass);
    printf("\n TIPO DE USUARIO..............: %d", a.tipoUsuario);
    printf("\n AÑO DE NACIMIENTO..............: %d", a.anioNacimiento);
}

void datosUsuarioUsuario(stUsuario a){
    printf("\n NOMBRE..............: %s", a.nombreUsuario);
    printf("\n GENERO..............: %c", a.genero);
    printf("\n PAIS..............: %s", a.pais);
    printf("\n CONTRASEÑA..............: %s", a.pass);
    printf("\n TIPO DE USUARIO..............: %d", a.tipoUsuario);
    printf("\n AÑO DE NACIMIENTO..............: %d", a.anioNacimiento);
}

void modificarUsuarioArchivo(stUsuario usuario){
    stUsuario a;
    int flag = 0;
    FILE *pArch = fopen(arUsuarios, "r+b");
    if(pArch){
        while(fread(&a,sizeof(stUsuario), 1, pArch)>0 && flag == 0){
            if(a.idUsuario == usuario.idUsuario){
                fwrite(&usuario, sizeof(stUsuario), 1, pArch);
                flag = 1;
            }
        }
        fclose(pArch);
    }
}


void listarUsuarios(){ //MUESTRA UN LISTADO DE TODOS LOS USUARIOS ORDENADOS POR NOMBRE DE USUARIO
    stUsuario a;
    int dimension = cantUsuariosTotal();
    int validos = 0;
    char array[dimension][30];
    FILE *pArchUsuarios = fopen(arUsuarios,"rb");
    if(pArchUsuarios != NULL){
        while((fread(&a,sizeof(stUsuario),1,pArchUsuarios)>0)&&(validos<dimension)){
            strcpy(array[validos],a.nombreUsuario);
            validos++;
        }
        fclose(pArchUsuarios);
    }
    ordenaArregloNombreUsuario(array, validos);
    system("cls");
    muestraArregloNombreUsuario(array, validos);
}


void muestraArregloNombreUsuario(char array[][30], int v){ //MUESTRA EL ARREGLO DE NOMBRES DE USUARIO
    int i;
    for(i=0;i<v;i++){
        printf("\n%d) %s",i,array[i]);
    }
}

void insertaUsuario(char array[][30],int v, char dato[30]){ //INSERTA UN NOMBRE DE USUARIO ORDENADAMENTE EN UN ARREGLO
    int i=v;
    while((i>=0)&&(strcmp(dato,array[i])<0)){
        strcpy(array[i+1],array[i]);
        i--;
    }
    strcpy(array[i+1],dato);
}

void ordenaArregloNombreUsuario(char array[][30],int v){//ORDENA UN ARREGLO DE NOMBRES DE USUARIO POR INSERCION
    int i;
    char aux[30];
    for(i=0;i<v-1;i++){
        strcpy(aux,array[i+1]);
        insertaUsuario(array,i,aux);
    }
}

stUsuario buscarUsuarioPorIdArchivo(int id){ //BUSCA EL USUARIO POR ID DENTRO DEL ARCHIVO Y LO MUESTRA
    int flag = 0;
    stUsuario a;
    FILE *pArchUsuarios = fopen(arUsuarios,"rb");
    if(pArchUsuarios != NULL){
        while((flag==0)&&(fread(&a,sizeof(stUsuario),1,pArchUsuarios)>0)){
            if(a.idUsuario == id){
                flag = 1;
            }
        }
        if(flag==1){
        fseek(pArchUsuarios, sizeof(stUsuario)*-1, SEEK_CUR);
        }
        else{
            a.idUsuario=-1;
        }
        fclose(pArchUsuarios);
    }
    return a;
}



