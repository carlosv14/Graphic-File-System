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
#include <QMessageBox>
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
    item->setIcon(0,QIcon(":/desktop.png"));
    item->setText(0,e->buscar(0)->nom);
    f = e->buscar(0);
    e = ((Folder*)f)->f;
    back->inserta(e);
    e->inserta(new Folder("Descargas","C:\\Descargas"));
    e->inserta(new Folder("Documentos","C:\\Documentos"));
    e->inserta(new Folder("Escritorio","C:\\Escritorio"));
    re = new QTreeWidgetItem();
    descargas = new QList<QTreeWidgetItem*>();
    clipboard = new Lista<TipoArchivo*>();
    arboles= new QList<QList<QTreeWidgetItem*> >();
  addFolder(item,e->buscar(0)->nom);
  addFolder(item,e->buscar(1)->nom);
  addFolder(item,e->buscar(2)->nom);

   for(int i = 0; i<e->size;i++){
   QListWidgetItem*itm = new  QListWidgetItem(ui->listWidget);
   QListWidgetItem*itm2 = new  QListWidgetItem(ui->listWidget_2);
      itm->setText(e->buscar(i)->nom);
      itm->setIcon(QIcon(":/folder.png"));
      itm2->setText(e->buscar(i)->nom);
      itm2->setIcon(QIcon(":/folder.png"));
     }
    ui->lineEdit->insert(f->path);
    ui->actionNueva_Carpeta->setDisabled(true);
    ui->actionNuevo_Archivo->setDisabled(true);
    e = back->buscar(1);
    qDebug()<<e->buscar(0)->nom;
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
arbol.append(itm);
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


  }

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
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
void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
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
e->inserta(new Folder(m.carpeta,ui->lineEdit->text()+"\\" +m.carpeta));
addFolder(re,e->buscar(e->size-1)->nom);
QListWidgetItem*itm = new  QListWidgetItem(ui->listWidget);
QListWidgetItem*itm2 = new  QListWidgetItem(ui->listWidget_2);
   itm->setText(m.carpeta);
   itm->setIcon(QIcon(":/folder.png"));
   itm2->setText(m.carpeta);
   itm2->setIcon(QIcon(":/folder.png"));
 qDebug()<<"inserte: " + e->buscar(e->size-1)->nom +e->buscar(e->size-1)->path;
 qDebug()<<"este es t";
 qDebug()<<arbol.size();
 //  qDebug()<<e->size;
 qDebug()<<"tama de e";
 qDebug()<<e->size;
 for(int i= 0; i<e->size; i++)
         qDebug()<<"Aqui estoy: " + e->buscar(i)->nom;
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


   // atras.append(ui->lineEdit->text());
    descargas->append(arbol.at(index.row()));
    arboles->append(arbol);
    qDebug()<<"Estoy en el arbol: " + descargas->at(descargas->size()-1)->text(0);
    qDebug()<<index.row();
   f=e->buscar(index.row());
   qDebug()<<"Este es: " +f->nom;
   if(f->tipo=="F"){
  ui->lineEdit->setText(f->path);
 e =((Folder*)f)->f;
 re = descargas->at(descargas->size()-1);
 if(f->nom!="C:"){
    ui->actionNueva_Carpeta->setDisabled(false);
    ui->actionNuevo_Archivo->setDisabled(false);
 }
 if(e->size==0){
     qDebug()<<"tamano";
      back->inserta(e);
}else{
 for(int i= 0; i<back->size;i++){
      qDebug()<<"nombre: " +back->buscar(i)->buscar(0)->nom;
    if(e->buscar(0)->nom!=back->buscar(i)->buscar(0)->nom){
      if(i==back->size-1)
        back->inserta(e);
   }else if(e->buscar(0)->nom==back->buscar(i)->buscar(0)->nom){
       break;
    }
 }

}

   qDebug()<<back->size;
   }else{
      ui->actionNuevo_Archivo->setDisabled(true);
  }
    arbol.clear();
}


void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{

}


