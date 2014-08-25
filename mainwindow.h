#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include <qlistwidget.h>
#include "Folder.h"
#include "Lista.h"
#include <QList>
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
        TipoArchivo* f;
        Lista <TipoArchivo*>* e;
        Lista <TipoArchivo*>* clipboard;
        Lista<Lista<TipoArchivo*>*>*back;
         QList<Lista<TipoArchivo*>*>forw;
    QListWidgetItem* addFol(QString name);
    QTreeWidgetItem * re ;
    QList<QString>atras;
    int copiar;
        QList<QTreeWidgetItem*> arbol;
        QList<QList<QTreeWidgetItem*> >* arboles;
        QTreeWidgetItem* sw;
        QList<QTreeWidgetItem*>* descargas;
        QListWidgetItem* cut;


   void addFil(QListWidgetItem* parent, QString name);
   QTreeWidgetItem* addFolder(QTreeWidgetItem * parent,QString name);
   void addFile(QTreeWidgetItem * parent, QString name);
private slots:

   void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

   void on_pushButton_clicked();

  void on_actionNueva_Carpeta_triggered();


  void on_actionNuevo_Archivo_triggered();

  void on_treeWidget_doubleClicked(const QModelIndex &index);

  void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

  void on_treeWidget_clicked(const QModelIndex &index);

  void on_commandLinkButton_clicked();

  void on_listWidget_2_doubleClicked(const QModelIndex &index);


  void on_listWidget_doubleClicked(const QModelIndex &index);

  void on_lineEdit_returnPressed();

  void on_treeWidget_expanded(const QModelIndex &index);

  void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

  void on_actionCopy_triggered();

  void on_listWidget_2_clicked(const QModelIndex &index);

  void on_actionPaste_triggered();

  void on_actionCut_triggered();

  void on_listWidget_2_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
