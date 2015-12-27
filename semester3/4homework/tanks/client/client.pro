#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T22:10:01
#
#-------------------------------------------------

QT       += core gui
QT += network

QT += widgets

QMAKE_CXXFLAGS += -std=c++0x

TARGET = client
TEMPLATE = app

target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneclient
INSTALLS += target

SOURCES += main.cpp\
        clienttankwindow.cpp \
    ../OnlineTanks/tanksgame.cpp \
    ../OnlineTanks/bullet.cpp \
    ../OnlineTanks/explosion.cpp \
    ../OnlineTanks/pieceoflandscape.cpp \
    ../OnlineTanks/tank.cpp \
    ../OnlineTanks/lightbullet.cpp \
    ../OnlineTanks/heavybullet.cpp

HEADERS  += clienttankwindow.h \
    ../OnlineTanks/tanksgame.h \
    ../OnlineTanks/bullet.h \
    ../OnlineTanks/explosion.h \
    ../OnlineTanks/pieceoflandscape.h \
    ../OnlineTanks/tank.h \
    ../OnlineTanks/lightbullet.h \
    ../OnlineTanks/heavybullet.h

FORMS    += clienttankwindow.ui
