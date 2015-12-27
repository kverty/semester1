#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T00:30:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app


SOURCES += main.cpp\
        tanksgame.cpp \
    tank.cpp \
    pieceoflandscape.cpp \
    bullet.cpp \
    explosion.cpp

HEADERS  += tanksgame.h \
    tank.h \
    pieceoflandscape.h \
    bullet.h \
    explosion.h

QMAKE_CXXFLAGS += -std=c++0x
