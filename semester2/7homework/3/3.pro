#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T22:03:11
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT += testlib

TARGET = 3
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp

HEADERS += \
    sharedPointer.h \
    sharedPointerTest.h
