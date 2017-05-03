#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
    int dato;
    struct nodo* siguiente;
}nodo;
nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void desplegarCola();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void vaciarCola();
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
        printf("|----------------- * COLAS *---------------|\n");
        printf("|******************************************|\n");
        printf("| 1.Insertar cola                          |\n");
        printf("| 2.Buscar cola                            |\n");
        printf("| 3.Modificar cola                         |\n");
        printf("| 4.Eliminar cola                          |\n");
        printf("| 5.Mostrar cola                           |\n");
        printf("| 6.Vaciar cola                            |\n");
        printf("| 0.Salir                                  |\n");
        printf("|******************************************|\n");
        printf("Ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("-INSERTAR NODO EN LA COLA \n");
                insertarNodo();
                break;
            case 2:
                printf("-BUSCAR NODO EN LA COLA \n");
                buscarNodo();
                break;
            case 3:
                printf("-EDITAR NODO EN LA COLA \n");
                modificarNodo();
                break;
            case 4:
                printf("-BORRAR NODO EN LA COLA \n");
                eliminarNodo();
                break;
            case 5:
                printf("-MOSTRAR COLA \n\n");
                desplegarCola();
                break;
            case 6:
                system("cls");
                vaciarCola();
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
        ultimo = nuevo;
    }else{
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = NULL;
        ultimo = nuevo;
    }
    printf("\nNODO INGRESADO CON EXITO\n");
    system("cls");
}

void desplegarCola(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    if(primero != NULL){
        while(actual != NULL){
            printf("\n     %d", actual -> dato);
            actual = actual -> siguiente;
        }
    }else{
        printf("\n\nLA COLA SE ENCUENTRA VACIA");
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
        printf("\nLA COLA SE ENCUENTRA VACIA\n");
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
        printf("\nLA COLA SE ENCUENTRA VACIA\n");
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
        printf("\nLA COLA SE ENCUENTRA VACIA\n");
    }
}

void vaciarCola(){
}

