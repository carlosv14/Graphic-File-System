#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    carpeta = ui->lineEdit->text();

 for(int i = 0; i<carpeta.length();i++){
     if(carpeta.at(i)=='.'){
         ext.clear();
         for(int k = i; k<carpeta.length();k++)
             ext.append(carpeta.at(k));

    }
 }
qDebug()<<ext;
}
