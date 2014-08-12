#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include "Lista.h"
#include "File.h"
using namespace std;
#include<QString>
#include "mainwindow.h"
class Folder{
public:
       Folder(QString nom);
       virtual ~Folder();
       QString nom;
       Lista<File *>* f;
      void Imprimir();
       void Agregar(QString nom);
   protected:
   private:


};

#endif // FOLDER_H
