#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T15:28:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2
TEMPLATE = app

QT += testlib
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        findpair.cpp

HEADERS  += findpair.h \
    myButton.h \
    buttonTest.h

FORMS    += findpair.ui
