#include "TipoArchivo.h"
#include <iostream>
#include<QString>
#include <QDebug>

TipoArchivo :: TipoArchivo(){

}
void TipoArchivo::Imprimir(){
        if(this->tipo == "F"){
            qDebug()<<"Folder";
          qDebug()<<this->nom;
          qDebug()<<this->path;
        }else{
           qDebug()<<"archivo";
         qDebug()<<this->nom;
        }
    }

