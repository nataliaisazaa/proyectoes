#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
    float dato;
    nodo *siguiente;
}nodo;

nodo* primero = NULL;

void insertarNodo();
void desplegarPila();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void vaciarPila();
void menu();

/*
* Funcion Principal
*/
int main(){
    system("color f1");
    menu();
    return 0;
}
void menu(){
    int opcion;
    do{
        printf("|******************************************|\n");
        printf("|----------------- * PILA *- --------------|\n");
        printf("|******************************************|\n");
        printf("| 1.Insertar pila                          |\n");
        printf("| 2.Buscar pila                            |\n");
        printf("| 3.Modificar pila                         |\n");
        printf("| 4.Eliminar pila                          |\n");
        printf("| 5.Desplegar pila                         |\n");
        printf("| 6.vaciar pila                            |\n");
        printf("| 0.Salir                                  |\n");
        printf("|******************************************|\n");
        printf("Ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: printf("-INSERTA NODO EN LA PILA\n");
                insertarNodo();
                break;
            case 2: printf("-BUSCAR UN NODO EN LA PILA\n");
                buscarNodo();
                break;
            case 3: printf("-MODIFICAR UN NODO EN LA PILA\n");
                modificarNodo();
                break;
            case 4: printf("-ELIMINAR UN NODO DE LA PILA\n");
                eliminarNodo();
                break;
            case 5: printf("-DESPLEGAR PILA DE NODOS\n");
                desplegarPila();
                break;
            case 6:
                system("cls");
                vaciarPila();
                break;
            case 0: exit(0);
                break;
            default: printf("\nNo es una opcion valida, intentelo de nuevo\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);

}
void insertarNodo(){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    printf("\n\nINGRESAR DATO DE NUEVO NODO: ");
    scanf("%d", &nuevo->dato);
    nuevo->siguiente = primero;
    primero = nuevo;
    system("cls");
}
void desplegarPila(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    if(primero != NULL){
        while(actual != NULL){
            printf("\n     %d", actual -> dato);
            actual = actual -> siguiente;
        }
    }else{
        printf("\n\nLA PILA SE ENCUENTRA VACIA");
    }
}

void buscarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL DATO DEL NODO A BUSCAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        while(actual != NULL){
            if(actual->dato == nodoBuscado){
                printf("\nEL NODO CON EL DATO ( %d ) - ENCONTRADO\n", nodoBuscado);
                encontrado = 1;
            }
            actual = actual -> siguiente;
        }
        if(encontrado == 0){
            printf("\nEL NODO NO HA SIDO ENCONTRADO\n");
        }
    }else{
        printf("\nLA PILA SE ENCUENTRA VACIA\n");
    }
}

void modificarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL DATO DEL NODO A BUSCAR PARA MODIFICAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        while(actual != NULL){
            if(actual->dato == nodoBuscado){
                printf("\nEL NODO CON EL DATO ( %d ) - ENCONTRADO", nodoBuscado);
                printf("\nINGRESE EL NUEVO DATO PARA EL NODO: ");
                scanf("%d", &actual->dato);
                printf("\nNODO MODIFICADO\n");
                encontrado = 1;
            }
            actual = actual -> siguiente;
        }
        if(encontrado == 0){
            printf("\nEL NODO NO HA SIDO ENCONTRADO\n");
        }
    }else{
        printf("\nLA PILA SE ENCUENTRA VACIA\n");
    }
}

void eliminarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    nodo* anterior = (nodo*) malloc(sizeof(nodo));
    anterior = NULL;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL DATO DEL NODO A BUSCAR PARA ELIMINAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        while(actual != NULL && encontrado != 1){
            if(actual->dato == nodoBuscado){
                if(actual == primero){
                    primero = primero -> siguiente;
                }else{
                    anterior -> siguiente = actual -> siguiente;
                }
                printf("\nEL NODO HA SIDO BORRADO CON EXITO\n");
                encontrado = 1;
            }
            anterior = actual;
            actual = actual -> siguiente;
        }
        if(encontrado == 0){
            printf("\nEL NODO NO HA SIDO ENCONTRADO\n");
        }else{
            free(anterior);
        }
    }else{
        printf("\nLA PILA SE ENCUENTRA VACIA\n");
    }
}

void vaciarPila(){

}


