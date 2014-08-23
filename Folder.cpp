#include "Folder.h"
#include <iostream>
#include<QString>
#include <QDebug>
#include <qtreewidget.h>
using namespace std;
Folder::Folder(QString nom,QString path){
    this->nom=nom;
   this->f= new Lista<TipoArchivo*>();
   this->tipo = "F";
    this->tamano = 1;
    this->path = path;
  }

Folder::~Folder(){
}



void Folder::AgregarFile(QString nom){
    File*f= new File(nom);
    this->f->inserta(f);
}
Folder* Folder::AgregarFolder(QString nom, QString path){
    Folder*fol= new Folder(nom,path);
    this->f->inserta(fol);
   return fol;
}
Folder*Folder::buscarFolder(QString nom){
     Nodo<TipoArchivo *>* nodo = this->f->primero();
     while(nodo!= NULL){
       if(nodo->valor->nom == nom)
           if(nodo->valor->tipo=="F")
            return new Folder(nom,nodo->valor->path);
         nodo =f->siguiente(nodo);
    }
    return NULL;
}

void Folder:: Imprimir(){

        qDebug()<<"FOLDER: "<<endl<<this->nom<<endl;
       Nodo<TipoArchivo *>* nodo = this->f->primero();
       while(nodo!= NULL){
         nodo->valor->Imprimir();
           nodo = this->f->siguiente(nodo);
       }

}

