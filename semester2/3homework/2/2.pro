#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T22:23:41
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    output.cpp \
    outToConsole.cpp \
    outToFile.cpp

HEADERS += \
    output.h \
    outToConsole.h \
    outToFile.h \
    outputTest.h

QT += testlib
