TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    qsort.cpp \
    sort.cpp \
    insertionsort.cpp \
    bubblesort.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    qsort.h \
    bubblesort.h \
    insertionsort.h \
    sort.h \
    sortTest.h

QT += core
QT -= gui
QT += testlib
TEMPLATE = app
TARGET = 1_2
