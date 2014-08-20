#ifndef TIPOARCHIVO_H
#define TIPOARCHIVO_H
#include <qstring.h>
#include<QtCore>

class TipoArchivo{
   public:
    QString nom;
    QString path;
    double tamano;
     QString tipo;
    TipoArchivo();
    void Imprimir();
};

Q_DECLARE_METATYPE(TipoArchivo);

#endif // TIPOARCHIVO_H
