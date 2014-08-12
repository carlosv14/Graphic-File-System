#include "Folder.h"
#include <iostream>
#include<QString>
#include <QDebug>
#include <qtreewidget.h>
using namespace std;
Folder::Folder(QString nom){
    this->nom=nom;
    this->f= new Lista<File*>();
}

Folder::~Folder(){
}



void Folder::Agregar(QString nom){
    File*f= new File(nom);
    this->f->inserta(f);
}

void Folder:: Imprimir(){
        qDebug()<<"FOLDER: "<<endl<<this->nom<<endl;
       Nodo<File *>* nodo = this->f->primero();
       while(nodo!= NULL){
         nodo->valor->Imprimir();

           nodo = this->f->siguiente(nodo);
       }

}
