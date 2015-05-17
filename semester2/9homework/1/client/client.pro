QT += network widgets

HEADERS       = client.h
SOURCES       = client.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneclient
INSTALLS += target

QMAKE_CXXFLAGS += -std=c++0x
