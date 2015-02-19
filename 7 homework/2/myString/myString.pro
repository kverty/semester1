TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mystring.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    mystring.h

QMAKE_CXXFLAGS += -std=c++11
