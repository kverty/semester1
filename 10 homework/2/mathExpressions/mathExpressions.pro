TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mathExpressions.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    mathExpressions.h

QMAKE_CXXFLAGS += -std=c++11
