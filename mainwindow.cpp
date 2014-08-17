#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include "File.h"
#include "Folder.h"
#include "Lista.h"
#include <QListView>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);
    this->item = new QTreeWidgetItem(ui->treeWidget);
    ui->treeWidget->addTopLevelItem(item);
    e = new Lista <Folder*>();
    f  = new Folder("C:","C:\\");
    e->inserta(f);
    re = new QTreeWidgetItem();
    item->setIcon(0,QIcon(":/desktop.png"));
    item->setText(0,f->nom);
    ui->lineEdit->insert(f->path);
}

MainWindow::~MainWindow()
{
    delete ui;
}



QTreeWidgetItem* MainWindow::addFolder(QTreeWidgetItem * parent,QString name){
QTreeWidgetItem*itm = new QTreeWidgetItem();
itm->setText(0,name);
parent->addChild(itm);
itm->setIcon(0,QIcon(":/folder.png"));

return itm;
}

void MainWindow::addFile(QTreeWidgetItem * parent, QString name){
    QTreeWidgetItem*itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setIcon(0,QIcon(":/document.png"));
    parent->addChild(itm);
}



void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
   ui->listWidget->clear();
   ui->listWidget_2->clear();
  if(item->text(0)!="C:"){
 busc = f->buscarFolder(item->text(0));
  qDebug()<<busc->tipo;
  }else if(item->text(0)=="C:"){
      busc = f;
     }
   if(item->text(column)+"\\"!=ui->lineEdit->text() )
   ui->lineEdit->insert(item->text(column)+"\\");
    for(int i = 0; i<item->childCount();i++){
        QListWidgetItem*itm = new  QListWidgetItem(ui->listWidget);
        QListWidgetItem*itm2 = new  QListWidgetItem(ui->listWidget_2);
           itm->setText(item->child(i)->text(column));
           itm->setIcon(item->child(i)->icon(column));
           itm2->setText(item->child(i)->text(column));
           itm2->setIcon(item->child(i)->icon(column));
        }

    re = item;
  }

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(!ui->stackedWidget->currentIndex());
}
void MainWindow::on_actionNueva_Carpeta_triggered()
{
Dialog m;
m.setModal(true);
m.exec();
if(re->isSelected()){
addFolder(re,m.carpeta);
busc->AgregarFolder(m.carpeta,ui->lineEdit->text()+"\\");
f->Imprimir();
}
}



void MainWindow::on_actionNuevo_Archivo_triggered()
{
    Dialog m;
    m.setModal(true);
    m.exec();
    if(re->isSelected() && re->text(0)!="C:"){
      addFile(re,m.carpeta);
      f->AgregarFile(m.carpeta);
        f->Imprimir();
    }
}
