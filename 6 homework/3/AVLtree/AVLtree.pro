TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tree.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    tree.h

QMAKE_CXXFLAGS += -std=c++11
