#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T16:52:48
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT += testlib

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    uniqueList.cpp \
    simpleList.cpp

HEADERS += \
    list.h \
    listTest.h \
    uniqueList.h \
    simpleList.h
