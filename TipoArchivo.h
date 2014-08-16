#ifndef TIPOARCHIVO_H
#define TIPOARCHIVO_H
#include <qstring.h>
class TipoArchivo{
   public:
    QString nom;
    QString path;
    double tamano;
     QString tipo;
    TipoArchivo();
    void Imprimir();
};
#endif // TIPOARCHIVO_H
