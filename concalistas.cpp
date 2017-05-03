#include <stdio.h>
#include <stdlib.h>
struct elemento
{
	int dato;
	struct elemento * sig;
};

void crear(struct elemento **lista);
void InsertaOrdenada(struct elemento **lista, int elemento);
void MuestraOrdenada(struct elemento *lista);
void JuntarListas(struct elemento **listaU, struct elemento **list1, struct elemento **list2);
int BuscarElemento(struct elemento **lista, int elemento);

main()
{
int opcion,x;
struct elemento *lista1, *lista2, *lista_unida;
crear(&lista1);
crear(&lista2);
crear(&lista_unida);

	do{
    printf("|*****************************************|\n");
   	printf("|  MENU OPCIONES LISTA ENLAZADA SIMPLE    |\n");
    printf("|*****************************************|\n");
    printf("|1.-Insertar elemento en la lista 1       |\n");
    printf("|2.-Insertar elemento en la lista 2       |\n");
    printf("|3.-Unir listas                           |\n");
    printf("|4.-Listar elementos                      |\n");
    printf("|0.-SALIR                                 |\n");
    printf("|*****************************************|\n");
    printf("\nIntroduce la opcion: ");
    scanf("%d",&opcion);
		switch(opcion)
      	{
			case 1:  printf("Introduce el elemento que quieras introducir en la lista 1: ");
         			scanf("%d",&x);
         			InsertaOrdenada(&lista1, x);
                  system("cls");
                  break;

			case 2:  printf("Introduce el elemento que quieras introducir en la lista 2: ");
         			scanf("%d",&x);
         			InsertaOrdenada(&lista2, x);
                  system("cls");
                  break;

         case 3:  system("cls");
         			printf("Uniendo listas....\n\n");
                  JuntarListas(&lista_unida,&lista1,&lista2);
                  MuestraOrdenada(lista_unida);

			case 4:  system("cls");
         			MuestraOrdenada(lista1);
                  MuestraOrdenada(lista2);
                  break;
			}

		}
   while(opcion!=0);

system("pause");
}


void crear(struct elemento **lista)
{
	*lista=NULL;
}

void InsertaOrdenada(struct elemento **lista, int elemento)
{
	struct elemento *aux,*ant,*nuevo;
	nuevo=(struct elemento*)malloc(sizeof(struct elemento));

	nuevo->dato=elemento;
   fflush(stdin);
   nuevo->sig=NULL;
   aux=(*lista);
   ant=(*lista);

   if(aux==NULL || aux->dato > nuevo->dato)
   {
   	nuevo->sig=aux;
   	(*lista)=nuevo;
   }
   else
   {
   	while(aux!=NULL && aux->dato < nuevo->dato)
         {
    			ant=aux;
            aux=aux->sig;
         }
      nuevo->sig=aux;
      ant->sig=nuevo;
   }
}

void JuntarListas(struct elemento **listaU, struct elemento **list1, struct elemento **list2)
{
	struct elemento *aux,*ant2,*aux2;

   aux=(*list1);
   aux2=(*listaU);
   ant2=(*listaU);

   while(aux!=NULL)
   {
   	if(aux2==NULL)
      {
      	aux->sig=aux2;
      	(*listaU)=aux;
      }
      else
      {
      	while(aux2!=NULL)
         {
         	ant2=aux2;
            aux2=aux2->sig;
         }
      	aux->sig=aux2;
         ant2->sig=aux;
      }
      aux=aux->sig;
  }
   MuestraOrdenada(*listaU);

   aux=(*list2);

   while(aux!=NULL)
   {
   	aux2=(*listaU);
   	ant2=(*listaU);

   	if(aux2==NULL || aux2->dato > aux->dato)
   	{
   		aux->sig=aux2;
   		(*listaU)=aux;
   	}
   	else
   	{
   		while(aux2!=NULL && aux2->dato < aux->dato)
         	{
    				ant2=aux2;
            	aux2=aux2->sig;
         	}
      	aux->sig=aux2;
      	ant2->sig=aux;
   	}
      aux=aux->sig;
   }

}

void MuestraOrdenada(struct elemento *lista)
{
	struct elemento *aux;
	int i=1;
   if(lista==NULL)
   {
   	printf("No se ha encontrado ningun elemento en la lista\n\n");
   }
   else
   {

		aux=lista;
		while(aux)
   	{
			printf("\nElemento %d: %d",i,aux->dato);
			aux=aux->sig;
      	i++;
		}
   	printf("\n\n");
   }
}
