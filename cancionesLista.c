#include "cancionesLista.h"

nodoListaCancion* inicLista(){

    return NULL;
}

nodoListaCancion* crearNodoLista(stCancion cancion){

    nodoListaCancion* nuevoNodo = (nodoListaCancion*) malloc(sizeof(nodoListaCancion));
    nuevoNodo->c=cancion;
    nuevoNodo->sig=NULL;

    return nuevoNodo;
}

nodoListaCancion * agregarNodoListaCancion(nodoListaCancion * lista, nodoListaCancion * nuevo){
    if(!lista){
        lista=nuevo;
    }
    else{
        nuevo->sig = lista;
        lista = nuevo;
    }
    return lista;
}

nodoListaCancion* agregarAlFinal(nodoListaCancion* lista, nodoListaCancion* nuevoNodo){

    if(lista==NULL){

        lista=nuevoNodo;
    }
    else{

        nodoListaCancion* posicionFinal = buscarUltimaCancion(lista);
        posicionFinal->sig= nuevoNodo;
    }
    return lista;
}


nodoListaCancion* agregarEnOrdenPoridDeCancion(nodoListaCancion* lista, nodoListaCancion* nuevoNodo){

    nodoListaCancion* seguidora = lista;

    while(seguidora!=NULL){

        if(nuevoNodo->c.idCancion>seguidora->c.idCancion){

            nuevoNodo->sig=seguidora->sig;
            seguidora->sig=nuevoNodo;
        }
        else{

            seguidora=seguidora->sig;
        }
    }
    return lista;
}
/*
nodoListaCancion* archAlista(char nombreArchivoCanciones[], nodoListaCancion* lista){

    stCancion e;

    FILE* fArchCanciones= fopen(nombreArchivoCanciones, "rb");

    if(fArchCanciones!=NULL){

        while(fread(&e, sizeof(stCancion), 1, fArchCanciones)>0){

            agregarAlFinal(lista, crearNodoLista(e));

        }
        fclose(fArchCanciones);
    }

    return lista;
}*/
/*
void listaAarch(char nombreArchCanciones[], nodoListaCancion* lista){

    FILE* fArchCanciones = fopen(nombreArchCanciones, "wb");
    nodoListaCancion* seguidora = lista;
    stCancion e;

    if(fArchCanciones!=NULL){

        while(seguidora!=NULL){

            e= seguidora->c;
            fwrite(&e, sizeof(stCancion), 1, fArchCanciones);

            seguidora=seguidora->sig;
        }
        fclose(fArchCanciones);
    }
}
*/


nodoListaCancion* borrarNodoPorIdCancion(nodoListaCancion* lista, int idBorrada){

    if(lista!=NULL){

        nodoListaCancion* anterior=lista;
        nodoListaCancion* seguidora=lista->sig;

        while(seguidora!=NULL){

            if(seguidora->c.idCancion== idBorrada){

                anterior->sig= seguidora->sig;
                free(seguidora);

            }
            else{

                seguidora=seguidora->sig;
                anterior->sig=seguidora;
            }
        }
    }
}

nodoListaCancion* buscarUltimaCancion(nodoListaCancion* lista){

    nodoListaCancion* seguidora = lista;

    while(seguidora!=NULL){

        seguidora=seguidora->sig;
    }
    return seguidora;
}

int cantidadCancionesPlaylist(nodoListaCancion * lista){
    int rta=0;
    while(lista){
        lista=lista->sig;
        rta++;
    }
    return rta;
}

stCancion buscarPorPosNodo(nodoListaCancion * lista, int pos){
    stCancion rta;
    if(pos!=0){
        pos--;
        rta = buscarPorPosNodo(lista->sig, pos);
    }
    else{
        rta = lista->c;
    }
    return rta;
}

/*Alta
Baja
Modificación
Consulta
Listados de Canciones ya esta
listado de canciones por genero
*/
