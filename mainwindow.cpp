#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include "File.h"
#include "Folder.h"
#include "Lista.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);
    this->item = new QTreeWidgetItem(ui->treeWidget);
    ui->treeWidget->addTopLevelItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QTreeWidgetItem* MainWindow::addFolder(QString name){
QTreeWidgetItem*itm = new QTreeWidgetItem();
itm->setText(0,name);
item->addChild(itm);
ui->treeWidget->addTopLevelItem(itm);
return itm;
}

void MainWindow::addFile(QTreeWidgetItem * parent, QString name){
    QTreeWidgetItem*itm = new QTreeWidgetItem();
    itm->setText(0,name);
    parent->addChild(itm);
}
