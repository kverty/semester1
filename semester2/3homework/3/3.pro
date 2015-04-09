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
    listComparator.cpp \
    comparableList.cpp \
    sortedSet.cpp

HEADERS += \
    listComparator.h \
    comparableList.h \
    sortedSet.h

QT += testlib
QMAKE_CXXFLAGS += -std=c++0x
