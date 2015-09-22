TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    computer.cpp \
    localnetwork.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    localnetwork.h \
    computer.h \
    list.h \
    linuxcomputer.h \
    windowscomputer.h

QMAKE_CXXFLAGS += -std=c++11
