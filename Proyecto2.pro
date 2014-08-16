#-------------------------------------------------
#
# Project created by QtCreator 2014-08-10T08:45:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    File.cpp \
    Folder.cpp \
    TipoArchivo.cpp

HEADERS  += mainwindow.h \
    File.h \
    Folder.h \
    Lista.h \
    Nodo.h \
    TipoArchivo.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    Resources.qrc
