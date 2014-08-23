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
#include <QGridLayout>
#include <QLabel>
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
   //e=((Folder*)e->buscar(0))->f;
    re = new QTreeWidgetItem();
    item->setIcon(0,QIcon(":/desktop.png"));
    item->setText(0,e->buscar(0)->nom);
   // QVariant x = QVariant::fromValue(f);
  //   item->setData(0,Qt::UserRole,x);
    ui->lineEdit->insert(f->path);
  // qDebug()<<item->data(0,Qt::UserRole);
    ui->actionNueva_Carpeta->setDisabled(true);
    ui->actionNuevo_Archivo->setDisabled(true);
   // qDebug()<<e->size;

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
for(int i = 0; i<e->size;i++)
    while(e->buscar(i)->nom==m.carpeta)
        m.exec();
e->inserta(new Folder(m.carpeta,m.carpeta+"//"));
addFolder(re,e->buscar(e->size-1)->nom);
 qDebug()<<"inserte: " + e->buscar(e->size-1)->nom +e->buscar(e->size-1)->path;
 //  qDebug()<<e->size;
 Lista<TipoArchivo*>* l;
 l = back->buscar(0);
 e =l;
 qDebug()<<e->size;
}


void MainWindow::on_actionNuevo_Archivo_triggered()
{
    Dialog m;
    m.setModal(true);
    m.exec();
    for(int i = 0; i<e->size;i++)
        while(e->buscar(i)->nom==m.carpeta)
            m.exec();
         e->inserta(new File(m.carpeta));
        ((File*)e->buscar(e->size-1))->extension = m.ext;
        addFile(re,e->buscar(e->size-1)->nom);
        Lista<TipoArchivo*>* l;
        l = back->buscar(0);
        e =l;
        qDebug()<<e->size;
        ui->actionNuevo_Archivo->setDisabled(true);

}



void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
     qDebug()<<index.row();
    ui->actionNueva_Carpeta->setDisabled(false);
    f=e->buscar(index.row());
    qDebug()<<f->nom;
    if(f->tipo=="F"){
  ui->actionNuevo_Archivo->setDisabled(false);
  e =((Folder*)f)->f;
  back->inserta(e);
    }else{
       ui->actionNuevo_Archivo->setDisabled(true);
    }
}


void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{

  //qDebug()<<index.row();
         //back->inserta(e);


        //qDebug()<< back->buscar(index.row())->buscar(index.row())->nom;
}


void MainWindow::on_commandLinkButton_clicked()
{
    qDebug()<<"L";
   Lista<TipoArchivo*>* l;
 // for(int i =0; i<back->size;i++){
  l=back->buscar(0);
 qDebug()<< l->size;
   for(int k=0;k<l->size;k++){
      qDebug()<<l->buscar(k)->nom;
     }
   //}
}

void MainWindow::on_listWidget_2_doubleClicked(const QModelIndex &index)
{
    QGridLayout *layout = new QGridLayout;
    QLabel *x = new QLabel("Extension");
    layout->addWidget(x,0,0);
    ui->listWidget_2->setLayout(layout);
    f =e->buscar(index.row());
    qDebug()<<f->nom;
 if(f->tipo=="F"){
    e = ((Folder*)f)->f;
    ui->listWidget->clear();
     for(int i =0; i<e->size;i++){
         QListWidgetItem*itm = new  QListWidgetItem(ui->listWidget);
         QListWidgetItem*itm2 = new  QListWidgetItem(ui->listWidget_2);
            itm->setText(e->buscar(i)->nom);
             itm2->setText(e->buscar(i)->nom);
        if(e->buscar(i)->tipo=="F"){
            itm->setIcon(QIcon(":/folder.png"));
             itm2->setIcon(QIcon(":/folder.png"));
            }else{
            itm->setIcon(QIcon(":/document.png"));
             itm2->setIcon(QIcon(":/document.png"));
        }


     }
   }

}
void busquemos(QString n){


}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{

}
