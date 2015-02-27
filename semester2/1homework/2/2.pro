TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    simpleStack.cpp \
    arrayStack.cpp \
    calculator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stack.h \
    simpleStack.h \
    arrayStack.h \
    calculator.h

QMAKE_CXXFLAGS += -std=c++11
