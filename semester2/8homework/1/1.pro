#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T23:51:22
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


SOURCES += main.cpp

HEADERS += \
    bag.h \
    bagTest.h
