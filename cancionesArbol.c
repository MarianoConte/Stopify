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

nodoArbolCancion * cargarArbol(){
    nodoArbolCancion * aux;
    int validos = cantidadCancionesArch();
    stCancion arreglo[validos];
    cargarArregloCanciones(arreglo);
    aux = pasarArreglo2Arbol(arreglo, 1, validos);
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
        nodoArbolCancion * nuevo = crearNodoArbol(arreglo[posMedia]);
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

void mostrarArbolPost(nodoArbolCancion* arbol){

    if(arbol!=NULL){

        mostrarArbolPost(arbol->izq);
        mostrarArbolPost(arbol->der);
        mostrarCancion(arbol->c);
    }
}

nodoArbolCancion* borrarUnNodoArbol (nodoArbolCancion* arbol, int idCancion);


stCancion buscarNodoPorId(nodoArbolCancion * arbolCancion, int id){
    stCancion a;
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
