#include "cancionesArbol.h"


nodoArbolCancion* inicArbol(){

    return NULL;
}

nodoArbolCancion* crearNodoArbol (stCancion cancion){

    nodoArbolCancion* nuevoNodo = (nodoArbolCancion*) malloc(sizeof(nodoArbolCancion));

    nuevoNodo->c= cancion;
    nuevoNodo->der= NULL;
    nuevoNodo->izq= NULL;

    return nuevoNodo;
}

nodoArbolCancion * cargarArbolDesdeArchivo(){
    nodoArbolCancion * aux;
    int validos = cantidadCancionesArch();
    stCancion arreglo[validos];
    cargarArregloCanciones(arreglo);
    aux = pasarArreglo2Arbol(arreglo, 0, validos-1);
    return aux;
}

nodoArbolCancion * pasarArreglo2Arbol(stCancion * arreglo, int posMin, int posMax)
{
    nodoArbolCancion * rta;
    if (posMin > posMax){
            rta = NULL;
    }
    else{
        int posMedia = (posMin + posMax)/2;
        rta = crearNodoArbol(arreglo[posMedia]);
        rta->izq =  pasarArreglo2Arbol(arreglo, posMin, posMedia-1);
        rta->der = pasarArreglo2Arbol(arreglo, posMedia+1, posMax);
    }

    return rta;
}

nodoArbolCancion* insertarNodoArbol (nodoArbolCancion* arbol, nodoArbolCancion* nuevoNodo){

    if(arbol==NULL){
        arbol=nuevoNodo;
    }
    else{

        if(nuevoNodo->c.idCancion> arbol->c.idCancion){

            arbol->der= insertarNodoArbol(arbol->der, nuevoNodo);
        }
        else{

            arbol->izq= insertarNodoArbol(arbol->izq, nuevoNodo);
        }
    }
    return arbol;
}
void mostrarArbolPre(nodoArbolCancion* arbol){

    if(arbol!=NULL){

        mostrarCancion(arbol->c);
        mostrarArbolPre(arbol->izq);
        mostrarArbolPre(arbol->der);
    }
}

void mostrarArbolIn(nodoArbolCancion* arbol){

    if(arbol!=NULL){

        mostrarArbolIn(arbol->izq);
        mostrarCancion(arbol->c);
        mostrarArbolIn(arbol->der);
    }
}

void mostrarArbolInGenero(nodoArbolCancion* arbol, char genero[]){

    if(arbol!=NULL){

        mostrarArbolIn(arbol->izq);
        if(strcmp(genero,arbol->c.genero)==0){
            mostrarCancion(arbol->c);
        }
        mostrarArbolIn(arbol->der);
    }
}

void mostrarArbolPost(nodoArbolCancion* arbol){

    if(arbol!=NULL){

        mostrarArbolPost(arbol->izq);
        mostrarArbolPost(arbol->der);
        mostrarCancion(arbol->c);
    }
}


stCancion buscarNodoPorId(nodoArbolCancion * arbolCancion, int id){
    stCancion a;
    a.idCancion = -1;
    if(arbolCancion){
        if(arbolCancion->c.idCancion == id){
            a = arbolCancion->c;
        }
        else{
            if(arbolCancion->c.idCancion > id){
                a = buscarNodoPorId(arbolCancion->izq, id);
            }
            else{
                a = buscarNodoPorId(arbolCancion->der, id);
            }
        }
    }
    return a;
}

int existeCancionPorId(nodoArbolCancion * arbolCancion, int id){
    int rta = 0;
    if(arbolCancion){
        if(arbolCancion->c.idCancion == id){
            rta = 1;
        }
        else{
            if(arbolCancion->c.idCancion > id){
                rta = existeCancionPorId(arbolCancion->izq, id);
            }
            else{
                rta = existeCancionPorId(arbolCancion->der, id);
            }
        }
    }
    return rta;
}

nodoArbolCancion* buscarMasIzqu(nodoArbolCancion* arbol){
    nodoArbolCancion* masIzquierdo= NULL;
    if(arbol==NULL){
        masIzquierdo=arbol;
    }
    else{
        masIzquierdo=buscarMasIzqu(arbol->izq);
    }
    return arbol;
}

nodoArbolCancion* buscarMasDer (nodoArbolCancion* arbol){
    nodoArbolCancion* masDer = NULL;
    if(arbol!=NULL){
        masDer=arbol;
    }
    else{
        masDer=buscarMasDer(arbol->der);
    }

    return masDer;
}

nodoArbolCancion* borrarNodoArbolPorIdCancion (nodoArbolCancion* arbol, int idCancion)
{
    if (arbol != NULL){
        if (idCancion == arbol->c.idCancion){
            if (arbol->izq != NULL){
                nodoArbolCancion* masDerecha = buscarMasDer(arbol->izq);
                arbol->c = masDerecha->c;
                arbol->izq = borrarNodoArbolPorIdCancion(arbol->izq, masDerecha->c.idCancion);
            }
            else if (arbol->der != NULL){
                nodoArbolCancion* masIzquierda = buscarMasIzqu(arbol->der);
                arbol->c = masIzquierda->c;
                arbol->der = borrarNodoArbolPorIdCancion(arbol->der, masIzquierda->c.idCancion);
            }
            else{
                free(arbol);
                arbol = NULL;
            }
        }
        else{
            if (idCancion > arbol->c.idCancion){
                arbol->der = borrarNodoArbolPorIdCancion(arbol->der, idCancion);
            }
            else{
                arbol->izq = borrarNodoArbolPorIdCancion(arbol->izq, idCancion);
            }
        }
    }
    return arbol;
}

nodoArbolCancion * borrarCancion(nodoArbolCancion * canciones, int id){
    int rta = existeCancionPorId(canciones, id);
    stCancion cancion;
    if(rta){
        canciones = borrarNodoArbolPorIdCancion(canciones, id);
        eliminarCancionArch(id);
        printf("\n CANCION ELIMINADA CORRECTAMENTE");
    }
    else{
        printf("\n ERROR: La cancion no se encontro...");
    }
    return canciones;
}

void modificarNodoDeCancion(nodoArbolCancion * canciones, stCancion cancion){
    if(canciones){
        if(canciones->c.idCancion == cancion.idCancion){
            canciones->c = cancion;
        }
        else{
            if(canciones->c.idCancion > cancion.idCancion){
                modificarNodoDeCancion(canciones->izq, cancion);
            }
            else{
                modificarNodoDeCancion(canciones->der, cancion);
            }
        }
    }
}

void pasarArbol2Arreglo(stCancion * arreglo, nodoArbolCancion * canciones, int * validos){
    if(canciones){
        arreglo[*validos] = canciones->c;
        ++*validos;
        pasarArbol2Arreglo(arreglo, canciones->izq, validos);
        pasarArbol2Arreglo(arreglo, canciones->der, validos);
    }
}



