#include "mainwindow.h"
#include <QApplication>
#include "File.h"
#include "Folder.h"
#include "Lista.h"
#include <QDebug>
#include <qtreewidget.h>
Folder * RegistrarFolder(Lista<Folder *>* folder, QString nom){
    Folder * fol = new Folder(nom);
    folder->inserta(fol);
    return fol;
}
void Imprimir( Lista<Folder *>* folder){

    Nodo<Folder *>* nodo = folder->primero();
    while(nodo!= NULL){
      nodo->valor->Imprimir();

        nodo =folder->siguiente(nodo);
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Lista <Folder*>* e = new Lista <Folder*>();
    Folder *f =RegistrarFolder(e,"C:");
    f->Agregar("primerArchivo");
     f->Agregar("segundoArchivo");
      f->Agregar("tercerArchivo");
   w.item->setText(0,f->nom);
    Imprimir(e);
 //  QTreeWidgetItem* parent = w.addFolder("");
  // w.addFile(parent,"que tal");
    return a.exec();
}
