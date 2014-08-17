#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include <qlistwidget.h>
#include "Folder.h"
#include "Lista.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   QTreeWidgetItem* item;
    QListWidgetItem * l;
        Folder* f;
          Folder*busc;
        Lista <Folder*>* e;
    QListWidgetItem* addFol(QString name);
    QTreeWidgetItem * re ;
   void addFil(QListWidgetItem* parent, QString name);
   QTreeWidgetItem* addFolder(QTreeWidgetItem * parent,QString name);
   void addFile(QTreeWidgetItem * parent, QString name);
private slots:

   void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

   void on_pushButton_clicked();

  void on_actionNueva_Carpeta_triggered();


  void on_actionNuevo_Archivo_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
