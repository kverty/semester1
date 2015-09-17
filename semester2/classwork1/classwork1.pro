#-------------------------------------------------
#
# Project created by QtCreator 2015-04-03T09:52:22
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = classwork1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    queue.h \
    queueTest.h

QT += testlib
QMAKE_CXXFLAGS += -std=c++0x
