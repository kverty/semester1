TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    outToConsole.cpp \
    outToFile.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    output.h \
    outToConsole.h \
    outToFile.h

