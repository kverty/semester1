TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    listComparator.cpp \
    comparableList.cpp \
    sortedSet.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    listComparator.h \
    comparableList.h \
    sortedSet.h

QMAKE_CXXFLAGS += -std=c++11
