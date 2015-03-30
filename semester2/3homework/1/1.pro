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

TEMPLATE = app
TARGET = 1_2

HEADERS += \
    qsort.h \
    bubblesort.h \
    insertionsort.h \
    sort.h \
    sortTest.h

QT       += core
QT       -= gui
QT += testlib
