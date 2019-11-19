#include "cancionesBasico.h"
#define arCanciones "canciones.dat"


void mostrarCancion(stCancion cancion){

        printf("\n----------------------------------\n");
        printf("id: %d\n", cancion.idCancion);
        printf("titulo: %s\n", cancion.titulo);
        printf("artista: %s\n", cancion.artista);
        printf("album: %s\n", cancion.album);
        printf("duracion: %d\n", cancion.duracion);
        printf("comentarios: %s\n", cancion.comentario);
        printf("\n----------------------------------\n");
}

void cargarArregloCanciones(stCancion * arreglo){
    stCancion a;
    int c = 0;
    FILE *pArch = fopen(arCanciones, "rb");
    if(pArch){
        while(fread(&a, sizeof(stCancion), 1, pArch)>0){
                if(a.eliminado==0){
                    arreglo[c] = a;
                    c++;
                }
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
            if(a.eliminado==0){
                c++;
            }
        }
        fclose(pArch);
    }
    return c;
}

int cantidadCancionesCompleto(){
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

int buscaUltimoIdCancion(){ //BUSCA EL ULTIMO ID DE UNA CANCION DENTRO DEL ARCHIVO
    int idCancion=-1;
    stCancion a;
    FILE *pArCanciones = fopen(arCanciones,"rb");
    if(pArCanciones != NULL){
        fseek(pArCanciones,sizeof(stCancion)*(-1),SEEK_END);
        if(fread(&a,sizeof(stCancion),1,pArCanciones)>0){
            idCancion=a.idCancion;
        }
        fclose(pArCanciones);
    }

    return idCancion;
}

void guardarCancion(stCancion a){ //GUARDA UNA CANCION DENTRO DEL ARCHIVO
    FILE * pArchCanciones = fopen(arCanciones, "ab");
    if(pArchCanciones!=NULL)
    {
        fwrite(&a, sizeof(stCancion),1,pArchCanciones);
        fclose(pArchCanciones);
    }
}

void eliminarCancionArch(int id){ //CAMBIA EL DATO DE ELIMINADO DE UNA CANCION DE 0 A 1
    int flag = 0;
    stCancion a;
    FILE *pArchCanciones = fopen(arCanciones,"r+b");
    if(pArchCanciones != NULL){
        while((flag==0)&&(fread(&a,sizeof(stCancion),1,pArchCanciones)>0)){
            if(a.idCancion == id){
                flag = 1;
            }
        }
        if(flag==1){
        a.eliminado = 1;
        fseek(pArchCanciones, sizeof(stCancion)*-1, SEEK_CUR);
        fwrite(&a, sizeof(stCancion), 1, pArchCanciones);
        }
        fclose(pArchCanciones);
    }
}

void datosCancion(stCancion a){ //IMPRIME TODOS LOS DATOS DE UNA CANCION
    printf("\n ID..............: %d", a.idCancion);
    printf("\n TITULO..............: %s", a.titulo);
    printf("\n ARTISTA..............: %s", a.artista);
    printf("\n DURACION..............: %d", a.duracion);
    printf("\n ALBUM..............: %s", a.album);
    printf("\n AÑO..............: %d", a.anio);
    printf("\n GENERO..............: %s", a.genero);
    printf("\n COMENTARIO..............: %s", a.comentario);
    printf("\n ELIMINADO..............: %d", a.eliminado);
    printf("\n----------------------------------------------------");
};

stCancion modificarCancion(stCancion a){
    int opcion;
    printf("<<<< CANCION ENCONTRADA >>>> ");
    printf("\n----------------------------------------------------");
    printf("\n Qué desea modificar?...");
    printf("\n 1) Titulo");
    printf("\n 2) Artista");
    printf("\n 3) Duracion");
    printf("\n 4) Album");
    printf("\n 5) Año");
    printf("\n 6) Genero");
    printf("\n 7) Comentario");
    printf("\n----------------------------------------------------");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            printf("\n NUEVO TITULO.......:  ");
            fflush(stdin);
            gets(a.titulo);
            break;
        case 2:
            printf("\n NUEVO ARTISTA.......:  ");
            fflush(stdin);
            gets(a.artista);
            break;
        case 3:
            printf("\n DURACION.......:  ");
            scanf("%d", &a.duracion);
            break;
        case 4:
            printf("\n ALBUM.......:  ");
            fflush(stdin);
            gets(a.album);
            break;
        case 5:
            printf("\n AÑO.......:  ");
            scanf("%d", &a.anio);
            break;
        case 6:
            printf("\n GENERO.......:  ");
            fflush(stdin);
            gets(a.genero);
            break;
        case 7:
            printf("\n COMENTARIO.......:  ");
            fflush(stdin);
            gets(a.comentario);
            break;
        default:
            return;
    }
    return a;
}

