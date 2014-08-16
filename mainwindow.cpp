#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include "File.h"
#include "Folder.h"
#include "Lista.h"
#include <QListView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);
    this->item = new QTreeWidgetItem(ui->treeWidget);
    ui->treeWidget->addTopLevelItem(item);
    item->setIcon(0,QIcon(":/desktop.png"));
    item->setText(0,"Este Equipo");
}

MainWindow::~MainWindow()
{
    delete ui;
}



QTreeWidgetItem* MainWindow::addFolder(QString name){
QTreeWidgetItem*itm = new QTreeWidgetItem();
itm->setText(0,name);
item->addChild(itm);
itm->setIcon(0,QIcon(":/folder.png"));
ui->treeWidget->addTopLevelItem(itm);
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
    for(int i = 0; i<item->childCount();i++){
        QListWidgetItem*itm = new  QListWidgetItem(ui->listWidget);
        QListWidgetItem*itm2 = new  QListWidgetItem(ui->listWidget_2);
           itm->setText(item->child(i)->text(column));
           itm->setIcon(item->child(i)->icon(column));
           itm2->setText(item->child(i)->text(column));
           itm2->setIcon(item->child(i)->icon(column));
        }
    }

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(!ui->stackedWidget->currentIndex());
}

