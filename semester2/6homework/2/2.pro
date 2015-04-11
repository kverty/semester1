#-------------------------------------------------
#
# Project created by QtCreator 2015-04-10T16:11:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    setTest.h \
    set.h

QT += testlib
QMAKE_CXXFLAGS += -std=c++0x
