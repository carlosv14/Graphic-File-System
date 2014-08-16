#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include <qlistwidget.h>
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
    QListWidgetItem* addFol(QString name);
   void addFil(QListWidgetItem* parent, QString name);
   QTreeWidgetItem* addFolder(QString name);
   void addFile(QTreeWidgetItem * parent, QString name);
private slots:

   void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

   void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
