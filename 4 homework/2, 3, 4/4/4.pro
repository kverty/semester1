TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stack.cpp \
    expressions.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stack.h \
    expressions.h

QMAKE_CXXFLAGS += -std=c++11
