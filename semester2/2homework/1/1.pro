TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    doublelinkedList.cpp \
    simpleList.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    doublelinkedList.h \
    list.h \
    simpleList.h

QMAKE_CXXFLAGS += -std=c++11
