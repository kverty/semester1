#pragma once
#include "list.h"
#include "listiterator.h"

#include <QObject>
#include <QTest>

const int constForRand = 100;

class ComputerTest : public QObject
{
   Q_OBJECT
public:
   explicit ComputerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void probabilityTest(); 
    void spreadTest();
private:
    int numberOfTests = 20;
    int epsilon = 0.1;
};

enum State
{
    healthy,
    newlyInfected, /// компьютер только что заразили
    infected
};
/// абстрактный класс компьютера
class Computer
{
public:
    ~Computer();
    int currentState() const;

    /// срабатывает, когда этот компьютер пытаются заразить
    void attacked();

    /// посылает данные связанным с ним компьютерам и автоматически атакует их, если этот компьтер заражен
    void touchOthers() const;

    /// переводит этот компьютер из состояния newlyInfected в infected
    void infectNewlyInfected();

    /// переводит этот компьютер в состояние infected
    void infect();

    /// добавляет соседа
    void addNeighbour(Computer *computer) const;

protected:
    /// зависит от ОС и может быть чего-нибудь еще
    double chanceToBeInfected;
    int state;
    /// те компьютеры, с кем этот компьютер связан
    List<Computer *> *neighbours;
};
