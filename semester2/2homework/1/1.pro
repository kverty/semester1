#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T14:06:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    doublelinkedList.cpp \
    simpleList.cpp

HEADERS += \
    doublelinkedList.h \
    list.h \
    listTest.h \
    simpleList.h

QT += testlib
QMAKE_CXXFLAGS += -std=c++0x