void modificarCancionArch(stCancion cancion){
    int flag = 0;
    stCancion a;
    FILE *pArchCanciones = fopen(arCanciones,"r+b");
    if(pArchCanciones != NULL){
        while((flag==0)&&(fread(&a,sizeof(stCancion),1,pArchCanciones)>0)){
            if(a.idCancion == cancion.idCancion){
                flag = 1;
            }
        }
        if(flag == 1){
            fseek(pArchCanciones, sizeof(stCancion)*(cancion.idCancion), SEEK_SET);
            fwrite(&cancion, sizeof(stCancion), 1, pArchCanciones);
        }
        fclose(pArchCanciones);
    }
}


stCancion buscarCancion(int id){ //BUSCA LA CANCION POR ID DENTRO DEL ARCHIVO
    int flag = 0;
    stCancion a;
    FILE *pArchCanciones = fopen(arCanciones,"rb");
    if(pArchCanciones != NULL){
        while((flag==0)&&(fread(&a,sizeof(stCancion),1,pArchCanciones)>0)){
            if(a.idCancion == id){
                flag = 1;
            }
        }
        if(flag==1){
        fseek(pArchCanciones, sizeof(stCancion)*-1, SEEK_CUR);
        datosCancion(a);
        }
        else{
            a.idCancion=-1;
        }
        fclose(pArchCanciones);
    }

    return a;
}

int archivo2ArregloCompleto(stCancion * array){ //MANDA TODAS LAS CANCIONES DENTRO DEL ARCHIVO A UN ARREGLO
    int dimension = cantidadCancionesArch();
    int validos = 0;
    stCancion a;
    FILE *pArchCanciones = fopen(arCanciones,"rb");
    if(pArchCanciones != NULL){
        while((fread(&a,sizeof(stCancion),1,pArchCanciones)>0)&&(validos<dimension)){
            strcpy(array[validos].titulo ,a.titulo);
            strcpy(array[validos].genero ,a.genero);
            validos++;

        }
        fclose(pArchCanciones);
    }
    return validos;
}

void listarPorGenero(){ //LISTA LAS CANCIONES POR GENERO Y POR INSERCION
    int dimension = cantidadCancionesCompleto();
    stCancion array[dimension];
    stCancion a;
    int validos = 0;
    validos = archivo2ArregloCompleto(array);
    ordenaArregloGenero(array, validos);
    system("cls");
    muestraArregloGenero(array, validos);
}

void ordenaArregloGenero(stCancion * array,int v){ //ORDENA EL ARREGLO POR GENERO Y POR INSERCION
    int i;
    stCancion aux;
    for(i=0;i<v-1;i++){
        aux = array[i+1];
        insertaGenero(array,i,aux);
    }
}

void insertaGenero(stCancion * array, int v, stCancion dato){ //INSERTA UNA CANCION POR GENERO ORDENADO
    int i=v;
    while((i>=0)&&(strcmp(dato.genero,array[i].genero)<0)){
        array[i+1] = array[i];
        i--;
    }
    array[i+1] = dato;
}

void muestraArregloGenero(stCancion * array, int v){ //MUESTRA EL ARREGLO MOSTRANDO PRIMERO EL GENERO
    int i;
    printf("GENERO - TITULO");
    for(i=0;i<v;i++){
        printf("\n%d) %s - %s",i,array[i].genero, array[i].titulo);
    }
}

void listarPorTitulo(){ //LISTA LAS CANCIONES POR TITULO Y POR SELECCION
    int dimension = cantidadCancionesCompleto();
    stCancion array[dimension];
    stCancion a;
    int validos = 0;
    validos = archivo2ArregloCompleto(array);
    ordenaArregloTitulo(array, validos);
    system("cls");
    muestraArregloTitulo(array, validos);
}

void ordenaArregloTitulo(stCancion * a, int v){ //ORDENA EL ARREGLO POR TITULO Y POR SELECCION
    int i;
    int posMenor;
    stCancion aux;
    for(i=0;i<v-1;i++){
        posMenor = seleccionaTitulo(a,v,i);
        aux = a[posMenor];
        a[posMenor] = a[i];
        a[i] = aux;
    }
}

int seleccionaTitulo(stCancion * a, int v, int inicio){ //SELECCIONA UNA CANCION POR TITULO ORDENADO
    int posMenor = inicio;
    char menorTitulo[30];
    strcpy(menorTitulo, a[posMenor].titulo);
    for(int i=inicio+1;i<v;i++){
        if(strcmp(a[i].titulo, menorTitulo)<0){
            strcpy(menorTitulo, a[i].titulo);
            posMenor=i;
        }
    }
    return posMenor;
}

void muestraArregloTitulo(stCancion * array, int v){ //MUESTRA EL ARREGLO MOSTRANDO PRIMERO EL TITULO
    int i;
    printf("TITULO - GENERO");
    for(i=0;i<v;i++){
        printf("\n%d) %s - %s",i, array[i].titulo, array[i].genero);
    }
}
