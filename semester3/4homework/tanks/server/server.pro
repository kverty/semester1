#-------------------------------------------------
#
# Project created by QtCreator 2015-12-27T00:02:41
#
#-------------------------------------------------

QT       += core gui
QT += network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++0x

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        servertankwindow.cpp \
    ../OnlineTanks/bullet.cpp \
    ../OnlineTanks/explosion.cpp \
    ../OnlineTanks/pieceoflandscape.cpp \
    ../OnlineTanks/tank.cpp \
    ../OnlineTanks/tanksgame.cpp \
    ../OnlineTanks/lightbullet.cpp \
    ../OnlineTanks/heavybullet.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneclient
INSTALLS += target

HEADERS  += servertankwindow.h \
    ../OnlineTanks/bullet.h \
    ../OnlineTanks/explosion.h \
    ../OnlineTanks/pieceoflandscape.h \
    ../OnlineTanks/tank.h \
    ../OnlineTanks/tanksgame.h \
    ../OnlineTanks/lightbullet.h \
    ../OnlineTanks/heavybullet.h

FORMS    += servertankwindow.ui
