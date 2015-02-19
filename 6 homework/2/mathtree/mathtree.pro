TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mathtree.cpp \
    digits.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    mathtree.h \
    digits.h

QMAKE_CXXFLAGS += -std=c++11
