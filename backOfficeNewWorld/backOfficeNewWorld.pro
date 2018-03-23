#-------------------------------------------------
#
# Project created by QtCreator 2017-11-17T10:48:19
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = backOfficeNewWorld
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connexion.cpp

HEADERS  += mainwindow.h \
    connexion.h

FORMS    += mainwindow.ui \
    connexion.ui

RESOURCES += \
    ImgRessources.qrc
