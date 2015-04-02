QT       += core

QT       -= gui

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    calculator.cpp \
    expressions.cpp \
    simpleStack.cpp \
    arrayStack.cpp

HEADERS += \
    calculator.h \
    expressions.h \
    simpleStack.h \
    stack.h \
    stackTest.h \
    arrayStack.h

QMAKE_CXXFLAGS += -std=c++11
QT += testlib
