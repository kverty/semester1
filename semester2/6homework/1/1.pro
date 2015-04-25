#-------------------------------------------------
#
# Project created by QtCreator 2015-04-23T21:15:31
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
    subtreeOperation.cpp \
    mathtree.cpp \
    digits.cpp

HEADERS += \
    subtree.h \
    subtreeNumber.h \
    subtreeOperation.h \
    mathtree.h \
    digits.h \
    subtreeTest.h \
    mathtreeTest.h
