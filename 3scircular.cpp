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
void desplegarLista();
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
        printf("|--------- * LISTA SIMPLE CIRCULAR *-------|\n");
        printf("|******************************************|\n");
        printf("| 1.Insertar LSC                           |\n");
        printf("| 2.Buscar LSC                             |\n");
        printf("| 3.Modificar LSC                          |\n");
        printf("| 4.Eliminar LSC                           |\n");
        printf("| 5.Mostrar LSC                            |\n");
        printf("| 6.Vaciar LSC                             |\n");
        printf("| 0.Salir                                  |\n");
        printf("|******************************************|\n");
        printf("Ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                system("cls");
                printf("-INSERTAR NODO EN LA LISTA SIMPLE CIRCULAR \n");
                insertarNodo();
                break;
            case 2:
                system("cls");
                printf("-BUSCAR NODO EN LA LISTA SIMPLE CIRCULAR \n");
                buscarNodo();
                break;
            case 3:
                printf("-EDITAR NODO EN LA LISTA SIMPLE CIRCULAR \n");
                modificarNodo();
                break;
            case 4:
                system("cls");
                printf("-BORRAR NODO EN LA LISTA SIMPLE CIRCULAR \n");
                eliminarNodo();
                break;
            case 5:
                system("cls");
                printf("-nMOSTRAR LISTA SIMPLE CIRCULAR \n\n");
                desplegarLista();
                break;
            case 6:
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
    }else{
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = primero;
        ultimo = nuevo;
    }
    printf("\nNODO INGRESADO CON EXITO\n");
    system("cls");
}

void desplegarLista(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    if(primero != NULL){
        do{
            printf("\n     %d", actual -> dato);
            actual = actual -> siguiente;
        }while(actual != primero);
    }else{
        printf("\n\nLA LISTA SIMPLE CIRCULAR SE ENCUENTRA VACIA");
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
        printf("\n\nLA LISTA SIMPLE CIRCULAR SE ENCUENTRA VACIA");
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
        printf("\n\nLA LISTA SIMPLE CIRCULAR SE ENCUENTRA VACIA");
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
                    ultimo -> siguiente = primero;
                }else if(actual == ultimo){
                    anterior -> siguiente = primero;
                    ultimo = anterior;
                }else{
                    anterior -> siguiente = actual -> siguiente;
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
        printf("\n\nLA LISTA SIMPLE CIRCULAR SE ENCUENTRA VACIA");
    }
}

void vaciarLista(){

}

