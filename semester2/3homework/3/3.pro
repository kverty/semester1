#-------------------------------------------------
#
# Project created by QtCreator 2015-04-03T01:19:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 3
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    comparableList.cpp \
    listComparator.cpp \
    sortedSet.cpp

QMAKE_CXXFLAGS += -std=c++0x

HEADERS += \
    comparableList.h \
    listComparator.h \
    sortedSet.h \
    comparableListTest.h \
    sortedSetTest.h

QT += testlib
