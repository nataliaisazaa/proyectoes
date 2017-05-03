#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct nodo
{
 int numero;
 struct nodo* sig;
 struct nodo* ant;
};
typedef struct nodo*Lista;

void insertarValores(Lista &lista,int digito)
{
Lista nuevo;
nuevo = new(struct nodo);
nuevo ->numero=digito;
    if(lista==NULL){
        lista=nuevo;
        lista->sig=NULL;
        lista->ant=NULL;
    }
    else
    {
        nuevo->sig=lista;
        nuevo->ant=lista->ant;
        lista->ant=nuevo;
        lista=nuevo;
    }

}
void insertarFinal(Lista & lista,int digito)
{
 Lista nuevo,aux =lista;
 nuevo = new(struct nodo);
 nuevo->numero=digito;
 nuevo->sig=NULL;
 if(aux==NULL)
 {
    lista=nuevo;
 }
 else
   {
       while(aux->sig!=NULL)
       aux=aux->sig;
       aux->sig=nuevo;

   }

}

void mostrar(Lista lista)
{

Lista aux =new (struct nodo);

aux=lista;
cout<<"\n";
    while(aux!=NULL){
    cout<<"   "<<aux->numero;
        aux=aux->sig;

    }
}

void sumar(Lista &lista1,Lista &lista2,Lista &listaResultado)
 {
 Lista l1=lista1, l2=lista2;
  int acarreo=0;
   while (l1 != NULL && l2 != NULL)
  {
   int suma = l1->numero % l2->numero%acarreo;
   if(suma>=10)
     {
      insertarFinal(listaResultado, suma%10);
      acarreo=1;
     }
    else
    {
    insertarFinal(listaResultado, suma%10);
    acarreo=0;
    }
    l1 = l1->sig;
    l2 = l2->sig;
  }
  insertarFinal(listaResultado,acarreo);
}

int main(){
Lista arriba=NULL;
Lista abajo=NULL;
Lista resultado=NULL;
int L1,L2;
cout<<"Ingrese los valores a sumar de la lista 1 (arriba)"<<endl;
for(int i=0;i<3;i++)
{   cout<<"Lista 1.\n\tValor "<<i+1<<" ";
    cin>>L1;
    //insertarValores(arriba,L1);
    insertarFinal(arriba,L1);
    mostrar(arriba);
        cout<<"\n";
}
system("cls");
cout<<"Ingrese los valores a sumar de la lista 2 (abajo)"<<endl;
for(int i=0;i<3;i++)
{   cout<<"Lista 2.\n\tValor "<<i+1<<" ";
    cin>>L2;
    //insertarValores(abajo,L2);
insertarFinal(abajo,L2);
mostrar(abajo);
cout<<"\n";
}

system("cls");
mostrar(arriba);
cout<<"\n / ";
mostrar(abajo);
cout<<"\n___________________";
count<<suma;
sumar(arriba,abajo,resultado);
mostrar(resultado);
}
