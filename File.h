#ifndef FILE_H
#define FILE_H
#include <iostream>
using namespace std;
#include<QString>

class File{
public:
      QString nom;
      File(QString nom);

      virtual ~File();

      void Imprimir();
  protected:
  private:
};

#endif // FILE_H
