#-------------------------------------------------
#
# Project created by QtCreator 2018-05-14T21:19:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = miniword_0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hdocumentmodel.cpp \
    hcontrol.cpp \
    htextedit.cpp \
    htextcursor.cpp

HEADERS  += mainwindow.h \
    hdocumentmodel.h \
    hcontrol.h \
    htextedit.h \
    htextcursor.h

FORMS    += mainwindow.ui
