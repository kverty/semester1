#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T16:37:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OnlineTanks
TEMPLATE = app


SOURCES += main.cpp \
    explosion.cpp \
    pieceoflandscape.cpp \
    tank.cpp \
    tanksgame.cpp \
    bullet.cpp

HEADERS  += \
    bullet.h \
    explosion.h \
    pieceoflandscape.h \
    tank.h \
    tanksgame.h

QMAKE_CXXFLAGS += -std=c++0x
