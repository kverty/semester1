TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    digits.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    digits.h

QMAKE_CXXFLAGS += -std=c++11
