#include "cancionesBasico.h"
#define arCanciones "canciones.dat"


void mostrarCancion(stCancion cancion){

        printf("\n----------------------------------\n");
        printf("id: %d\n", cancion.idCancion);
        printf("titulo: %s", cancion.titulo);
        printf("\n----------------------------------\n");
}

void cargarArregloCanciones(stCancion * arreglo){
    stCancion a;
    int c = 0;
    FILE *pArch = fopen(arCanciones, "rb");
    if(pArch){
        while(fread(&a, sizeof(stCancion), 1, pArch)>0){
                arreglo[c] = a;
                c++;
        }
        fclose(pArch);
    }
}

int cantidadCancionesArch(){
    int c=0;
    stCancion a;
    FILE *pArch = fopen(arCanciones, "rb");
    if(pArch){
        while(fread(&a, sizeof(stCancion), 1, pArch)>0){
            c++;
        }
        fclose(pArch);
    }
    return c;
}


