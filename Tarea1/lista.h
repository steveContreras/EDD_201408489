#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
   int valor;
   struct nodo *siguiente;
   struct nodo *anterior;
}Nodo;

typedef Nodo *Lista;
typedef Nodo *Nodop;

void insertar(Lista *l, int val);
void eliminar(Lista *l,int val);
void mostrar(Lista l);








#endif // LISTA_H_INCLUDED
