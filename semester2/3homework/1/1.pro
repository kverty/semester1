TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

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
    sort.h

