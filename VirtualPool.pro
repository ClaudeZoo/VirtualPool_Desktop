#-------------------------------------------------
#
# Project created by QtCreator 2015-02-19T18:21:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VirtualPool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylistwidget.cpp \
    vm.cpp \
    croundprocessbar.cpp

HEADERS  += mainwindow.h \
    mylistwidget.h \
    vm.h \
    croundprocessbar.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

RC_FILE = vp.rc
