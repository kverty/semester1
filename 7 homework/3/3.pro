TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mystring.cpp \
    list.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    mystring.h \
    list.h

QMAKE_CXXFLAGS += -std=c++11
