#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo* siguiente;
    struct nodo* atras;
}nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void desplegarListaPU();
void desplegarListaUP();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void vaciarLista();
void menu();
int main(){
    system("color f1");
    menu();
    return 0;
}
void menu(){
     int opcion;
    do{
        printf("|******************************************|\n");
        printf("|--------- * LISTA DOBLE CIRCULAR *--------|\n");
        printf("|******************************************|\n");
        printf("| 1.Insertar LDC                           |\n");
        printf("| 2.Buscar LDC                             |\n");
        printf("| 3.Modificar LDC                          |\n");
        printf("| 4.Eliminar LDC                           |\n");
        printf("| 5.Mostrar LDC PU                         |\n");
        printf("| 6.Mostrar LDC UP                         |\n");
        printf("| 7.Vaciar LdC                             |\n");
        printf("| 0.Salir                                  |\n");
        printf("|******************************************|\n");
        printf("Ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                system("cls");
                printf("\n\nINSERTAR NODO EN LA LISTA DOBLE CIRCULAR \n");
                insertarNodo();
                break;
            case 2:
                system("cls");
                printf("\n\nBUSCAR NODO EN LA LISTA DOBLE CIRCULAR \n");
                buscarNodo();
                break;
            case 3:
                printf("\n\nEDITAR NODO EN LA LISTA DOBLE CIRCULAR \n");
                modificarNodo();
                break;
            case 4:
                system("cls");
                printf("\n\nBORRAR NODO EN LA LISTA DOBLE CIRCULAR \n");
                eliminarNodo();
                break;
            case 5:
                system("cls");
                printf("\n\nMOSTRAR LISTA DOBLE CIRCULAR \n\n");
                desplegarListaPU();
                break;
            case 6:
                system("cls");
                printf("\n\nMOSTRAR LISTA DOBLE CIRCULAR \n\n");
                desplegarListaUP();
                break;
            case 7:
                system("cls");
                vaciarLista();
                break;
            case 0: exit(0);
                break;
            default: printf("\nNo es una opcion valida, intentelo de nuevo\n");
                break;


        }
    }while(opcion != 0);
}
void insertarNodo(){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    printf("\n\nINGRESAR DATO DE NUEVO NODO: ");
    scanf("%d", &nuevo->dato);
    if(primero == NULL){
        primero = nuevo;
        primero -> siguiente = primero;
        ultimo = primero;
        primero -> atras = ultimo;
    }else{
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = primero;
        nuevo -> atras = ultimo;
        ultimo = nuevo;
        primero -> atras = ultimo;
    }
    printf("\nNODO INGRESADO CON EXITO\n");
    system("cls");
}

void desplegarListaPU(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    if(primero != NULL){
        do{
            printf("\n     %d", actual -> dato);
            actual = actual -> siguiente;
        }while(actual != primero);
    }else{
        printf("\n\nLA LISTA DOBLE CIRCULAR SE ENCUENTRA VACIA");
    }
}

void desplegarListaUP(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = ultimo;
    if(primero != NULL){
        do{
            printf("\n     %d", actual -> dato);
            actual = actual -> atras;
        }while(actual != ultimo);
    }else{
        printf("\n\nLA LISTA DOBLE CIRCULAR SE ENCUENTRA VACIA");
    }
}

void buscarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL DATO DEL NODO A BUSCAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        do{
            if(actual->dato == nodoBuscado){
                printf("\n\nEL NODO CON EL DATO ( %d ) - ENCONTRADO\n", nodoBuscado);
                encontrado = 1;
            }
            actual = actual -> siguiente;
        }while(actual != primero && encontrado != 1);
        if(encontrado == 0){
            printf("\n\nEL NODO NO HA SIDO ENCONTRADO\n");
        }
    }else{
        printf("\n\nLA LISTA DOBLE CIRCULAR SE ENCUENTRA VACIA");
    }
}

void modificarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL DATO DEL NODO A BUSCAR PARA MODIFICAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        do{
            if(actual->dato == nodoBuscado){
                printf("\n\nEL NODO CON EL DATO ( %d ) - ENCONTRADO\n", nodoBuscado);
                printf("\nINGRESE EL NUEVO DATO PARA EL NODO: ");
                scanf("%d", &actual->dato);
                printf("\nNODO MODIFICADO\n");
                encontrado = 1;
            }
            actual = actual -> siguiente;
        }while(actual != primero && encontrado != 1);
        if(encontrado == 0){
            printf("\n\nEL NODO NO HA SIDO ENCONTRADO\n");
        }
    }else{
        printf("\n\nLA LISTA DOBLE CIRCULAR SE ENCUENTRA VACIA");
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
        do{
            if(actual->dato == nodoBuscado){
                if(actual == primero){
                    primero = primero -> siguiente;
                    primero -> atras = ultimo;
                    ultimo -> siguiente = primero;
                }else if(actual == ultimo){
                    ultimo = anterior;
                    ultimo -> siguiente = primero;
                    primero -> atras = ultimo;
                }else{
                    anterior -> siguiente = actual -> siguiente;
                    actual -> siguiente -> atras = anterior;
                }
                printf("\nEL NODO HA SIDO BORRADO CON EXITO\n");
                encontrado = 1;
            }
            anterior = actual;
            actual = actual -> siguiente;
        }while(actual != primero && encontrado != 1);
        if(encontrado == 0){
            printf("\n\nEL NODO NO HA SIDO ENCONTRADO\n");
        }else{
            free(anterior);
        }
    }else{
        printf("\n\nLA LISTA DOBLE CIRCULAR SE ENCUENTRA VACIA");
    }
}

void vaciarLista(){

}

