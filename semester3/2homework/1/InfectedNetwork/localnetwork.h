#pragma once
#include "list.h"
#include "listiterator.h"
#include "computer.h"
#include "linuxcomputer.h"
#include "windowscomputer.h"

#include <iostream>

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
private:
    /// вызывается в конце, для того чтобы перевести всех newlyInfected в infected
    void dealWithNewlyInfected(); // just changes state of some computers

    /// список компьютеров
    List<Computer*> *computers;
};
