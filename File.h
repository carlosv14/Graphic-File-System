#ifndef FILE_H
#define FILE_H
#include <iostream>
using namespace std;
#include<QString>
#include <TipoArchivo.h>

class File : public TipoArchivo{
public:
      QString extension;
      File(QString nom);

      virtual ~File();

      void Imprimir();
  protected:
  private:
};

#endif // FILE_H
