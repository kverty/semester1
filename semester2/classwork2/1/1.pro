#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T13:55:58
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x
QT += testlib

SOURCES += main.cpp \
    tree.cpp \
    iterator.cpp

HEADERS += \
    tree.h \
    iterator.h \
    treeTest.h \
    iteratorTest.h
