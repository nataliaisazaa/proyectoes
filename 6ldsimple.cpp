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
        printf("|------------- * LISTA DOBLE *-------------|\n");
        printf("|******************************************|\n");
        printf("| 1.Insertar LD                            |\n");
        printf("| 2.Buscar LD                              |\n");
        printf("| 3.Modificar LD                           |\n");
        printf("| 4.Eliminar LD                            |\n");
        printf("| 5.Mostrar LD  PU                         |\n");
        printf("| 6.Mostrar LD  UP                         |\n");
        printf("| 7.Vaciar LD                              |\n");
        printf("| 0.Salir                                  |\n");
        printf("|******************************************|\n");
        printf("Ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                system("cls");
                printf("\n\nINSERTAR NODO EN LA LISTA DOBLE \n");
                insertarNodo();
                break;
            case 2:
                system("cls");
                printf("\n\nBUSCAR NODO EN LA LISTA DOBLE \n");
                buscarNodo();
                break;
            case 3:
                printf("\n\nEDITAR NODO EN LA LISTA DOBLE \n");
                modificarNodo();
                break;
            case 4:
                system("cls");
                printf("\n\nBORRAR NODO EN LA LISTA DOBLE \n");
                eliminarNodo();
                break;
            case 5:
                system("cls");
                printf("\n\nMOSTRAR LISTA DOBLE \n\n");
                desplegarListaPU();
                break;
            case 6:
                system("cls");
                printf("\n\nMOSTRAR LISTA DOBLE \n\n");
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
        primero -> siguiente = NULL;
        primero->atras = NULL;
        ultimo = primero;
    }else{
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = NULL;
        nuevo -> atras = ultimo;
        ultimo = nuevo;
    }
    printf("\nNODO INGRESADO CON EXITO\n");
    system("cls");
}

void desplegarListaPU(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    if(primero != NULL){
        while(actual != NULL){
            printf("\n     %d", actual -> dato);
            actual = actual -> siguiente;
        }
    }else{
        printf("\n\nLA LISTA DOBLE SE ENCUENTRA VACIA");
    }
}

void desplegarListaUP(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = ultimo;
    if(primero != NULL){
        while(actual != NULL){
            printf("\n     %d", actual -> dato);
            actual = actual -> atras;
        }
    }else{
        printf("\n\nLA LISTA DOBLE SE ENCUENTRA VACIA");
    }
}

void buscarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL DATO DEL NODO A BUSCAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        while(actual != NULL && encontrado != 1){
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
        printf("\nLA LISTA DOBLE SE ENCUENTRA VACIA\n");
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
        printf("\nLA LISTA DOBLE SE ENCUENTRA VACIA\n");
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
                    primero -> atras = NULL;
                }else if(actual == ultimo){
                    anterior -> siguiente = NULL;
                    ultimo = anterior;
                }else{
                    anterior -> siguiente = actual -> siguiente;
                    actual -> siguiente -> atras = anterior;
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
        printf("\nLA LISTA DOBLE SE ENCUENTRA VACIA\n");
    }
}

void vaciarLista(){

}

