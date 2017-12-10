#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main()
{
    Lista lista = 0;
    int opcion=0;
    int val=0;
    do
    {
        mostrarMenu();
        scanf("%i", &opcion);
        switch( opcion )
        {
            case 1:
                printf("Ingresa un valor para ingresar en la lista: ");
                scanf("%i", &val);
                insertar(&lista,val);
                break;
            case 2:
                mostrar(lista);
                break;
            case 3:
                printf("Ingresa el valor para eliminar de la lista: ");
                scanf("%i", &val);
                eliminar(&lista,val);
                break;
            default:
                printf("Ingresa un valor entre 1 y 3.");
                break;
        }

    }
    while(opcion<4);


    printf("Aplicacion terminada.");

    return 0;

}

void mostrarMenu()
{
    printf("\n\nOpcion 1 -> Insertar en lista \n");
    printf("Opcion 2 -> Mostrar lista\n");
    printf("Opcion 3 -> Eliminar de l lista \n");
    printf("Ingresa un opcion: ");
}

void insertar(Lista *l,int val)
{
    Nodop nuevo;
    Nodop actual;
    nuevo = (Nodop)malloc(sizeof(Nodo));
    nuevo->valor = val;
    actual = *l;
    if(actual)
        while(actual->anterior)
            actual = actual->anterior;

    if(!actual || actual->valor > val){
        nuevo->siguiente = actual;
        nuevo->anterior = 0;
        if(actual) actual->anterior = nuevo;
        if(!*l) *l = nuevo;
    }
    else {
        while(actual->siguiente && actual->siguiente->valor <= val)
            actual = actual->siguiente;

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
        if(nuevo->siguiente)
            nuevo->siguiente->anterior = nuevo;
   }
    printf("Valor ingresado\n");
}

void eliminar(Lista *lista, int val){
    Nodop tmp;
    tmp = *lista;
    while(tmp && tmp->valor < val)
        tmp = tmp->siguiente;
    while(tmp && tmp->valor < val)
        tmp = tmp->siguiente;

    if(!tmp || tmp->valor != val){
      printf("El valor no esta en la lista \n");
      return;
    }

    if(tmp == *lista)
        if(tmp->anterior)
            *lista = tmp->anterior;
        else
            *lista = tmp->siguiente;

    if(tmp->anterior)
        tmp->anterior->siguiente = tmp->siguiente;
    if(tmp->siguiente)
        tmp->siguiente->anterior = tmp->anterior;

    free(tmp);

}

void mostrar(Lista lista){
    Nodop tmp;

    if(lista==0){
      printf("La lista esta vacia\n");
      return;
    }

    tmp = lista;

    while(tmp->anterior) tmp = tmp->anterior;

    while(tmp){
        printf("%d\n", tmp->valor);
        tmp = tmp->siguiente;
    }
}
