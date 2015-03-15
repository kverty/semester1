TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    calculator.cpp \
    expressions.cpp \
    simpleStack.cpp

include(deployment.pri)

HEADERS += \
    calculator.h \
    expressions.h \
    simpleStack.h \
    stack.h

QMAKE_CXXFLAGS += -std=c++11
