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
   QTreeWidgetItem* addFolder(QString name);
   void addFile(QTreeWidgetItem * parent, QString name);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