void MainWindow::on_commandLinkButton_clicked()
{
     atras.pop_back();
    ui->lineEdit->setText(atras.at(atras.size()-1));
    bool found = false;
    ui->listWidget_2->clear();
      ui->listWidget->clear();
  for(int k=0; k<back->size;k++){
     e = back->buscar(k);
    for(int i=0; i<e->size;i++){
         f= e->buscar(i);
         qDebug()<<f->path;
        if(f->path == ui->lineEdit->text()){
          qDebug()<<"found";
          e = ((Folder*)f)->f;

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
        found = true;
    }
}
    if(found){
       arbol = arboles->at(arboles->size()-1);
       if(!descargas->isEmpty()){
       descargas->removeLast();
       re= descargas->at(descargas->size()-1);
       for(int i = 0; i<e->size;i++){
           qDebug()<<"Esto contiene la lista: " + e->buscar(i)->nom;
       }
       }
       break;

    }
  }
       // e = back->buscar(0);
   /** qDebug()<<"L";
      Lista<TipoArchivo*>* l;

    // for(int i =0; i<back->size;i++){
     l=back->buscar(1);
    qDebug()<< l->size;
      for(int k=0;k<l->size;k++){
         qDebug()<<l->buscar(k)->nom;
        }
      //}**/

}

