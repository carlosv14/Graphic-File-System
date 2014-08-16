#include "Folder.h"
#include <iostream>
#include<QString>
#include <QDebug>
#include <qtreewidget.h>
using namespace std;
Folder::Folder(QString nom){
    this->nom=nom;
   this->f= new Lista<TipoArchivo*>();
   this->tipo = "F";

  }

Folder::~Folder(){
}



void Folder::AgregarFile(QString nom){
    File*f= new File(nom);
    this->f->inserta(f);
}
Folder* Folder::AgregarFolder(QString nom){
    Folder*fol= new Folder(nom);
    this->f->inserta(fol);
   return fol;
}

void Folder:: Imprimir(){

        qDebug()<<"FOLDER: "<<endl<<this->nom<<endl;
       Nodo<TipoArchivo *>* nodo = this->f->primero();
       while(nodo!= NULL){
         nodo->valor->Imprimir();
           nodo = this->f->siguiente(nodo);
       }

}
