#include "mainwindow.h"
#include <QApplication>
#include "File.h"
#include "Folder.h"
#include "Lista.h"
#include "TipoArchivo.h"
#include <QDebug>
#include <qtreewidget.h>
#include "dialog.h"
/**Folder * RegistrarFolder(Lista<Folder *>* folder, QString nom){
    Folder * fol = new Folder(nom,path);
    folder->inserta(fol);
    return fol;
}**/
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

   /** f->AgregarFolder("primer folder");
    f->AgregarFile("holis");
    w.addFolder(f->f->inicio->valor->nom);
   **/

 //  QTreeWidgetItem* parent = w.addFolder("");
  // w.addFile(parent,"que tal");
    return a.exec();
}
