#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T16:13:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = numComplex
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    complexo.cpp \
    ../template.cpp \


HEADERS  += mainwindow.h \
    complexo.h \
    matriz.h \
    ../template.h \
    testetemplate.h

FORMS    += mainwindow.ui
