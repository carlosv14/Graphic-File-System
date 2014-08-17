#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include "Lista.h"
#include "File.h"
using namespace std;
#include<QString>
#include <TipoArchivo.h>
class Folder : public TipoArchivo{
public:
       Folder(QString nom,QString path);
       virtual ~Folder();
       Lista<TipoArchivo*>* f;
         void Imprimir();
       void AgregarFile(QString nom);
         Folder* AgregarFolder(QString nom,QString path);
        Folder *buscarFolder(QString nom);
   protected:
   private:


};

#endif // FOLDER_H
