#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include "Lista.h"
#include "File.h"
using namespace std;
#include<QString>
#include "mainwindow.h"
#include <TipoArchivo.h>
class Folder : public TipoArchivo{
public:
       Folder(QString nom);
       virtual ~Folder();
       Lista<TipoArchivo*>* f;
         void Imprimir();
       void AgregarFile(QString nom);
         Folder* AgregarFolder(QString nom);
   protected:
   private:


};

#endif // FOLDER_H
