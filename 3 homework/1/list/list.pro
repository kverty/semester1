TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circledlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    circledlist.h

QMAKE_CXXFLAGS += -std=c++11
