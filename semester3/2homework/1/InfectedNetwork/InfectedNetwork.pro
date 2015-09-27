#-------------------------------------------------
#
# Project created by QtCreator 2015-09-27T20:59:06
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = untitled
CONFIG   += console
CONFIG   -= app_bundle

TARGET = 1
TEMPLATE = app

SOURCES += main.cpp \
    computer.cpp \
    localnetwork.cpp \
    computertest.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    localnetwork.h \
    computer.h \
    list.h \
    linuxcomputer.h \
    windowscomputer.h \
    listiterator.h

QMAKE_CXXFLAGS += -std=c++0x
QT += testlib
