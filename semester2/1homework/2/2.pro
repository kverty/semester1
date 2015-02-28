TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    simpleStack.cpp \
    calculator.cpp \
    expressions.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stack.h \
    simpleStack.h \
    calculator.h \
    expressions.h

QMAKE_CXXFLAGS += -std=c++11
