#pragma once
#include "list.h"
#include "listiterator.h"
#include "computer.h"
#include "linuxcomputer.h"
#include "windowscomputer.h"
#include "testingcomputer.h"

#include <iostream>

#include <QObject>
#include <QTest>

class NetworkTest : public QObject
{
   Q_OBJECT
public:
   explicit NetworkTest(FILE *fileWithTest, QObject *parent = 0) : inputFile(fileWithTest), QObject(parent) {}

private slots:
    void networkTest();
private:
    FILE *inputFile;
};

/// класс для локальной сети, ничего не знает о связях между компьютерами, инициирует передачу данных
class LocalNetwork
{
public:
    /// считывает информацию о сети из файла
    LocalNetwork(FILE *inputFile);
    ~LocalNetwork();

    /// начинается передача данных от каждого копьютера всем
    void startThisTurn();

    /// выводятся результаты передачи данных, кто заражен, кто нет
    void writeResults() const;

    friend NetworkTest;
private:
    /// вызывается в конце, для того чтобы перевести всех newlyInfected в infected
    void dealWithNewlyInfected();

    /// список компьютеров
    List<Computer*> *computers;
};
