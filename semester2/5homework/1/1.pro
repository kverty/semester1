#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T16:02:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    simpleList.cpp \
    hashFucntionSquares.cpp \
    hashFunctionPolynom.cpp \
    hashFunctionSum.cpp \
    hashTable.cpp

HEADERS += \
    listTest.h \
    simpleList.h \
    hashTable.h \
    hashTableTest.h \
    hashFunctionTest.h \
    hashFunction.h \
    hashFunctionSum.h \
    hashFunctionSquares.h \
    hashFunctionPolynom.h

QMAKE_CXXFLAGS += -std=c++11
QT += testlib
