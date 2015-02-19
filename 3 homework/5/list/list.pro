TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sortedlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sortedlist.h

QMAKE_CXXFLAGS += -std=c++11
