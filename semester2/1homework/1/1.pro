TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    simpleList.cpp \
    doublelinkedList.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    simpleList.h \
    doublelinkedList.h

QMAKE_CXXFLAGS += -std=c++11