void MainWindow::on_listWidget_2_doubleClicked(const QModelIndex &index)
{


    /**QGridLayout *layout = new QGridLayout;
    QLabel *x = new QLabel("Extension");
    layout->addWidget(x,0,0);
    ui->listWidget_2->setLayout(layout);**/
    qDebug()<< index.row();
    descargas->append(arbol.at(index.row()));
    arboles->append(arbol);
    qDebug()<<arboles->at(arboles->size()-1).size();
    qDebug()<<"este es: " + descargas->at(descargas->size()-1)->text(0);
    f =e->buscar(index.row());
    qDebug()<<"Nombre en Lista: " + f->nom;
ui->actionNueva_Carpeta->setDisabled(false);
ui->actionNuevo_Archivo->setDisabled(false);
 if(f->tipo=="F"){
     ui->lineEdit->setText(f->path);
     atras.append(ui->lineEdit->text());
    e = ((Folder*)f)->f;
    re= descargas->at(descargas->size()-1);
     ui->listWidget->clear();
     ui->listWidget_2->clear();

     if(e->size==0){
         qDebug()<<"tamano";
          back->inserta(e);
    }else{
     for(int i= 0; i<back->size;i++){
          qDebug()<<"nombre: " +back->buscar(i)->buscar(0)->nom;
        if(e->buscar(0)->nom!=back->buscar(i)->buscar(0)->nom){
          if(i==back->size-1)
            back->inserta(e);
       }else if(e->buscar(0)->nom==back->buscar(i)->buscar(0)->nom){
           break;
        }
     }
     }
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


for(int i= 0; i<arbol.size();i++){
qDebug()<< "arbol :" + arbol.at(i)->text(0);

}
for(int i=0; i<arboles->size();i++){
    for(int k=0; k<arboles->at(i).size();k++)
           qDebug()<<"arb: " + arboles->at(i).at(k)->text(0);
}
 arbol.clear();
 qDebug()<<arboles->size();
 qDebug()<<"despues de clear";
   qDebug()<<arboles->at(arboles->size()-1).size();
   qDebug()<<arbol.size();
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    qDebug()<< index.row();
    descargas->append(arbol.at(index.row()));
    arboles->append(arbol);
    qDebug()<<arboles->at(arboles->size()-1).size();
    qDebug()<<"este es: " + descargas->at(descargas->size()-1)->text(0);
    f =e->buscar(index.row());
    qDebug()<<"Nombre en Lista: " + f->nom;
ui->actionNueva_Carpeta->setDisabled(false);
ui->actionNuevo_Archivo->setDisabled(false);
 if(f->tipo=="F"){
     ui->lineEdit->setText(f->path);
     atras.append(ui->lineEdit->text());
    e = ((Folder*)f)->f;
    re= descargas->at(descargas->size()-1);
     ui->listWidget->clear();
     ui->listWidget_2->clear();

     if(e->size==0){
         qDebug()<<"tamano";
          back->inserta(e);
    }else{
     for(int i= 0; i<back->size;i++){
          qDebug()<<"nombre: " +back->buscar(i)->buscar(0)->nom;
        if(e->buscar(0)->nom!=back->buscar(i)->buscar(0)->nom){
          if(i==back->size-1)
            back->inserta(e);
       }else if(e->buscar(0)->nom==back->buscar(i)->buscar(0)->nom){
           break;
        }
     }
     }
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


for(int i= 0; i<arbol.size();i++){
qDebug()<< "arbol :" + arbol.at(i)->text(0);

}
for(int i=0; i<arboles->size();i++){
    for(int k=0; k<arboles->at(i).size();k++)
           qDebug()<<"arb: " + arboles->at(i).at(k)->text(0);
}
 arbol.clear();
 qDebug()<<arboles->size();
 qDebug()<<"despues de clear";
   qDebug()<<arboles->at(arboles->size()-1).size();
   qDebug()<<arbol.size();
}


void MainWindow::on_lineEdit_returnPressed()
{
 /**   qDebug()<<"Path Changed";
   Lista<TipoArchivo*>* l;
   qDebug()<<back->size;
  for(int i =0; i<back->size;i++){
  l=back->buscar(i);
 qDebug()<< l->size;
   for(int k=0;k<l->size;k++){
    if(l->buscar(k)->path == ui->lineEdit->text()){
       qDebug()<<"Found";
     }
   }
}**/
   // e = back->buscar(0);
    bool found = false;
    ui->listWidget_2->clear();
      ui->listWidget->clear();
  for(int k=0; k<back->size;k++){
     e = back->buscar(k);
    for(int i=0; i<e->size;i++){
         f= e->buscar(i);
         qDebug()<<f->path;
        if(f->path == ui->lineEdit->text()){
          qDebug()<<"found";
          e = ((Folder*)f)->f;

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
        found = true;
    }
}
    if(found)
    break;
  }

}

void MainWindow::on_treeWidget_expanded(const QModelIndex &index)
{

}



void MainWindow::on_actionCopy_triggered()
{
      qDebug()<<clipboard->size;
      if(clipboard->size>1)
          clipboard->borrarTodo();
      clipboard->inserta(e->buscar(copiar));
      qDebug()<<"copiado: " + clipboard->buscar(clipboard->size-1)->nom;
}

void MainWindow::on_listWidget_2_clicked(const QModelIndex &index)
{

         qDebug()<<  e->buscar(index.row())->nom;
        copiar = index.row();

}

void MainWindow::on_actionPaste_triggered()
{

  TipoArchivo * copiado  =  clipboard->buscar(clipboard->size-1);
    for(int i = 0; i<e->size;i++)
       while(e->buscar(i)->nom==copiado->nom){
            QMessageBox msgBox;
            msgBox.setText("Ya existe un Archivo con este nombre ");
            msgBox.setInformativeText("Desea Guardar el Archivo como " + copiado->nom + "(COPIA)");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            switch (ret) {
              case QMessageBox::Yes:
                   copiado->nom = copiado->nom+"(COPIA)";

                  break;
              case QMessageBox::No:
                  break;

              default:

                  break;
            }
        }
      copiado->path = ui->lineEdit->text()+"\\" + copiado->nom;
    e->inserta(copiado);
    addFolder(re,e->buscar(e->size-1)->nom);
    QListWidgetItem*itm = new  QListWidgetItem(ui->listWidget);
    QListWidgetItem*itm2 = new  QListWidgetItem(ui->listWidget_2);
       itm->setText(copiado->nom);
       itm->setIcon(QIcon(":/folder.png"));
       itm2->setText(copiado->nom);
       itm2->setIcon(QIcon(":/folder.png"));
     qDebug()<<"inserte: " + e->buscar(e->size-1)->nom +e->buscar(e->size-1)->path;
     qDebug()<<"este es t";
     qDebug()<<arbol.size();
     //  qDebug()<<e->size;
     qDebug()<<"tama de e";
     qDebug()<<e->size;
     for(int i= 0; i<e->size; i++)
             qDebug()<<"Aqui estoy: " + e->buscar(i)->nom;


}

void MainWindow::on_actionCut_triggered()
{

    qDebug()<<clipboard->size;
    if(clipboard->size>1)
        clipboard->borrarTodo();
    clipboard->inserta(e->buscar(copiar));
    qDebug()<<"copiado: " + clipboard->buscar(clipboard->size-1)->nom;
    e->eliminar(copiar);
        delete cut;
    qDebug()<<  descargas->at(descargas->size()-1)->takeChild(copiar)->text(0);
    ui->treeWidget->repaint();
}

void MainWindow::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    cut = item;
}
