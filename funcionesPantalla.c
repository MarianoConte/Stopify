#include "funcionesPantalla.h"


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
        a.eliminado = 0;
        return a;
}

void registroUsuario(stCelda usuarios[], int validos){ //VISTA DE REGISTRO
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


