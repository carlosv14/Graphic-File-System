#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
using namespace std;

template <class T>

class Lista
{
    public:
        int size;
        Nodo<T>* inicio;

        Lista();
        virtual ~Lista();
        void inserta(int posicion, T valor);
        void inserta(T valor);
        T recupera(Nodo<T>* posicion);
        int localiza(T valor);
        Nodo<T>* suprime(Nodo<T>* posicion);
        Nodo<T>* siguiente(Nodo<T>* posicion);
        Nodo<T>* anterior(Nodo<T>* posicion);
        void anula();
        Nodo<T>* primero();
        Nodo<T>* fin();
        void imprime_lista();



    protected:
    private:
};

template<class T>
Lista<T>::Lista()
{
    size = 0;
    inicio = NULL;
}

template<class T>
Lista<T>::~Lista()
{
    //dtor
}

template<class T>
T Lista<T>::recupera(Nodo<T>* posicion)
{
    return posicion->valor;
}

template<class T>
int Lista<T>::localiza(T valor)
{
    Nodo<T>* tmp = inicio;
    int cont = 0;
    while(tmp != NULL)
    {
        if(tmp->valor==valor)
            return cont;
        tmp = tmp->siguiente;
        cont++;
    }

    return -1;
}

template<class T>
Nodo<T>* Lista<T>::suprime(Nodo<T>* posicion)
{
    Nodo<T>* tmp = inicio;
    if(posicion == inicio)
    {
        inicio = inicio->siguiente;
        delete tmp;
        return inicio;
    }

    while(tmp != NULL)
    {
        if(tmp->siguiente==posicion)
        {
            Nodo<T> * tmp2 = tmp->siguiente->siguiente;
            delete tmp->siguiente;
            tmp->siguiente = tmp2;
            size--;
            return tmp2;
        }

        tmp = tmp->siguiente;

    }

}

template<class T>
void Lista<T>::inserta(T valor){
    inserta(this->size, valor);
}



template<class T>
void Lista<T>::inserta(int posicion, T valor)
{
    if(posicion>size)
        return ;
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if(posicion == 0)
    {
        if(size == 0)
        {
            inicio = nuevoNodo;
        }else
        {
            nuevoNodo->siguiente = inicio;
            inicio = nuevoNodo;
        }
        size++;
        return ;
    }
    Nodo<T>* tmp;
    int i = 0;
    for(tmp = inicio; tmp != NULL; tmp = tmp->siguiente)
    {
        if(i == posicion-1)
        {
            nuevoNodo->siguiente = tmp->siguiente;
            tmp->siguiente = nuevoNodo;
        }
        i++;
    }


    size++;
}

template<class T>
Nodo<T>* Lista<T>::siguiente(Nodo<T>* posicion)
{

    return posicion->siguiente;
}

template<class T>
Nodo<T>* Lista<T>::anterior(Nodo<T>* posicion)
{
    Nodo<T>* tmp = inicio;
    while(tmp->siguiente!=posicion)
    {
        tmp = tmp->siguiente;
    }
    return tmp;
}

template<class T>
void Lista<T>::anula()
{

}

template<class T>
Nodo<T>* Lista<T>::primero()
{
    return inicio;
}

template<class T>
Nodo<T>* Lista<T>::fin()
{
    return NULL;
}

template<class T>
void Lista<T>::imprime_lista()
{
    Nodo<T>* tmp = inicio;
    while(tmp!=NULL)
    {
        cout<<tmp->valor<<endl;
        tmp = tmp->siguiente;
    }
}


#endif // LISTA_H
