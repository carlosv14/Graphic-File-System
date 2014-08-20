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
    e = new Lista <TipoArchivo*>();
    back = new Lista<Lista<TipoArchivo*>*>();
    f  = new TipoArchivo();
    e->inserta(new Folder("C:","C:"));
    back->inserta(e);

   //e=((Folder*)e->buscar(0))->f;
    re = new QTreeWidgetItem();
    item->setIcon(0,QIcon(":/desktop.png"));
    item->setText(0,e->buscar(0)->nom);
   // QVariant x = QVariant::fromValue(f);
  //   item->setData(0,Qt::UserRole,x);
    ui->lineEdit->insert(f->path);
  // qDebug()<<item->data(0,Qt::UserRole);
   // ui->actionNueva_Carpeta->setDisabled(true);
    //ui->actionNuevo_Archivo->setDisabled(true);
    qDebug()<<e->size;
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

        }else if(item->text(0)=="C:"){

           }

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

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(item->text(column)+"\\"!=ui->lineEdit->text() )
       ui->lineEdit->insert(item->text(column)+"\\");
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
e->inserta(new Folder(m.carpeta,m.carpeta+"//"));
addFolder(re,e->buscar(e->size-1)->nom);
 qDebug()<<e->buscar(e->size-1)->nom;
  qDebug()<<e->buscar(e->size-1)->path;
    qDebug()<<e->size;
 //ui->actionNueva_Carpeta->setDisabled(true);

}


void MainWindow::on_actionNuevo_Archivo_triggered()
{
    Dialog m;
    m.setModal(true);
    m.exec();
        e->inserta(new File(m.carpeta));

}


void MainWindow::on_listWidget_2_doubleClicked(const QModelIndex &index)
{
/** f=e->buscar(index.row());
 if(f->tipo=="F")
     e=((Folder*)f)->f;**/
}

void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{

    qDebug()<<index.row();
  e =((Folder*)e->buscar(index.row()))->f;
  back->inserta(e);

}


void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{


         //back->inserta(e);


        //qDebug()<< back->buscar(index.row())->buscar(index.row())->nom;
}

void MainWindow::on_commandLinkButton_clicked()
{
   Lista<TipoArchivo*>* l;
   l =back->buscar(back->size-1);
    qDebug()<<l;
    qDebug()<<l->buscar(l->size-1)->nom;

}
